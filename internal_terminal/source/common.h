/*
 * common.h
 *
 *  Created on: 5 lut 2015
 *      Author: Servis_Krakow1
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <avr/wdt.h>
#include "DS3231/ds3231.h"
#include "DHT22/dht22.h"
#include "BMP180/bmp180.h"
#include "PMSA003/pmsa003.h"
//#include "nRF24L01/radio.h"


// ******************* definicje

#define DEBUGENABLED 1

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define LCD_ILUM_PORT B
#define LCD_ILUM 4

#define SPI_SSRAM_CS_PORT B
#define SPI_SSRAM_CS 0

#define NRF24L01_CSN_PORT C
#define NRF24L01_CSN 2

#define RADIO_IRQ_PORT C
#define RADIO_IRQ 4

#define DS3231_SQW_PORT B // port INT2 jako wejœcie dla DS3231 SQW
#define DS3231_SQW 2

//#define LCD_ILUM_ON (PORT(LCD_ILUM_PORT) |= (1<<LCD_ILUM))
//#define LCD_ILUM_OFF (PORT(LCD_ILUM_PORT) &= ~(1<<LCD_ILUM))
//#define LCD_ILUM_SWITCH (PORT(LCD_ILUM_PORT) ^= (1<<LCD_ILUM))

#define SPI_SSRAM_CS_ON PORT(SPI_SSRAM_CS_PORT) &= ~(1<<SPI_SSRAM_CS)
#define SPI_SSRAM_CS_OFF PORT(SPI_SSRAM_CS_PORT) |= (1<<SPI_SSRAM_CS)

#define nrf24l01_CSNhi PORT(NRF24L01_CSN_PORT) |= (1<<NRF24L01_CSN)
#define nrf24l01_CSNlo PORT(NRF24L01_CSN_PORT) &= ~(1<<NRF24L01_CSN)

#define RADIO_IRQ_READ (PIN(RADIO_IRQ_PORT) & (1<<RADIO_IRQ))

#define SENSORS_T1_QUANTITY 1	// iloœæ czujników (modu³ów radowych slave) typu 1
#define SENSORS_T2_QUANTITY 0	// iloœæ czujników (modu³ów radowych slave) typu 2

#define LCD_ILUM_DAY 255
#define LCD_ILUM_NIGHT 175

#define LCD_PREPARE_FOREGROUND_EV 0
//#define LCD_REFRESH_EV 4
//#define RADIO_CHECK_EV 10
//#define SENSORS_READ_EV 45
//#define SENSORS_STRINGS_EV 50
//#define CHECK_STACK_EV 30



// ******************* definicje

// Dane na potrzeby rysowania wykresów

typedef struct
{
	int8_t value[144];		// wartoœci co 15 minut przez 36 godzin
	int8_t max_value;
	int8_t min_value;
	char max_value_string[10];
	char min_value_string[10];
} VALUE_DIAGRAM_t;

typedef struct
{
	uint8_t rst_status;
	uint8_t sensors_status;
	uint8_t flags;
	uint8_t supply_voltage_integral;
	uint8_t supply_voltage_decimal;
	char rst_status_string[20];			/// "RST FLAG: BROWN-OUT"
	char supply_voltage_string[12];	// "VCC: 3,35V"
} SENSORS_SYS_DATA_t;

typedef struct  
{
	DHT22_DATA_t data;
	DHT22_ERROR_t error;
	uint8_t temperature_int_value;
	uint8_t humidity_int_value;
	VALUE_DIAGRAM_t temperature_diag;
	VALUE_DIAGRAM_t humidity_diag;
	char temperature_string[8];			// "-25.5*C" - 8 znaków
	char humidity_string[7];			// "47.5 %" - 7 znaków
	char error_string[26];				// "DHT: przekroczony czas danych"
} DHT22_SENSOR_DATA_t;

typedef struct
{
	BMP180_DATA_t bmp180_value;
//	BMP180_DATA_t pressure_value;
//	uint8_t pressure_int_value;
	VALUE_DIAGRAM_t pressure_diag;
	char pressure_string[12];			// 1013.25 hPa - 12 znaków
	char temperature_string[7];			// 25.5*C - 7 znaków
} BMP180_SENSOR_DATA_t;

typedef struct
{
	DS3231_DATETIME_t datetime_value;
	DS3231_TEMP_t temperature_value;
	char time_string[9];				// 22.22.22 - 9 znaków
	char date_string[11];				// 12.02.1984 - 11 znaków
	char day_string[13];				// poniedzia³ek - 13 znaków
	char temperature_string[8];			// 25.5*C - 7 znaków
} DS3231_SENSOR_DATA_t;

typedef struct  
{
	uint8_t speed_value;
	uint8_t direction_value;	// 0-31, 32-63, 64-95, 96-127, 128-159, 160-191, 192-223, 224-255
	VALUE_DIAGRAM_t speed_diag;
	char speed_string[9];		// "99.9 m/s" - 9 znaków
	char direction_string[];	// "N", "W", "S", "E", "NW", "NE", "SW", "SE" - 3 znaki
} ANEMOMETER_SENSOR_DATA_t;

typedef struct
{
	PMSA003_DATA_t pms_value;
	VALUE_DIAGRAM_t caqi_diag;
	uint16_t pm1_percent;
	uint16_t pm2_percent;
	uint16_t pm10_percent;
	char pm1_string[14];		// "2000% PM1"
	char pm2_string[14];		// "2000% PM2.5"
	char pm10_string[14];		// "1000% PM10"
	char caqi_string[4];		// "100"
} PMS_SENSOR_DATA_t;

typedef struct
{
	uint8_t mmH2O_value;
	VALUE_DIAGRAM_t mmH2O_diag;
	char mmH2O_string[10];			// "255 mmH20"
} PLUVIOMETER_SENSOR_DATA_t;

// Czujnik typu 1: zewnêtrzny temp + wilg + pluw

typedef struct
{
	SENSORS_SYS_DATA_t system_data;
	DHT22_SENSOR_DATA_t dht22_data;
//	ANEMOMETER_SENSOR_DATA_t anemometer_data;
	PMS_SENSOR_DATA_t pms_data;
	PLUVIOMETER_SENSOR_DATA_t pluviometer_data;
	const uint8_t read_period_min;			// okres odczytu (1 - 60 minut)
	char timestamp[9];						// TYMCZASOWE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
} EXTERNAL_SENSOR_TYPE1_DATA_t;

// ******************* zmienne

//extern uint8_t _end;
//extern uint8_t __stack;				// deklaracja symboli stosu

extern EXTERNAL_SENSOR_TYPE1_DATA_t external_t1_sensor[SENSORS_T1_QUANTITY];
extern DHT22_SENSOR_DATA_t dht22_internal_sensor;
extern DS3231_SENSOR_DATA_t ds3231_internal_sensor;
extern BMP180_SENSOR_DATA_t bmp180_internal_sensor;

// ******************* funkcje

void _StackPaint(void)  __attribute__ ((naked)) __attribute__ ((section (".init1")));	// wype³nienie pamiêci znacznikami
uint16_t StackCount(void);		// zliczenie znaczników/bajtów wolnej pamiêci stosu

void main_port_init(void);
void interrupts_init(void);
void timers_on(void);
void lcd_ilum_timer_init(uint8_t duty_cycle);
void lcd_ilum_change(uint8_t duty_cycle);

//void common_check_stack_event(GPIO_flags_t* const task_flag);
//void common_read_sensors_event(GPIO_flags_t* task_flag);
//void common_prepare_sensors_strings_event(GPIO_flags_t* task_flag);
//void common_prepare_datetime_strings_event(GPIO_flags_t* task_flag);

uint8_t common_check_stack_action(void);
uint8_t common_read_sensors_action(void);
uint8_t common_prepare_sensors_strings_action(void);
uint8_t common_prepare_ext_system_strings_action(void);
uint8_t common_prepare_datetime_strings_action(void);
uint8_t common_lcd_ilum_change_action(void);

void common_read_internal_sensors(void);
void common_read_external_sensors(void);
void common_prepare_sensors_strings(void);
void common_prepare_datetime_strings(void);
void common_prepare_ext_system_strings(void);

void common_prepare_voltage_string(SENSORS_SYS_DATA_t *data);
void common_prepare_status_string(SENSORS_SYS_DATA_t *data);

void ds3231_prepare_time_string(DS3231_SENSOR_DATA_t *data);
void ds3231_prepare_date_string(DS3231_SENSOR_DATA_t *data);
void ds3231_prepare_day_string(DS3231_SENSOR_DATA_t *data);
void ds3231_prepare_temp_string(DS3231_SENSOR_DATA_t *data);

void bmp180_prepare_temp_string(BMP180_SENSOR_DATA_t *data);
void bmp180_prepare_press_string(BMP180_SENSOR_DATA_t *data);

void dht22_prepare_temp_string(DHT22_SENSOR_DATA_t *data);
void dht22_prepare_humid_string(DHT22_SENSOR_DATA_t *data);
void dht22_prepare_error_string(DHT22_SENSOR_DATA_t *error);

void pms_prepare_pm_strings(PMS_SENSOR_DATA_t *data);

void pluviometer_prepare_strings(PLUVIOMETER_SENSOR_DATA_t *data);


#endif /* COMMON_H_ */
