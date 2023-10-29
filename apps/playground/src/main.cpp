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

#include <SI/frequency.h>

using namespace SI::literals;

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	board::init();
	using com = board::debug;
	using blinker1 = board::ld1;
	using blinker2 = board::ld2;
	using blinker3 = board::ld3;
	using util = board::controller;
	blinker1::setMode(blinker1::Mode::output);
	blinker2::setMode(blinker2::Mode::output);
	blinker3::setMode(blinker3::Mode::output);

	for (;;)
	{
		com::write("Hello");
		blinker1::write(true);
		util::delay(250_ms);
		blinker2::write(true);
		util::delay(250_ms);
		blinker3::write(true);
		util::delay(250_ms);

		blinker1::write(false);
		blinker2::write(false);
		blinker3::write(false);
		util::delay(250_ms);
	}
}