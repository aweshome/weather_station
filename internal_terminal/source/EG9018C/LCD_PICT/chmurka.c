/*
 * chmurka.c
 *
 * Created: 09.04.2017 21:51:26
 *  Author: adamw
 */ 

#include <avr/io.h>
//#include <avr/pgmspace.h>
#include "chmurka.h"


const uint8_t __flash bmp_chmurka_bits[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0xfc, 0xff,
	0x07, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x07, 0x00, 0xff, 0xff, 0x1f, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf8, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
	0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0xff, 0x3f, 0x80, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x0f, 0x00, 0xfc,
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0xff, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00, 0xc0, 0xff, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x1f,
	0x00, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00,
	0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0x01, 0x00, 0x00, 0x00, 0xf0, 0x1f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xe0,
	0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x7f,
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
	0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x01, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
	0x01, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f, 0xf0, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0xfe, 0x03, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0x3f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0xff,
	0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0xf8, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0x03, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
	0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x06, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x3f, 0x00, 0xff, 0x01,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
	0xff, 0xff, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xfb, 0xff, 0x7f, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00,
	0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x87, 0xff, 0xff, 0xff,
	0xff, 0x0f, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf0,
	0x7f, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xfc, 0x01,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f, 0x00, 0xe0, 0xff, 0x03, 0xff, 0x3f,
	0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00,
	0xc0, 0xff, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x07, 0x00, 0x80, 0xff, 0x00, 0xe0, 0xff, 0x00, 0x00,
	0x00, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0xff,
	0x01, 0x80, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xfe, 0x01, 0x00, 0x00, 0xfc, 0x03, 0x00, 0xff, 0x03, 0x00, 0x80, 0x7f,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0xfc, 0x03, 0x00,
	0xfe, 0x03, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00,
	0x00, 0x00, 0xf8, 0x03, 0x00, 0xfc, 0x03, 0x00, 0xc0, 0x3f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x00, 0xf8, 0x07,
	0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
	0xf8, 0x03, 0x00, 0xf0, 0x0f, 0x00, 0xe0, 0x1f, 0x30, 0x00, 0x00, 0x00,
	0x80, 0x7f, 0x00, 0x00, 0x00, 0xf8, 0x07, 0x00, 0xf0, 0xff, 0x01, 0xc0,
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0xf0, 0x07,
	0x00, 0xf8, 0xff, 0x03, 0x80, 0x0f, 0xf8, 0x01, 0x00, 0x00, 0xf8, 0x7f,
	0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0xff, 0xff, 0x1f, 0x00, 0x07, 0xf0,
	0x07, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0x00, 0xe0, 0x03, 0xc0, 0xff,
	0xff, 0x7f, 0x00, 0x02, 0x80, 0x0f, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00,
	0x00, 0xe0, 0x01, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x80, 0x0f, 0x00,
	0x80, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff,
	0x01, 0x00, 0x00, 0x0c, 0x00, 0xc0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff,
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x80, 0xff, 0x07, 0x00,
	0x00, 0x00, 0x00, 0xf0, 0x3f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
	0x07, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f, 0xff, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
	0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 0xfe, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x7c, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc,
	0x03, 0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0xc0, 0x3f,
	0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xfc,
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00,
	0x00, 0x00, 0xfe, 0x00, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0xf0, 0x03, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00,
	0x7e, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00,
	0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00,
	0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
	0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00,
	0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00,
	0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
	0x7f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00,
	0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x1f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xc0,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
