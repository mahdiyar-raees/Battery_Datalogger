#ifndef TYPEDEF
	#define TYPEDEF
	#include "define.h"
	
	#include "stdint.h"
	// structure for LCD Vartiable
	
	

typedef  enum
{
	CURR,
	TLEV,
	SLWP,
	SLWN,
	SLW,
}CURRENT_MENU_t;


typedef enum
		{
				MODE_COUNT,
				ACTIVE_ON,
				MODE_PULLS,
				MODE_TOGG,
		}INPUT_UP_DOWN_t;
		
		
typedef	struct
			{
				uint8_t CRC_fault;
				uint8_t BOARD_WAIT_COUNTER;
				uint8_t MASTER_NOT_RESPON;
				
	}Error_t;
		
typedef union
	{
	uint16_t data;
		struct
			{
				uint8_t byte[2];
			}detail;
	}data_to_byte_t;
	


typedef union
	{
	uint32_t FLAG;
		struct
			{
				uint32_t not_this_board:1;
				uint32_t not_master_command:1;
				uint32_t flag_ask_for_data:1;
				uint32_t not_true_packet:1;
			}BIT;
	}FLAG_t;


typedef union
{
uint8_t send_data[master_to_slave_size];
	struct 
		{
			uint8_t start_frame1 ;
			uint8_t start_frame2 ;
			uint8_t command_or_data;
			uint8_t Address;
			uint8_t command;
			uint8_t data[3*22]; 
			//uint8_t CRC[2];
			uint8_t end_frame1;
			uint8_t end_frame2;		
		}detail;
	}master_to_slave_t;


#endif
