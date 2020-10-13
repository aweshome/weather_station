    /*
     * bmp180.h
     *
     *  Created on: 28 kwi 2014
     *  Autor: £ukasz £uczko
     *
     */
     
    #ifndef BMP180_H_
    #define BMP180_H_
     
    #define BMP180_ADDR 0xEE        // Adres I2C
    #define BMP180_MODE 1           // oversampling setting (0-3)
	
	typedef struct
	{
		int AC1, AC2, AC3, B1, B2, MB, MC, MD;
		unsigned int AC4, AC5, AC6;
		long ut, up, B5;
		long bmp180_temp;
		long bmp180_press;
	} BMP180_DATA_t;
     
    void bmp180_init(BMP180_DATA_t *);			// Inicjalizacja czujnika
    void bmp180_getut(BMP180_DATA_t *);			// Odczyt temperatury bez kompensacji
    void bmp180_getup(BMP180_DATA_t *);			// odczyt ciœnienia bez kompensacji
    void bmp180_gett(BMP180_DATA_t *);			// Wylicza temperaturê
    void bmp180_getp(BMP180_DATA_t *);			// Wylicza ciœnienie
     
    #endif /* BMP180_H_ */
