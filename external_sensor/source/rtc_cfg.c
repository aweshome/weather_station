/*
 * rtc_cfg.c
 *
 * Created: 15.11.2016 21:46:51
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "rtc_cfg.h"
#include "fsm.h"
#include "power_cfg.h"
#include "common.h"


void rtc_init(void)
{
	CLK.RTCCTRL |= CLK_RTCSRC_ULP_gc | CLK_RTCEN_bm;		// ustawienie Ÿród³a zegara RTC na ULP i uruchomienie
	RTC.PER = 30000;										// ustawienie okresu licznika (ok. 30 s)
	RTC.CNT = 25000;
	RTC.INTCTRL |= RTC_OVFINTLVL_HI_gc;						// w³aczenie priorytetu hi dla przerwania od przepe³nienia
	RTC.CTRL = RTC_PRESCALER_DIV1_gc;						// ustawienie dzielnika na 1
}

ISR(RTC_OVF_vect)
{
	power_sleep_disable();
	fsm_event_flag_set(&fsm_event_flags, common_condition_1_event);	// Ustaw flagê dla zdarzenia
}