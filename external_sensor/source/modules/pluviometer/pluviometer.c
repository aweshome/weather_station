/*
 * pluviometer.c
 *
 * Created: 19.03.2018 23:16:04
 *  Author: adamw
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "pluviometer.h"
#include "common.h"

volatile PLUVIOMETER_DATA_t pluviometer_data;

void pluviometer_init(void)
{
	pluviometer_data.mmH2O_per_15min = 0;
}

ISR(PORTB_INT0_vect)
{
	pluviometer_data.mmH2O_per_15min++;
	if(system_data.sleep_status) sleep_mode();	
}