/*
 * anemometer.h
 *
 * Created: 15.12.2016 21:52:45
 *  Author: Adam
 */ 


#ifndef ANEMOMETER_H_
#define ANEMOMETER_H_

typedef struct  
{
	uint8_t speed;
	uint8_t direction;
} ANEMOMETER_DATA_t;

extern ANEMOMETER_DATA_t anemometer_data;



#endif /* ANEMOMETER_H_ */