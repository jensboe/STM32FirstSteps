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
#include "board.hpp"
#include "peripherals.hpp"

#include <SI/frequency.h>

using namespace SI::literals;

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	board::mycontroller::init();
	using com = board::mycontroller::debug;
	using blinker1 = board::ld1;
	using blinker2 = board::ld2;
	using blinker3 = board::ld3;
	using rx = board::mycontroller::stlk_rx;
	using tx = board::mycontroller::stlk_tx;

	// UART MSP INIT KRAMS
	// GPIO_InitTypeDef GPIO_InitStruct = {0};

	// __HAL_RCC_GPIOD_CLK_ENABLE();
	/**USART3 GPIO Configuration
	PD8     ------> USART3_TX
	PD9     ------> USART3_RX
	*/

	rx::reg()->AFR[8 / 8] |= 7;

	tx::reg()->AFR[9 / 8] |= (7 << (4 * 1));
	tx::reg()->OSPEEDR = 0x4f0000ul;
	tx::reg()->MODER = 0xa0000;

	for (;;)
	{
		com::write("Hello");
		blinker1::write(true);
		stm32f446::delay(250_ms);
		blinker2::write(true);
		stm32f446::delay(250_ms);
		blinker3::write(true);
		stm32f446::delay(250_ms);

		blinker1::write(false);
		blinker2::write(false);
		blinker3::write(false);
		stm32f446::delay(250_ms);
	}
}