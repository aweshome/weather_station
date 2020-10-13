/*
 * radio.h
 *
 * Created: 05.11.2015 12:51:02
 *  Author: Adam
 */ 


#ifndef RADIO_H_
#define RADIO_H_

#include <stdbool.h>
#include "nrf24l01.h"
#include "nrf24l01registers.h"
#include "../common.h"

enum radio_rx_buffer
{
	system_data_status,		// status watchdoga xmegi
	system_data_supply,		// napiêcie zasilania xmegi mierzone przez wewnêtrzny adc
	sensors_data_status,	// stany czujników (flagi)
	dht22_data_hum_h,		// 
	dht22_data_hum_l,
	dht22_data_temp_h,
	dht22_data_temp_l,
	pluviometer_data_mmH2O,
	pms_data_pm1,
	pms_data_pm2,
	pms_data_pm10
};

typedef struct RADIO_DATA
{
	uint8_t pipe_nr;
	uint8_t tx_buffer[NRF24L01_PAYLOAD];
	uint8_t rx_buffer[NRF24L01_PAYLOAD];
	bool status;							// true - dane aktualne, false - dane nieaktualne
} RADIO_DATA_t;

/*	Czujnik typu 1

	radio_data.tx_buffer[system_data_status] = system_data.status;
	radio_data.tx_buffer[system_data_supply] = system_data.supply_voltage;
	
	radio_data.tx_buffer[sensors_data_status] = dht22_data.error;
	radio_data.tx_buffer[dht22_data_hum_h] = dht22_data.humidity_hi;
	radio_data.tx_buffer[dht22_data_hum_l] = dht22_data.humidity_lo;
	radio_data.tx_buffer[dht22_data_temp_h] = dht22_data.temperature_hi;
	radio_data.tx_buffer[dht22_data_temp_l] = dht22_data.temperature_lo;
	
	radio_data.tx_buffer[pluviometer_data_mmH2O] = pluviometer_data.mmH2O_p_min;
	
	radio_data.tx_buffer[pms_data_pm1] = pms_pm_data.pm_1_0_concentr;
	radio_data.tx_buffer[pms_data_pm2] = pms_pm_data.pm_2_5_concentr;
	radio_data.tx_buffer[pms_data_pm10] = pms_pm_data.pm_10_concentr;
*/

extern RADIO_DATA_t radio_sensors[SENSORS_T1_QUANTITY];

//void radio_comm_event(GPIO_flags_t *task_flag);

uint8_t radio_call_action(void);
uint8_t radio_check_action(void);
bool radio_data_send(RADIO_DATA_t *data);


#endif /* RADIO_H_ */