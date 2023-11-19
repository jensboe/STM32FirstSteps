/*
 * Copyright (c) 2013, Kevin Läufer
 * Copyright (c) 2014-2019, Niklas Hauser
 * Copyright (c) 2017, Fabian Greif
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/architecture/interface/atomic_lock.hpp>
#include <modm/platform/device.hpp>
#include "systick_timer.hpp"

static constexpr auto systick_step(1);
static volatile uint32_t milli_time{};
static volatile uint32_t micro_time{};
static volatile bool interrupt{};

extern "C" void
vApplicationTickHook()
{
	milli_time += systick_step;
	micro_time += systick_step * 1'000ul;
	interrupt = true;
}

// pick the lowest possible priority for the SysTick interrupt
static constexpr uint8_t systick_priority{(1ul << __NVIC_PRIO_BITS) - 1ul};

// ----------------------------------------------------------------------------
void
modm::platform::SysTickTimer::enable([[maybe_unused]] uint32_t reload,
									 [[maybe_unused]] bool use_processor_clock)
{
}

void
modm::platform::SysTickTimer::disable()
{
}

// ----------------------------------------------------------------------------
modm::chrono::milli_clock::time_point modm_weak
modm::chrono::milli_clock::now() noexcept
{
	return time_point{duration{milli_time}};
}

modm::chrono::micro_clock::time_point modm_weak
modm::chrono::micro_clock::now() noexcept
{
	uint32_t val, us;

	do	// We cannot use an atomic lock here, the counter still overflows even
	{	// if the interrupt hasn't happened yet.
		interrupt = false;
		val = SysTick->VAL;
		us = micro_time;
	}
	while(interrupt);
	const auto diff = SysTick->LOAD - val;
	const auto us_per_Ncycles = platform::SysTickTimer::us_per_Ncycles;
	constexpr auto Ncycles = platform::SysTickTimer::Ncycles;

	// use a 32x32=32bit multiplication
	us += uint32_t(diff * us_per_Ncycles) >> Ncycles;
	return time_point{duration{us}};
}