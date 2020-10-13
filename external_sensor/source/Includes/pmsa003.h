/*
 * pmsa003.h
 *
 * Created: 11.01.2018 22:43:12
 *  Author: adamw
 */ 


#ifndef PMSA003_H_
#define PMSA003_H_

#define PMS_PORT PORTD
#define PMS_TX_PIN PIN7_bm		// PMSA003 PIN7
#define PMS_RX_PIN PIN6_bm		// PMSA003 PIN9

/*
	HOST PROTOCOL
	
		1		|		2		|		3	|	4		|	5		|		6		|		7		|
	START BYTE	|	START BYTE	|	COMMAND	|	DATA1	|	DATA2	|	VERIFY BYTE	|	VERIFY BYTE	|
		0x42	|	0x4D		|	CMD		|	DATAH	|	DATAL	|	LRCH		|	LRCL		|
*/

#define PMS_START_BYTE_1 0x42
#define PMS_START_BYTE_2 0x4D
#define PMS_CMD_PASSIVE_READ 0xE2
#define PMS_CMD_CHANGE_MODE 0xE1	// DATAL: 0 - passive, DATAL: 1 - active
#define PMS_CMD_VALUE_PASSIVE 0x00
#define PMS_CMD_VALUE_ACTIVE 0x01
#define PMS_CMD_SLEEP_SET 0xE4		// DATAL: 0 - sleep, DATAL: 1 - wakeup
#define PMS_CMD_VALUE_SLEEP 0x00
#define PMS_CMD_VALUE_WAKEUP 0x01

#define PMS_REQUEST_BYTES_QUANTITY 7
#define PMS_ANSWER_BYTES_QUANTITY 32

typedef enum
{
	DATA_CORRECT = 0,
	WRONG_CRC = 64
} PMS_ERROR_t;

typedef struct  
{
	uint8_t pm_1_0_concentr_lo;
	uint8_t pm_2_5_concentr_lo;
	uint8_t pm_10_concentr_lo;
	PMS_ERROR_t error;
} PMS_PM_DATA_t;

enum pms_request_structure
{
	START_BYTE_1,
	START_BYTE_2,
	COMMAND,
	DATA_H,
	DATA_L,
	VERIFY_BYTE_H,
	VERIFY_BYTE_L	
};

enum pms_response_structure
{
	START_CHAR_1,
	START_CHAR_2,
	FRAME_LENGTH_H,
	FRAME_LENGTH_L,
	PM_1_0_CONCENTR_STANDARD_H,
	PM_1_0_CONCENTR_STANDARD_L,
	PM_2_5_CONCENTR_STANDARD_H,
	PM_2_5_CONCENTR_STANDARD_L,
	PM_10_CONCENTR_STANDARD_H,
	PM_10_CONCENTR_STANDARD_L,
	PM_1_0_CONCENTR_ATMOSPERIC_H,
	PM_1_0_CONCENTR_ATMOSPERIC_L,
	PM_2_5_CONCENTR_ATMOSPERIC_H,
	PM_2_5_CONCENTR_ATMOSPERIC_L,
	PM_10_CONCENTR_ATMOSPERIC_H,
	PM_10_CONCENTR_ATMOSPERIC_L,
	PARTICLES_0_3UM_NR_H,
	PARTICLES_0_3UM_NR_L,
	PARTICLES_0_5UM_NR_H,
	PARTICLES_0_5UM_NR_L,
	PARTICLES_1_0UM_NR_H,
	PARTICLES_1_0UM_NR_L,
	PARTICLES_2_5UM_NR_H,
	PARTICLES_2_5UM_NR_L,
	PARTICLES_5_0UM_NR_H,
	PARTICLES_5_0UM_NR_L,
	PARTICLES_10UM_NR_H,
	PARTICLES_10UM_NR_L,
	RESERVED_H,
	RESERVED_L,
	CRC_H,
	CRC_L
};
/*
typedef struct  
{
	uint8_t start_char_1;
	uint8_t start_char_2;
	uint8_t frame_length_h;
	uint8_t frame_length_l;
	uint8_t pm_1_0_concentr_standard_h;
	uint8_t pm_1_0_concentr_standard_l;
	uint8_t pm_2_5_concentr_standard_h;
	uint8_t pm_2_5_concentr_standard_l;
	uint8_t pm_10_concentr_standard_h;
	uint8_t pm_10_concentr_standard_l;
	uint8_t pm_1_0_concentr_atmosperic_h;
	uint8_t pm_1_0_concentr_atmosperic_l;
	uint8_t pm_2_5_concentr_atmosperic_h;
	uint8_t pm_2_5_concentr_atmosperic_l;
	uint8_t pm_10_concentr_atmosperic_h;
	uint8_t pm_10_concentr_atmosperic_l;
	uint8_t particles_0_3um_nr_h;
	uint8_t particles_0_3um_nr_l;
	uint8_t particles_0_5um_nr_h;
	uint8_t particles_0_5um_nr_l;
	uint8_t particles_1_0um_nr_h;
	uint8_t particles_1_0um_nr_l;
	uint8_t particles_2_5um_nr_h;
	uint8_t particles_2_5um_nr_l;
	uint8_t particles_5_0um_nr_h;
	uint8_t particles_5_0um_nr_l;
	uint8_t particles_10um_nr_h;
	uint8_t particles_10um_nr_l;
	uint8_t reserved_h;
	uint8_t reserved_l;
	uint8_t crc_h;
	uint8_t crc_l;
} PMS_BYTES_t;

typedef union
{
	uint8_t pms_response_frame[32];
	PMS_BYTES_t pms_response_bytes;	
} PMS_DATA_t;
*/
void PMS_USART_init(void);
void PMS_send_request(uint8_t * data_frame, uint8_t command, uint8_t data);
void PMS_set_passive_mode(void);
void PMS_sleep_mode(bool state);
uint8_t PMS_read_action(void);
uint8_t PMS_prepare_data_action(void);

extern PMS_PM_DATA_t pms_pm_data;
extern uint8_t pms_request_frame[];
extern uint8_t pms_answer_frame[];

#endif /* PMSA003_H_ */