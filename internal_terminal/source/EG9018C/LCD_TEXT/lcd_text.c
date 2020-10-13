/*
 * lcd_text.h
 *
 *  Created on: 19 lut 2015
 *      Author: Adam
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "../eg9018c.h"
#include "lcd_text.h"
#include "../LCD_FONT/lcd_fonts.h"
#include "../LCD_GRAPH/lcd_graph.h"

FONT_INFO currentFont;
uint8_t font_transparency;

uint16_t CX, CY;

void setCurrentFont( const FONT_INFO * font )
{
	currentFont.heightPixels 		= pgm_read_byte(&font->heightPixels);
	currentFont.startChar 			= pgm_read_byte(&font->startChar);
	currentFont.interspacePixels	= pgm_read_byte(&font->interspacePixels);
	currentFont.spacePixels 		= pgm_read_byte(&font->spacePixels);
	currentFont.charInfo 			= (FONT_CHAR_INFO*)pgm_read_word(&font->charInfo);
	currentFont.data 				= (uint8_t*)pgm_read_word(&font->data);
	currentFont.filename			= (char*)pgm_read_word(&font->filename);
}

static void send_glyph_byte(uint16_t x, uint16_t y, uint8_t bajt, uint8_t width)
{
	uint8_t i;
	for(i=0; i<width; i++ )
	{
		if(bajt&0x80) lcd_set_pixel(x+i, y);
		else
		{
			if(!font_transparency) lcd_clear_pixel(x+i, y); // przezroczystosc - zeruje piksele poza obrysem znaku
		}
		bajt<<=1;
	}
}

static void send_font_bitmap(uint16_t xPixel, uint16_t yPixel, uint8_t *glyph, uint16_t glyphHeight, uint16_t glyphWidth)
{
	uint8_t i, j, k, bajt;
	uint16_t p=0;

	for(i=0; i<glyphHeight; i++ )
	{
		for(j=0, k=0; j<glyphWidth; j+=8, k++)
		{
			bajt = pgm_read_byte( &glyph[ p++ ] );
			if( ((k+1)*8)<=glyphWidth ) send_glyph_byte(xPixel+j, yPixel+i, bajt, 8);
			else send_glyph_byte(xPixel+j, yPixel+i, bajt, glyphWidth-(k*8));
		}
	}
}

void lcd_mputs( uint16_t x, uint16_t y, char * s)
{
	uint8_t gH, gW, gS, gIS;
	uint16_t offset;
	uint8_t startChar = currentFont.startChar;
	uint8_t * glyph = (uint8_t*)currentFont.data;

	gH = currentFont.heightPixels;
	gIS = currentFont.interspacePixels;
	gS = currentFont.spacePixels;

	while( *s ) {
		if( *s > ' ')
		{
			gW = pgm_read_byte( &currentFont.charInfo[ *s - startChar  ].widthBits );

			offset = pgm_read_word( &currentFont.charInfo[ *s - startChar  ].offset);

			send_font_bitmap(x, y, glyph+offset, gH, gW);
//			x = x + gW + gIS;

// ******** wstawianie miêdzy znaki pola w zaleznosci od zmiennej transparency **********

			x = x + gW;
			for(uint8_t i=0; i<gH; i++ )
			{
				for(uint8_t j=0, k=0; j<gIS; j+=8, k++)
				{
					if( ((k+1)*8)<=gIS ) send_glyph_byte(x+j, y+i, 0x00, 8);
					else send_glyph_byte(x+j, y+i, 0x00, gIS-(k*8));
				}
			}
			x = x + gIS;

// *************************************************************************************

		}
		else
		{
/*			for(uint16_t j=0; j<gH; j++)
			{
				for(uint16_t i=0; i<gS; i++)
				{
					lcd_clear_pixel(x+i, y+j);
				}

			}
*/
// ******** wstawianie miêdzy znaki pola w zaleznosci od zmiennej transparency *********

			for(uint8_t i=0; i<gH; i++ )
			{
				for(uint8_t j=0, k=0; j<gS; j+=8, k++)
				{
					if( ((k+1)*8)<=gS ) send_glyph_byte(x+j, y+i, 0x00, 8);
					else send_glyph_byte(x+j, y+i, 0x00, gS-(k*8));
				}
			}

// *************************************************************************************

			x+=gS;
		}
		s++;
	}

	CX=x;
	CY=y;
}

void lcd_puts( uint16_t x, uint16_t y, char * s)
{
	if( !currentFont.filename )
	{
		lcd_mputs(x, y, s);
		return;
	}
}

void lcd_mputs_P( uint16_t x, uint16_t y, char * s)
{
	char c;
	uint8_t gH, gW, gS, gIS;
	uint16_t offset;
	uint8_t startChar = currentFont.startChar;
	uint8_t * glyph = (uint8_t*)currentFont.data;

	gH = currentFont.heightPixels;
	gIS = currentFont.interspacePixels;
	gS = currentFont.spacePixels;

	while( (c=pgm_read_byte(s)) )
	{
		if( c > ' ')
		{
			gW = pgm_read_byte( &currentFont.charInfo[ c - startChar  ].widthBits );

			offset = pgm_read_word( &currentFont.charInfo[ c - startChar  ].offset);

			send_font_bitmap(x, y, glyph+offset, gH, gW );
			x = x + gW + gIS;

		}
		else
		{
			for(uint16_t j=0; j<gH; j++)
			{
				for(uint16_t i=0; i<gS; i++)
				{
					lcd_clear_pixel(x+i, y+j); //<- TESTOWO!!!!!!!!!!!!!!!!!!!!
				}

			}
			x+=gS;
		}
		s++;
	}

	CX=x;
	CY=y;
}

uint16_t text_len(char *s)
{
	int x=0;
	uint8_t gW, gS, gIS;
	uint8_t startChar = currentFont.startChar;

//	gH = currentFont.heightPixels;
	gIS = currentFont.interspacePixels;
	gS = currentFont.spacePixels;

	while( *s )
	{
		if( *s > ' ')
		{
			gW = pgm_read_byte( &currentFont.charInfo[ *s - startChar  ].widthBits );
			x = x + gW + gIS;
		}
		else x+=gS;
		s++;
	}

	return x;
}

uint16_t text_len_P(char *s)
{
	char c;
	uint16_t x=0;
	uint8_t gW, gS, gIS;
	uint8_t startChar = currentFont.startChar;

//	gH = currentFont.heightPixels;
	gIS = currentFont.interspacePixels;
	gS = currentFont.spacePixels;

	while( (c=pgm_read_byte(s)) )
	{
		if( c > ' ')
		{
			gW = pgm_read_byte( &currentFont.charInfo[ c - startChar  ].widthBits );
			x = x + gW + gIS;
		}
		else x+=gS;
		s++;
	}
	return x;
}

void lcd_puts_P( uint16_t x, uint16_t y, char * s)
{
	if( !currentFont.filename)
	{
		lcd_mputs_P(x, y, s);
		return;
	}
}

void lcd_putint(uint16_t x, uint16_t y, uint16_t val)
{
	char bufor[17];

	itoa(val, bufor, 10);
	lcd_puts(x, y, bufor);

}

void lcd_puthex(uint16_t x, uint16_t y, uint32_t val)
{
	char bufor[17];

	memset(bufor, 0, 17);
	ltoa(val, bufor, 16);
	lcd_puts(x, y, bufor);
}
