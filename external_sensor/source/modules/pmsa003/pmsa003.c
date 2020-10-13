/*
 * pmsa003.c
 *
 * Created: 11.01.2018 22:42:55
 *  Author: adamw
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include "pmsa003.h"
#include "usart.h"
#include "fsm.h"
#include "common.h"

uint8_t pms_request_frame[PMS_REQUEST_BYTES_QUANTITY];
uint8_t pms_answer_frame[PMS_ANSWER_BYTES_QUANTITY];
volatile uint8_t pms_request_element_cnt = 0;
volatile uint8_t pms_answer_element_cnt = 0;

PMS_PM_DATA_t pms_pm_data;

void PMS_USART_init(void)	// 9600 8N1
{
	PMS_PORT.OUTSET = PMS_TX_PIN;
	PMS_PORT.DIRSET = PMS_TX_PIN;
	PMS_PORT.DIRCLR = PMS_RX_PIN;
	
	USARTD1.CTRLC |= USART_CHSIZE_8BIT_gc;

	usart_set_baudrate(&USARTD1, 9600, F_CPU);
	
	USARTD1.CTRLB |= USART_TXEN_bm;					// W³¹czenie nadajnika
}

void PMS_set_passive_mode(void)
{
	PMS_send_request(pms_request_frame, PMS_CMD_CHANGE_MODE, PMS_CMD_VALUE_PASSIVE);
}

void PMS_sleep_mode(bool state)
{
	if(state)
		PMS_send_request(pms_request_frame, PMS_CMD_SLEEP_SET, PMS_CMD_VALUE_SLEEP);
	else
		PMS_send_request(pms_request_frame, PMS_CMD_SLEEP_SET, PMS_CMD_VALUE_WAKEUP);
}

void PMS_send_request(uint8_t * data_frame, uint8_t command, uint8_t data)
{
	uint16_t crc = 0;
	
	data_frame[START_BYTE_1] = PMS_START_BYTE_1;
	data_frame[START_BYTE_2] = PMS_START_BYTE_2;
	data_frame[COMMAND] = command;
	data_frame[DATA_H] = 0;
	data_frame[DATA_L] = data;
	
	for(uint8_t i = 0; i < 5; ++i) crc += data_frame[i];
	
	data_frame[VERIFY_BYTE_H] = (crc >> 8);
	data_frame[VERIFY_BYTE_L] = (crc & 0xFF);
	
	USART_send_block(&USARTD1, data_frame, 7);
	_delay_ms(100);
//	for(uint8_t i = 0; i < 7; ++i) USART_putchar(&USARTD0, data_frame[i]);
}

void pms_prepare_data(void)
{
	uint16_t checksum = 0;
	uint8_t checksum_lo = 0;
	uint8_t checksum_hi = 0;
	
	PMS_sleep_mode(true);			// Usypianie PMS bo ju¿ niepotrzebny
	
//	pms_answer_element_cnt = 0;
	
	for(uint8_t i=0; i<(PMS_ANSWER_BYTES_QUANTITY-2); ++i) checksum += pms_answer_frame[i];
	
	checksum_lo = (uint8_t) (checksum & 0xFF);
	checksum_hi = (uint8_t) (checksum >> 8);
	
	if((checksum_hi == pms_answer_frame[CRC_H]) && (checksum_lo == pms_answer_frame[CRC_L]))
	{
		pms_pm_data.error = DATA_CORRECT;
		
		// Sprawdzenie czy starszy bajt > 0 czyli stezenie pylow > 255 mg/m3 - jesli tak, to nie ma potrzeby wysylac tak duzej wartosci, a jedynie maksymalna 255
		
		if(pms_answer_frame[PM_1_0_CONCENTR_ATMOSPERIC_H] > 0) pms_pm_data.pm_1_0_concentr_lo = 0xFF;
		else pms_pm_data.pm_1_0_concentr_lo = pms_answer_frame[PM_1_0_CONCENTR_ATMOSPERIC_L];
		if(pms_answer_frame[PM_2_5_CONCENTR_ATMOSPERIC_H] > 0) pms_pm_data.pm_2_5_concentr_lo = 0xFF;
		else pms_pm_data.pm_2_5_concentr_lo = pms_answer_frame[PM_2_5_CONCENTR_ATMOSPERIC_L];
		if(pms_answer_frame[PM_10_CONCENTR_ATMOSPERIC_H] > 0) pms_pm_data.pm_10_concentr_lo = 0xFF;
		else pms_pm_data.pm_10_concentr_lo = pms_answer_frame[PM_10_CONCENTR_ATMOSPERIC_L];
	}
	else
	{
		pms_pm_data.error = WRONG_CRC;
		
		pms_pm_data.pm_1_0_concentr_lo = 0;
		pms_pm_data.pm_2_5_concentr_lo = 0;
		pms_pm_data.pm_10_concentr_lo = 0;
	}
	
	
	// Zerowanie zmiennych
	
//	for(uint8_t i=0; i<32; ++i) pms_response_frame[i] = 0;
}

uint8_t PMS_read_action(void)
{
//	USART_flush_rx_buff(&USARTD0);
	pms_answer_element_cnt = 0;
	USARTD1.CTRLA |= USART_RXCINTLVL_LO_gc;						// W³¹czenie przerwania niskiego poziomu od odebrania danych
	USARTD1.CTRLB |= USART_RXEN_bm;								// W³¹czenie odbiornika
	PMS_send_request(pms_request_frame, PMS_CMD_PASSIVE_READ, 0);
		
	return 1;
}

uint8_t PMS_prepare_data_action(void)
{
	pms_prepare_data();

	return 1;
}

ISR(USARTD1_RXC_vect)
{

	pms_answer_frame[pms_answer_element_cnt] = USARTD1.DATA;
	pms_answer_element_cnt++;
	if(pms_answer_element_cnt > PMS_ANSWER_BYTES_QUANTITY)
	{
		USARTD1.CTRLB &= ~USART_RXEN_bm;								// Wy³¹czenie odbiornika
		USARTD1.CTRLA &= ~USART_RXCINTLVL_gm;							// Wy³¹czenie przerwania niskiego poziomu od odebrania danych
		fsm_event_flag_set(&fsm_event_flags, pms_prepare_data_event);	// Ustaw flagê dla zdarzenia
	}		
}
