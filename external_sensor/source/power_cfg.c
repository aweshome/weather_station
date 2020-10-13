/*
 * power_cfg.c
 *
 * Created: 04.11.2016 20:43:34
 *  Author: Adam
 */ 

#include <avr/power.h>
#include <avr/sleep.h>
#include "power_cfg.h"
#include "wdt_driver.h"
#include "common.h"

void power_peripherials_disable(void)
{
	power_aes_disable();
//	power_rtc_disable();
//	power_evsys_disable();
//	power_dma_disable();
	power_daca_disable();
	power_dacb_disable();
//	power_adca_disable();
	power_adcb_disable();
	power_aca_disable();
	power_twic_disable();
	power_twid_disable();
	power_twie_disable();
	power_twif_disable();
	power_usartc0_disable();
	power_usartd0_disable();
	power_usarte0_disable();
	power_usartf0_disable();
	power_usartc1_disable();
//	power_usartd1_disable();
	power_usarte1_disable();
	power_usartf1_disable();
//	power_spic_disable();
	power_spid_disable();
	power_spie_disable();
	power_spif_disable();
	power_hiresc_disable();
	power_hiresd_disable();
	power_hirese_disable();
	power_hiresf_disable();
	power_tc0c_disable();
//	power_tc0d_disable();
	power_tc0e_disable();
//	power_tc0f_disable();
	power_tc1c_disable();
	power_tc1d_disable();
	power_tc1e_disable();
	power_tc1f_disable();
}

void power_sleep_mode_cfg(void)
{
	set_sleep_mode(SLEEP_MODE_PWR_SAVE);
}

void power_sleep_enable(void)
{
	system_data.sleep_status = true;
	WDT_Disable();
	WDT_Reset();
	sleep_mode();
}

void power_sleep_disable(void)
{
	system_data.sleep_status = false;
	do {} while (RTC.STATUS & RTC_SYNCBUSY_bm);			// zaczekaj na synchronizacjê RTC
	WDT_Enable();
}

uint8_t power_sleep_action(void)
{
	power_sleep_enable();
	
	return 1;
}