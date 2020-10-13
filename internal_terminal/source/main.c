/*
 * main.c
 *
 *  Created on: 13 wrz 2014
 *      Author: Adam
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
// do³¹czanie systemu
#include "watchdog.h"
#include "common.h"
#include "fsm/fsm.h"
// do³¹czanie interfejsów
#include "Interfaces/spi.h"
#include "Interfaces/uart.h"
#include "Interfaces/i2c_twi.h"
// do³¹czanie urz¹dzeñ
#include "EG9018C/eg9018c.h"
#include "EG9018C/LCD_GRAPH/lcd_graph.h"
#include "EG9018C/LCD_TEXT/lcd_text.h"
#include "EG9018C/lcd.h"
#include "23LCV1024/23lcv1024.h"
#include "DS3231/ds3231.h"
#include "nRF24L01/radio.h"
#include "BMP180/bmp180.h"
// do³¹czanie us³ug
#include "Telnet/komendy_at.h"
#include "Telnet/telnet_menu.h"

char bufor[20];
char MCUSR_string[20];


int main(void)
{	
	watchdog_get_mcusr();
	watchdog_MCUSR_to_string();
	
	wdt_enable(WDTO_4S);
		
	// *** ustawienie portów ***
	main_port_init();
	lcd_port_init();
	timers_on();
	LCD_DISP_ON;
	
	// *** ustawienie interfejsu i peryferiów SPI ***
	spi_init();
	sram_init();
	nrf24l01_init();
			
	// *** ustawienie interfejsu USART *** 
	USART_Init(__UBRR);
	register_uart_str_rx_event_callback( parse_uart_data );
	
	// *** ustawienie interfejsu i peryferów IIC *** 
	i2cSetBitrate(100);
	ds3231_init();
	bmp180_init(&bmp180_internal_sensor.bmp180_value);

	wdt_reset();

	// *** uruchomienie testów pamiêci ***	
	telnet_event_puts_P(telnet_event_content[11]);
	if(eg9018c_serial_sram_test()) telnet_event_puts_P(telnet_event_content[10]);
	else telnet_event_puts_P(telnet_event_content[2]);
	
	eg9018c_parallel_SRAM_test();

	// *** zakoñczenie testów pamiêci ***
	
	interrupts_init();
	
	telnet_print_main_screen(MAIN_SCREEN_BEGIN, 1);
	telnet_print_time(MAIN_SCREEN_BEGIN, 5);
	telnet_print_radio_status(RADIO_STATUS_BEGIN, 1);
	
	TRANSPARENCY_ON;

	lcd_prepare_background();
	
	/* Jeœli do odœwie¿enia ekranu daleka droga - zrób to teraz */
	
	if( ds3231_internal_sensor.datetime_value.ss < 45)
		fsm_event_flag_set(fsm_event_flags, fsm_lcd_prepare_foreground_event);
	
	/* ******************************************************** */

	for(;;)
	{		
		wdt_reset();
		UART_RX_STR_EVENT(bufor);
		radio_check_action();
		fsm_transition(fsm_event_flags, fsm_telnet_time_update_event, telnet_time_update_action, fsm_null_event, fsm_null_event);	// ród³o sygna³u: DS3231 INT set
		
		fsm_transition(fsm_event_flags, fsm_common_prepare_ext_system_strings_event, common_prepare_ext_system_strings_action, fsm_null_event, fsm_null_event);							// ród³o sygna³u: fsm_common_prepare_sensors_strings_event
		fsm_transition(fsm_event_flags, fsm_common_prepare_sensors_strings_event, common_prepare_sensors_strings_action, fsm_common_prepare_ext_system_strings_event, fsm_null_event);	// ród³o sygna³u: fsm_common_read_sensors_event
		fsm_transition(fsm_event_flags, fsm_common_read_sensors_event, common_read_sensors_action, fsm_common_prepare_sensors_strings_event, fsm_null_event);							// ród³o sygna³u: fsm_telnet_main_update_event set
		fsm_transition(fsm_event_flags, fsm_telnet_main_update_event, telnet_main_update_action, fsm_common_read_sensors_event, fsm_null_event);										// ród³o sygna³u: fsm_common_lcd_ilum_change_event set
		fsm_transition(fsm_event_flags, fsm_common_lcd_ilum_change_event, common_lcd_ilum_change_action, fsm_telnet_main_update_event, fsm_null_event);									// ród³o sygna³u: fsm_lcd_refresh_2_event set
		fsm_transition(fsm_event_flags, fsm_lcd_refresh_event, lcd_refresh_action, fsm_common_lcd_ilum_change_event, fsm_null_event);													// ród³o sygna³u: fsm_lcd_refresh_1_event
		fsm_transition(fsm_event_flags, fsm_lcd_prepare_foreground_event, lcd_prepare_foreground_action, fsm_lcd_refresh_event, fsm_null_event);										// ród³o sygna³u:  DS3231 INT set
	}
	return 0;
}





