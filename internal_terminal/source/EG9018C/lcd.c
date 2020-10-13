/*
 * lcd.c
 *
 * Created: 20.09.2015 14:45:34
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <string.h>
#include "lcd.h"
#include "../common.h"
#include "../watchdog.h"
#include "../EG9018C/eg9018c.h"
#include "../EG9018C/LCD_GRAPH/lcd_graph.h"
#include "../EG9018C/LCD_TEXT/lcd_text.h"
#include "../EG9018C/LCD_PICT/dom.h"
#include "../EG9018C/LCD_PICT/domek.h"
#include "../EG9018C/LCD_PICT/chmurka.h"
#include "../Telnet/telnet_menu.h"

char lcd_short_time_string[6];

void lcd_prepare_background(void)
{	
	SCREEN_BACKGROUND;
	
	lcd_clear();
	wdt_reset();
	lcd_draw_bitmap_P(240, 180, bmp_dom_bits, bmp_dom_width, bmp_dom_height);
	lcd_draw_rectangle_filled(0, 113, 639, 115);									// Linia oddzielaj¹ca datê od wskaŸników
//	wdt_reset();
}

void lcd_prepare_foreground(void)
{	
	SCREEN_FOREGROUND;
	
	telnet_event_puts("czyszczenie...");
	lcd_clear();
	wdt_reset();
	telnet_event_puts("godzina...");	
	setCurrentFont(&TimesNewRoman120ptFontInfo);					// Character height 110
	lcd_puts(0, 0, strncpy(lcd_short_time_string, ds3231_internal_sensor.time_string, 5));
	wdt_reset();
	telnet_event_puts("data...");
	setCurrentFont(&TimesNewRoman36ptFontInfo);						// wysokoœæ najwy¿szego znaku 44
	lcd_puts(340, 0, ds3231_internal_sensor.date_string);			// data
	lcd_puts(340, 60, ds3231_internal_sensor.day_string);			// dzieñ tygodnia
	wdt_reset();
	telnet_event_puts("czujniki zewn...");
	lcd_puts(10, 120, external_t1_sensor[0].dht22_data.temperature_string);		// temperatura (DHT22)
	lcd_puts(210, 120, external_t1_sensor[0].dht22_data.humidity_string);		// wilgotnoœæ
	lcd_puts(410, 120, bmp180_internal_sensor.pressure_string);					// ciœnienie
//	lcd_puts(410, 210, external_t1_sensor[0].pluviometer_data.mmH2O_string);	// opady
	
	wdt_reset();
//	lcd_puts(0, 200, external_t1_sensor[0].pms_data.pm1_string);
	lcd_puts(0, 250, external_t1_sensor[0].pms_data.pm2_string);
	lcd_puts(0, 300, external_t1_sensor[0].pms_data.pm10_string);
	wdt_reset();
	telnet_event_puts("czujniki wewn...");
	lcd_puts(320, 350, dht22_internal_sensor.temperature_string);				// temperatura (DHT22)
	lcd_puts(320, 400, dht22_internal_sensor.humidity_string);					// wilgotnoœæ
	wdt_reset();
	telnet_event_puts("status...");
	setCurrentFont(&Tahoma12ptFontInfo);										// Character height 19
	lcd_puts(0, 380, external_t1_sensor[0].timestamp);							// znacznik czasu danych zewnêtrznych - TYMCZASOWE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	lcd_puts(0, 400, external_t1_sensor[0].system_data.rst_status_string);		// status watchdoga w Xmega
	lcd_puts(0, 420, external_t1_sensor[0].system_data.supply_voltage_string);	// napiêcie zasilania Xmega
	lcd_puts(0, 440, external_t1_sensor[0].dht22_data.error_string);			// status DHT22
	lcd_puts(0, 460, MCUSR_string);												// status watchdoga w ATmega
	wdt_reset();																
}

void lcd_refresh(void)
{
	eg9018c_screen_merge();
	wdt_reset();
	eg9018c_parallel_SRAM_refresh();
	wdt_reset();
}

uint8_t lcd_prepare_foreground_action(void)
{
	#if DEBUGENABLED 
	telnet_event_puts_P(telnet_event_content[4]);
	#endif
	
	lcd_prepare_foreground();
	
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[2]);
	#endif
	
	return 1;
}

uint8_t lcd_refresh_action(void)
{
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[5]);
	#endif
	
	lcd_refresh();
	
	#if DEBUGENABLED
	telnet_event_puts_P(telnet_event_content[2]);
	#endif
	
	return 1;
}


