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

  while((myTick - tickstart) < wait)
  {
  }
}

void stm32f446::updateSystemCoreClock()
{
	SI::hertz_t<uint32_t> clk = 16_MHz;
	SI::hertz_t<uint32_t> HSE = 8_MHz;

	switch (Rcc::SystemClock::getSource())
	{
	case Rcc::SystemClock::Source::HSI:
		clk = 16_MHz;
		break;
	case Rcc::SystemClock::Source::HSE:
		clk = HSE;
		break;
	case Rcc::SystemClock::Source::PLLCLK:
	case Rcc::SystemClock::Source::PLLR:
		switch (Rcc::PLL::getSource())
		{
		case Rcc::PLL::Source::HSI:
			clk = 16_MHz;
			break;
		case Rcc::PLL::Source::HSE:
			clk = HSE;
			break;
		}
		clk = (clk / Rcc::PLL::getM()) * Rcc::PLL::getN();
		break;
	}
	switch (Rcc::SystemClock::getSource())
	{
	case Rcc::SystemClock::Source::PLLCLK:
		switch (Rcc::PLL::getP())
		{
		case Rcc::PLL::P::DIV2:
			clk = clk / 2;
			break;
		case Rcc::PLL::P::DIV4:
			clk = clk / 4;
			break;
		case Rcc::PLL::P::DIV6:
			clk = clk / 6;
			break;
		case Rcc::PLL::P::DIV8:
			clk = clk / 8;
			break;
		}
		break;
	case Rcc::SystemClock::Source::PLLR:
		clk = clk / Rcc::PLL::getR();
		break;
	}
	SystemCoreClock = clk.value();
}

extern "C" void SysTick_Handler(void)
{
	myTick = myTick + 1;
}