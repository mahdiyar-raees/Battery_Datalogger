/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
	#include <TYPEDEF.h>
	#include <FUNCTION.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern 	uint8_t 								command_counter;
extern	master_to_slave_t 			rx_buffer;
extern	FLAG_t 									flag;
extern  Error_t 								error;
extern	master_to_slave_t 			slave_to_master;
extern	uint32_t								rx_CRC_CALCULATE;
extern	uint32_t								tx_CRC_CALCULATE;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
/* USER CODE BEGIN EV */
void USART_RX(uint8_t x);
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	USART_RX(USART1->DR);
	return;
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void USART_RX(uint8_t x)
	{
	TIM3->CNT =0;	
		 if(flag.BIT.flag_ask_for_data)
			{
				if(command_counter ==0)
					{
						if(x == slave_first_frame_1)
							{
								#if wait_time_for_master
									HAL_TIM_Base_Start_IT(&htim3);
								#endif
								command_counter++;
								rx_buffer.send_data[0] = x; 
							}
						else // fault
							{
								command_counter=0;
								
							}
					}
				else if(command_counter ==1)
					{
						if(x == slave_first_frame_2)
							{
								command_counter++;
								rx_buffer.send_data[1] = x; 
							}
						else // fault
							{
								command_counter=0;
							}
					}
				else if(command_counter ==2)
				{
						command_counter++;
						if(x == 1)
							{
								rx_buffer.send_data[2] = 1; 
								flag.BIT.not_master_command =0;
							}
						else
							{
								flag.BIT.not_master_command =1;
							}
				}
				else	if(command_counter ==3)
				{
						command_counter++;
						if(x == SLAVE_ADDRESS)
							{
								rx_buffer.send_data[3] = x; 
								flag.BIT.not_this_board=0;
							}
						else
							{
								flag.BIT.not_this_board =1;
							}
				}
				else
				{
					rx_buffer.send_data[command_counter] = x;
					command_counter++;
					if(command_counter ==master_to_slave_size)
						{
							//cheak CRC and footer
							flag.BIT.flag_ask_for_data =0;
							command_counter=0;
//							rx_CRC_CALCULATE = HAL_CRC_Calculate(&hcrc,(uint32_t*)rx_buffer.detail.data,66);
							uint8_t condition =0;
							condition = rx_buffer.send_data[master_to_slave_size-2] == slave_second_frame_1 & rx_buffer.send_data[master_to_slave_size-1] == slave_second_frame_2;
							if(/*CRC_cheak_func && */condition )
									{
										if((flag.BIT.not_master_command+flag.BIT.not_this_board) ==0)
											{
												// true command
												switch(rx_buffer.send_data[4])
													{
														case 0:// get_data
															{
																data_to_byte_t		data_to_byte;
																for(register uint8_t fast_cnt =0; fast_cnt<20; fast_cnt++)
																	{
																		data_to_byte.data = Battery_Voltage[fast_cnt];
																		slave_to_master.detail.data[3*fast_cnt +1] = data_to_byte.detail.byte[0];
																		slave_to_master.detail.data[3*fast_cnt +2] = data_to_byte.detail.byte[1];
																	}
															//	tx_CRC_CALCULATE = HAL_CRC_Calculate(&hcrc,(uint32_t*)slave_to_master.detail.data,66);
																SLAVE_SEND();
																reset_state();
																
															}
															return;
														default:
															{
																flag.BIT.not_true_packet=1;
																reset_state();
															}
															return;
													}
													
											}
										else
											{
												error.BOARD_WAIT_COUNTER++;
												reset_state();
												
											}
									}
								else
									{
										error.CRC_fault++;
										reset_state();
									}
						}
				}
			}
	}
/* USER CODE END 1 */
