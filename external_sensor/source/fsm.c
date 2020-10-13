/*
 * fsm.c
 *
 * Created: 2016-02-28 13:02:17
 *  Author: Adam
 */ 

#include <avr/io.h>
#include "wdt_driver.h"
#include "fsm.h"

/* wskaŸnik na rejestr ogólnego przeznaczenia przechowuj¹cy flagi zdarzeñ, 16 bitów = 16 flag */
volatile uint16_t * fsm_event_flags = (uint16_t *)&GPIO0;

/* struktura zmiennych kontroluj¹cych stan maszyny stanów */
volatile FSM_PARAMS_t fsm_params = {.counter1 = 0, .flag1 = 0};

/* funkcja ustawiaj¹ca flagê zdarzenia */
void fsm_event_flag_set(volatile uint16_t **p_event_flag, enum fsm_event event_number)
{
	**p_event_flag |= (1<<event_number);
}

/* funkcja czyszcz¹ca flagê zdarzenia */
void fsm_event_flag_clear(volatile uint16_t **p_event_flag, enum fsm_event event_number)
{
	**p_event_flag &= ~(1<<event_number);
}

/* funkcja realizuj¹ca przejœcia pomiêdzy stanami: ( wskaŸnik do zmiennej z flagami, kolejny numer flagi od 0 do 15, wskaŸnik do funkcji realizuj¹cej akcjê ) */
void fsm_transition(volatile uint16_t **p_event_flag, enum fsm_event event_number, uint8_t (*action)(void), enum fsm_event event_if_true, enum fsm_event event_if_false)
{
	if(**p_event_flag & (1<<event_number))
	{	
		fsm_event_flag_clear(p_event_flag, event_number);
		uint8_t status = action(); 
		if(status)
		{
			if(event_if_true > null_event)
				fsm_event_flag_set(p_event_flag, event_if_true);
		}
		else
		{
			if(event_if_false > null_event)
				fsm_event_flag_set(p_event_flag, event_if_false);
		}
	}
	
	WDT_Reset();
}