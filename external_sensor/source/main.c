/*
 * Terminal-external_sensor.c
 *
 * Created: 2015-12-30 22:24:29
 * Author : Adam
 */ 

#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <util/atomic.h>
#include "fsm.h"
#include "power_cfg.h"
#include "spi_driver.h"
#include "wdt_driver.h"
#include "common.h"
#include "rtc_cfg.h"
#include "adc.h"
#include "nrf24l01.h"
#include "radio.h"
#include "DHT22.h"
#include "pmsa003.h"

int main(void)
{
	WDT_EnableAndSetTimeout(WDT_PER_4KCLK_gc);	// 4 s
	
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{
		CCP	= CCP_IOREG_gc;				// wy³¹czenie JTAG
		MCU.MCUCR = MCU_JTAGD_bm;
	}
	
	common_get_status();
	common_port_config();
	power_peripherials_disable();
	spi_init();
	adc_config();
	DHT22_config();
	PMS_USART_init();
	PMS_sleep_mode(false);				// wybudzenie czujnika w celu sprawdzenia dzia³ania po resecie (przy za³¹czeniu zasilania domyœlnie uruchomiony)
	common_delay_ms(2000);				// oczekiwanie na ustabilizowanie zasilania PMSA
	PMS_set_passive_mode();
	common_delay_ms(15);
	PMS_sleep_mode(true);
	common_pmic_config();	
	nrf24l01_init();
	
	if(!radio_power_check())
	{
		common_led_blink(20, 2);
		rtc_init();
	}
	else
	common_led_blink(10, 6);
	
	nrf24l01_powerdown();
	WDT_Reset();
	power_sleep_mode_cfg();
	power_sleep_enable();

	
	for(;;)
	{
		WDT_Reset();
		
		fsm_transition(&fsm_event_flags, power_sleep_event, power_sleep_action, null_event, null_event);
		fsm_transition(&fsm_event_flags, radio_respond_event, radio_respond_action, power_sleep_event, power_sleep_event);
		fsm_transition(&fsm_event_flags, radio_prepare_data_event, radio_prepare_data_action, radio_respond_event, null_event);							// Uruchamiane przez przerwanie od ADC

		fsm_transition(&fsm_event_flags, adc_init_event, adc_init_action, null_event, null_event);														// Uruchamia ADC
		fsm_transition(&fsm_event_flags, pms_prepare_data_event, PMS_prepare_data_action, adc_init_event, null_event);									// Uruchamiane przez przerwanie od DMA
		fsm_transition(&fsm_event_flags, pms_read_event, PMS_read_action, null_event, null_event);														// Uruchamia DMA
		fsm_transition(&fsm_event_flags, dht22_checksum_calculate_event, DHT22_checksum_calculate_action, pms_read_event, null_event);
/*
		fsm_transition(&fsm_event_flags, adc_init_event, adc_init_action, null_event, null_event);														// Uruchamia ADC														// Uruchamia DMA
		fsm_transition(&fsm_event_flags, dht22_checksum_calculate_event, DHT22_checksum_calculate_action, adc_init_event, null_event);
*/
		fsm_transition(&fsm_event_flags, dht22_init_event, DHT22_init_action, null_event, null_event);
		fsm_transition(&fsm_event_flags, common_condition_5_event, common_condition_5_action, radio_respond_event, power_sleep_event);
		fsm_transition(&fsm_event_flags, common_condition_4_event, common_condition_4_action, dht22_init_event, common_condition_5_event);
		fsm_transition(&fsm_event_flags, common_condition_3_event, common_condition_3_action, power_sleep_event, common_condition_4_event);
		fsm_transition(&fsm_event_flags, common_condition_2_event, common_condition_2_action, power_sleep_event, power_sleep_event);
		fsm_transition(&fsm_event_flags, common_condition_1_event, common_condition_1_action, common_condition_2_event, common_condition_3_event);		// Ust. flagi - RTC (60 s)
	}
}


