/*
 * lcd.h
 *
 * Created: 20.09.2015 14:45:43
 *  Author: Adam
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../common.h"

void lcd_prepare_background(void);

uint8_t lcd_prepare_foreground_action(void);
uint8_t lcd_refresh_action(void);

//void lcd_prepare_foreground_event(GPIO_flags_t* task_flag);
//void lcd_refresh_event(GPIO_flags_t* task_flag);




#endif /* LCD_H_ */