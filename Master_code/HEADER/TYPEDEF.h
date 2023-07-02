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
				uint8_t CRC_fault:1;
				uint8_t NOT_CORRECT_SETTING:1;
				uint8_t board_not_respond:1;	
	}Error_t;
		

	


typedef union
	{
	uint32_t FLAG;
		struct
			{
				uint32_t not_slave_command:1;
				uint32_t not_correct_address:1;
				uint32_t get_command_fault:1;
				uint32_t flag_ask_for_data:1;
			}BIT;
	}FLAG_t;


typedef union
{
uint8_t send_data[master_to_slave_size];
	struct 
		{
			uint8_t start_frame1 ;
			uint8_t start_frame2 ;
			uint8_t slave_or_master;
			uint8_t Address;
			uint8_t command;
			uint8_t data[3*22]; 
			//uint8_t CRC[2];
			uint8_t end_frame1;
			uint8_t end_frame2;		
		}detail;
	}master_to_slave_t;

typedef union
{
uint8_t send_data[master_to_pc_size];
	struct 
		{
			uint8_t start_frame1;
			uint8_t start_frame2;
			uint8_t start_frame3;
			uint8_t module_num;
			uint8_t data[3*22]; 
			//uint8_t CRC[2];
			uint8_t end_frame1;
			uint8_t end_frame2;	
			uint8_t end_frame3;				
		}detail;
	}master_to_pc_t;
#endif
