/*
 * adc.c
 *
 * Created: 11.12.2016 14:21:38
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stddef.h>
#include "common.h"
#include "adc.h"
#include "fsm.h"


int8_t adc_read_calib_byte(uint8_t index)
{
	uint8_t result;
	
	/* Load the NVM Command register to read the calibration row. */
	NVM.CMD = NVM_CMD_READ_CALIB_ROW_gc;
	result = pgm_read_byte(index);
	
	/* Clean up NVM Command register. */
	NVM.CMD = NVM_CMD_NO_OPERATION_gc;
	
	return(result);
}

void adc_config(void)
{
	/* Pobranie fabrycznych danych kalibracyjnych zapisanych w EEPROM */
	ADCA.CALL = adc_read_calib_byte(offsetof(NVM_PROD_SIGNATURES_t, ADCACAL0));
	ADCA.CALH = adc_read_calib_byte(offsetof(NVM_PROD_SIGNATURES_t, ADCACAL1));
	
	ADCA.CTRLB |= ADC_CONMODE_bm | ADC_RESOLUTION_12BIT_gc;												// Tryb signed, 12-bitowy
	ADCA.REFCTRL |= ADC_REFSEL_INT1V_gc | ADC_BANDGAP_bm;												// Napiêcie odniesienia 1V
	ADCA.PRESCALER |= ADC_PRESCALER_DIV32_gc;															// Próbkowanie 62,5 ksps
	ADCA.CH0.CTRL |= ADC_CH_GAIN_1X_gc | ADC_CH_INPUTMODE_INTERNAL_gc;									// Wzmocnienie 1x
	ADCA.CH0.MUXCTRL |= ADC_CH_MUXINT_SCALEDVCC_gc;														// Pomiar Vcc/10
	ADCA.CTRLA |= ADC_ENABLE_bm;																		// Aktywacja ADC
	
	ADCA.CH0.INTCTRL |= ADC_CH_INTMODE_COMPLETE_gc | ADC_CH_INTLVL_LO_gc;								// Uruchomienie przerwania LO od ukoñczenia konwersji
}

void adc_init(void)
{
	ADCA.CH0.CTRL |= ADC_CH_START_bm;
/*	
	uint16_t adc_value=0;
	int8_t i;
	
	for(i=0; i<20; i++)
	{
		ADCA.CH0.CTRL |= ADC_CH_START_bm;
		while(!(ADCA.CH0.INTFLAGS & ADC_CH_CHIF_bm));
		ADCA.CH0.INTFLAGS = ADC_CH_CHIF_bm;
		adc_value += ADCA.CH0RESL;
	}
	
	system_data.supply_voltage = (uint8_t) (adc_value / i);
	
	fsm_event_flag_set(&fsm_event_flags, radio_prepare_data_event);	// Ustaw flagê dla zdarzenia
*/
}

uint8_t adc_init_action(void)
{
	adc_init();
	
	return 1;
}

ISR(ADCA_CH0_vect)
{
	uint16_t adc_data;
	uint16_t supply;
	adc_data = ADCA.CH0RES;
	
	
//	Przeliczenie wartoœci odczytanej z przetwornika na wartoœæ napiêcia:
//	napiêcie = ((( przemno¿enie przez 10 bo pomiar Vcc/10 * napiêcie odniesienia * wynik ADC * przemno¿enie przez 100 dla uzyskania liczby ca³kowitej) / 11 bitów ) - odjêcie 100 czyli pomniejszenie wyniku o 1V ¿eby zmieœciæ siê w 8 bit
//	przyk³ad dla nap. 3,18 V:
//	supply = (((10 * 1 * 652 * 100) / 2048) - 100) = 652000 / 2048 - 100 = 318 - 100 = 218
//	¿eby odtworzyæ wartoœæ trzeba:
//	U = (supply + 100) / 100 = (218 + 100) / 100 = 318 /100 = 3,18 V
	
	supply = (((10UL * 1UL * adc_data * 100UL) / 2048UL) - 100UL);

	system_data.supply_voltage = (uint8_t) supply;
	
	fsm_event_flag_set(&fsm_event_flags, radio_prepare_data_event);	// Ustaw flagê dla zdarzenia
}

