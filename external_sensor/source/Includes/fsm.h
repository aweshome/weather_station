/*
 * fsm.h
 *
 * Created: 2016-02-28 13:02:26
 *  Author: Adam
 */ 


#ifndef FSM_H_
#define FSM_H_

enum fsm_event 
{
	null_event,
	dht22_init_event,
	dht22_checksum_calculate_event,
	adc_init_event,
	radio_prepare_data_event,
	radio_respond_event,
	power_sleep_event,
	pms_read_event,
	pms_prepare_data_event,
	common_condition_1_event,
	common_condition_2_event,
	common_condition_3_event,
	common_condition_4_event,
	common_condition_5_event
};

typedef struct
{
	uint8_t counter1;
	uint8_t flag1;
} FSM_PARAMS_t;

extern volatile FSM_PARAMS_t fsm_params;

extern volatile uint16_t *fsm_event_flags;

void fsm_event_flag_set(volatile uint16_t **event_flag, enum fsm_event event_number);
void fsm_event_flag_clear(volatile uint16_t **event_flag, enum fsm_event event_number);
void fsm_transition(volatile uint16_t **p_event_flag, enum fsm_event event_number, uint8_t (*action)(void), enum fsm_event event_if_true, enum fsm_event event_if_false);



#endif /* FSM_H_ */