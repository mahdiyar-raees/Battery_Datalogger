#ifndef FUNCTION
	#define FUNCTION
	#include "stdio.h"
	#include "string.h"
	#include "stdint.h"
	#include "math.h"
	#include <TYPEDEF.h>
	#include "main.h"
	#include "stm32f1xx_hal.h"


//***********************************************************************
//***************************DEFINE VARIABLE
//***********************************************************************
//***********************************************************************
// system variable
extern			I2C_HandleTypeDef  					hi2c1;
extern			I2C_HandleTypeDef  					hi2c2;
extern			UART_HandleTypeDef 					huart1;
extern			UART_HandleTypeDef 					huart2;
extern			TIM_HandleTypeDef 					htim3;
extern			TIM_HandleTypeDef 					htim2;
extern			CRC_HandleTypeDef 					hcrc;
// uniq variable
extern			master_to_slave_t 	slave_to_master;
extern			master_to_slave_t 			rx_buffer;
extern		  Error_t 						error;
extern			FLAG_t 									flag;
// regular variable
extern			uint8_t 						command_counter;
extern			uint8_t 						current_module; 

extern			unsigned char 			ADSwrite[4];
extern			int16_t 						reading;
extern			uint16_t 						Battery_Voltage[21];
extern			const float 				ADCConv ;
extern			const float 				R ;
extern			uint8_t							str[28];
extern			float 							temp;
extern			float 							temp_real;
extern			float							  Battery_Temperature[2];

//***********************************************************************
//***************************DEFINE FUNCTION 
//***********************************************************************
//***********************************************************************
void				SLAVE_SEND									(void);
void				reset_state									(void);
float 			Temperature1 								(void);
float 			Temperature2 								(void);
uint16_t 		Cell_Voltage 								(void);
void 				delayUS											(uint32_t us);
void 				MUX_Enable 									(uint8_t i);
void				All_MUX_Disable							(void);
void 				Channel_Select							(uint8_t cell);
void 				crc_init										(void);
uint8_t			cal_crc											(uint8_t *data,uint8_t *cal_crc);

#endif