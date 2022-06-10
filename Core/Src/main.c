/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int dotLen = 200;       // длина "точки" в коде Морзе
int dashLen = 600;      // длина "тире" в коде Морзе
int interval = 1000;	// длина интервала между буквами
int space = 1500; 		// длина интервала между словами
void MorseDot()
	{
	HAL_GPIO_WritePin(Buzz_GPIO_Port, Buzz_Pin, GPIO_PIN_SET);
	HAL_Delay(dotLen);
	HAL_GPIO_WritePin(Buzz_GPIO_Port, Buzz_Pin, GPIO_PIN_RESET);
	HAL_Delay(dotLen);
	}
void MorseDash()
	{
	HAL_GPIO_WritePin(Buzz_GPIO_Port, Buzz_Pin, GPIO_PIN_SET);
	HAL_Delay(dashLen);
	HAL_GPIO_WritePin(Buzz_GPIO_Port, Buzz_Pin, GPIO_PIN_RESET);
	HAL_Delay(dashLen);
	}
void MorseOutput(char tmpChar)
	{
	switch (tmpChar)
		{
		case 'a':
		MorseDot();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'b':
		MorseDash();
		MorseDot();
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'c':
		MorseDash();
		MorseDot();
		MorseDash();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'd':
		MorseDash();
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'e':
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'f':
		MorseDot();
		MorseDot();
		MorseDash();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'g':
		MorseDash();
		MorseDash();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'h':
		MorseDot();
		MorseDot();
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'i':
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'j':
		MorseDot();
		MorseDash();
		MorseDash();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'k':
		MorseDash();
		MorseDot();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'l':
		MorseDot();
		MorseDash();
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'm':
		MorseDash();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'n':
		MorseDash();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'o':
		MorseDash();
		MorseDash();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'p':
		MorseDot();
		MorseDash();
		MorseDash();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 'q':
		MorseDash();
		MorseDash();
		MorseDot();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'r':
		MorseDot();
		MorseDash();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 's':
		MorseDot();
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case 't':
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'u':
		MorseDot();
		MorseDot();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'v':
		MorseDot();
		MorseDot();
		MorseDot();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'w':
		MorseDot();
		MorseDash();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'x':
		MorseDash();
		MorseDot();
		MorseDot();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'y':
		MorseDash();
		MorseDot();
		MorseDash();
		MorseDash();
		HAL_Delay(interval);
		break;
		case 'z':
		MorseDash();
		MorseDash();
		MorseDot();
		MorseDot();
		HAL_Delay(interval);
		break;
		case ' ':
		HAL_Delay(space);
		break;
		default:
			   break;
		}
	}
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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	char symbol;
	char array[1024] = "";
	int  k = 0;

  while (1)
  {
	  HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_SET);
	  if(HAL_UART_Receive(&huart1, (uint8_t*)&symbol, 1, -1) == HAL_OK)
	 	  {
	 		  HAL_UART_Transmit(&huart1, (uint8_t*)&symbol, 1, -1); //вывод введенного символа
	 		  array[k] = symbol;
	 		  k++;
	 		  if(symbol == '\n')
	 		  {
	 			char ch = '\r';
	 			HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, -1); //убирает отступ в консоли
	 			for(int i = 0; i < k ; i++)
	 			  {
	 				HAL_UART_Transmit(&huart1, (uint8_t*)&array[i], 1, -1); //вывод посимвольно букв, которые пропикиваются
	 				MorseOutput(tolower(array[i]));
	 				if(array[i]== '\n')
	 				{
	 					HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, -1);
	 				}
	 			  }
	 			memset(array, 0, 1024);	//очищаем массив
	 			k = 0;
	 		  }
	 	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
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
  huart1.Init.BaudRate = 115200;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Buzz_GPIO_Port, Buzz_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : Buzz_Pin */
  GPIO_InitStruct.Pin = Buzz_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Buzz_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Led_Pin */
  GPIO_InitStruct.Pin = Led_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Led_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

