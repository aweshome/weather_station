/*
 * lcd_graph.h
 *
 *  Created on: 19 lut 2015
 *      Author: Adam
 */

#ifndef EG9018C_LCD_GRAPH_H_
#define EG9018C_LCD_GRAPH_H_

extern uint8_t draw_negative;
extern uint32_t screen_select;

#define DRAW_POSITIVE draw_negative = 0
#define DRAW_NEGATIVE draw_negative = 1

void lcd_draw_byte(uint16_t x, uint16_t y, uint8_t pix_byte);
void lcd_clear(void);
void lcd_set_pixel(uint16_t x, uint16_t y);
void lcd_clear_pixel(uint16_t x, uint16_t y);
void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void lcd_draw_rectangle_filled(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void lcd_draw_bitmap_P(uint16_t x, uint16_t y, const uint8_t __flash* glyph, uint16_t width, uint16_t height);
void lcd_draw_diag_frame(uint16_t x, uint16_t y);

#endif /* EG9018C_LCD_GRAPH_H_ */
