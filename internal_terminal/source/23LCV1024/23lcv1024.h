/*
 * _23lcv1024.h
 *
 * Created: 23.10.2015 23:14:42
 *  Author: Adam
 */ 


#ifndef SRAM_23LCV1024_H_
#define SRAM_23LCV1024_H_

#define INSTR_READ 0x03 // Read data from memory array beginning at selected address
#define INSTR_WRITE 0x02 // Write data to memory array beginning at selected address
#define INSTR_EDIO 0x3B // Enter Dual I/O address
#define INSTR_RSTIO 0xFF // Reset Dual I/O address
#define INSTR_RDMR 0x05 // Read Mode Register
#define INSTR_WRMR 0x01 // Write Mode Register

#define BYTE_MODE 0x00
#define PAGE_MODE 0x80
#define SEQUENTIAL_MODE 0x40

void sram_init(void);
void sram_write_byte(uint32_t address, uint8_t spi_data);
unsigned char sram_read_byte(uint32_t address);



#endif /* SRAM_23LCV1024_H_ */