#pragma once
#include "Rcc.hpp"
struct SystemClock
{
	static inline void init()
	{
		Rcc::SystemClock::SetSource(Rcc::SystemClock::Source::PLLCLK);
	}
};
