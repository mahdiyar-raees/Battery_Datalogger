#include <FUNCTION.h>

void delayUS(uint32_t us)
	{   // Sets the delay in microseconds.
		uint32_t ms_value = us;
		while (ms_value>0)
			{
				__HAL_TIM_SET_COUNTER(&htim2,0);  // set the counter value a 0
				while (__HAL_TIM_GET_COUNTER(&htim2) < 1000);
				ms_value--;
			}
	}	


void	PC_SEND(void)
{

	HAL_UART_Transmit(&huart2, master_to_pc.send_data, master_to_pc_size,100);
}
void	SLAVE_SEND(void )
{
	USART_T;
	delayUS(100);
	HAL_UART_Transmit(&huart3, master_to_slave.send_data, master_to_slave_size,100);
	USART_R;
}
void 	reset_state	(void)
	{
		command_counter =0;
		
	}
void request_data(void)
	{
		
		if(master_to_slave.detail.Address ==30)
			{
				master_to_slave.detail.Address =0;
			}
		else
			{
				for(uint8_t cnt= master_to_slave.detail.Address ; cnt<30; cnt++)
					{
						if(available_board[cnt] == 1)
							{
								master_to_slave.detail.Address = cnt;
								break;
							}
						else if(cnt ==29 ) // All voard select there is no board left
							{
								for(uint8_t cnt= 0 ; cnt<30; cnt++)	
									{
										if(available_board[cnt] == 1)
											{
												master_to_slave.detail.Address = cnt;
												break;
											}
									}
							}
					}
					
					master_to_slave.detail.command=0;
					// change type of RS485
					#if SLAVE_WAIT_TIME
						TIM3->CNT=0;
						HAL_TIM_Base_Start_IT(&htim3);
					#endif
					command_counter=0;
					flag.BIT.flag_ask_for_data=1;
					tx_CRC_CALCULATE = HAL_CRC_Calculate(&hcrc,(uint32_t*)master_to_slave.detail.data,66);
					SLAVE_SEND();
					// change type of RS485 to recieve		
			 }
	}