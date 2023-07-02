
#ifndef SEMIFUNCTION
	#define SEMIFUNCTION
	/*--------- Select A -------*/
	#define A0		HAL_GPIO_WritePin(uA_GPIO_Port, uA_Pin, GPIO_PIN_RESET)
	#define A1		HAL_GPIO_WritePin(uA_GPIO_Port, uA_Pin, GPIO_PIN_SET)
	/*--------- Select B -------*/
	#define B0		HAL_GPIO_WritePin(uB_GPIO_Port, uB_Pin, GPIO_PIN_RESET)
	#define B1		HAL_GPIO_WritePin(uB_GPIO_Port, uB_Pin, GPIO_PIN_SET)
	/*--------- MUX Enable -------*/
	#define MUX1_Enable HAL_GPIO_WritePin(uINH1_GPIO_Port, uINH1_Pin, GPIO_PIN_SET)
	#define MUX2_Enable HAL_GPIO_WritePin(uINH2_GPIO_Port, uINH2_Pin, GPIO_PIN_SET)
	#define MUX3_Enable HAL_GPIO_WritePin(uINH3_GPIO_Port, uINH3_Pin, GPIO_PIN_SET)
	#define MUX4_Enable HAL_GPIO_WritePin(uINH4_GPIO_Port, uINH4_Pin, GPIO_PIN_SET)
	#define MUX5_Enable HAL_GPIO_WritePin(uINH5_GPIO_Port, uINH5_Pin, GPIO_PIN_SET)
	/*--------- MUX Disable -------*/
	#define MUX1_Disable HAL_GPIO_WritePin(uINH1_GPIO_Port, uINH1_Pin, GPIO_PIN_RESET)
	#define MUX2_Disable HAL_GPIO_WritePin(uINH2_GPIO_Port, uINH2_Pin, GPIO_PIN_RESET)
	#define MUX3_Disable HAL_GPIO_WritePin(uINH3_GPIO_Port, uINH3_Pin, GPIO_PIN_RESET)
	#define MUX4_Disable HAL_GPIO_WritePin(uINH4_GPIO_Port, uINH4_Pin, GPIO_PIN_RESET)
	#define MUX5_Disable HAL_GPIO_WritePin(uINH5_GPIO_Port, uINH5_Pin, GPIO_PIN_RESET)
	/*--------- LED EMG -------*/
	#define EMG_OFF HAL_GPIO_WritePin(LED_EMG_GPIO_Port, LED_EMG_Pin, GPIO_PIN_RESET)
	#define EMG_ON	HAL_GPIO_WritePin(LED_EMG_GPIO_Port, LED_EMG_Pin, GPIO_PIN_SET)
	#define EMG_Toggle	HAL_GPIO_TogglePin(LED_EMG_GPIO_Port, LED_EMG_Pin)
	/*--------- RS485-1 -------*/
	#define USART1_T		HAL_GPIO_WritePin(USART1_GPIO_Port, USART1_Pin, GPIO_PIN_SET)
	#define USART1_R		HAL_GPIO_WritePin(USART1_GPIO_Port, USART1_Pin, GPIO_PIN_RESET)
	/*--------- RS485-2 -------*/
	#define USART2_T		HAL_GPIO_WritePin(USART2_GPIO_Port, USART2_Pin, GPIO_PIN_SET)
	#define USART2_R	HAL_GPIO_WritePin(USART2_GPIO_Port, USART2_Pin, GPIO_PIN_RESET)
	
#endif
