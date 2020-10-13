/*
 * spi.h
 *
 *  Created on: 2 lut 2015
 *      Author: Servis_Krakow1
 */

#ifndef SPI_H_
#define SPI_H_

#define SPI_MOSI_PORT B
#define SPI_MOSI 5
#define SPI_MISO_PORT B
#define SPI_MISO 6
#define SPI_SCK_PORT B
#define SPI_SCK 7

#include <avr/io.h>

//volatile unsigned char spi_data;
void spi_init(void);
unsigned char spi_send_read_byte(uint8_t data);


#endif /* SPI_H_ */
