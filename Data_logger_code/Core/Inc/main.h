/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USART2_Pin GPIO_PIN_1
#define USART2_GPIO_Port GPIOA
#define uB_Pin GPIO_PIN_4
#define uB_GPIO_Port GPIOA
#define uA_Pin GPIO_PIN_5
#define uA_GPIO_Port GPIOA
#define uINH5_Pin GPIO_PIN_6
#define uINH5_GPIO_Port GPIOA
#define uINH4_Pin GPIO_PIN_7
#define uINH4_GPIO_Port GPIOA
#define uINH3_Pin GPIO_PIN_0
#define uINH3_GPIO_Port GPIOB
#define uINH2_Pin GPIO_PIN_1
#define uINH2_GPIO_Port GPIOB
#define uINH1_Pin GPIO_PIN_2
#define uINH1_GPIO_Port GPIOB
#define uSCL_Pin GPIO_PIN_10
#define uSCL_GPIO_Port GPIOB
#define uSDA_Pin GPIO_PIN_11
#define uSDA_GPIO_Port GPIOB
#define LED_EMG_Pin GPIO_PIN_3
#define LED_EMG_GPIO_Port GPIOB
#define USART1_Pin GPIO_PIN_5
#define USART1_GPIO_Port GPIOB
#define E2SCL_Pin GPIO_PIN_8
#define E2SCL_GPIO_Port GPIOB
#define E2SDA_Pin GPIO_PIN_9
#define E2SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
