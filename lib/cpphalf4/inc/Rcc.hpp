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

	enum class PLLSource : uint32_t
	{
		HSI = RCC_PLLCFGR_PLLSRC_HSI,
		HSE = RCC_PLLCFGR_PLLSRC_HSE,
	};

	enum class PLLP : uint32_t
	{
		DIV2 = 0b00,
		DIV4 = 0b01,
		DIV6 = 0b10,
		DIV8 = 0b11,
	};

	static inline void SetSystemClockSource(SystemClockSource source = SystemClockSource::PLLCLK, uint32_t timeout = 2000)
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

	static inline void enablePLL(uint32_t timeout = 2000)
	{
		RCC->CR |= RCC_CR_PLLON;
		while (not PLLready())
		{
			if (--timeout < 0)
			{
				return;
			}
		}
	}

	static inline void disablePLL(uint32_t timeout = 2000)
	{
		RCC->CR &= ~RCC_CR_PLLON;
		while (PLLready())
		{
			if (--timeout < 0)
			{
				return;
			}
		}
	}

	static inline bool PLLready()
	{
		return RCC->CR & RCC_CR_PLLRDY;
	}

	static inline void SetPLLSource(PLLSource source = PLLSource::HSE, uint32_t timeout = 2000)
	{
		RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLSRC) | uint32_t(source);
	}
	static inline PLLSource GetPLLSource()
	{
		return PLLSource(RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
	}

	static inline void SetPLLM(const size_t value = 4)
	{
		RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | (value << RCC_PLLCFGR_PLLM_Pos);
	}
	static inline size_t GetPLLM()
	{
		return (RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> RCC_PLLCFGR_PLLM_Pos;
	}

	static inline void SetPLLN(const size_t value = 168)
	{
		RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | (value << RCC_PLLCFGR_PLLN_Pos);
	}

	static inline size_t GetPLLN()
	{
		return (RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> RCC_PLLCFGR_PLLN_Pos;
	}

	static inline void SetPLLP(const PLLP value = PLLP::DIV2)
	{
		RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | (uint32_t(value) << RCC_PLLCFGR_PLLP_Pos);
	}

	static inline PLLP GetPLLP()
	{
		return PLLP((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >> RCC_PLLCFGR_PLLP_Pos);
	}

	static inline void SetPLLQ(const size_t value = 7)
	{
		RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLQ) | (value << RCC_PLLCFGR_PLLQ_Pos);
	}

	static inline size_t GetPLLQ()
	{
		return (RCC->PLLCFGR & RCC_PLLCFGR_PLLQ) >> RCC_PLLCFGR_PLLQ_Pos;
	}

	static inline void SetPLLR(const size_t value = 2)
	{
		RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLR) | (value << RCC_PLLCFGR_PLLR_Pos);
	}

	static inline size_t GetPLLR()
	{
		return (RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >> RCC_PLLCFGR_PLLR_Pos;
	}
};
