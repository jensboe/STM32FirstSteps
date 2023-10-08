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

	struct PLL
	{
		enum class Source : uint32_t
		{
			HSI = RCC_PLLCFGR_PLLSRC_HSI,
			HSE = RCC_PLLCFGR_PLLSRC_HSE,
		};

		enum class P : uint32_t
		{
			DIV2 = 0b00,
			DIV4 = 0b01,
			DIV6 = 0b10,
			DIV8 = 0b11,
		};

		static inline bool isReady()
		{
			return RCC->CR & RCC_CR_PLLRDY;
		}

		struct config {
			Source src	= Source::HSE;
			uint32_t M 	= 4;
			uint32_t N 	= 168;
			P Pval 		= P::DIV2;
			uint32_t Q 	= 7;
			uint32_t R 	= 2;

		};

		static inline void set(const config &cfg)
		{
			if(isReady())
			{
				disable();
			}
			SetSource(cfg.src);
			SetM(cfg.M);
			SetN(cfg.N);
			SetP(cfg.Pval);
			SetQ(cfg.Q);
			SetR(cfg.R);
			enable();
		}

		static inline Source GetSource()
		{
			return Source(RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
		}

		static inline size_t GetM()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> RCC_PLLCFGR_PLLM_Pos;
		}

		static inline size_t GetN()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> RCC_PLLCFGR_PLLN_Pos;
		}

		static inline P GetP()
		{
			return P((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >> RCC_PLLCFGR_PLLP_Pos);
		}

		static inline size_t GetQ()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLQ) >> RCC_PLLCFGR_PLLQ_Pos;
		}

		static inline size_t GetR()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >> RCC_PLLCFGR_PLLR_Pos;
		}

		private:
		
		static inline void enable(uint32_t timeout = 2000)
		{
			RCC->CR |= RCC_CR_PLLON;
			while (not isReady())
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}

		static inline void disable(uint32_t timeout = 2000)
		{
			RCC->CR &= ~RCC_CR_PLLON;
			while (isReady())
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}

		static inline void SetSource(Source source = Source::HSE, uint32_t timeout = 2000)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLSRC) | uint32_t(source);
		}

		static inline void SetM(const size_t value = 4)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | (value << RCC_PLLCFGR_PLLM_Pos);
		}

		static inline void SetN(const size_t value = 168)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | (value << RCC_PLLCFGR_PLLN_Pos);
		}

		static inline void SetP(const P value = P::DIV2)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | (uint32_t(value) << RCC_PLLCFGR_PLLP_Pos);
		}

		static inline void SetQ(const size_t value = 7)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLQ) | (value << RCC_PLLCFGR_PLLQ_Pos);
		}

		static inline void SetR(const size_t value = 2)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLR) | (value << RCC_PLLCFGR_PLLR_Pos);
		}
	};
};
