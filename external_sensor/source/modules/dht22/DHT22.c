/*
 * DHT22.c
 *
 * Created: 2016-11-19 20:27:01
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "common.h"
#include "DHT22.h"
#include "fsm.h"

volatile DHT22_STATES_t dht22_state;									// Stan maszyny stan�w
volatile DHT22_DATA_t dht22_data;										// Dane z czujnika
 
volatile uint8_t bit_position;											// Pozycja kolejnego bitu			

static inline uint16_t CalcTime(uint16_t time)
{
	return time*(F_CPU/1000000UL)/2;		//Przelicza czas w mikrosekundach na tykni�cia timera
											//Przy timerze taktowanym CLKPER/2 i zegarze 2 MHz jedno tykni�cie to 1us
}

void DHT22_config(void)
{
	// Konfiguracja zdarze� dla pinu DATA czujnika
	EVSYS.CH0MUX = EVSYS_CHMUX_PORTF_PIN2_gc;													// Zdarzenia transmitowane przez kana� 0
	
	// Konfiguracja licznika do odbioru danych (Timer0 portu D)
	TCD0.CTRLB |= TC_WGMODE_NORMAL_gc | TC0_CCAEN_bm;											// Tryb pracy normalny
	TCD0.CTRLD |= TC_EVSEL_CH0_gc | TC_EVACT_PW_gc;												// Kana� 0 jako capture, tryb Pulse Width Capture
	TCD0.PER = CalcTime(DHT22_ONE_HIGH_UPPER_LIMIT + DHT22_LOW_UPPER_LIMIT + 10);				// Czas do wykrycia b��du transmisji (brak nadej�cia zbocza rosn�cego
	
	// Konfiguracja licznika do wygenerowania sygna�u startu (Timer0 portu F)
	TCF0.CTRLB |= TC_WGMODE_NORMAL_gc;															// Tryb pracy normalny
	TCF0.PER = CalcTime(DHT22_HOST_INIT_LOW);													// Czas generowania sygna�u startu (do momentu wyst�pienia przerwania)
}

uint8_t DHT22_init_action(void)
{
	dht22_state = DHT22_IDLE_STATE;					// Zeruj maszyn� stan�w
	
	/* Zerowanie struktury danych */
	dht22_data.humidity_hi = 0;
	dht22_data.humidity_lo = 0;
	dht22_data.temperature_hi = 0;
	dht22_data.temperature_lo = 0;
	dht22_data.checksum = 0;
	dht22_data.error = DHT_ERROR_HOST_INIT;

	/* Konfiguracja licznika do odbioru danych (Timer0 portu D) */
	TCD0.CNT = 0;
	
	/* Konfiguracja licznika do wygenerowania sygna�u startu (Timer0 portu F) */
	TCF0.CNT = 0;
	SENSOR_DATA_PORT.DIRSET = SENSOR_DATA_PIN;		// Prze��cz na wyj�cie
	SENSOR_DATA_PORT.OUTCLR = SENSOR_DATA_PIN;		// Rozpocznij sygna� startu
	TCF0.INTCTRLA |= TC_OVFINTLVL_LO_gc;			// W��cz przerwanie nadmiaru
	TCF0.CTRLA = TC_CLKSEL_DIV2_gc;					// Ustaw dzielnik 2 - w��cz licznik!
	
	return 1;
}

// Przerwanie od przepe�nienia licznika sygna�u startu - zako�czenie stanu niskiego
ISR(TCF0_OVF_vect)
{
	/* Konfiguracja licznika do wygenerowania sygna�u startu (Timer0 portu F) */
	TCF0.INTCTRLA &= ~TC0_OVFINTLVL_gm;			// Wy��cz przerwanie nadmiaru
	TCF0.CTRLA &= ~TC0_CLKSEL_gm;				// Wy��cz licznik!
	
	/* Konfiguracja licznika do odbioru danych (Timer0 portu D) */
	TCD0.INTCTRLA |= TC_OVFINTLVL_LO_gc;			// W��cz przerwanie nadmiaru - wykrywanie b��d�w transmisji
	TCD0.INTCTRLB |= TC_CCAINTLVL_LO_gc;			// W��cz przerwanie CC - prze��czanie maszyny stan�w
	TCD0.CTRLA |= TC_CLKSEL_DIV2_gc;				// Ustaw dzielnik 2 - w��cz licznik!
	
	SENSOR_DATA_PORT.OUTSET = SENSOR_DATA_PIN;	// Zako�cz sygna� startu - zbocze rosn�ce wyzeruje licznik w trybie Pulse Width Capture
	SENSOR_DATA_PORT.DIRCLR = SENSOR_DATA_PIN;	// Prze��cz na wej�cie
}

// Przerwanie od przepe�nienia licznika odbioru danych - b��d lub koniec odbioru
ISR(TCD0_OVF_vect)
{
	TCD0.INTCTRLA &= ~TC0_OVFINTLVL_gm;									// Wy��cz przerwanie nadmiaru - wykrywanie b��d�w transmisji
	TCD0.INTCTRLB &= ~TC0_CCAINTLVL_gm;									// Wy��cz przerwanie CC - prze��czanie maszyny stan�w
	TCD0.CTRLA &= ~TC0_CLKSEL_gm;										// Wy��cz licznik!

	fsm_event_flag_set(&fsm_event_flags, dht22_checksum_calculate_event);	// Ustaw flag� dla zdarzenia
}


// Przerwanie od zdarzenia wykonania pomiaru czasu trwania stanu wysokiego (0 czy 1)
ISR(TCD0_CCA_vect)
{
	uint16_t capture_channel_a = TCD0.CCA;
	
	switch(dht22_state)
	{
		case DHT22_IDLE_STATE:
			if ((CalcTime(DHT22_HOST_INIT_RELEASE_LOWER_LIMIT) < capture_channel_a) && (CalcTime(DHT22_HOST_INIT_RELEASE_UPPER_LIMIT) > capture_channel_a))
			{
				dht22_state = DHT22_RESPONSE_STATE;
			}
			dht22_data.error = DHT_ERROR_RESPONSE;
			break;
		
		case DHT22_RESPONSE_STATE:
			if ((CalcTime(DHT22_RESPONSE_RELEASE_LOWER_LIMIT) < capture_channel_a) && (CalcTime(DHT22_RESPONSE_RELEASE_UPPER_LIMIT) > capture_channel_a))
			{
				dht22_state = DHT22_RECEIVE_HUMID_HI_BYTE_STATE;
				bit_position = 0;
			}
			dht22_data.error = DHT_ERROR_DATA_RECEIVE;
			break;
		
		case DHT22_RECEIVE_HUMID_HI_BYTE_STATE:
//			if ((CalcTime(DHT22_ONE_HIGH_LOWER_LIMIT) < capture_channel_b) && (CalcTime(DHT22_ONE_HIGH_UPPER_LIMIT) > capture_channel_b))
			if(capture_channel_a > (CalcTime(DHT22_ZERO_HIGH_UPPER_LIMIT)))
			{
				dht22_data.humidity_hi |= (1 << (7 - bit_position));
			}
			bit_position++;
			if (bit_position == 8)
			{
				bit_position = 0;
				dht22_data.error = DHT_ERROR_DATA_RECEIVE;
				dht22_state = DHT22_RECEIVE_HUMID_LO_BYTE_STATE;
			}
			break;
			
		case DHT22_RECEIVE_HUMID_LO_BYTE_STATE:
//			if ((CalcTime(DHT22_ONE_HIGH_LOWER_LIMIT) < capture_channel_b) && (CalcTime(DHT22_ONE_HIGH_UPPER_LIMIT) > capture_channel_b))
			if(capture_channel_a > (CalcTime(DHT22_ZERO_HIGH_UPPER_LIMIT)))
			{
				dht22_data.humidity_lo |= (1 << (7 - bit_position));
			}
			bit_position++;
			if (bit_position == 8)
			{
				bit_position = 0;
				dht22_data.error = DHT_ERROR_DATA_RECEIVE;
				dht22_state = DHT22_RECEIVE_TEMP_HI_BYTE_STATE;
			}
			break;
			
		case DHT22_RECEIVE_TEMP_HI_BYTE_STATE:
//			if ((CalcTime(DHT22_ONE_HIGH_LOWER_LIMIT) < capture_channel_b) && (CalcTime(DHT22_ONE_HIGH_UPPER_LIMIT) > capture_channel_b))
			if(capture_channel_a > (CalcTime(DHT22_ZERO_HIGH_UPPER_LIMIT)))
			{
				dht22_data.temperature_hi |= (1 << (7 - bit_position));
			}
			bit_position++;
			if (bit_position == 8)
			{
				bit_position = 0;
				dht22_data.error = DHT_ERROR_DATA_RECEIVE;
				dht22_state = DHT22_RECEIVE_TEMP_LO_BYTE_STATE;
			}
			break;
		
		case DHT22_RECEIVE_TEMP_LO_BYTE_STATE:
//			if ((CalcTime(DHT22_ONE_HIGH_LOWER_LIMIT) < capture_channel_b) && (CalcTime(DHT22_ONE_HIGH_UPPER_LIMIT) > capture_channel_b))
			if(capture_channel_a > (CalcTime(DHT22_ZERO_HIGH_UPPER_LIMIT)))
			{
				dht22_data.temperature_lo |= (1 << (7 - bit_position));
			}
			bit_position++;
			if (bit_position == 8)
			{
				bit_position = 0;
				dht22_data.error = DHT_ERROR_DATA_RECEIVE;
				dht22_state = DHT22_RECEIVE_CHECKSUM_BYTE_STATE;
			}
			break;
				
		case DHT22_RECEIVE_CHECKSUM_BYTE_STATE:
//			if ((CalcTime(DHT22_ONE_HIGH_LOWER_LIMIT) < capture_channel_b) && (CalcTime(DHT22_ONE_HIGH_UPPER_LIMIT) > capture_channel_b))
			if(capture_channel_a > (CalcTime(DHT22_ZERO_HIGH_UPPER_LIMIT)))
			{
				dht22_data.checksum |= (1 << (7 - bit_position));
			}
			bit_position++;
			if (bit_position == 8)
			{
				bit_position = 0;
				dht22_data.error = DHT_ERROR_CHECKSUM;
				dht22_state = DHT22_IDLE_STATE;
			}
			break;
	}
}

uint8_t DHT22_checksum_calculate_action(void)
{	
	if (dht22_data.error == DHT_ERROR_CHECKSUM)	// Je�eli odebrano wszystkie 5 bajt�w
	{
		uint8_t checksum = (dht22_data.humidity_hi + dht22_data.humidity_lo + dht22_data.temperature_hi + dht22_data.temperature_lo);
		
		if(dht22_data.checksum == checksum)
		{
			dht22_data.error = DHT_ERROR_NONE;
		}
		else
		{
			dht22_data.humidity_hi = 0;
			dht22_data.humidity_lo = 4;
			dht22_data.temperature_hi = 0;
			dht22_data.temperature_lo = 4;
		}
	}
	else
	{
		dht22_data.humidity_hi = 0;
		dht22_data.humidity_lo = 2;
		dht22_data.temperature_hi = 0;
		dht22_data.temperature_lo = 2;
	}
	
	return 1;
}