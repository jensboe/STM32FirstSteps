#include <cstdint>

#include "stm32f446xx.h"
struct Rcc
{
	enum class SystemClockSource : uint32_t
	{
		HSI = RCC_CFGR_SW_HSI,
		HSE = RCC_CFGR_SW_HSE,
		PLLCLK = RCC_CFGR_SW_PLL,
		PLLR = RCC_CFGR_SW_PLLR,
	};

	static inline void SetSystemClockSource(SystemClockSource source, uint32_t timeout = 2000)
	{
		// Set the System clock Switch
		RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW) | uint32_t(source);

		// Readback System Clock Switch Status
		while (GetSystemClockSource() != source)
		{
			if (--timeout < 0)
			{
				return;
			}
		}
	}
	static inline SystemClockSource GetSystemClockSource()
	{
		return SystemClockSource((RCC->CFGR & RCC_CFGR_SWS) >> (RCC_CFGR_SWS_Pos - RCC_CFGR_SW_Pos));
	}
};
