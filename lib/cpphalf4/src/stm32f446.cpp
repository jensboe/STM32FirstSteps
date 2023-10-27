#include "stm32f446.hpp"
#include "Rcc.hpp"
#include "Flash.hpp"
#include "Pwr.hpp"
#include "SI/frequency.h"
#include "SI/time.h"
volatile uint32_t myTick;

void stm32f446::delay(SI::milli_seconds_t<uint32_t> delay)
{
	uint32_t tickstart = myTick;
	uint32_t wait = delay.value();

	while ((myTick - tickstart) < wait)
	{
	}
}

extern "C" void SysTick_Handler(void)
{
	myTick = myTick + 1;
}