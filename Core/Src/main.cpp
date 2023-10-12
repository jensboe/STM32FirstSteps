/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.hpp"
#include <generics.hpp>
#include <stm32f446.hpp>
#include <ClockConfiguration.hpp>

#include <SI/frequency.h>

using namespace SI::literals;

UART_HandleTypeDef huart3;

constexpr auto sysTick_freq = 1_kHz;

static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
namespace board
{
	struct mycontroller : public generic_controller
	{
		constexpr static SI::hertz_t<uint32_t> HSE = 8_MHz;
	};
}

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	Flash::setICEN(true);
	Flash::setDCEN(true);
	Flash::setPRFTEN(true);
	Nvic::setPriorityGrouping(Nvic::Grouping::PG4);

	ClockConfiguration::init<board::mycontroller>();
	SysTick_Config(SystemCoreClock / SI::hertz_t<uint32_t>(sysTick_freq).value());

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	// UART MSP INIT KRAMS
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* Peripheral clock enable */



	__HAL_RCC_GPIOD_CLK_ENABLE();
	/**USART3 GPIO Configuration
	PD8     ------> USART3_TX
	PD9     ------> USART3_RX
	*/
	GPIO_InitStruct.Pin = STLK_RX_Pin | STLK_TX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	using debug = Usart<stm32f446::peripherals::usart3>;

	debug::init();
	//MX_USART3_UART_Init();
	huart3.Instance = USART3;
	huart3.ErrorCode = HAL_UART_ERROR_NONE;
	huart3.gState = HAL_UART_STATE_READY;
	huart3.RxState = HAL_UART_STATE_READY;
	huart3.RxEventType = HAL_UART_RXEVENT_TC;

	while (1)
	{
		uint8_t bla[] = {'H', 'e', 'l', 'l', 'o', '\n'};
		HAL_UART_Transmit(&huart3, bla, sizeof(bla), 100);
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		HAL_Delay(500);
	}
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
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, LD1_Pin | LD3_Pin | LD2_Pin, GPIO_PIN_RESET);


	/*Configure GPIO pin : USER_Btn_Pin */
	GPIO_InitStruct.Pin = USER_Btn_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
	GPIO_InitStruct.Pin = LD1_Pin | LD3_Pin | LD2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : USB_OverCurrent_Pin */
	GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */
