/*
 * common.c
 *
 * Created: 2016-01-16 15:27:01
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <avr/sleep.h>
#include "common.h"
#include "nrf24l01.h"
#include "radio.h"
#include "usart.h"
#include "wdt_driver.h"
#include "fsm.h"
#include "pmsa003.h"
#include "power_cfg.h"

SYSTEM_DATA_t system_data = {.reset_status=0, .sensors_status=0, .supply_voltage=0, .sleep_status=false };

void common_get_status(void)
{
	system_data.reset_status = RST.STATUS;
	RST.STATUS = RST_PORF_bm | RST_EXTRF_bm | RST_BORF_bm | RST_WDRF_bm | RST_PDIRF_bm | RST_SRF_bm | RST_SDRF_bm;
}

void common_port_config(void)
{
	/* Ustawienie wszystkich portów jako wejœcia pull-down (redukcja zak³óceñ i poboru pr¹du) */
	
	PORTA.DIR = 0x00;
	PORTB.DIR = 0x00;
	PORTC.DIR = 0x00;
	PORTD.DIR = 0x00;
	PORTE.DIR = 0x00;
	PORTF.DIR = 0x00;
	
	PORTCFG.MPCMASK = 0xFF;					// ustawienie maski na wszystkie piny portu
	PORTA.PIN0CTRL = PORT_OPC_PULLDOWN_gc; // w³¹czenie pulldown dla wszystkich pinów portu	
	PORTCFG.MPCMASK = 0xFF;					// ustawienie maski na wszystkie piny portu
	PORTB.PIN0CTRL = PORT_OPC_PULLDOWN_gc; // w³¹czenie pulldown dla wszystkich pinów portu	
	PORTC.PIN0CTRL = PORT_OPC_PULLDOWN_gc; // w³¹czenie pulldown dla PC0
//	PORTCFG.MPCMASK = 0xFF;					// ustawienie maski na wszystkie piny portu
//	PORTD.PIN0CTRL = PORT_OPC_PULLDOWN_gc; // w³¹czenie pulldown dla wszystkich pinów portu
	PORTCFG.MPCMASK = 0xFF;					// ustawienie maski na wszystkie piny portu
	PORTE.PIN0CTRL = PORT_OPC_PULLDOWN_gc; // w³¹czenie pulldown dla wszystkich pinów portu
	PORTCFG.MPCMASK = 0xFF;					// ustawienie maski na wszystkie piny portu
	PORTF.PIN0CTRL = PORT_OPC_PULLDOWN_gc; // w³¹czenie pulldown dla wszystkich pinów portu
	
		
	/* Konfiguracja poszczególnych portów dla peryferiów */
	
	RADIO_PORT.OUTSET = RADIO_CE_PIN | RADIO_CSN_PIN | RADIO_MOSI_PIN | RADIO_SCK_PIN; 
	RADIO_PORT.DIRSET = RADIO_CE_PIN | RADIO_CSN_PIN | RADIO_MOSI_PIN | RADIO_SCK_PIN;
	RADIO_PORT.DIRCLR = RADIO_IRQ_PIN | RADIO_MISO_PIN;
	RADIO_PORT.RADIO_IRQ_PIN_CTRL = PORT_OPC_PULLUP_gc;
	RADIO_PORT.RADIO_MISO_PIN_CTRL = PORT_OPC_PULLUP_gc;
	
//	FLIP_SW_PORT.DIRCLR = FLIP_SW_PIN;
//	FLIP_SW_PORT.FLIP_SW_PIN_CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc;
//	FLIP_SW_PORT.INT1MASK = FLIP_SW_PIN;
//	FLIP_SW_PORT.INTCTRL = PORT_INT1LVL_LO_gc;
	
	STATUS_LED_PORT.STATUS_LED_PIN_CTRL &= ~PORT_OPC_PULLDOWN_gc;
	STATUS_LED_PORT.OUTSET = STATUS_LED_PIN;
	STATUS_LED_PORT.DIRSET = STATUS_LED_PIN;
	
	RADIO_PORT.DIRSET = SENSOR_PWR_PIN;
	RADIO_PORT.OUTCLR = SENSOR_PWR_PIN;
		
	SENSOR_DATA_PORT.SENSOR_DATA_PIN_CTRL = PORT_OPC_WIREDANDPULL_gc | PORT_ISC_BOTHEDGES_gc;	// Linia danych czujnika jako wire AND; przerwania od obu zboczy
	SENSOR_DATA_PORT.OUTSET = SENSOR_DATA_PIN;													// Linia danych - stan wysoki
	SENSOR_DATA_PORT.DIRSET = SENSOR_DATA_PIN;													// Linia danych jako wyjœcie
	
//	LION_DATA_PORT.LION_DATA_PIN_CTRL &= ~PORT_OPC_PULLDOWN_gc;
//	LION_DATA_PORT.DIRCLR = LION_DATA_PIN;
	
	PLUVIO_PULSE_PORT.PLUVIO_PULSE_PIN_CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_FALLING_gc;
	PLUVIO_PULSE_PORT.INT0MASK = PLUVIO_PULSE_PIN;
	PLUVIO_PULSE_PORT.INTCTRL = PORT_INT0LVL_LO_gc;
	PLUVIO_PULSE_PORT.DIRCLR = PLUVIO_PULSE_PIN;
}

void common_pmic_config(void)
{
	PMIC.CTRL |= PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;						// w³¹czenie przerwañ o priorytecie LO MED HI
	sei();
}

void common_disable_jtag(void)
{
	CCP	= CCP_IOREG_gc;				// wy³¹czenie JTAG
	MCU.MCUCR = MCU_JTAGD_bm;
}

void common_delay_ms(unsigned int ms_period)
{
	for(unsigned int i=0; i<ms_period; i++)
	{
		_delay_ms(1);
		WDT_Reset();
	}
}

void common_led_blink(uint8_t period_10ms, uint8_t quantity)
{
	for(uint8_t i=0; i<quantity; i++)
	{
		STATUS_LED_PORT.OUTCLR = STATUS_LED_PIN;
		for(uint8_t i=0; i<period_10ms; i++)
		{
			_delay_ms(5);
			WDT_Reset();
		}
		STATUS_LED_PORT.OUTSET = STATUS_LED_PIN;
		for(uint8_t i=0; i<period_10ms; i++)
		{ 
			_delay_ms(5);
			WDT_Reset();
		}
	}
}

uint8_t common_condition_1_action(void)
{
	uint8_t status;
	
	fsm_params.counter1++;
	if (fsm_params.counter1 >= 30)
		status = 1;
	else
		status = 0;
	
	return status;
}

uint8_t common_condition_2_action(void)
{
	uint8_t status;
	
	fsm_params.counter1 = 0;
	
	if (fsm_params.flag1 == 1)
	{
		fsm_params.flag1 = 0;
		status = 1;	
	}
	else
	{
		common_led_blink(5, 20);	
		status = 0;
	}
	
	return status;
}

uint8_t common_condition_3_action(void)
{
	uint8_t status;
	
	if (fsm_params.counter1 == 1)
	{
		PMS_sleep_mode(false);			// Budzenie PMS (uruchamianie wentylatora)
		status = 1;
	}
	else
		status = 0;
	
	return status;
}

uint8_t common_condition_4_action(void)
{
	uint8_t status;
	
	if (fsm_params.counter1 == 2)
		status = 1;
	else
		status = 0;
	
	return status;
}

uint8_t common_condition_5_action(void)
{
	uint8_t status;
	
	if (fsm_params.flag1 == 0)
		status = 1;
	else
		status = 0;
	
	return status;
}
