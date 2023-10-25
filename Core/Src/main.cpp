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
	using blinker1 = board::mycontroller::ld1;
	using blinker2 = board::mycontroller::ld2;
	using blinker3 = board::mycontroller::ld3;
	using rx = board::mycontroller::stlk_rx;
	using tx = board::mycontroller::stlk_tx;



	// UART MSP INIT KRAMS
	// GPIO_InitTypeDef GPIO_InitStruct = {0};

	// __HAL_RCC_GPIOD_CLK_ENABLE();
	/**USART3 GPIO Configuration
	PD8     ------> USART3_TX
	PD9     ------> USART3_RX
	*/

	rx::reg()->AFR[8/8] |= 7;
	
	tx::reg()->AFR[9/8] |= (7<<(4*1));
	tx::reg()->OSPEEDR = 0x4f0000ul;
	tx::reg()->MODER = 0xa0000;

	while (1)
	{
		com::write("Hello");
		blinker1::write(true);
		HAL_Delay(2);
		blinker2::write(true);
		HAL_Delay(2);
		blinker3::write(true);
		HAL_Delay(2);

		blinker1::write(false);
		blinker2::write(false);
		blinker3::write(false);
		HAL_Delay(5);
	}
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
