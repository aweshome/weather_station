/*
 * watchdog.h
 *
 * Created: 12.09.2015 15:33:17
 *  Author: Adam
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_

extern char MCUSR_string[20];

void watchdog_get_mcusr(void);// __attribute__ ((naked)) __attribute__ ((section (".init1")));
void watchdog_MCUSR_to_string(void);



#endif /* WATCHDOG_H_ */