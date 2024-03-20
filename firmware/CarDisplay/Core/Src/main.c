/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "disp_conf.h"
#include "disp_gui.h"
#include "image.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi3;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI3_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define DISP_ACTIVE

ecu ecuVal;
dev_state devState;
vehicle vehicleVal;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void logoScreenDisplay();
void paramScreenDisplay();
void gearboxScreenDisplay();
void fuelConsScreenDisplay();
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  MX_SPI3_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  	devState.switchActv = 0;

#ifdef DISP_ACTIVE
	DISP_Init(VERTICAL);
	DISP_NewImage(DISP_WIDTH, DISP_HEIGHT, 0, BLACK);
//	logoScreenDisplay();
//
//	// Waiting for pressing the switch
//	while(HAL_GPIO_ReadPin(D6_SWITCH_PIN));
//	HAL_Delay(100);

	paramScreenDisplay();
	//gearboxScreenDisplay();

	ecuVal.IAT = 40;
	ecuVal.batt_v = 12.6;
	ecuVal.oil_bar = 3.5;
	ecuVal.oil_temp = 90;
	ecuVal.CLT = 90;
	ecuVal.lambda = 12.6;

	vehicleVal.actGear = 3;

	vehicleVal.gearRatio[0] = 1;
	vehicleVal.gearRatio[1] = 442;
	vehicleVal.gearRatio[2] = 230;
	vehicleVal.gearRatio[3] = 167;
	vehicleVal.gearRatio[4] = 119;
	vehicleVal.gearRatio[5] = 100;

	vehicleVal.revGear[1] = 5000;
	for(int i = 2; i <= 5 ; i++) {
		vehicleVal.revGear[i] = vehicleVal.revGear[i-1] * vehicleVal.gearRatio[i] / vehicleVal.gearRatio[i-1];
	}
#endif

	__HAL_RCC_TIM2_CLK_ENABLE();
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_TIM_Base_Start_IT(&htim2);
	vehicleVal.speedSensCnt = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

#ifdef DISP_ACTIVE
	if(devState.switchActv) {
		if(devState.screenNo == PARAM) {
			DISP_DrawNum(105, 15, (int32_t)ecuVal.CLT, &Font24, BRRED, BLACK);
			DISP_DrawNum(40, 70, (int32_t)ecuVal.oil_temp, &Font24, BRRED, BLACK);
			DISP_DrawNum(160, 70, (int32_t)ecuVal.oil_bar, &Font24, BRRED, BLACK);
			DISP_DrawNum(40, 130, (int32_t)ecuVal.batt_v, &Font24, BRRED, BLACK);
			DISP_DrawNum(160, 130, (int32_t)ecuVal.lambda, &Font24, BRRED, BLACK);
			DISP_DrawNum(105, 207, (int32_t)ecuVal.IAT, &Font24, BRRED, BLACK);
			ecuVal.oil_bar++;
			ecuVal.oil_temp++;
			ecuVal.batt_v++;
			ecuVal.lambda++;
			ecuVal.CLT++;
			ecuVal.IAT++;
		} else if(devState.screenNo == GEARBOX) {
			DISP_DrawNum(60, 18, (int32_t)vehicleVal.actSpeed, &Font24, BLACK, BRRED);
			DISP_DrawNum(60, 43, (int32_t)vehicleVal.fuelCons, &Font24, BLACK, BRRED);
			DISP_DrawNum(130, 90,  vehicleVal.revGear[1], &Font24, ((vehicleVal.actGear == 1) ? BRRED : BLACK), ((vehicleVal.actGear == 1) ? BLACK : BRRED));
			DISP_DrawNum(130, 115, vehicleVal.revGear[2], &Font24, ((vehicleVal.actGear == 2) ? BRRED : BLACK), ((vehicleVal.actGear == 2) ? BLACK : BRRED));
			DISP_DrawNum(130, 140, vehicleVal.revGear[3], &Font24, ((vehicleVal.actGear == 3) ? BRRED : BLACK), ((vehicleVal.actGear == 3) ? BLACK : BRRED));
			DISP_DrawNum(130, 165, vehicleVal.revGear[4], &Font24, ((vehicleVal.actGear == 4) ? BRRED : BLACK), ((vehicleVal.actGear == 4) ? BLACK : BRRED));
			DISP_DrawNum(130, 190, vehicleVal.revGear[5], &Font24, ((vehicleVal.actGear == 5) ? BRRED : BLACK), ((vehicleVal.actGear == 5) ? BLACK : BRRED));
		}

		HAL_UART_Transmit(&huart2, "\nCnt ", 5, 100);
		char b[4];
		itoa(vehicleVal.actSpeed, b, 10);

		HAL_UART_Transmit(&huart2, b, 4, 100);

	} else {
		if(devState.screenNo == CHANGE_TO_PARAM) {
			paramScreenDisplay();
		} else if(devState.screenNo == CHANGE_TO_GEARBOX) {
			gearboxScreenDisplay();
		}
	}

#endif

//	HAL_UART_Transmit(&huart2, "dupa\n", 5, 100);
//	uint32_t timerValue = __HAL_TIM_GET_COUNTER(&htim2);
//	HAL_UART_Transmit(&huart2, "\ntim2: ", 7, 100);
//	uint8_t b[4];
//	itoa(timerValue, b, 10);
//	HAL_UART_Transmit(&huart2, b, 4, 100);
	HAL_UART_Transmit(&huart1, "123aaa", 5, 100);
	HAL_Delay(800);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration 
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{

  /* USER CODE BEGIN SPI3_Init 0 */

  /* USER CODE END SPI3_Init 0 */

  /* USER CODE BEGIN SPI3_Init 1 */

  /* USER CODE END SPI3_Init 1 */
  /* SPI3 parameter configuration*/
  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 7;
  hspi3.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi3.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI3_Init 2 */

  /* USER CODE END SPI3_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 31999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 19200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, A3_DISP_CS_Pin|D2_DISP_BL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D3_DISP_RST_Pin|D4_DISP_DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : A3_DISP_CS_Pin D2_DISP_BL_Pin */
  GPIO_InitStruct.Pin = A3_DISP_CS_Pin|D2_DISP_BL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D3_DISP_RST_Pin D4_DISP_DC_Pin */
  GPIO_InitStruct.Pin = D3_DISP_RST_Pin|D4_DISP_DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : D6_SWITCH_Pin */
  GPIO_InitStruct.Pin = D6_SWITCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(D6_SWITCH_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : D9_SPEED_SENS_Pin */
  GPIO_InitStruct.Pin = D9_SPEED_SENS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(D9_SPEED_SENS_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI1_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
///////////// SWITCH /////////////
	if(GPIO_Pin == D6_SWITCH_Pin && devState.switchActv) {

		devState.switchActv = 0;

		if(devState.screenNo == PARAM) {
			devState.screenNo = CHANGE_TO_GEARBOX;

		} else if(devState.screenNo == GEARBOX) {
			devState.screenNo = CHANGE_TO_PARAM;
		}
///////////// SPEED SENSOR /////////////
	} else if(GPIO_Pin == D9_SPEED_SENS_Pin) {

		if(devState.switchActv) {
			vehicleVal.speedSensCnt++;

		} else {
			vehicleVal.speedSensCnt = 0;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	vehicleVal.actSpeed = vehicleVal.speedSensCnt * 110 / 78;
	vehicleVal.speedSensCnt = 0;
}

void logoScreenDisplay() {

	DISP_Clear(BLACK);
	DISP_DrawImage(gImage_samurai_logo_q1, 30, 30, 90, 90);
	DISP_DrawImage(gImage_samurai_logo_q3, 30, 120, 90, 90);
	DISP_DrawImage(gImage_samurai_logo_q2, 120, 30, 90, 90);
	DISP_DrawImage(gImage_samurai_logo_q4, 120, 120, 90, 90);

	devState.screenNo = LOGO;
}

void paramScreenDisplay() {

	DISP_Clear(BLACK);
	DISP_DrawString(65, 40, "WATER oC", &Font20, BLACK, BRRED);
	DISP_DrawLine(20, 60, 220, 60, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawLine(120, 60, 120, 120, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawString(25, 100, "OIL oC", &Font20, BLACK, BRRED);
	DISP_DrawString(130, 100, "OIL bar", &Font20, BLACK, BRRED);
	DISP_DrawLine(5, 120, 235, 120, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawLine(120, 120, 120, 180, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawString(25, 160, "BATT V", &Font20, BLACK, BRRED);
	DISP_DrawString(130, 160, "LAMBDA", &Font20, BLACK, BRRED);
	DISP_DrawLine(20, 180, 220, 180, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawString(75, 182, "IAT oC", &Font20, BLACK, BRRED);

	devState.screenNo = PARAM;
	devState.switchActv = 1;
}

void gearboxScreenDisplay() {

	DISP_Clear(BLACK);
	DISP_DrawString(120, 18, "km/h", &Font20, BLACK, BRRED);
	DISP_DrawString(120, 43, "l/100km", &Font20, BLACK, BRRED);
	DISP_DrawLine(20, 68, 220, 68, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawLine(105, 68, 105, 220, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	DISP_DrawString(40, 70, "GEAR", &Font20, BLACK, BRRED);
	DISP_DrawString(130, 70, "RPM", &Font20, BLACK, BRRED);
	DISP_DrawString(60, 90, "1", &Font20, BLACK, BRRED);
	DISP_DrawString(60, 115, "2", &Font20, BLACK, BRRED);
	DISP_DrawString(60, 140, "3", &Font20, BLACK, BRRED);
	DISP_DrawString(60, 165, "4", &Font20, BLACK, BRRED);
	DISP_DrawString(60, 190, "5", &Font20, BLACK, BRRED);

	devState.screenNo = GEARBOX;
	devState.switchActv = 1;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
