/*
34 * eg9018c.c
 *
 *  Created on: 12 wrz 2014
 *      Author: Adam
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include "eg9018c.h"
#include "../common.h"
#include "../Interfaces/spi.h"

#include "../Interfaces/uart.h"

#include "../23LCV1024/23lcv1024.h"
#include "../EG9018C/LCD_GRAPH/lcd_graph.h"
#include "../EG9018C/LCD_TEXT/lcd_text.h"


// KONFIGURACJA OBS£UGI SPRZÊTOWEJ WYŒWIETLACZA EG9018C

void lcd_port_init(void)
{
	PORT(LCD_DATA) = 0x00;
	LCD_CP2_CLR;
	LCD_CP1_CLR;
	LCD_S_CLR;
	LCD_DISP_OFF;
	MEM_WE_CLR;
	MEM_CCLR_CLR;
	MEM_A16_CLR;
	
	
	DDR(LCD_DATA) = 0x00;

	DDR(LCD_CP2_PORT) |= (1<<LCD_CP2);
	DDR(LCD_CP1_PORT) |= (1<<LCD_CP1);
	DDR(LCD_S_PORT) |= (1<<LCD_S);
	DDR(LCD_DISP_PORT) |= (1<<LCD_DISP);

	DDR(MEM_WE_PORT) |= (1<<MEM_WE);
	DDR(MEM_CCLR_PORT) |= (1<<MEM_CCLR);
	DDR(MEM_A16_PORT) |= (1<<MEM_A16);

	DDRB &= ~(1<<1); // T1 jako wejœcie
	DDRD &= ~(1<<0); // T3 jako wejœcie
}

void lcd_cp2_timer_init(void)
{
	TCCR2A |= (1<<COM2A0);	// tryb "toggle OC2A"
	TCCR2A |= (1<<WGM21);	// tryb CTC (Mode 2)
	TCCR2B |= (1<<CS20);	// (clk/1)
}

void lcd_cp1_timer_init(void)
{
	TCCR1A |= (1<<COM1A1) | (1<<COM1A0); // tryb "set OC1A"
	TCCR1A |= (1<<WGM11); // tryb fast PWM (Mode 14)
	TCCR1B |= (1<<WGM13) | (1<<WGM12); // tryb fast PWM (Mode 14)
	TCCR1B |= (1<<CS12) | (1<<CS11) | (1<<CS10); // Ÿród³o zegara na T1, zbocze rosn¹ce
//	TIMSK1 |= (1<<OCIE1A); // w³¹czenie przerwania od porównania
}

void lcd_s_and_cclr_timer_init(void)
{
	TCCR3B |= (1<<WGM33) | (1<<WGM32); // tryb CTC (Mode 12)
	TCCR3B |= (1<<CS32) | (1<<CS31) | (1<<CS30); // Ÿród³o zegara na T3, zbocze rosn¹ce
	TIMSK3 |= (1<<OCIE3A) | (1<<OCIE3B); // w³¹czenie przerwania od porównania
}

void timers_setup(void)
{
	// CP2
	OCR2A = 3;		// OCR2A = 9 -> clk 921600 Hz (ekran 24 Hz), MAX OCR2A = 2 -> clk 3072000 Hz (ekran 80 Hz)
	TCNT2 = 0;
	
	// CP1
	ICR1 = 159;		// okres (TOP)
	OCR1A = 158;	// szerokoœæ impulsu PWM
	TCNT1 = 0;
	
	// S, CCLR
	ICR3 = 38399;
	OCR3A = 38396;
	OCR3B = 156;
	TCNT3 = 0;
}

ISR(TIMER3_COMPA_vect)
{
	MEM_CCLR_SET;
	MEM_CCLR_CLR;
}

ISR(TIMER3_COMPB_vect)
{
	LCD_S_SET;
	LCD_S_SET;
	LCD_S_SET;
	LCD_S_SET; // przed³u¿enie stanu wysokiego na S
	LCD_S_CLR;
}

void eg9018c_screen_merge(void)														// przygotowanie danych do bezpoœredniego zapisu do EG9018C
{
	uint8_t byte_a;																	// pierwsza po³owa scalona
	uint8_t byte_b;																	// druga po³owa scalona
	uint8_t byte_a1;																// pierwsza po³owa pierwszego planu
	uint8_t byte_b1;																// druga po³owa pierwszego planu
	uint8_t byte_a2;																// pierwsza po³owa t³a
	uint8_t byte_b2;																// druga po³owa t³a
	
	for(uint16_t k = 0; k < 38400; k = k + 2)
	{
		byte_a1 = sram_read_byte(k / 2 + SCR_FOREGR_ADDR);
		byte_a2 = sram_read_byte(k / 2 + SCR_BACKGR_ADDR);
		byte_b1 = sram_read_byte(k / 2 + 19200 + SCR_FOREGR_ADDR);
		byte_b2 = sram_read_byte(k / 2 + 19200 + SCR_BACKGR_ADDR);
		byte_a = (byte_a1 | byte_a2);												// ³¹czy pierwszy plan z t³em - pierwsza po³owa
		byte_b = (byte_b1 | byte_b2);												// ³¹czy pierwszy plan z t³em - druga po³owa
		sram_write_byte(k + SCR_MERG_ADDR, ((byte_a << 4) | (byte_b & 0x0F)));
		sram_write_byte(k + 1 + SCR_MERG_ADDR, ((byte_a & 0xF0) | (byte_b >> 4)));
	}
}


void eg9018c_parallel_SRAM_refresh(void) // przepisanie danych z pamiêci szeregowej SRAM do pamiêci równoleg³ej SRAM w trybie sequence
{
		SCREEN_MERGED;
		
		TCCR2A &= ~(1<<COM2A0);
		timers_setup();
		DDR(LCD_DATA) = 0xFF;
		MEM_CCLR_SET;
		MEM_CCLR_CLR;
		MEM_WE_SET;
		MEM_A16_SW;		// prze³¹czanie po³ówek pamiêci - dla zasady ;)
		
		SPI_SSRAM_CS_ON;
		spi_send_read_byte(INSTR_READ);
		spi_send_read_byte(screen_select>>16);
		spi_send_read_byte(screen_select>>8);
		spi_send_read_byte(screen_select);
		for(uint16_t k = 0; k < 38400; k++)
		{
			LCD_CP2_SET;
			PORT(LCD_DATA) = spi_send_read_byte(0xFF);
			LCD_CP2_CLR;
			wdt_reset();
		}
		SPI_SSRAM_CS_OFF;
				
		MEM_WE_CLR;
		DDR(LCD_DATA) = 0x00;
		PORT(LCD_DATA) = 0x00;
		TCCR2A |= (1<<COM2A0);
		wdt_reset();
}

/**********************************************************************************************
                               FUNKCJE TESTUJ¥CE
 **********************************************************************************************/


uint8_t eg9018c_serial_sram_test(void)
{
	uint8_t result = 0;
	uint8_t pattern = 0;
	uint8_t variable = 0;
	
	for(uint32_t k = 0; k < 131072; k++)
	{
		sram_write_byte(k, pattern);
		variable = sram_read_byte(k);
		
		if(variable == pattern) pattern++;
		else
		{
			result = 1;
			break;
		}
		wdt_reset();
	}
	
	return result;
}

void eg9018c_parallel_SRAM_test(void)
{
	TCCR2A &= ~(1<<COM2A0);
	timers_setup();
	DDR(LCD_DATA) = 0xFF;
	MEM_A16_SW;
	MEM_CCLR_SET;
	MEM_CCLR_CLR;
	MEM_WE_SET;

	for(uint16_t k = 0; k < 38400; k++)
	{
		LCD_CP2_SET;
		PORT(LCD_DATA) = 0xCC;
		LCD_CP2_CLR;
		
		wdt_reset();
	}

	MEM_WE_CLR;
	MEM_CCLR_SET;
	MEM_CCLR_CLR;
	DDR(LCD_DATA) = 0x00;
	PORT(LCD_DATA) = 0x00;
	TCCR2A |= (1<<COM2A0);
}


/* ********************************************************************************************************

void eg9018c_screen_refresh(void)
{
//	uint8_t byte_a; // pierwsza po³owa
//	uint8_t byte_b; // druga po³owa
		
//	byte_a = sram_read_byte(screen_addr / 2 + SCR_FOREGR_ADDR);
//	byte_b = sram_read_byte(screen_addr / 2 + 19200 + SCR_FOREGR_ADDR);
	
//	LCD_CP2_SET;
//	PORT(LCD_DATA) = ((byte_a << 4) | (byte_b & 0x0F));
//	PORT(LCD_DATA) = 0xCC;
//	LCD_CP2_CLR;
	
//	screen_addr++;
	
	LCD_CP2_SET;
//	PORT(LCD_DATA) = ((byte_a & 0xF0) | (byte_b >> 4));
	PORT(LCD_DATA) = screen_addr;
	LCD_CP2_CLR;
	
	if(screen_addr < 38400) screen_addr++;
	else screen_addr = 0;	
}

void eg9018c_screen_merge(void) // przygotowanie danych do bezpoœredniego zapisu do EG9018C
{
	uint8_t byte_a; // pierwsza po³owa scalona
	uint8_t byte_b; // druga po³owa scalona
	uint8_t byte_a1; // pierwsza po³owa pierwszego planu
	uint8_t byte_b1; // druga po³owa pierwszego planu
	uint8_t byte_a2; // pierwsza po³owa t³a
	uint8_t byte_b2; // druga po³owa t³a
	
	for(uint16_t k = 0; k < 38400; k = k + 2)
	{
		byte_a1 = sram_read_byte(k / 2 + SCR_FOREGR_ADDR);
		byte_a2 = sram_read_byte(k / 2 + SCR_BACKGR_ADDR);
		byte_b1 = sram_read_byte(k / 2 + 19200 + SCR_FOREGR_ADDR);
		byte_b2 = sram_read_byte(k / 2 + 19200 + SCR_BACKGR_ADDR);
		byte_a = (byte_a1 | byte_a2); // ³¹czy pierwszy plan z t³em - pierwsza po³owa
		byte_b = (byte_b1 | byte_b2); // ³¹czy pierwszy plan z t³em - druga po³owa
		sram_write_byte(k + SCR_MERG_ADDR, ((byte_a << 4) | (byte_b & 0x0F)));
		sram_write_byte(k + 1 + SCR_MERG_ADDR, ((byte_a & 0xF0) | (byte_b >> 4)));
		
		byte_a1 = sram_read_byte(k / 2 + SCR_FOREGR_ADDR);
		byte_b1 = sram_read_byte(k / 2 + 19200 + SCR_FOREGR_ADDR);
		sram_write_byte(k + SCR_MERG_ADDR, ((byte_a1 << 4) | (byte_b1 & 0x0F)));
		sram_write_byte(k + 1 + SCR_MERG_ADDR, ((byte_a1 & 0xF0) | (byte_b1 >> 4)));
	}
}

void eg9018c_screen_prepare(uint8_t screen) // przygotowanie danych do bezpoœredniego zapisu do EG9018C
{
	uint8_t byte_a; // pierwsza po³owa
	uint8_t byte_b; // druga po³owa
	
	if(screen==1) SCREEN_1;
	else if(screen==2) SCREEN_2;
	
	for(uint16_t addr = 0; addr < 38400; addr = addr + 2)
	{
		byte_a = sram_read_byte(addr / 2 + screen_select);
		byte_b = sram_read_byte(addr / 2 + 19200 + screen_select);
		sram_write_byte(addr + SCR_PREP_ADDR, ((byte_a << 4) | (byte_b & 0x0F)));
		sram_write_byte(addr + 1 + SCR_PREP_ADDR, ((byte_a & 0xF0) | (byte_b >> 4)));
		wdt_reset();
	}
}

*/