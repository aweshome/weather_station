/*
 * fsm.h
 *
 * Created: 2016-02-28 13:02:26
 *  Author: Adam
 */ 


#ifndef FSM_H_
#define FSM_H_

extern uint16_t *fsm_event_flags;

enum fsm_event 
{
	fsm_null_event,									// zdarzenie puste ("0")
	fsm_telnet_time_update_event,					// telnet_time_update_action
	fsm_telnet_main_update_event,					// telnet main_update_action
	fsm_common_read_sensors_event,					// common_read_sensors_action
	fsm_common_prepare_sensors_strings_event,		// common_prepare_sensors_strings_action
	fsm_common_prepare_ext_system_strings_event,	// common_prepare_ext_system_strings_action
	fsm_common_prepare_datetime_string_event,		// common_prepare_datetime_strings_action
	fsm_lcd_prepare_foreground_event,				// lcd_prepare_foreground_action
	fsm_lcd_refresh_event,							// lcd_refresh_action
	fsm_radio_call_event,							// radio_comm_action
	fsm_radio_check_event,							// radio_comm_action
	fsm_common_check_stack_event,					// common_check_stack_action
	fsm_common_lcd_ilum_change_event,				// common_lcd_ilum_change_action
	event_13,
	event_14,
	event_15,
	fsm_end_event									// znacznik koñca listy
};

void fsm_event_flag_set(uint16_t *event_flag, enum fsm_event event_number);
void fsm_event_flag_clear(uint16_t *event_flag, enum fsm_event event_number);
void fsm_transition(uint16_t *event_flag, enum fsm_event event_number, uint8_t (*action)(void), enum fsm_event next_event, enum fsm_event error_event);

#endif /* FSM_H_ */