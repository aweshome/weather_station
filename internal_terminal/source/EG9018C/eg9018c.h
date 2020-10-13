/*
 * eg9018c.h
 *
 *  Created on: 12 wrz 2014
 *      Author: Adam
 */

#ifndef EG9018C_H_
#define EG9018C_H_

#define LCD_DATA A

#define LCD_CP2_PORT D
#define LCD_CP2 7
#define LCD_CP1_PORT D
#define LCD_CP1 5
#define LCD_S_PORT D
#define LCD_S 6
#define LCD_DISP_PORT D
#define LCD_DISP 4

#define MEM_WE_PORT C
#define MEM_WE 7
#define MEM_CCLR_PORT C
#define MEM_CCLR 6
#define MEM_A16_PORT D
#define MEM_A16 1

#define LCD_CP2_SET PORT(LCD_CP2_PORT) |= (1<<LCD_CP2)
#define LCD_CP2_CLR PORT(LCD_CP2_PORT) &= ~(1<<LCD_CP2)
#define LCD_CP1_SET PORT(LCD_CP1_PORT) |= (1<<LCD_CP1)
#define LCD_CP1_CLR PORT(LCD_CP1_PORT) &= ~(1<<LCD_CP1)
#define LCD_S_SET PORT(LCD_S_PORT) |= (1<<LCD_S)
#define LCD_S_CLR PORT(LCD_S_PORT) &= ~(1<<LCD_S)
#define LCD_DISP_ON PORT(LCD_DISP_PORT) &= ~(1<<LCD_DISP)
#define LCD_DISP_OFF PORT(LCD_DISP_PORT) |= (1<<LCD_DISP)

#define MEM_WE_SET PORT(MEM_WE_PORT) &= ~(1<<MEM_WE)
#define MEM_WE_CLR PORT(MEM_WE_PORT) |= (1<<MEM_WE)
#define MEM_CCLR_SET PORT(MEM_CCLR_PORT) |= (1<<MEM_CCLR)
#define MEM_CCLR_CLR PORT(MEM_CCLR_PORT) &= ~(1<<MEM_CCLR)
#define MEM_A16_SET PORT(MEM_A16_PORT) |= (1<<MEM_A16)
#define MEM_A16_CLR PORT(MEM_A16_PORT) &= ~(1<<MEM_A16)
#define MEM_A16_SW PORT(MEM_A16_PORT) ^= (1<<MEM_A16)

#define SCR_MERG_ADDR 0										// 0 - 38399, maks. 131072
#define SCR_FOREGR_ADDR 38400								// 38400 - 76799, maks. 131072
#define SCR_BACKGR_ADDR 76800

#define SCREEN_MERGED screen_select = SCR_MERG_ADDR			// 0 - 38399, maks. 131072
#define SCREEN_FOREGROUND screen_select = SCR_FOREGR_ADDR	// 38400 - 76799, maks. 131072
#define SCREEN_BACKGROUND screen_select = SCR_BACKGR_ADDR	// 76800 - 115200, maks. 131072

void lcd_port_init(void);
void lcd_cp2_timer_init(void);
void lcd_cp1_timer_init(void);
void lcd_s_and_cclr_timer_init(void);
void timers_setup(void);
void timers_on(void);
void timers_off(void);

void eg9018c_screen_merge(void);
void eg9018c_parallel_SRAM_refresh(void);

uint8_t eg9018c_serial_sram_test(void);
void eg9018c_parallel_SRAM_test(void);

#endif /* EG9018C_H_ */
