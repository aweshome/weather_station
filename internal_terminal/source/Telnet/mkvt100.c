/*
 * mk_term.c
 *
 *  Created on: 30-04-2013
 *      Author: Miros³aw Kardaœ
 */
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "../Interfaces/uart.h"
#include "mkvt100.h"

// aby mieæ polskie ogonki w PUTTY ----> ustawiæ WINDOW / Translation / Win1250

const char __flash UCLS[] = { "\x1b""[2J" };

const char __flash UHOME[] = { "\x1b""[;H" };

const char __flash UCUR_HIDE[] = { "\x1b""[?25l" };
const char __flash UCUR_SHOW[] = { "\x1b""[?25h" };

const char __flash U_ATTR_OFF[] = { "\x1b""[m" };

void tr_cursor_visib(uint8_t visibility)
{
	if(visibility) uart_puts_P(UCUR_SHOW);
	else uart_puts_P(UCUR_HIDE);
}

void tr_cls(uint8_t cur_onoff)
{
	uart_puts_P(U_ATTR_OFF);
	tr_cursor_visib(cur_onoff);
	uart_puts_P(UCLS);
	uart_puts_P(UHOME);
}

void fill_line( char ascii, uint8_t cnt )
{
	for(uint8_t i=0; i<cnt; i++) uart_putc(ascii);
}

void tr_attr(uint8_t atr, uint8_t fg, uint8_t bg)
{
	uart_putc( 0x1b );		// <ESC>[0;32;44m
	uart_putc( '[' );
	uart_putc( atr+'0' );
	uart_putc( ';' );
	uart_putc( '3' );
	uart_putc( fg+'0' );
	uart_putc( ';' );
	uart_putc( '4' );
	uart_putc( bg+'0' );
	uart_putc( 'm' );
}

void tr_pen_color( uint8_t cl )
{
	uart_putc( 0x1b );		// <ESC>[34m
	uart_putc( '[' );
	uart_putc( '3' );
	uart_putc( cl+'0' );
	uart_putc( 'm' );
}

void tr_brush_color( uint8_t cl )
{
	uart_putc( 0x1b );		// <ESC>[44m
	uart_putc( '[' );
	uart_putc( '4' );
	uart_putc( cl+'0' );
	uart_putc( 'm' );
}


void tr_locate( uint8_t y, uint8_t x )
{
	uart_putc( 0x1b );	// <ESC>[y;xH
	uart_putc( '[' );
	uart_putint( y, 10 );
	uart_putc( ';' );
	uart_putint( x, 10 );
	uart_putc( 'H' );
}
