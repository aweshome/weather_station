/*
 * komendy_at.c  
 *
 *  Created on: 13-03-2012
 *      Author: Miros�aw Karda�
 */
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "../common.h"
#include "../Interfaces/uart.h"
#include "komendy_at.h"
#include "telnet_menu.h"
#include "../EG9018C/LCD_TEXT/lcd_text.h"
#include "../DS3231/DS3231.h"


#define AT_CNT 7	// ilo� polece� AT

//----------- tablica z poleceniami AT i wska�nikami funkcji do ich obs�ugi --------------------
const TATCMD __flash polecenia_at[AT_CNT] = {
	// { at_cmd } , { wska�nik do funkcji obs�ugi at },
		{"AT", 		at_service},
		{"ATI", 	ati_service},
		{"AT+LED", 	at_led_service},
		{"AT+STIME", at_set_time_service},
		{"AT+SDATE", at_set_date_service},
		{"AT+RST", at_reset_service},
		{"AT+DEBUG", at_debug_service},
};


//----------------- funkcja do analizowania danych odebranych z UART ------------------------------
void parse_uart_data( char * pBuf )
{
	int8_t (*_at_srv)(uint8_t inout, char * data);

	char * cmd_wsk;
	char * reszta;
	uint8_t i=0, len;

	uart_puts("Odebrano komende AT: ");
	uart_putc('[');
	uart_puts( pBuf );
	uart_puts("] - ");

	if ( strpbrk(pBuf, "=?"))	// Szuka pierwszego wyst�pienia znaku (z puli znak�w string2 bez '\0') w �a�cuchu znak�w string1.
	{
		// obs�uga polece� AT we/wy + parametry

		if ( strpbrk(pBuf, "?"))
		{
			// zapytania do uk�adu w postaci: AT+CMD?

			cmd_wsk = strtok_r(pBuf, "?", &reszta);
			len = strlen(cmd_wsk);
			for(i=0;i<AT_CNT;i++)
			{
				if ( len && 0 == strncasecmp_P(cmd_wsk, polecenia_at[i].polecenie_at, len) )
				{
					if( pgm_read_word(polecenia_at[i].polecenie_at) )
					{ // <--- UWAGA! w tek�cie ksi��ki zabrak�o pgm_read_word()
						_at_srv = (void *)pgm_read_word( &polecenia_at[i].at_service );
						if( _at_srv)
						{
							if( _at_srv( 0, reszta ) < 0 ) uart_puts("ERROR\r\n");
						}
					}
					uart_puts("\r\n");
					break;
				}
			}

		}
		else
		{
			// ustawienia uk�adu w postaci: AT+CMD=parametry

			cmd_wsk = strtok_r(pBuf, "=", &reszta);
			len = strlen(cmd_wsk);
			for(i=0;i<AT_CNT;i++)
			{
				if ( len && 0 == strncasecmp_P(cmd_wsk, polecenia_at[i].polecenie_at, len) )
				{
					if( pgm_read_word(polecenia_at[i].polecenie_at) )
					{ // <--- UWAGA! w tek�cie ksi��ki zabrak�o pgm_read_word()
						_at_srv = (void *)pgm_read_word( &polecenia_at[i].at_service );
						if( _at_srv && ! _at_srv( 1, reszta ) ) uart_puts("OK\r\n");
						else uart_puts("ERROR\r\n");
					}
					break;
				}
			}
		}

	}
	else
	{
		// obs�uga polece� AT bez parametr�w

		if( 0 == pBuf[0] )
		{
		//	uart_puts("\r\n");	// reakcja na znak CR lub CRLF z terminala
			telnet_print_main_screen(MAIN_SCREEN_BEGIN, 1);
			telnet_print_update_main(MAIN_SCREEN_BEGIN, 14);
		}
		else
		{
			for(i=0;i<AT_CNT;i++)
			{
				if ( 0 == strncasecmp_P(pBuf, polecenia_at[i].polecenie_at, strlen(pBuf)) )
				{
					if( pgm_read_word(polecenia_at[i].polecenie_at) )
					{ // <--- UWAGA! w tek�cie ksi��ki zabrak�o pgm_read_word()
						_at_srv = (void *)pgm_read_word( &polecenia_at[i].at_service );
						if( _at_srv) _at_srv(2,0);
					}
					break;
				}
			}
		}
	}

	if( AT_CNT == i ) uart_puts("ERROR\r\n");
}



//----------------- obs�uga poszczeg�lnych komend AT ----------------------------------
int8_t at_service(uint8_t inout, char * params)
{
	uart_puts("OK\r\n");
	return 0;
}

int8_t ati_service(uint8_t inout, char * params)
{
	uart_puts("Terminal EG9018C v 2.0\r\n");
	return 0;
}

int8_t at_led_service(uint8_t inout, char * params)
{
	char buff[2];
	uint8_t val;

	if( inout < 2 )
	{
		if( 1 == inout )
		{
			if( params[0] < '0' || params[0] > '9' ) return -1;
//			if( '1' == params[0] ) LCD_ILUM_ON;
//			else LCD_ILUM_OFF;
			switch (params[0])
			{
				case '0': lcd_ilum_timer_init(130); break;
				case '1': lcd_ilum_timer_init(132); break;
				case '2': lcd_ilum_timer_init(134); break;
				case '3': lcd_ilum_timer_init(136); break;
				case '4': lcd_ilum_timer_init(138); break;
				case '5': lcd_ilum_timer_init(140); break;
				case '6': lcd_ilum_timer_init(150); break;
				case '7': lcd_ilum_timer_init(160); break;
				case '8': lcd_ilum_timer_init(180); break;
				case '9': lcd_ilum_timer_init(255); break;
			}
			uart_puts("# OCR0B: ");
			uart_puts(itoa(val=OCR0B, buff, 10));
			uart_putc('#');
		}
	}
	else if( 2 == inout )
	{
		uart_puts("AT+LED=[0-8]\r\n");
	}
	return 0;
}

int8_t at_set_time_service( uint8_t inout, char * params )
{
	char * parm1;
	char * parm2;
	char * parm3;
	uint8_t hh, mm, ss;

	if( 1 == inout )
	{
		if(!strlen(params)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d

		parm1 = strtok(params, ":"); // wy�uskujemy pierwszy parametr do przecinka
		if(!strlen(parm1)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		hh=atoi(parm1); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(hh>=0 && hh<=23) ) return -1; // je�li hh nie mie�ci si� w zakresie od 0 do 23 to b��d

		parm2 = strtok(NULL, ":"); // wy�uskujemy drugi parametr do przecinka
		if(!strlen(parm2)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		mm=atoi(parm2); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(mm>=0 && mm<=59) ) return -1; // je�li mm nie mie�ci si� w zakresie od 0 do 59 to b��d

		parm3 = strtok(NULL, "."); // wy�uskujemy trzeci parametr do przecinka
		if(!strlen(parm1)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		ss=atoi(parm3); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(ss>=0 && ss<=59) ) return -1; // je�li ss nie mie�ci si� w zakresie od 0 do 59 to b��d

		ds3231_set_time(hh, mm, ss); // ustawiamy godzin� w DS3231
	}
	else if( 2 == inout )
	{
		uart_puts("AT+STIME=[0-23]:[0-59]:[0-59].\r\n");
	}
	else
	{
		if( !inout ) return -1;
	}

	return 0;
}

int8_t at_set_date_service( uint8_t inout, char * params )
{
	char * parm1;
	char * parm2;
	char * parm3;
	char * parm4;
	uint8_t year, month, day, dow;

	if( 1 == inout )
	{

		if(!strlen(params)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d

		parm1 = strtok(params, "."); // wy�uskujemy pierwszy parametr do przecinka
		if(!strlen(parm1)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		year=atoi(parm1); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(year>=0 && year<=99) ) return -1; // je�li hh nie mie�ci si� w zakresie od 0 do 23 to b��d

		parm2 = strtok(NULL, "."); // wy�uskujemy drugi parametr do przecinka
		if(!strlen(parm2)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		month=atoi(parm2); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(month>=1 && month<=12) ) return -1; // je�li mm nie mie�ci si� w zakresie od 0 do 59 to b��d

		parm3 = strtok(NULL, "."); // wy�uskujemy trzeci parametr do przecinka
		if(!strlen(parm1)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		day=atoi(parm3); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(day>=1 && day<=31) ) return -1; // je�li ss nie mie�ci si� w zakresie od 0 do 59 to b��d

		parm4 = strtok(NULL, "."); // wy�uskujemy czwarty parametr do przecinka
		if(!strlen(parm4)) return -1; // sprawdzamy czy s� parametry, je�li nie, to b��d
		dow=atoi(parm4); // zamieniamy liczb� ASCII na warto�� dziesi�tn�
		if( !(dow>=1 && dow<=7) ) return -1; // je�li ss nie mie�ci si� w zakresie od 0 do 59 to b��d

		ds3231_set_date(year, month, day, dow); // ustawiamy dat� w DS3231
	}
	else if( 2 == inout )
	{
		uart_puts("AT+SDATE=[0-99].[1-12].[1-31].[1-7].\r\n");
	}
	else
	{
		if( !inout ) return -1;
	}

	return 0;
}

int8_t at_reset_service(uint8_t inout, char * params)
{
	{
		wdt_enable(WDTO_15MS);  	// set  watchdog
		cli();						// disable interrupts
		while(1);					// wait for RESET
	}
	return 0;
}

int8_t at_debug_service(uint8_t inout, char * params)
{
	{
		wdt_disable();
		uart_puts("WATCHDOG DISABLED!\r\n");
	}
	return 0;
}

