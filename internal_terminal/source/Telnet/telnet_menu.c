/*
 * telnet_menu.c
 *
 *  Created on: 19 lip 2015
 *      Author: Adam
 */

#include <avr/io.h>
#include <stdlib.h>
#include "../common.h"
#include "../watchdog.h"
#include "telnet_menu.h"
#include "mkvt100.h"
#include "komendy_at.h"
#include "../Interfaces/uart.h"
#include "../nRF24L01/radio.h"

uint8_t event_list_line = EVENT_LIST_BEGIN;
uint8_t event_counter = 1;

const char telnet_event_content[EVENT_CONTENT_QUANTITY][EVENT_CONTENT_LENGTH] =
{
	"Czujniki: odczyt",						// 0
	"Czujniki: generowanie lancuchow",		// 1
	"Zdarzenie: OK",						// 2
	"LCD: generowanie statusu",				// 3
	"LCD: generowanie 1. planu",			// 4
	"LCD: odswiezenie",						// 5
	"Terminal: odswiezenie",				// 6
	"Radio: odczyt...",						// 7
	"Radio: nie odbiera",					// 8
	"Radio: cos przyszlo",					// 9
	"Zdarzenie: BLAD!",						// 10
	"Test serial SRAM...",					// 11
	"Test parallel SRAM..."					// 12
};

void telnet_print_line(uint8_t colour, uint8_t lenght)
{
	tr_brush_color(colour);
	for(uint8_t i=1; i<=lenght; i++) uart_putc(' ');
}

void telnet_prepare_time(void)
{
	ds3231_prepare_time_string(&ds3231_internal_sensor);
	uart_puts(ds3231_internal_sensor.time_string);
}

void telnet_event_puts(char *s) // funcja wypisuje zda¿enia w formie listy
{
	register char c;
	char buffer[4];
	
	tr_attr(RESET, WHITE, BLACK);
	tr_locate(event_list_line, 1);
	telnet_print_line(BLACK, 80);
	tr_locate(event_list_line+1, 1);
	telnet_print_line(BLACK, 80);
	tr_locate(event_list_line, 1);
	uart_puts(itoa(event_counter, buffer, 10));
	uart_puts(". ");
	telnet_prepare_time();
	uart_puts(": ");
	while ((c = *s++)) uart_putc(c);
	if(event_list_line > EVENT_LIST_END) event_list_line = EVENT_LIST_BEGIN;
	else event_list_line++;
	if(event_counter >= 255) event_counter = 1;
	else event_counter++;
}

void telnet_event_puts_P(const char *s) // funcja wypisuje zda¿enia w formie listy
{
	register char c;
	char buffer[4];
	
	tr_attr(RESET, WHITE, BLACK);
	tr_locate(event_list_line, 1);
	telnet_print_line(BLACK, 80);
	tr_locate(event_list_line+1, 1);
	telnet_print_line(BLACK, 80);
	tr_locate(event_list_line, 1);
	uart_puts(itoa(event_counter, buffer, 10));
	uart_puts(". ");
	telnet_prepare_time();
	uart_puts(": ");
	while ((c = *s++)) uart_putc(c);
	if(event_list_line > EVENT_LIST_END) event_list_line = EVENT_LIST_BEGIN;
	else event_list_line++;
	if(event_counter >= 255) event_counter = 1;
	else event_counter++;
}

void telnet_prepare_full_date(void)
{
	ds3231_prepare_day_string(&ds3231_internal_sensor);
	ds3231_prepare_date_string(&ds3231_internal_sensor);
	uart_puts(ds3231_internal_sensor.day_string);
	uart_putc(' ');
	uart_puts(ds3231_internal_sensor.date_string);
}

void telnet_prepare_temp(void)
{
	uart_puts("DHT22 temp. zewn.: ");
	uart_puts(external_t1_sensor->dht22_data.temperature_string);
	uart_puts("\r\nDHT22 temp. wewn.: ");
	uart_puts(dht22_internal_sensor.temperature_string);
	uart_puts("\r\nBMP180 temp.: ");
	uart_puts(bmp180_internal_sensor.temperature_string);
	uart_puts("\r\nDS3231 temp.: ");
	uart_puts(ds3231_internal_sensor.temperature_string);
}

/* funkcja przygotowuj¹ca dane dla programu poœrednicz¹cego miêdzy terminalem a serwerem MQTT */

void telnet_prepare_data_for_mqtt(void)
{
	
	uart_puts("##TEMP_INT_BMP180#");
	uart_puts(bmp180_internal_sensor.temperature_string);
	uart_puts("##TEMP_INT_DS3231#");
	uart_puts(ds3231_internal_sensor.temperature_string);
	uart_puts("##HUM_INT_DHT22#");
	uart_puts(dht22_internal_sensor.humidity_string);
	
	uart_puts("##SUPP_EXT_SYS#");
	uart_puts(external_t1_sensor->system_data.supply_voltage_string);
	uart_puts("##RST_EXT_SYS#");
	uart_puts(external_t1_sensor->system_data.rst_status_string);
	uart_puts("##TEMP_EXT_DHT22#");
	uart_puts(external_t1_sensor->dht22_data.temperature_string);
	uart_puts("##HUM_EXT_DHT22#");
	uart_puts(external_t1_sensor->dht22_data.humidity_string);
	uart_puts("##DUST_EXT_PM10#");
	uart_puts(external_t1_sensor->pms_data.pm10_string);
	uart_puts("##DUST_EXT_PM2#");
	uart_puts(external_t1_sensor->pms_data.pm2_string);
	uart_puts("##DUST_EXT_PM1#");
	uart_puts(external_t1_sensor->pms_data.pm1_string);
	uart_puts("##TIME_EXT#");
	uart_puts(external_t1_sensor->timestamp);
	
}

void telnet_print_main_screen(uint8_t x_pos, uint8_t y_pos)
{
	tr_cls(0);
	tr_cursor_visib(INVISIBLE);
	tr_locate(x_pos, y_pos);
	telnet_print_line(BLUE, 80);
	tr_locate(x_pos+1, y_pos);
	telnet_print_line(BLUE, 80);	
	tr_locate(x_pos+1, y_pos+4);
	tr_attr(RESET, WHITE, BLUE);
	uart_puts(MCUSR_string);
}

void telnet_print_update_main(uint8_t x_pos, uint8_t y_pos)
{
	tr_attr(BOLD, WHITE, BLUE);
	tr_locate(x_pos, y_pos);
	telnet_prepare_full_date();
}

void telnet_print_time(uint8_t x_pos, uint8_t y_pos)
{
	tr_attr(BOLD, WHITE, BLUE);
	tr_locate(x_pos, y_pos);
	telnet_prepare_time();
}

void telnet_print_temp(uint8_t x_pos, uint8_t y_pos)
{
	tr_attr(BOLD, WHITE, BLUE);
	tr_locate(x_pos, y_pos);
	telnet_prepare_temp();
}

void telnet_print_mqtt(uint8_t x_pos, uint8_t y_pos)
{
	tr_attr(RESET, WHITE, BLACK);
	tr_locate(x_pos, y_pos);
	telnet_prepare_data_for_mqtt();
}

void telnet_print_radio_status(uint8_t x_pos, uint8_t y_pos)
{
	tr_attr(RESET, WHITE, BLACK);
	tr_locate(x_pos, y_pos);
	nrf24l01_printinfo(uart_puts, uart_putc);
}

void telnet_print_command_line(uint8_t x_pos, uint8_t y_pos)
{
	tr_attr(RESET, WHITE, BLACK);
	tr_locate(x_pos, y_pos);
}

uint8_t telnet_main_update_action(void)
{
	telnet_print_update_main(MAIN_SCREEN_BEGIN, 14);
	telnet_print_temp(TEMP_SCREEN_BEGIN, 1);
	telnet_print_mqtt(MQTT_DATA_BEGIN, 1);
	
	return 1;
}

uint8_t telnet_time_update_action(void)
{
	telnet_print_time(MAIN_SCREEN_BEGIN, 5);
	telnet_print_command_line(CMD_LINE_BEGIN, 1);
	
	return 1;
}

