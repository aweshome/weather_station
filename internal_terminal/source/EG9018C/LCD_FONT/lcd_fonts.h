/*
 * fontx.h
 *
 *  Created on: 2011-09-19
 *       Autor: Miros�aw Karda�
 */
#include <avr/io.h>
//#include <avr/pgmspace.h>

#ifndef lcd_FONTX_H_
#define lcd_FONTX_H_


// ==========================================================================
// structure definition
// ==========================================================================

// This structure describes a single character's display information
typedef struct
{
	const uint8_t widthBits;					// width, in bits (or pixels), of the character
	const uint16_t offset;					// offset of the character's bitmap, in bytes, into the the FONT_INFO's data array

} FONT_CHAR_INFO;

// Describes a single font
typedef struct
{
	uint8_t 						heightPixels;		// height, in pages (8 pixels), of the font's characters
	uint8_t	 						startChar;			// the first character in the font (e.g. in charInfo and data)
	uint8_t							interspacePixels;	// number of pixels of interspace between characters
	uint8_t							spacePixels;		// number of pixels of space character
	const FONT_CHAR_INFO __flash*	charInfo;			// pointer to array of char information
	const uint8_t __flash*			data;				// pointer to generated array of character visual representation
	const char __flash*				filename;			// (Pointer) Font filename saved on SD card or 0 (null) otherwise
} FONT_INFO;

//const extern char FontNames[][13] PROGMEM;

// Font data for Tahoma 12pt
extern const uint8_t __flash Tahoma12ptBitmaps[];
extern const FONT_CHAR_INFO __flash Tahoma12ptDescriptors[];
extern const FONT_INFO __flash Tahoma12ptFontInfo;

// Font data for Times New Roman 36pt
extern const uint8_t __flash TimesNewRoman36ptBitmaps[];
extern const FONT_CHAR_INFO __flash TimesNewRoman36ptDescriptors[];
extern const FONT_INFO __flash TimesNewRoman36ptFontInfo;

// Font data for Times New Roman 54pt
extern const uint8_t __flash TimesNewRoman54ptBitmaps[];
extern const FONT_CHAR_INFO __flash TimesNewRoman54ptDescriptors[];
extern const FONT_INFO __flash TimesNewRoman54ptFontInfo;

// Font data for Times New Roman 120pt
extern const uint8_t __flash TimesNewRoman120ptBitmaps[];
extern const FONT_CHAR_INFO __flash TimesNewRoman120ptDescriptors[];
extern const FONT_INFO __flash TimesNewRoman120ptFontInfo;

#endif /* lcd_FONTX_H_ */
