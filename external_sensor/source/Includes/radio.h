/*
 * radio.h
 *
 * Created: 05.11.2015 12:51:02
 *  Author: Adam
 */ 


#ifndef RADIO_H_
#define RADIO_H_

/* ***************************************** */
/* Definicje dodatkowych pinów dla nRF24L01: */

#define IRQPORT PORTC
#define IRQPIN_bm PIN2_bm
#define CEPORT PORTC
#define CEPIN_bm PIN3_bm

enum radio_tx_buffer
{
	system_reset_status = 0,
	system_supply_value = 1,
	sensors_data_status = 2,
	dht22_data_hum_h = 3,
	dht22_data_hum_l = 4,
	dht22_data_temp_h = 5,
	dht22_data_temp_l = 6,
	pluviometer_data_mmH2O = 7,
	pms_data_pm1 = 8,
	pms_data_pm2 = 9,
	pms_data_pm10 = 10
};

typedef struct RADIO_DATA
{
	const uint8_t number;
	const uint8_t tx_pipe;
	uint8_t tx_buffer[NRF24L01_PAYLOAD];
	uint8_t rx_buffer[NRF24L01_PAYLOAD];
	uint8_t status;
} RADIO_DATA_t;

extern RADIO_DATA_t radio_data;

//void radio_event(GPIO_FLAGS_t *event_flag);
uint8_t radio_prepare_data_action(void);
uint8_t radio_listen_action(void);
uint8_t radio_respond_action(void);
void radio_data_send(RADIO_DATA_t *data);
void radio_data_read(RADIO_DATA_t *data);
void radio_csn_enable(_Bool cs);
_Bool radio_power_check(void);


#endif /* RADIO_H_ */