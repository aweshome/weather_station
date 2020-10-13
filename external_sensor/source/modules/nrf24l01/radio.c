/*
 * radio.c
 *
 * Created: 05.11.2015 12:50:52
 *  Author: Adam
 */ 

#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#include "nrf24l01registers.h"
#include "nrf24l01.h"
#include "common.h"
#include "radio.h"
#include "DHT22.h"
#include "anemometer.h"
#include "pluviometer.h"
#include "pmsa003.h"
#include "fsm.h"

RADIO_DATA_t radio_data;

uint8_t sendpipe = 0;
uint8_t addrtx0[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP0;
uint8_t addrtx1[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP1;
uint8_t addrtx2[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP2;
uint8_t addrtx3[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP3;
uint8_t addrtx4[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP4;
uint8_t addrtx5[NRF24L01_ADDRSIZE] = NRF24L01_ADDRP5;


uint8_t radio_prepare_data_action(void)
{
	radio_data.tx_buffer[system_reset_status] = system_data.reset_status;
	radio_data.tx_buffer[system_supply_value] = system_data.supply_voltage;
	radio_data.tx_buffer[sensors_data_status] = (dht22_data.error | pms_pm_data.error);
	
	radio_data.tx_buffer[dht22_data_hum_h] = dht22_data.humidity_hi;
	radio_data.tx_buffer[dht22_data_hum_l] = dht22_data.humidity_lo;
	radio_data.tx_buffer[dht22_data_temp_h] = dht22_data.temperature_hi;
	radio_data.tx_buffer[dht22_data_temp_l] = dht22_data.temperature_lo;	
	radio_data.tx_buffer[pluviometer_data_mmH2O] = pluviometer_data.mmH2O_per_15min;
	radio_data.tx_buffer[pms_data_pm1] = pms_pm_data.pm_1_0_concentr_lo;
	radio_data.tx_buffer[pms_data_pm2] = pms_pm_data.pm_2_5_concentr_lo;
	radio_data.tx_buffer[pms_data_pm10] = pms_pm_data.pm_10_concentr_lo;

	pluviometer_data.mmH2O_per_15min = 0;

	return 1;
}


uint8_t radio_listen_action(void)
{
	uint8_t pipe = 0;
	
	if(nrf24l01_readready(&pipe))	// jeœli s¹ dane do odebrania
	{
		nrf24l01_settxaddr(addrtx0);		//set tx address for pipe 0
		radio_data_read(&radio_data);	// pobiera dane z buforu
	}
	_delay_ms(10);
	return 1;
}

uint8_t radio_respond_action(void)
{
	uint8_t status;
	
	nrf24l01_settxaddr(addrtx0);		//set tx address for pipe 0
	radio_data_send(&radio_data);
	
	if(radio_data.status)
	{
		fsm_params.flag1 = 1;
		common_led_blink(5, 1);
		status = 1;
	}
	else
	{
		common_led_blink(5, 5);
		status = 0;
	}
	

	return status;
}

void radio_data_send(RADIO_DATA_t *data)
{
	data->status = nrf24l01_write(data->tx_buffer);
}

void radio_data_read(RADIO_DATA_t *data)
{	
	nrf24l01_read(data->rx_buffer);
}

void radio_csn_enable(_Bool cs)
{
	if(cs) RADIO_PORT.OUTCLR = RADIO_CSN_PIN;
	else RADIO_PORT.OUTSET = RADIO_CSN_PIN;
}

_Bool radio_power_check(void)
{
	_Bool status = false;
	if((nrf24l01_readregister(NRF24L01_REG_CONFIG) & (1<<NRF24L01_REG_PWR_UP))) status = true;
	return status;
}			





