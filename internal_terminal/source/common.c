/*
 * common.c
 *
 *  Created on: 5 lut 2015
 *      Author: Servis_Krakow1
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <util/atomic.h>
#include "common.h"
#include "fsm/fsm.h"
#include "watchdog.h"
#include "EG9018C/eg9018c.h"
#include "EG9018C/LCD_GRAPH/lcd_graph.h"
#include "EG9018C/LCD_TEXT/lcd_text.h"
#include "Interfaces/spi.h"
#include "Interfaces/uart.h"
#include "DS3231/ds3231.h"
#include "BMP180/bmp180.h"
#include "DHT22/dht22.h"
#include "nRF24L01/radio.h"
#include "Telnet/telnet_menu.h"
#include "Telnet/mkvt100.h"

EXTERNAL_SENSOR_TYPE1_DATA_t external_t1_sensor[SENSORS_T1_QUANTITY];
DHT22_SENSOR_DATA_t dht22_internal_sensor;
DS3231_SENSOR_DATA_t ds3231_internal_sensor;
BMP180_SENSOR_DATA_t bmp180_internal_sensor;

const char days[7][13] = {"poniedzia³ek", "wtorek", "œroda", "czwartek", "pi¹tek", "sobota", "niedziela"};
/*
void _StackPaint(void)
{
	for(void* fill_pos = (void*)&_end; fill_pos < (void*)&__stack; fill_pos++) *(uint8_t*)fill_pos =  0xAB;
}

uint16_t StackCount(void)
{
	const void *ptr = &_end;
	uint16_t cnt = 0;
	
	while((*(uint8_t*)ptr == 0xAB) && (ptr <= (void*)&__stack))
	{
		ptr++;
		cnt++;
	}
	
	return cnt;
}
*/
void main_port_init(void)
{	
	SPI_SSRAM_CS_OFF;
	DDR(SPI_SSRAM_CS_PORT) |= (1<<SPI_SSRAM_CS);
	
	nrf24l01_CSNhi;
	DDR(NRF24L01_CSN_PORT) |= (1<<NRF24L01_CSN);
	
	PORT(LCD_ILUM_PORT) &= ~(1<<LCD_ILUM);
	DDR(LCD_ILUM_PORT) |= (1<<LCD_ILUM);
	
	PORT(RADIO_IRQ_PORT) |= (1<<RADIO_IRQ); // pullup w³¹czony, bo IRQ active low
	DDR(RADIO_IRQ_PORT) &= ~(1<<RADIO_IRQ); // wejœcie dla IRQ
	
	PORT(DS3231_SQW_PORT) |= (1<<DS3231_SQW); // INT2 pullup w³¹czony, bo SQW to mosfet
	DDR(DS3231_SQW_PORT) &= ~(1<<DS3231_SQW); // port INT2 jako wejœcie dla DS3231 SQW
}

void interrupts_init(void)
{
	EICRA |= (1<<ISC21); // przerwanie dla INT2 od zbocza opadaj¹cego
	EIMSK |= (1<<INT2); // w³¹czenie przerwania od INT2
}

void timers_on(void)
{
	timers_setup();
	lcd_s_and_cclr_timer_init();
	lcd_cp1_timer_init();
	sei();
	lcd_cp2_timer_init();
	lcd_ilum_timer_init(LCD_ILUM_DAY);
}

void lcd_ilum_timer_init(uint8_t duty_cycle)
{
	TCCR0A |= (1<<WGM01) | (1<<WGM00);	// Mode 3 - fast PWM
	
	TCCR0A |= (1<<COM0B1);				// Clear OC0B on Compare Match, set on TOP
	TCCR0B |= (1<<CS00) | (1<<CS01);	// clk/64 = 1350 Hz ----clk/1 = 86400 Hz
	
	OCR0B = duty_cycle;					// Output Compare Register value (8 bit)
}

void lcd_ilum_change(uint8_t duty_cycle)
{
	OCR0B = duty_cycle;					// Output Compare Register value (8 bit)
}


// ********************** ZDARZENIA ********************************

uint8_t common_check_stack_action(void)
{
	uint16_t stack_value = 0;
	char buff[6];
	
	stack_value = StackCount();
	uart_puts(itoa(stack_value, buff, 10));
	
	return 1;
}

uint8_t common_read_sensors_action(void)
{
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[0]);
	#endif
	
	common_read_internal_sensors();
	common_read_external_sensors();
	
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[2]);
	#endif
	
	return 1;
}

uint8_t common_prepare_sensors_strings_action(void)
{
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[1]);
	#endif
	
	common_prepare_sensors_strings();
	
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[2]);
	#endif
	
	return 1;
}

uint8_t common_prepare_ext_system_strings_action(void)
{
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[1]);
	#endif
	
	common_prepare_ext_system_strings();
	
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[2]);
	#endif
	
	return 1;
}

uint8_t common_prepare_datetime_strings_action(void)
{
	common_prepare_datetime_strings();
	
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[2]);
	#endif
	
	return 1;
}

uint8_t common_lcd_ilum_change_action(void)
{
	if( (ds3231_internal_sensor.datetime_value.hh > 6) && (ds3231_internal_sensor.datetime_value.hh < 20) )
		lcd_ilum_change(LCD_ILUM_DAY);
	else	
		lcd_ilum_change(LCD_ILUM_NIGHT);
	
	return 1;
}

ISR(INT2_vect) // przerwanie generowane przez DS3231 SQW co 1 s
{
	switch(ds3231_get_datetime(&ds3231_internal_sensor.datetime_value))
	{
		case LCD_PREPARE_FOREGROUND_EV: fsm_event_flag_set(fsm_event_flags, fsm_lcd_prepare_foreground_event); break;
	}
	fsm_event_flag_set(fsm_event_flags, fsm_telnet_time_update_event);
}

void common_read_internal_sensors(void)
{
	ds3231_get_temp( &ds3231_internal_sensor.temperature_value );
	bmp180_getut( &bmp180_internal_sensor.bmp180_value );
	bmp180_gett( &bmp180_internal_sensor.bmp180_value );
	bmp180_getup( &bmp180_internal_sensor.bmp180_value );
	bmp180_getp( &bmp180_internal_sensor.bmp180_value );
	dht22_internal_sensor.error = readDHT22( &dht22_internal_sensor.data );
}

void common_read_external_sensors(void)
{
	uint16_t humidity, temperature;

/*	Czujnik typu 1

	radio_data.tx_buffer[system_data_status] = system_data.status;
	radio_data.tx_buffer[system_data_supply] = system_data.supply_voltage;
	radio_data.tx_buffer[sensors_data_status] = ;
	
	radio_data.tx_buffer[dht22_data_hum_h] = dht22_data.humidity_hi;
	radio_data.tx_buffer[dht22_data_hum_l] = dht22_data.humidity_lo;
	radio_data.tx_buffer[dht22_data_temp_h] = dht22_data.temperature_hi;
	radio_data.tx_buffer[dht22_data_temp_l] = dht22_data.temperature_lo;
	
	radio_data.tx_buffer[pluviometer_data_mmH2O] = pluviometer_data.mmH2O_p_15min;
	
	radio_data.tx_buffer[pms_data_pm1] = pms_pm_data.pm_1_0_concentr;
	radio_data.tx_buffer[pms_data_pm2] = pms_pm_data.pm_2_5_concentr;
	radio_data.tx_buffer[pms_data_pm10] = pms_pm_data.pm_10_concentr;
*/
	
	for(uint8_t i=0; i<SENSORS_T1_QUANTITY; i++)
	{
		if(radio_sensors[i].status)
		{
			radio_sensors[i].status = false;						// zerowanie flagi nowych danych
						
			// *********** ODCZYT REJESTRU STATUSU (RESET) ************
			external_t1_sensor[i].system_data.rst_status = radio_sensors[i].rx_buffer[system_data_status];
			external_t1_sensor[i].system_data.sensors_status = radio_sensors[i].rx_buffer[sensors_data_status];
			
			strcpy(external_t1_sensor[i].timestamp, ds3231_internal_sensor.time_string);	// TYMCZASOWE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			
			// *********** ODCZYT NAPIÊCIA ZASILANIA ************
			
			//	Przeliczenie wartoœci odczytanej z przetwornika na wartoœæ napiêcia:
			//	napiêcie = ((( przemno¿enie przez 10 bo pomiar Vcc/10 * napiêcie odniesienia * wynik ADC * przemno¿enie przez 100 dla uzyskania liczby ca³kowitej) / 11 bitów ) - odjêcie 100 czyli pomniejszenie wyniku o 1V ¿eby zmieœciæ siê w 8 bit
			//	przyk³ad dla nap. 3,18 V:
			//	supply = (((10 * 1 * 652 * 100) / 2048) - 100) = 652000 / 2048 - 100 = 318 - 100 = 218
			//	¿eby odtworzyæ wartoœæ trzeba:
			//	U = (supply + 100) / 100 = (218 + 100) / 100 = 318 /100 = 3,18 V
			
			uint16_t vol;
			
			vol = (radio_sensors[i].rx_buffer[system_data_supply] + 100);
			external_t1_sensor[i].system_data.supply_voltage_integral = (uint8_t) (vol / 100);
			external_t1_sensor[i].system_data.supply_voltage_decimal = (uint8_t) (vol % 100);
			
			
			// *********** ODCZYT CZUJNIKA DHT22 ************
			
			external_t1_sensor[i].dht22_data.error = (0x3F & radio_sensors[i].rx_buffer[sensors_data_status]);		// maskowanie b³êdów DHT22
			
			if(!(external_t1_sensor[i].dht22_data.error))	// SprawdŸ czy czujnik DHT22 zosta³ poprawnie odczytany
			{
				// Po³¹cz dane z czujnika w 16 bit
				humidity = radio_sensors[i].rx_buffer[dht22_data_hum_h];
				humidity = humidity << 8;
				humidity |= radio_sensors[i].rx_buffer[dht22_data_hum_l];
				temperature = radio_sensors[i].rx_buffer[dht22_data_temp_h];
				temperature = temperature << 8;
				temperature |= radio_sensors[i].rx_buffer[dht22_data_temp_l];
				
				external_t1_sensor[i].dht22_data.data.humidity_integral = (uint8_t)(humidity / 10);
				external_t1_sensor[i].dht22_data.data.humidity_decimal = (uint8_t)(humidity % 10);

				if(temperature & 0x8000)	// Check if temperature is below zero, non standard way of encoding negative numbers!
				{
					temperature &= 0x7FFF; // Remove sign bit
					external_t1_sensor[i].dht22_data.data.temperature_integral = (int8_t)(temperature / 10) * -1;
					external_t1_sensor[i].dht22_data.data.temperature_decimal = (uint8_t)(temperature % 10);
				} else
				{
					external_t1_sensor[i].dht22_data.data.temperature_integral = (int8_t)(temperature / 10);
					external_t1_sensor[i].dht22_data.data.temperature_decimal = (uint8_t)(temperature % 10);
				}
			}
/*			else
			{
				external_t1_sensor[i].dht22_data.data.humidity_decimal = 0xFF;
				external_t1_sensor[i].dht22_data.data.temperature_decimal = 0xFF;
			}
*/			
			// *********** ODCZYT CZUJNIKA PMSA003 ************
			
			external_t1_sensor[i].pms_data.pms_value.error = (0xC0 & radio_sensors[i].rx_buffer[sensors_data_status]);		// maskowanie b³êdów pmsa0033
			
			if(!(external_t1_sensor[i].pms_data.pms_value.error))	// SprawdŸ czy czujnik PMS zosta³ poprawnie odczytany
			{
				external_t1_sensor[i].pms_data.pms_value.pm1_mass = radio_sensors[i].rx_buffer[pms_data_pm1];
				external_t1_sensor[i].pms_data.pms_value.pm2_mass = radio_sensors[i].rx_buffer[pms_data_pm2];
				external_t1_sensor[i].pms_data.pms_value.pm10_mass = radio_sensors[i].rx_buffer[pms_data_pm10];
			}
/*			else
			{
				external_t1_sensor[i].pms_data.pms_value.pm1_mass = 0xFF;
				external_t1_sensor[i].pms_data.pms_value.pm2_mass = 0xFF;
				external_t1_sensor[i].pms_data.pms_value.pm10_mass = 0xFF;
			}
*/			
			// *********** ODCZYT CZUJNIKA ************
			
			external_t1_sensor[i].pluviometer_data.mmH2O_value = radio_sensors[i].rx_buffer[pluviometer_data_mmH2O];
		}
/*		else
		{
			external_t1_sensor[i].system_data.supply_voltage_decimal = 0xFF;
			external_t1_sensor[i].dht22_data.data.humidity_decimal = 0xFF;
			external_t1_sensor[i].dht22_data.data.temperature_decimal = 0xFF;
			external_t1_sensor[i].pms_data.pms_value.pm1 = 0xFF;
			external_t1_sensor[i].pms_data.pms_value.pm2 = 0xFF;
			external_t1_sensor[i].pms_data.pms_value.pm10 = 0xFF;
			external_t1_sensor[i].pluviometer_data.mmH2O_value = 0xFF;
		}
*/	} 
}

void common_prepare_sensors_strings(void)
{
	ds3231_prepare_temp_string(&ds3231_internal_sensor);
	
	bmp180_prepare_temp_string(&bmp180_internal_sensor);
	bmp180_prepare_press_string(&bmp180_internal_sensor);
	wdt_reset();
	dht22_prepare_temp_string(&dht22_internal_sensor);
	dht22_prepare_humid_string(&dht22_internal_sensor);
//	dht22_prepare_error_string( &sensor_internal );
	wdt_reset();
	dht22_prepare_temp_string( &external_t1_sensor[0].dht22_data );
	dht22_prepare_humid_string( &external_t1_sensor[0].dht22_data );
	dht22_prepare_error_string( &external_t1_sensor[0].dht22_data );
	wdt_reset();
	pms_prepare_pm_strings( &external_t1_sensor[0].pms_data );
	pluviometer_prepare_strings( &external_t1_sensor[0].pluviometer_data );
}

void common_prepare_datetime_strings(void)
{
	ds3231_prepare_time_string(&ds3231_internal_sensor);
	ds3231_prepare_date_string(&ds3231_internal_sensor);
	ds3231_prepare_day_string(&ds3231_internal_sensor);
}

void common_prepare_ext_system_strings(void)
{
	common_prepare_voltage_string(&external_t1_sensor->system_data);
	common_prepare_status_string(&external_t1_sensor->system_data);
}

void common_update_diagram_value(void)
{
	
}

// ********************** PRZYGOTOWANIE STRINGÓW SYSTEMOWYCH ********************************

void common_prepare_voltage_string(SENSORS_SYS_DATA_t *data)	// "VCC: 3,35V"
{
	char buff[4];

	strcpy(data->supply_voltage_string, "VCC: ");
	
	if(data->supply_voltage_decimal == 0xFF)
	{
		strcat(data->supply_voltage_string, "- V");
	}
	else
	{
		strcat(data->supply_voltage_string, itoa(data->supply_voltage_integral, buff, 10));
		strcat(data->supply_voltage_string, ".");
		if(data->supply_voltage_decimal < 10)
			strcat(data->supply_voltage_string, "0");
		strcat(data->supply_voltage_string, itoa(data->supply_voltage_decimal, buff, 10));
		strcat(data->supply_voltage_string, "V");
	}	
}

void common_prepare_status_string(SENSORS_SYS_DATA_t *data)	// "RST FLAG: BROWN-OUT"
{
	if (data->rst_status != 0)
	{
		strcpy(data->rst_status_string, "RST FLAG: ");
		if ((data->rst_status & (1 << 0)) != 0)
		strcat(data->rst_status_string, "POWER-ON");
		else if ((data->rst_status & (1 << 1)) != 0)
		strcat(data->rst_status_string, "EXTERNAL");
		else if ((data->rst_status & (1 << 2)) != 0)
		strcat(data->rst_status_string, "BROWN-OUT");
		else if ((data->rst_status & (1 << 3)) != 0)
		strcat(data->rst_status_string, "WATCHDOG");
		else if ((data->rst_status & (1 << 4)) != 0)
		strcat(data->rst_status_string, "DEBUG");
		else if ((data->rst_status & (1 << 5)) != 0)
		strcat(data->rst_status_string, "SOFTWARE");
	}
	else strcpy(data->rst_status_string, "RST FLAG ERROR!");
}

// ********************** PRZYGOTOWANIE STRINGÓW DS3231 ********************************

void ds3231_prepare_time_string(DS3231_SENSOR_DATA_t *data)
{
	char buffer[4];
	if( data->datetime_value.hh < 10 )
	{
		strcpy(data->time_string, " ");
		strcat(data->time_string, itoa(data->datetime_value.hh, buffer, 10));
	}
	else
	{
		strcpy(data->time_string, itoa(data->datetime_value.hh, buffer, 10));
	}
	strcat(data->time_string, ":");
	if( data->datetime_value.mm < 10 )
	{
		strcat(data->time_string, "0");
		strcat(data->time_string, itoa(data->datetime_value.mm, buffer, 10));
	}
	else
	{
		strcat(data->time_string, itoa(data->datetime_value.mm, buffer, 10));
	}
	strcat(data->time_string, ":");
	if( data->datetime_value.ss < 10 )
	{
		strcat(data->time_string, "0");
		strcat(data->time_string, itoa(data->datetime_value.ss, buffer, 10));
	}
	else
	{
		strcat(data->time_string, itoa(data->datetime_value.ss, buffer, 10));
	}
}

void ds3231_prepare_date_string(DS3231_SENSOR_DATA_t *data)
{
	char buffer[4];

	if( data->datetime_value.day < 10 )
	{
		strcpy(data->date_string, itoa(data->datetime_value.day, buffer, 10));
	}
	else
	{
		strcpy(data->date_string, itoa(data->datetime_value.day, buffer, 10));
	}
	strcat(data->date_string, ".");

	if( data->datetime_value.month < 10 )
	{
		strcat(data->date_string, "0");
		strcat(data->date_string, itoa(data->datetime_value.month, buffer, 10));
	}
	else
	{
		strcat(data->date_string, itoa(data->datetime_value.month, buffer, 10));
	}
	strcat(data->date_string, ".20");

	if( data->datetime_value.year < 10 )
	{
		strcat(data->date_string, "0");
		strcat(data->date_string, itoa(data->datetime_value.year, buffer, 10));
	}
	else
	{
		strcat(data->date_string, itoa(data->datetime_value.year, buffer, 10));
	}
}

void ds3231_prepare_day_string(DS3231_SENSOR_DATA_t *data)
{
	strcpy(data->day_string, days[ data->datetime_value.dayofweek - 1 ]);
}

void ds3231_prepare_temp_string(DS3231_SENSOR_DATA_t *data)
{
	uint8_t fr[4] = {0,2,5,7};
	char buffer[4];

	strcpy(data->temperature_string, itoa(data->temperature_value.cel, buffer, 10));
	strcat(data->temperature_string, ".");
	if( data->temperature_value.cel >= 0 ) strcat(data->temperature_string, itoa(fr[ data->temperature_value.fract ], buffer, 10));
	else strcat(data->temperature_string, itoa(fr[3 - data->temperature_value.fract ], buffer, 10));
	strcat(data->temperature_string, "°C");
}


// ********************** PRZYGOTOWANIE STRINGÓW BMP180 ********************************

void bmp180_prepare_temp_string(BMP180_SENSOR_DATA_t *data)
{
	char buffer[4];
	
	strcpy(data->temperature_string, itoa((data->bmp180_value.bmp180_temp/10), buffer, 10));
	strcat(data->temperature_string, ".");
	strcat(data->temperature_string, itoa((data->bmp180_value.bmp180_temp%10), buffer, 10));
	strcat(data->temperature_string, "°C");
}

void bmp180_prepare_press_string(BMP180_SENSOR_DATA_t *data)
{
	char buffer[4];
	
	strcpy(data->pressure_string, itoa((data->bmp180_value.bmp180_press/100), buffer, 10));
	strcat(data->pressure_string, ".");
	if((data->bmp180_value.bmp180_press%100)<10) strcat(data->pressure_string, "0");
	strcat(data->pressure_string, itoa((data->bmp180_value.bmp180_press%100), buffer, 10));
	strcat(data->pressure_string, " hPa"); // hPa
	
//	zredukowanie wartoœci do zakresu int: min (0) - 970 hPa, max (255) - 1034 hPa; 1 bit = 0,25 hPa
//	data->pressure_int_value = ((data->pressure_value.bmp180_press - 97000)/25);
	
}
	

// ********************** PRZYGOTOWANIE STRINGÓW DHT22 ********************************
	
void dht22_prepare_temp_string(DHT22_SENSOR_DATA_t *data)
{
	char buffer[4];
	
	if(data->error)
	{
		strcpy(data->temperature_string, "- °C");
	}
	else
	{
		strcpy(data->temperature_string, itoa(data->data.temperature_integral, buffer, 10));
		strcat(data->temperature_string, ".");
		strcat(data->temperature_string, itoa(data->data.temperature_decimal, buffer, 10));
		strcat(data->temperature_string, "°C");
	}
	// zredukowanie wartoœci do zakresu int: min (0) - -26 st. C, max (255) - +38 st. C; 1 bit =  0,25 K
	//	data->temperature_int_value = (((( data->data.temperature_decimal + 26) * 10) + data->data.humidity_integral) * 10) / 25;
}

void dht22_prepare_humid_string(DHT22_SENSOR_DATA_t *data)
{
	char buffer[4];
	
	if(data->error)
	{
		strcpy(data->humidity_string, "- %");
	}
	else
	{
		strcpy(data->humidity_string, itoa(data->data.humidity_integral, buffer, 10));
		strcat(data->humidity_string, ".");
		strcat(data->humidity_string, itoa(data->data.humidity_decimal, buffer, 10));
		strcat(data->humidity_string, " %");
	}
	// zredukowanie wartoœci do zakresu int: min (0) - 970 hPa, max (255) - 1034 hPa; 1 bit = 0,25 hPa
	//	data->pressure_int_value = ((data->pressure_value.bmp180_press - 97000)/25);
}

void dht22_prepare_error_string(DHT22_SENSOR_DATA_t *data)
{
	strcpy(data->error_string, "DHT: ");
	
	switch(data->error)
	{
		case DHT_ERROR_NONE: strcat(data->error_string, "OK"); break;
		case DHT_BUS_HUNG: strcat(data->error_string, "BUSY"); break;
		case DHT_ERROR_NOT_PRESENT: strcat(data->error_string, "NOT PRESENT"); break;
		case DHT_ERROR_ACK_TOO_LONG: strcat(data->error_string, "ACK ERR"); break;
		case DHT_ERROR_SYNC_TIMEOUT: strcat(data->error_string, "SYNC ERR"); break;	// 25
		case DHT_ERROR_DATA_TIMEOUT: strcat(data->error_string, "DATA ERR"); break;	// 25
		case DHT_ERROR_CHECKSUM: strcat(data->error_string, "CHECKSUM ERR"); break;
		default: strcat(data->error_string, "EXT ERR"); break;
	}
	
}

// ********************** PRZYGOTOWANIE STRINGÓW PMS ********************************

void pms_prepare_pm_strings(PMS_SENSOR_DATA_t *data)
{
	char buffer[10];
	
	if(!data->pms_value.error)
	{
	//	data->pm1_percent = data->pms_value.pm1_mass / 1 * 100;				// nie znam normy
	//	strcpy(data->pm1_string, itoa(data->pm1_percent, buffer, 10));
	//	strcat(data->pm1_string, "% PM1");
		
		data->pm2_percent = data->pms_value.pm2_mass / 25 * 100;
		strcpy(data->pm2_string, itoa(data->pms_value.pm2_mass, buffer, 10));
		strcat(data->pm2_string, "% PM2.5");
		
		data->pm10_percent = data->pms_value.pm10_mass / 50 * 100;
		strcpy(data->pm10_string, itoa(data->pms_value.pm10_mass, buffer, 10));
		strcat(data->pm10_string, "% PM10");
	}
	else
	{
		strcpy(data->pm1_string, "- % PM1");
		strcpy(data->pm2_string, "- % PM2.5");
		strcpy(data->pm10_string, "- % PM10");
	}
	
	
	
}

// ********************** PRZYGOTOWANIE STRINGÓW PLUVIO ********************************

void pluviometer_prepare_strings(PLUVIOMETER_SENSOR_DATA_t *data)
{
	char buffer[11];

	if(data->mmH2O_value == 0xFF)
	{
		strcpy(data->mmH2O_string, "- mm H2O");
	}
	else
	{
		strcpy(data->mmH2O_string, itoa(data->mmH2O_value, buffer, 10));
		strcat(data->mmH2O_string, " mm H2O");
	}
}

// ********************** BACKUP ********************************

	


/*
ISR(TIMER0_COMPA_vect)
{
	if(tact_counter2 < 3000 )
	{
		tact_counter2++;
	}
	else
	{
		tact_20s_flag = 1;
		tact_counter2 = 0;
	}
	if(tact_counter1 < 5000 )
	{
		tact_counter1++;
	}
	else
	{
		tact_60s_flag = 1;
		tact_counter1 = 0;
	}
} */

/*
void common_check_stack_event(GPIO_flags_t* const task_flag)
{
	if(task_flag->common_check_stack_ev)
	{
		task_flag->common_check_stack_ev = 0;
		
		uint16_t stack_value = 0;
		char buff[6];
		
		stack_value = StackCount();
		uart_puts(itoa(stack_value, buff, 10));
	}
}

void common_read_sensors_event(GPIO_flags_t* const task_flag)
{
	if(task_flag->common_read_sens_ev)
	{
		#if DEBUGENABLED
			telnet_event_puts_P(telnet_event_content[0]);
		#endif
		
		common_read_internal_sensors();
		common_read_external_sensors();
		
		#if DEBUGENABLED
			telnet_event_puts_P(telnet_event_content[2]);
		#endif

		task_flag->common_read_sens_ev = 0;
	}
}

void common_prepare_sensors_strings_event(GPIO_flags_t* task_flag)
{
	if(task_flag->common_prep_sens_str_ev)
	{
		#if DEBUGENABLED
		telnet_event_puts_P(telnet_event_content[1]);
		#endif
		
		common_prepare_sensors_strings();
		
		#if DEBUGENABLED
		telnet_event_puts_P(telnet_event_content[2]);
		#endif
		
		task_flag->common_prep_sens_str_ev = 0;
	}
}

void common_prepare_datetime_strings_event(GPIO_flags_t* task_flag)
{
	if(task_flag->common_prep_datetime_str_ev)
	{
		
		common_prepare_datetime_strings();
		
		#if DEBUGENABLED
		telnet_event_puts_P(telnet_event_content[2]);
		#endif
		
		task_flag->common_prep_datetime_str_ev = 0;
	}
}

*/