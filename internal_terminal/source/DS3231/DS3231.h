/*
 * DS3231.h
 *
 *  Created on: 1 mar 2015
 *      Author: Adam
 */

#ifndef DS3231_DS3231_H_
#define DS3231_DS3231_H_

#include <avr/io.h>

//extern uint8_t min_refresh;

typedef union
{
	uint8_t bytes[7];
	struct
	{
		uint8_t ss;
		uint8_t mm;
		uint8_t hh;
		uint8_t dayofweek;
		uint8_t day;
		uint8_t month;
		uint8_t year;
	};
} DS3231_DATETIME_t;

typedef struct
{
	int8_t cel;
	uint8_t fract;
} DS3231_TEMP_t;

#define DS3231_ADDR 0xD0
#define DS3231_CTRL_INTCN 2
#define DS3231_CTRL_RS1 3
#define DS3231_CTRL_RS2 4
#define DS3231_CTRL_EOSC 7 // "Enable Oscillator"

void ds3231_init( void );
uint8_t dec2bcd(uint8_t dec);
uint8_t bcd2dec(uint8_t bcd);
uint8_t ds3231_get_datetime( DS3231_DATETIME_t * dt );
void ds3231_get_temp( DS3231_TEMP_t * tmp );
void ds3231_set_time( uint8_t hh, uint8_t mm, uint8_t ss );
void ds3231_set_date( uint8_t year, uint8_t month, uint8_t day, uint8_t dayofweek );

#endif /* DS3231_DS3231_H_ */
