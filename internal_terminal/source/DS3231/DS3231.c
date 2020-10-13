/*
 * DS3231.c
 *
 *  Created on: 1 mar 2015
 *      Author: Adam
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../Interfaces/i2c_twi.h"
#include "ds3231.h"

volatile uint8_t prev_mm = 0;

//uint8_t stc[] = {12,18,18,12,32,32,32,32};

void ds3231_init( void )
{
	uint8_t ctrl = 0; // w³¹czony generator 1 Hz na SQW
	TWI_write_buf( DS3231_ADDR, 0x0e, 1, &ctrl );
}

uint8_t ds3231_get_datetime( DS3231_DATETIME_t * dt )
{
	uint8_t i;
	uint8_t buf[7];
	TWI_read_buf( DS3231_ADDR, 0x00, 7, buf );
	for( i=0; i<7; i++ ) dt->bytes[i] = bcd2dec( buf[i] );
	return dt->ss;
}

void ds3231_get_temp( DS3231_TEMP_t * tmp )
{
	uint8_t buf[2];
	TWI_read_buf( DS3231_ADDR, 0x11, 2, buf );
	tmp->cel = buf[0] ;
	tmp->fract = buf[1]>>6;

//	TWI_read_buf( DS3231_ADDR, 0x0e, 1, buf );
//	buf[0] |= (1<<5);
//	TWI_write_buf( DS3231_ADDR, 0x0e, 1, buf );
}

void ds3231_set_time( uint8_t hh, uint8_t mm, uint8_t ss )
{
	uint8_t buf[3];
	
	buf[0]=dec2bcd(ss);
	buf[1]=dec2bcd(mm);
	buf[2]=dec2bcd(hh);
	TWI_write_buf( DS3231_ADDR, 0x00, 3, buf );
}

void ds3231_set_date( uint8_t year, uint8_t month, uint8_t day, uint8_t dayofweek )
{
	uint8_t buf[4];
	
	buf[0]=dayofweek;
	buf[1]=dec2bcd(day);
	buf[2]=dec2bcd(month);
	buf[3]=dec2bcd(year);
	TWI_write_buf( DS3231_ADDR, 0x03, 4, buf );
}

// konwersja liczby dziesiêtnej na BCD
uint8_t dec2bcd(uint8_t dec)
{
	return ((dec / 10)<<4) | (dec % 10);
}

// konwersja liczby BCD na dziesiêtn¹
uint8_t bcd2dec(uint8_t bcd)
{
    return ((((bcd) >> 4) & 0x0F) * 10) + ((bcd) & 0x0F);
}



