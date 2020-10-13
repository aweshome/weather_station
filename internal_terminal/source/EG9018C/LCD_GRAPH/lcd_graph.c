/*
 * lcd_graph.c
 *
 *  Created on: 19 lut 2015
 *      Author: Adam
 */

#include <avr/io.h>
#include <avr/wdt.h>
#include "../../23LCV1024/23lcv1024.h"
#include "../eg9018c.h"
#include "lcd_graph.h"

uint8_t draw_negative = 0;
uint32_t screen_select = 0;


void lcd_draw_byte(uint16_t x, uint16_t y, uint8_t pix_byte)
{
	uint32_t pix_byte_address;
	uint8_t old_pix_byte;
	uint8_t new_pix_byte;

	pix_byte_address = x / 8 + y * 80 + screen_select;
	old_pix_byte = sram_read_byte(pix_byte_address);
	new_pix_byte = (old_pix_byte | pix_byte);
	sram_write_byte(pix_byte_address, new_pix_byte);
}

void lcd_clear(void)
{
	for(uint32_t k = 0 ; k < 38400; k++)
	{
		sram_write_byte((k + screen_select), 0);
	}
}

void lcd_set_pixel(uint16_t x, uint16_t y)
{
	uint32_t pix_byte_address;
	uint8_t old_pix_byte;
	uint8_t new_pix_byte;

	pix_byte_address = x/8+y*80 + screen_select;
	old_pix_byte = sram_read_byte(pix_byte_address);
	new_pix_byte = (old_pix_byte | (1<<(x%8)));
	sram_write_byte(pix_byte_address, new_pix_byte);
}

void lcd_clear_pixel(uint16_t x, uint16_t y)
{	
	uint32_t pix_byte_address;
	uint8_t old_pix_byte;
	uint8_t new_pix_byte;

	pix_byte_address = x/8+y*80 + screen_select;
	old_pix_byte = sram_read_byte(pix_byte_address);
	new_pix_byte = old_pix_byte & ~(1<<(x%8));
	sram_write_byte(pix_byte_address, new_pix_byte);
}

void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{	
	for(uint16_t k=x1; k<(x2); k++)
	{
		lcd_set_pixel(k, y1);
		lcd_set_pixel(k, y2);
	}
	for(uint16_t k=y1; k<(y2); k++)
	{
		lcd_set_pixel(x1, k);
		lcd_set_pixel(x2, k);
	}
}

void lcd_draw_rectangle_filled(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	if(!draw_negative)
	{
		for(uint16_t i=y1; i<(y2); i++)
		{
			for(uint16_t j=x1; j<(x2); j++)
			{
				lcd_set_pixel(j, i);
			}
		}
	}
	else
	{
		for(uint16_t i=y1; i<(y2); i++)
		{
			for(uint16_t j=x1; j<(x2); j++)
			{
				lcd_clear_pixel(j, i);
			}
		}
	}
}

void lcd_draw_bitmap_P(uint16_t x, uint16_t y, const uint8_t __flash* glyph, uint16_t width, uint16_t height)
{
	uint16_t idx=0;
	uint16_t i;
	uint16_t j;
	uint8_t byte;

	for(j=0; j<height; j++)
	{
		for(i=0; i<width; i+=8)
		{
			byte = glyph[idx++];					// dla __flash
			lcd_draw_byte(x+i, y+j, byte);
		}
	}
}

void lcd_draw_diag_frame(uint16_t x, uint16_t y)
{
	const uint8_t h_tot = 80;
	const uint8_t h_rect = 40;
	const uint8_t w_rect = 146;
	
	
	lcd_draw_rectangle(x, y, x, y+h_tot);							// pionowa krecha
	lcd_draw_rectangle(x, y+h_tot-h_rect, x+w_rect, y+h_tot);		// prostok¹t na s³upki
	
	lcd_draw_rectangle(x+1, y+h_tot, x+1, y+h_tot+3);											// ogonek godziny 0
	lcd_draw_rectangle(x+1+((w_rect-2)/3*1), y+h_tot, x+1+((w_rect-2)/3*1), y+h_tot+3);			// ogonek godziny 12
	lcd_draw_rectangle(x+1+((w_rect-2)/3*2), y+h_tot, x+1+((w_rect-2)/3*2), y+h_tot+3);			// ogonek godziny 24
	lcd_draw_rectangle(x+1+((w_rect-2)/3*3), y+h_tot, x+1+((w_rect-2)/3*3), y+h_tot+3);			// ogonek godziny 12 kolejnego dnia
	
	lcd_draw_rectangle(x+w_rect, y+h_tot-h_rect, x+w_rect+3, y+h_tot-h_rect);	// ogonek MAX
	lcd_draw_rectangle(x+w_rect, y+h_tot, x+w_rect+3, y+h_tot);					// ogonek MIN
}