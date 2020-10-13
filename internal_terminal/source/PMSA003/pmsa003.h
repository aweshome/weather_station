/*
 * pmsa003.h
 *
 * Created: 18.02.2018 21:24:00
 *  Author: adamw
 */ 


#ifndef PMSA003_H_
#define PMSA003_H_

typedef enum
{
	DATA_CORRECT = 0,
	WRONG_CRC = 64
} PMS_ERROR_t;

typedef struct 
{
	uint8_t pm1_mass;
	uint8_t pm2_mass;
	uint8_t pm10_mass;
	PMS_ERROR_t error;
} PMSA003_DATA_t;



#endif /* PMSA003_H_ */