/*
 * radio.c
 *
 * Created: 05.11.2015 12:50:52
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include "../common.h"
#include "../Interfaces/uart.h"
#include "radio.h"
#include "../Telnet/telnet_menu.h"


RADIO_DATA_t radio_sensors[SENSORS_T1_QUANTITY];

/*
void radio_comm_event(GPIO_flags_t *task_flag)
{	
	if(task_flag->radio_comm_ev_1)	// jeœli ustawiona flaga zdarzenia
	{
		task_flag->radio_comm_ev_1 = 0;
				
		telnet_event_puts_P(telnet_event_content[7]);
		
		for(uint8_t i=0; i<SENSORS_QUANTITY; i++)	// wysy³a zapytanie do ka¿dego czujnika
		{
			radio_data_send( &radio_sensors[i] );
			if(radio_sensors[i].status) telnet_event_puts_P(telnet_event_content[2]);
			else telnet_event_puts_P(telnet_event_content[8]);
		}
	}
	else if(task_flag->radio_comm_ev_2)
	{
		task_flag->radio_comm_ev_2 = 0;
		
		char buff[4];
		uint8_t pipe=0;
		
		while(nrf24l01_readready(&pipe))	// sprawdza czy s¹ dane i zapisuje numer rurki
		{
			nrf24l01_read(radio_sensors[pipe].rx_buffer);
			telnet_event_puts(itoa( radio_sensors[pipe].rx_buffer[0], buff, 10));
		}
	}
}
*/
uint8_t radio_call_action(void)
{
	uint8_t result = 1;
	
	telnet_event_puts_P(telnet_event_content[7]);
	
	nrf24l01_clear_flush();
	
	for(uint8_t i=0; i<SENSORS_T1_QUANTITY; i++)	// wysy³a zapytanie do ka¿dego czujnika
	{
		radio_data_send( &radio_sensors[i] );
		if(radio_sensors[i].status)
		{
//			result = 1;
			telnet_event_puts_P(telnet_event_content[2]);
		}
		
		else
		{
//			result = 0;
			telnet_event_puts_P(telnet_event_content[8]);
		}
	}
	
	return result;
}

uint8_t radio_check_action(void)
{
	
	uint8_t pipe;
	uint8_t state = 0;
	
	while(nrf24l01_readready(&pipe))	// sprawdza czy s¹ dane i zapisuje numer rurki
	{
		for(uint8_t i=0; i<NRF24L01_PAYLOAD; i++)
			radio_sensors[pipe].rx_buffer[i]=0;
		nrf24l01_read(radio_sensors[pipe].rx_buffer);
		radio_sensors[pipe].status = true;
		radio_sensors[pipe].pipe_nr = pipe;
		state = 1;
	}
	if(state)
	{	
		nrf24l01_clear_flush();
		#if DEBUGENABLED
		telnet_event_puts_P(telnet_event_content[9]);
		#endif
	}
	// zwraca 1 jeœli s¹ dane i 0 jeœli nie ma
	return state;
}

bool radio_data_send(RADIO_DATA_t *data)
{
	bool result = false;
	
	uint8_t addrtx0[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP0;
	uint8_t addrtx1[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP1;
	uint8_t addrtx2[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP2;
	uint8_t addrtx3[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP3;
	uint8_t addrtx4[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP4;
	uint8_t addrtx5[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP5;
	
	switch(data->pipe_nr)
	{
		case 0: nrf24l01_settxaddr(addrtx0); break;
		case 1: nrf24l01_settxaddr(addrtx1); break;
		case 2: nrf24l01_settxaddr(addrtx2); break;
		case 3: nrf24l01_settxaddr(addrtx3); break;
		case 4: nrf24l01_settxaddr(addrtx4); break;
		case 5: nrf24l01_settxaddr(addrtx5); break;
	}
	
	result = nrf24l01_write(data->tx_buffer);
	
	return result;
}
/*
uint8_t radio_data_read(SENSOR_DATA_t *data)
{	
	uint8_t result=0;
	if(nrf24l01_readready(data->tx_pipe))
	{
		nrf24l01_read(data->rx_buffer);
		result=1;
	}
	return result;
}
*/
			





