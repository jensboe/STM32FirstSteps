/**
 ******************************************************************************
 * @file         stm32f4xx_hal_msp.c
 * @brief        This file provides code for the MSP Initialization
 *               and de-Initialization codes.
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

/* Includes ------------------------------------------------------------------*/
#include "main.hpp"

/**
 * @brief UART MSP De-Initialization
 * This function freeze the hardware resources used in this example
 * @param huart: UART handle pointer
 * @retval None
 */
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
	if (huart->Instance == USART3)
	{
		/* Peripheral clock disable */
		__HAL_RCC_USART3_CLK_DISABLE();

		/**USART3 GPIO Configuration
		PD8     ------> USART3_TX
		PD9     ------> USART3_RX
		*/
		HAL_GPIO_DeInit(GPIOD, STLK_RX_Pin | STLK_TX_Pin);
	}
}

/**
 * @brief PCD MSP Initialization
 * This function configures the hardware resources used in this example
 * @param hpcd: PCD handle pointer
 * @retval None
 */
void HAL_PCD_MspInit(PCD_HandleTypeDef* hpcd)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
	if (hpcd->Instance == USB_OTG_FS)
	{
		/** Initializes the peripherals clock
		 */
		PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_CLK48;
		PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48CLKSOURCE_PLLQ;
		if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
		{
			Error_Handler();
		}

		__HAL_RCC_GPIOA_CLK_ENABLE();
		/**USB_OTG_FS GPIO Configuration
		PA8     ------> USB_OTG_FS_SOF
		PA9     ------> USB_OTG_FS_VBUS
		PA10     ------> USB_OTG_FS_ID
		PA11     ------> USB_OTG_FS_DM
		PA12     ------> USB_OTG_FS_DP
		*/
		GPIO_InitStruct.Pin = USB_SOF_Pin | USB_ID_Pin | USB_DM_Pin | USB_DP_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = USB_VBUS_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(USB_VBUS_GPIO_Port, &GPIO_InitStruct);

		/* Peripheral clock enable */
		__HAL_RCC_USB_OTG_FS_CLK_ENABLE();
	}
}

/**
 * @brief PCD MSP De-Initialization
 * This function freeze the hardware resources used in this example
 * @param hpcd: PCD handle pointer
 * @retval None
 */
void HAL_PCD_MspDeInit(PCD_HandleTypeDef* hpcd)
{
	if (hpcd->Instance == USB_OTG_FS)
	{
		/* Peripheral clock disable */
		__HAL_RCC_USB_OTG_FS_CLK_DISABLE();

		/**USB_OTG_FS GPIO Configuration
		PA8     ------> USB_OTG_FS_SOF
		PA9     ------> USB_OTG_FS_VBUS
		PA10     ------> USB_OTG_FS_ID
		PA11     ------> USB_OTG_FS_DM
		PA12     ------> USB_OTG_FS_DP
		*/
		HAL_GPIO_DeInit(GPIOA, USB_SOF_Pin | USB_VBUS_Pin | USB_ID_Pin | USB_DM_Pin | USB_DP_Pin);
	}
}
