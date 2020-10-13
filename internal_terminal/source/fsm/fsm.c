/*
 * fsm.c
 *
 * Created: 2016-02-28 13:02:17
 *  Author: Adam
 */ 

#include <avr/io.h>
#include <avr/wdt.h>
#include "fsm.h"

/* zmienna przechowuj�ca flagi zdarze�, 16 bit�w = 16 flag */
uint16_t *fsm_event_flags = (uint16_t*) &GPIOR1;

/* funkcja ustawiaj�ca flag� zdarzenia */
void fsm_event_flag_set(uint16_t *p_event_flag, enum fsm_event event_number)
{
	*p_event_flag |= (1<<event_number);
}

/* funkcja czyszcz�ca flag� zdarzenia */
void fsm_event_flag_clear(uint16_t *p_event_flag, enum fsm_event event_number)
{
	*p_event_flag &= ~(1<<event_number);
}

/* funkcja realizuj�ca przej�cia pomi�dzy stanami: ( wska�nik do zmiennej z flagami, kolejny numer flagi od 0 do 7, wska�nik do funkcji realizuj�cej akcj� ) */
/*
void fsm_transition(uint16_t *p_event_flag, enum fsm_event event_number, uint8_t (*action)(void), enum fsm_event next_event)
{
	if(*p_event_flag & (1<<event_number))
	{	
		fsm_event_flag_clear(p_event_flag, event_number);
		uint8_t status = action(); 
		if(status)
			if(next_event > fsm_null_event)
				fsm_event_flag_set(p_event_flag, next_event);
	}
}
*/
/* funkcja realizuj�ca przej�cia pomi�dzy stanami: ( wska�nik do zmiennej z flagami, kolejny numer flagi od 0 do 15, wska�nik do funkcji realizuj�cej akcj�, nast�pna flaga do ustawienia je�li ok, nast�pna flaga do ustawienia je�li b��d ) */
void fsm_transition(uint16_t *p_event_flag, enum fsm_event event_number, uint8_t (*action)(void), enum fsm_event next_event, enum fsm_event error_event)
{
	if(*p_event_flag & (1<<event_number))
	{
		wdt_reset();
		fsm_event_flag_clear(p_event_flag, event_number);
		uint8_t status = action();
		if(status)
		{
			if(next_event > fsm_null_event)
			fsm_event_flag_set(p_event_flag, next_event);
		}
		else
		{
			if(error_event > fsm_null_event)
			fsm_event_flag_set(p_event_flag, error_event);
		}
	}
}