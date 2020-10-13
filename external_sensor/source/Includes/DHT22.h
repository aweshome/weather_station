
#ifndef _DHT22_H_
#define _DHT22_H_

#define DHT22_HOST_INIT_LOW					1000	// Czas stanu niskiego do zainicjowania transmisji (us)
#define DHT22_HOST_INIT_RELEASE				30		// Nominalny czas zwolnienia stanu niskiego (oczekiwanie na odpowiedŸ czujnika)
#define DHT22_HOST_INIT_RELEASE_LOWER_LIMIT	20		// dolna granica
#define DHT22_HOST_INIT_RELEASE_UPPER_LIMIT	200		// górna granica
#define DHT22_RESPONSE_LOW					80		// Nominalny czas stanu niskiego odpowiedzi czujnia
#define DHT22_RESPONSE_LOW_LOWER_LIMIT		75		// dolna granica
#define DHT22_RESPONSE_LOW_UPPER_LIMIT		90		// górna granica
#define DHT22_RESPONSE_RELEASE				80		// Czas zwolnienia stanu niskiego odpowiedzi
#define DHT22_RESPONSE_RELEASE_LOWER_LIMIT	75		// dolna granica
#define DHT22_RESPONSE_RELEASE_UPPER_LIMIT	90		// górna granica
#define DHT22_LOW							50		// Czas stanu niskiego ka¿dego bitu
#define DHT22_LOW_LOWER_LIMIT				48		// dolna granica
#define DHT22_LOW_UPPER_LIMIT				60		// górna granica
#define DHT22_ZERO_HIGH						26		// Czas stanu wysokiego dla bitu "0"
#define DHT22_ZERO_HIGH_LOWER_LIMIT			22		// dolna granica
#define DHT22_ZERO_HIGH_UPPER_LIMIT			35		// górna granica
#define DHT22_ONE_HIGH						70		// Czas stanu wysokiego dla bitu "1"
#define DHT22_ONE_HIGH_LOWER_LIMIT			68		// dolna granica
#define DHT22_ONE_HIGH_UPPER_LIMIT			80		// górna granica

typedef enum
{
	DHT22_IDLE_STATE = 0,
	DHT22_RESPONSE_STATE = 1,
	DHT22_RECEIVE_HUMID_HI_BYTE_STATE = 2,
	DHT22_RECEIVE_HUMID_LO_BYTE_STATE = 3,
	DHT22_RECEIVE_TEMP_HI_BYTE_STATE = 4,
	DHT22_RECEIVE_TEMP_LO_BYTE_STATE = 5,
	DHT22_RECEIVE_CHECKSUM_BYTE_STATE = 6
} DHT22_STATES_t;

typedef enum
{
	DHT_ERROR_NONE = 0,
	DHT_ERROR_HOST_INIT = 1,
	DHT_ERROR_RESPONSE = 2,
	DHT_ERROR_DATA_RECEIVE = 16,
	DHT_ERROR_CHECKSUM = 32
} DHT22_ERROR_t;

/*
	DHT_ERROR_NONE = 0,
	DHT_BUS_HUNG = 1,
	DHT_ERROR_NOT_PRESENT = 2,
	DHT_ERROR_ACK_TOO_LONG = 4,
	DHT_ERROR_SYNC_TIMEOUT = 8,
	DHT_ERROR_DATA_TIMEOUT = 16,
	DHT_ERROR_CHECKSUM = 32
*/

typedef struct
{
	uint8_t humidity_hi;
	uint8_t humidity_lo;
	uint8_t temperature_hi;
	uint8_t temperature_lo;
	uint8_t checksum;
	DHT22_ERROR_t error;
} DHT22_DATA_t;

extern volatile DHT22_STATES_t dht22_state;		// Stan maszyny stanów
extern volatile DHT22_DATA_t dht22_data;		// Dane z czujnika

void DHT22_config(void);
uint8_t DHT22_init_action(void);
uint8_t DHT22_checksum_calculate_action(void);

#endif
