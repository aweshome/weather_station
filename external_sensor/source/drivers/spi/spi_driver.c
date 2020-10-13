
#include <avr/io.h>
#include <stdbool.h>
#include "spi_driver.h"
#include "avr_compiler.h"
#include "common.h"

void spi_init(void)
{
//	SPIC.CTRL |= SPI_CLK2X_bm;
	SPIC.CTRL |= SPI_ENABLE_bm;
//	SPIC.CTRL |= SPI_DORD_bm;
	SPIC.CTRL |= SPI_MASTER_bm;
	SPIC.CTRL |= SPI_MODE_0_gc;
	SPIC.CTRL |= SPI_PRESCALER_DIV4_gc;
}

uint8_t spi_writereadbyte(uint8_t data)
{
	SPIC.DATA = data;
	while(!(SPIC.STATUS & SPI_IF_bm));
//	SPIC.STATUS = ;
	return SPIC.DATA;
}


