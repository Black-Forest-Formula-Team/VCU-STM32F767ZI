/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum
{
	  /**
	   * success status.
	   */
	  STATUS_OK,
	  /**
	   * idle status.
	   */
	  STATUS_IDLE,
	  /**
	   * busy status.
	   */
	  STATUS_BUSY,
	  /**
	   * generic fail status.
	   */
	  STATUS_FAIL,
	  /**
	   * invalid argument status.
	   */
	  STATUS_ARGUMENT_INVALID,
}vcu_status_t;


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
#define BOTS_Pin GPIO_PIN_1
#define BOTS_GPIO_Port GPIOF
#define HVOK_IN_Pin GPIO_PIN_2
#define HVOK_IN_GPIO_Port GPIOF
#define HV_unlock_Pin GPIO_PIN_3
#define HV_unlock_GPIO_Port GPIOF
#define Throttle_IN1_Pin GPIO_PIN_0
#define Throttle_IN1_GPIO_Port GPIOA
#define Throttle_IN2_Pin GPIO_PIN_1
#define Throttle_IN2_GPIO_Port GPIOA
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define INV1_RX_Pin GPIO_PIN_12
#define INV1_RX_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define SysEl_RX_Pin GPIO_PIN_11
#define SysEl_RX_GPIO_Port GPIOA
#define SysEl_TX_Pin GPIO_PIN_12
#define SysEl_TX_GPIO_Port GPIOA
#define INV2_TX_Pin GPIO_PIN_6
#define INV2_TX_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
