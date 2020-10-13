/*
 * common.h
 *
 * Created: 2016-01-16 15:27:13
 *  Author: Adam
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#include <stdbool.h>

#define SENSOR_DATA_PORT		PORTF
#define STATUS_LED_PORT			PORTE
#define FLIP_SW_PORT			PORTE
#define USB_PORT				PORTD
#define RADIO_PORT				PORTC
#define EXTRA_PORT				PORTB
#define PLUVIO_PULSE_PORT		PORTB

#define SENSOR_DATA_PIN			PIN2_bm
#define	SENSOR_PWR_PIN			PIN1_bm		// Dzia³a na porcie RADIO_PORT !!!
#define STATUS_LED_PIN			PIN2_bm
#define FLIP_SW_PIN				PIN5_bm
#define USB_DMINUS_PIN			PIN6_bm
#define USB_DPLUS_PIN			PIN7_bm
#define RADIO_IRQ_PIN			PIN2_bm
#define RADIO_CE_PIN			PIN3_bm
#define RADIO_CSN_PIN			PIN4_bm
#define RADIO_MOSI_PIN			PIN5_bm
#define RADIO_MISO_PIN			PIN6_bm
#define RADIO_SCK_PIN			PIN7_bm
#define PLUVIO_PULSE_PIN		PIN2_bm

#define SENSOR_DATA_PIN_CTRL	PIN2CTRL
#define STATUS_LED_PIN_CTRL		PIN2CTRL
#define FLIP_SW_PIN_CTRL		PIN5CTRL
#define RADIO_IRQ_PIN_CTRL		PIN2CTRL
#define RADIO_MISO_PIN_CTRL		PIN6CTRL
#define PLUVIO_PULSE_PIN_CTRL	PIN2CTRL

typedef struct  
{
	uint8_t reset_status;
	uint8_t sensors_status;
	uint8_t supply_voltage;
	bool sleep_status;			// true - sleep, false - active
} SYSTEM_DATA_t;

extern SYSTEM_DATA_t system_data;

void common_get_status(void);
void common_port_config(void);
void common_pmic_config(void);
void common_disable_jtag(void);
void common_delay_ms(unsigned int ms_period);
void common_led_blink(uint8_t period_10ms, uint8_t quantity);

uint8_t common_condition_1_action(void);
uint8_t common_condition_2_action(void);
uint8_t common_condition_3_action(void);
uint8_t common_condition_4_action(void);
uint8_t common_condition_5_action(void);

#endif /* COMMON_H_ */

/*

#define SENSOR_DATA_PORT	PORTF
#define STATUS_LED_PORT		PORTE
#define FLIP_SW_PORT		PORTE
#define USB_PORT			PORTD
#define RADIO_PORT			PORTC
#define EXTRA_PORT			PORTB

#define SENSOR_DATA_PIN		PIN2_bm
#define STATUS_LED_PIN		PIN2_bm
#define FLIP_SW_PIN			PIN5_bm
#define USB_DMINUS_PIN		PIN6_bm
#define USB_DPLUS_PIN		PIN7_bm
#define	RADIO_PWR_PIN		PIN1_bm
#define RADIO_IRQ_PIN		PIN2_bm
#define RADIO_CE_PIN		PIN3_bm
#define RADIO_CSN_PIN		PIN4_bm
#define RADIO_MOSI_PIN		PIN5_bm
#define RADIO_MISO_PIN		PIN6_bm
#define RADIO_SCK_PIN		PIN7_bm

*/