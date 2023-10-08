#pragma once
#include "Rcc.hpp"
struct SystemClock
{
	static inline void init()
	{
		Rcc::SetSystemClockSource(Rcc::SystemClockSource::PLLCLK);
	}
};
