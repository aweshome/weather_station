/*
 * anemometer.c
 *
 * Created: 15.12.2016 21:52:33
 *  Author: Adam
 */ 

#include <avr/io.h>
#include "anemometer.h"

ANEMOMETER_DATA_t anemometer_data = {.direction=0, .speed=0};