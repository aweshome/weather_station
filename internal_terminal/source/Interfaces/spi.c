/*
 * spi.c
 *
 *  Created on: 2 lut 2015
 *      Author: Servis_Krakow1
 */


#include "spi.h"
#include "../common.h"


void spi_init(void)
{
   DDR(SPI_MOSI_PORT) |= (1<<SPI_MOSI);
   DDR(SPI_SCK_PORT) |= (1<<SPI_SCK);
   DDR(SPI_MISO_PORT) &= ~(1<<SPI_MISO);

   SPCR |= (1<<SPE) | (1<<MSTR); // Master
   SPSR |= (1<<SPI2X); // osc/2
}

uint8_t spi_send_read_byte(uint8_t data)
{
	SPDR = data;
	while (!(SPSR & (1<<SPIF))); // Wait for transmission complete
	return SPDR;
}





