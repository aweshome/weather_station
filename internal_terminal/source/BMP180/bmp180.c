/*
     * bmp180.c
     *
     *  Created on: 28 kwi 2014
     *  Autor: £ukasz £uczko
     *
     */
    #include <avr/io.h>
    #include <avr/interrupt.h>
    #include <util/delay.h>
     
    #include "../Interfaces/i2c_twi.h"
    #include "bmp180.h"

     
	void bmp180_init(BMP180_DATA_t * p_data)
	{
		uint8_t buf[22];
		TWI_read_buf( BMP180_ADDR, 0xAA, 22, buf );
		
		p_data->AC1 = ((int) buf[0] <<8 | ((int) buf[1]));
		p_data->AC2 = ((int) buf[2] <<8 | ((int) buf[3]));
		p_data->AC3 = ((int) buf[4] <<8 | ((int) buf[5]));
		p_data->AC4 = ((unsigned int) buf[6] <<8 | ((unsigned int) buf[7]));
		p_data->AC5 = ((unsigned int) buf[8] <<8 | ((unsigned int) buf[9]));
		p_data->AC6 = ((unsigned int) buf[10] <<8 | ((unsigned int) buf[11]));
		p_data->B1 = ((int) buf[12] <<8 | ((int) buf[13]));
		p_data->B2 = ((int) buf[14] <<8 | ((int) buf[15]));
		p_data->MB = ((int) buf[16] <<8 | ((int) buf[17]));
		p_data->MC = ((int) buf[18] <<8 | ((int) buf[19]));
		p_data->MD = ((int) buf[20] <<8 | ((int) buf[21]));
	}
	
	void bmp180_getut(BMP180_DATA_t * p_data)
	{
		//odczyt temperatury bez kompensacji
		uint8_t  buf[2], g=0x2E;
		
		TWI_write_buf( BMP180_ADDR, 0xF4, 1, &g );
		_delay_ms(10); // min. 4.5ms
		TWI_read_buf( BMP180_ADDR, 0xF6, 2, buf );
		p_data->ut = ((long) buf[0] << 8 | ((long) buf[1]));
	}

	void bmp180_gett(BMP180_DATA_t * p_data)
	{
		long x1, x2;
		
	//	bmp180_getut(p_data);
		x1 = ((long)p_data->ut - p_data->AC6) * p_data->AC5 >> 15;
		x2 = ((long)p_data->MC << 11) / (x1 + p_data->MD);
		p_data->B5 = x1 + x2;
		p_data->bmp180_temp = ((p_data->B5 + 8)>>4);
	}

	void bmp180_getup(BMP180_DATA_t * p_data)
	{
		//odczyt cisnienia bez kompensacji
		uint8_t  buf[3], g;
		
		g=0x34+(BMP180_MODE << 6);
		TWI_write_buf( BMP180_ADDR, 0xF4, 1, &g );
		_delay_ms(5 + (3<<BMP180_MODE));
		TWI_read_buf( BMP180_ADDR, 0xF6, 3, buf );
		p_data->up = ((((long) buf[0] <<16) | ((long) buf[1] <<8) | ((long) buf[2])) >> (8-BMP180_MODE)); // wartoœæ cisnienia bez kompensacji
	}

	void bmp180_getp(BMP180_DATA_t * p_data)
	{
		long x1,x2,x3,b3,b6,p;
		unsigned long b4,b7;
		
	//	bmp180_getup(p_data);
		b6 = p_data->B5 - 4000;
		x1 = ( (long)p_data->B2 * (b6 * b6) >> 12) >> 11;	//??
		x2 = ( (long)p_data->AC2 * b6) >> 11;				//??
		x3 = x1 + x2;
		b3 = (((((long)p_data->AC1) * 4 + x3) << BMP180_MODE) + 2) >> 2;
		x1 = ( (long)p_data->AC3 * b6) >> 13;				//??
		x2 = ( (long)p_data->B1 * ((b6 * b6) >> 12)) >> 16;
		x3 = ((x1 + x2) + 2) >> 2;
		b4 = ( p_data->AC4 * (unsigned long)(x3 + 32768)) >> 15;
		b7 = ((unsigned long)p_data->up - b3) * (50000 >> BMP180_MODE);
		p = b7 < 0x80000000 ? (b7 << 1) / b4 : (b7 / b4) << 1;
		x1 = (p >> 8) * (p >> 8);
		x1 = (x1 * 3038) >> 16;
		x2 = (-7357 * p) >> 16;
		p = p + ((x1 + x2 + 3791) >> 4);
		p_data->bmp180_press = p;
	}
