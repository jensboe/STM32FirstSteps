/*
 * Copyright (c) 2013, Kevin Läufer
 * Copyright (c) 2014-2017, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef MODM_CORTEX_SYSTICK_TIMER_HPP
#define MODM_CORTEX_SYSTICK_TIMER_HPP

#include <modm/architecture/interface/peripheral.hpp>
#include <modm/architecture/interface/clock.hpp>
#include <modm/math/algorithm/prescaler.hpp>

namespace modm::platform
{

/// @ingroup modm_platform_clock
class SysTickTimer
{
public:
	/**
	 * Initializes the SysTick to provide a timer to `modm::Clock` and
	 * `modm::PreciseClock`.
	 *
	 * @tparam	SystemClock
	 * 		the currently active system clock
	 * @tparam	tolerance
	 * 		the allowed tolerance for the resulting clock rate
	 */
	template< class SystemClock, percent_t tolerance=pct(0) >
	static void
	initialize()
	{
		static_assert(SystemClock::Frequency < (1ull << 24)*8*1000,
		              "HLCK is too fast for the SysTick to run at 1000Hz!");
		if constexpr (SystemClock::Frequency < 8'000'000)
		{
			constexpr auto result = Prescaler::from_range(
					SystemClock::Frequency, 1000, 1, (1ul << 24)-1);
			PeripheralDriver::assertBaudrateInTolerance< result.frequency, 1000, tolerance >();

			us_per_Ncycles = ((1ull << Ncycles) * 1'000'000ull) / SystemClock::Frequency;
			enable(result.index, true);
		}
		else
		{
			constexpr auto result = Prescaler::from_range(
					SystemClock::Frequency/8, 1000, 1, (1ul << 24)-1);
			PeripheralDriver::assertBaudrateInTolerance< result.frequency, 1000, tolerance >();

			us_per_Ncycles = ((1ull << Ncycles) * 8'000'000ull) / SystemClock::Frequency;
			enable(result.index, false);
		}
	}

	/**
	 * Disables SysTick Timer.
	 *
	 * @warning	If the SysTick Timer is disabled, `modm::Clock` and
	 *			`modm::PreciseClock` will stop incrementing.
	 */
	static void
	disable();

private:
	static void
	enable(uint32_t reload, bool use_processor_clock);

	// FCPU < 8MHz
	// 536e6/1000 < 20-bit, 8e6/1000 < 13-bit
	// 2^20*1e6/536e6 < 11-bit, 2^20*1e6/8e6 = 17-bit
	// FCPU >= 8MHz
	// 536e6/8/1000 < 17-bit, 8e6/8/1000 < 10-bit
	// 2^20*8e6/536e6 < 14-bit, 2^20*8e6/8e6 = 20-bit
	static constexpr uint8_t Ncycles{20};
	static inline uint32_t us_per_Ncycles{0};
	friend class modm::chrono::milli_clock;
	friend class modm::chrono::micro_clock;
};

}

#endif	//  MODM_STM32_CORTEX_TIMER_HPP