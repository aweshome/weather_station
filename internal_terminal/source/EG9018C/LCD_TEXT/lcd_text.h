/*
 * lcd_text.h
 *
 *  Created on: 19 lut 2015
 *      Author: Adam
 */

#include "../LCD_FONT/lcd_fonts.h"

#ifndef lcd_TEXT_H_
#define lcd_TEXT_H_

extern FONT_INFO currentFont;
extern uint8_t font_transparency;

extern uint16_t CX, CY;

#define TRANSPARENCY_ON font_transparency = 1;
#define TRANSPARENCY_OFF font_transparency = 0;

void setCurrentFont( const FONT_INFO * font );

void lcd_puts( uint16_t x, uint16_t y, char * s);
void lcd_puts_P( uint16_t x, uint16_t y, char * s);

void lcd_mputs( uint16_t x, uint16_t y, char * s);

uint16_t text_len(char *s);
uint16_t text_len_P(char *s);

void lcd_putint(uint16_t x, uint16_t y, uint16_t val);
void lcd_puthex(uint16_t x, uint16_t y, uint32_t val);

#endif


