#ifndef FUNCTION
	#define FUNCTION
	#include "main.h"
	#include "stdio.h"
	#include "string.h"
	#include "stdint.h"
	#include <TYPEDEF.h>
	#include <SEMIFUNCTION.h>
	#include "stm32f1xx_hal.h"



//***************************DEFINE VARIABLE
extern			I2C_HandleTypeDef  					hi2c1;
extern			UART_HandleTypeDef 					huart1;
extern			UART_HandleTypeDef 					huart2;
extern			UART_HandleTypeDef 					huart3;
extern			TIM_HandleTypeDef 					htim2;
extern			TIM_HandleTypeDef 					htim3;
extern			CRC_HandleTypeDef 					hcrc;

//					type variable
extern			master_to_pc_t							master_to_pc;
extern			master_to_slave_t 					master_to_slave;
extern			master_to_slave_t 							rx_buffer;
extern			const	uint8_t								available_board[30];	 
extern			FLAG_t										  flag;
extern			uint8_t 										slave_board_num;
extern			uint8_t 										command_counter;
extern			uint8_t 										current_module; 
extern			Error_t											Error;	
extern			uint32_t										rx_CRC_CALCULATE;
extern			uint32_t										tx_CRC_CALCULATE;	
//***************************DEFINE FUNCTION 
void				SLAVE_SEND									(void);
void				PC_SEND											(void);
void 				reset_state									(void);
void 				request_data								(void);	
void 				delayUS											(uint32_t us);


#endif