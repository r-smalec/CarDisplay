/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

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
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOA
#define A7_UART_PC_TX_Pin GPIO_PIN_2
#define A7_UART_PC_TX_GPIO_Port GPIOA
#define A2_UART_PC_RX_Pin GPIO_PIN_3
#define A2_UART_PC_RX_GPIO_Port GPIOA
#define A3_DISP_CS_Pin GPIO_PIN_4
#define A3_DISP_CS_GPIO_Port GPIOA
#define D3_DISP_RST_Pin GPIO_PIN_0
#define D3_DISP_RST_GPIO_Port GPIOB
#define D9_SPEED_SENS_Pin GPIO_PIN_8
#define D9_SPEED_SENS_GPIO_Port GPIOA
#define D1_UART_ECU_TX_Pin GPIO_PIN_9
#define D1_UART_ECU_TX_GPIO_Port GPIOA
#define D0_UART_ECU_RX_Pin GPIO_PIN_10
#define D0_UART_ECU_RX_GPIO_Port GPIOA
#define D2_DISP_BL_Pin GPIO_PIN_12
#define D2_DISP_BL_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define D13_DISP_CLK_Pin GPIO_PIN_3
#define D13_DISP_CLK_GPIO_Port GPIOB
#define D12_SWITCH_Pin GPIO_PIN_4
#define D12_SWITCH_GPIO_Port GPIOB
#define D11_DISP_DIN_Pin GPIO_PIN_5
#define D11_DISP_DIN_GPIO_Port GPIOB
#define D4_DISP_DC_Pin GPIO_PIN_7
#define D4_DISP_DC_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define SWITCH_PIN     	D12_SWITCH_GPIO_Port, D12_SWITCH_Pin

typedef struct {
	uint16_t RPM;
	int8_t IAT;
	float batt_v;
	float oil_bar;
	uint8_t oil_temp;
	int16_t CLT;
	float lambda;
} ecu_val;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
