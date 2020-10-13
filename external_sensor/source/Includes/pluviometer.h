/*
 * pluviometer.h
 *
 * Created: 19.03.2018 23:16:30
 *  Author: adamw
 */ 


#ifndef PLUVIOMETER_H_
#define PLUVIOMETER_H_

typedef struct
{
	uint8_t mmH2O_per_15min;
} PLUVIOMETER_DATA_t;

extern volatile PLUVIOMETER_DATA_t pluviometer_data;

#endif /* PLUVIOMETER_H_ */