/*
 * komendy_at.h  
 *
 *  Created on: 13-03-2012
 *      Author: Miros³aw Kardaœ
 */

#ifndef KOMENDY_AT_H_
#define KOMENDY_AT_H_

// definicja typu strukturalnego
typedef struct
{
	char polecenie_at[9];
	int8_t (* at_service)(uint8_t inout, char * params);
} TATCMD;

// deklaracje zmiennych zewnêtrznych
extern const TATCMD __flash polecenia_at[];

// deklaracje funkcji
void parse_uart_data( char * pBuf );

int8_t at_service(uint8_t inout, char * params);
int8_t ati_service(uint8_t inout, char * params);
int8_t at_led_service(uint8_t inout, char * params);
int8_t at_set_time_service( uint8_t inout, char * params );
int8_t at_set_date_service( uint8_t inout, char * params );
int8_t at_reset_service(uint8_t inout, char * params);
int8_t at_debug_service(uint8_t inout, char * params);

#endif /* KOMENDY_AT_H_ */
