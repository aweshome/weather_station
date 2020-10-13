/*
 * _23lcv1024.c
 *
 * Created: 19.10.2015 08:40:17
 *  Author: Adam
 */ 

#include <avr/io.h>
#include "../Interfaces/spi.h"
#include "../common.h"
#include "23lcv1024.h"

void sram_init(void)
{
	SPI_SSRAM_CS_ON;
	_delay_loop_1(250);
	spi_send_read_byte(INSTR_WRMR);
	spi_send_read_byte(SEQUENTIAL_MODE);
	SPI_SSRAM_CS_OFF;   
}

void sram_write_byte(uint32_t address, uint8_t spi_data) // adres 24 bitowy dla 23LCV1024
{
	SPI_SSRAM_CS_ON;
	spi_send_read_byte(INSTR_WRITE);
	spi_send_read_byte(address>>16);
	spi_send_read_byte(address>>8);
	spi_send_read_byte(address);
	spi_send_read_byte(spi_data); // negacja bajtu powoduje negatyw ekranu
	SPI_SSRAM_CS_OFF;
}

uint8_t sram_read_byte(uint32_t address) // adres 24 bitowy dla 23LCV1024
{
	uint8_t spi_data;
	
	SPI_SSRAM_CS_ON;
	spi_send_read_byte(INSTR_READ);
	spi_send_read_byte(address>>16);
	spi_send_read_byte(address>>8);
	spi_send_read_byte(address);
	spi_data = spi_send_read_byte(0xFF);
	SPI_SSRAM_CS_OFF;
	return spi_data; // negacja bajtu powoduje negatyw ekranu
}