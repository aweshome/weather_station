/*
 * mkuart.h
 *
 *  Created on: 2010-09-04
 *       Autor: Miros�aw Karda�
 */

#ifndef MKUART_H_
#define MKUART_H_


#define UART_BAUD 115200		// tu definiujemy interesuj�c� nas pr�dko��
#define __UBRR ((F_CPU+UART_BAUD*8UL)/(16UL*UART_BAUD)-1)  // obliczamy UBRR dla U2X=0 - poprawiony wz�r uwzgl�dniaj�cy kwarce nieprzyjazne UART

#define UART_RX_BUF_SIZE 32 // definiujemy bufor o rozmiarze 32 bajt�w
// definiujemy mask� dla naszego bufora
#define UART_RX_BUF_MASK ( UART_RX_BUF_SIZE - 1)

#define UART_TX_BUF_SIZE 2 // definiujemy bufor o rozmiarze 16 bajt�w
// definiujemy mask� dla naszego bufora
#define UART_TX_BUF_MASK ( UART_TX_BUF_SIZE - 1)


extern volatile uint8_t ascii_line;


// deklaracje funkcji publicznych

void USART_Init( uint16_t baud );

int uart_getc(void);
void uart_putc( char data );
void uart_puts(char *s);
void uart_puts_P(const char *s);
void uart_putint(int value, int radix);

char * uart_get_str(char * buf);

void UART_RX_STR_EVENT(char * rbuf);
void register_uart_str_rx_event_callback(void (*callback)(char * pBuf));

#endif /* MKUART_H_ */
