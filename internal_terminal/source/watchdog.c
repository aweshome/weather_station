/*
 * watchdog.c
 *
 * Created: 12.09.2015 15:29:50
 *  Author: Adam
 */ 


#include <avr/io.h>
#include <avr/wdt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "watchdog.h"

uint8_t mcusr_mirror;// __attribute__ ((section (".init3")));
char MCUSR_string[20];

void watchdog_get_mcusr(void)
{
	mcusr_mirror = MCUSR;
	MCUSR = 0;
	wdt_disable();
}

void watchdog_MCUSR_to_string(void)
{	
	if (mcusr_mirror != 0)
	{
		strcpy(MCUSR_string, "RST FLAG: ");
		if ((mcusr_mirror & (1 << PORF)) != 0)
		strcat(MCUSR_string, "POWER-ON");
		else if ((mcusr_mirror & (1 << EXTRF)) != 0)
		strcat(MCUSR_string, "EXTERNAL");
		else if ((mcusr_mirror & (1 << BORF)) != 0)
		strcat(MCUSR_string, "BROWN-OUT");
		else if ((mcusr_mirror & (1 << WDRF)) != 0)
		strcat(MCUSR_string, "WATCHDOG");
		#ifdef JTRF
		else if ((mcusr_mirror & (1 << JTRF)) != 0)
		strcat(MCUSR_string, "JTAG");
		#endif
	}
	else strcpy(MCUSR_string, "RST FLAG ERROR!");
}