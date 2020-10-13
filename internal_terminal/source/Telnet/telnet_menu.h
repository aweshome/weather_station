/*
 * telnet_menu.h
 *
 *  Created on: 19 lip 2015
 *      Author: Adam
 */

#ifndef TELNET_TELNET_MENU_H_
#define TELNET_TELNET_MENU_H_

#define MAIN_SCREEN_BEGIN 1
#define TEMP_SCREEN_BEGIN 4
#define RADIO_STATUS_BEGIN 9
#define MQTT_DATA_BEGIN 16
#define CMD_LINE_BEGIN 18
#define EVENT_LIST_BEGIN 20
#define EVENT_LIST_END 50
#define EVENT_CONTENT_LENGTH 40
#define EVENT_CONTENT_QUANTITY 13

extern const char telnet_event_content[EVENT_CONTENT_QUANTITY][EVENT_CONTENT_LENGTH];

void telnet_print_MCUSR(void);
void telnet_print_line(uint8_t colour, uint8_t lenght);
void telnet_event_puts(char *s);
void telnet_event_puts_P(const char *s);

void telnet_print_main_screen(uint8_t x_pos, uint8_t y_pos);
void telnet_print_update_main(uint8_t x_pos, uint8_t y_pos);
void telnet_print_time(uint8_t x_pos, uint8_t y_pos);
void telnet_print_temp(uint8_t x_pos, uint8_t y_pos);
void telnet_print_mqtt(uint8_t x_pos, uint8_t y_pos);
void telnet_print_radio_status(uint8_t x_pos, uint8_t y_pos);
void telnet_print_command_line(uint8_t x_pos, uint8_t y_pos);

uint8_t telnet_main_update_action(void);
uint8_t telnet_time_update_action(void);

//void telnet_main_update_event(GPIO_flags_t *task_flag);
//void telnet_time_update_event(GPIO_flags_t *task_flag);

// extern uint8_t telnet_refresh_flag;


#endif /* TELNET_TELNET_MENU_H_ */
