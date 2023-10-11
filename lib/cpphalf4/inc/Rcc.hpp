#pragma once
#include <cstdint>

#include "stm32f446xx.h"
#include "stm32f446.hpp"
struct Rcc
{
	template <stm32::peripherals p>
	static inline void enable(void)
	{
		static_assert(isSupported<p>(), "RCC: peripheral not supported");
		// static_assert(1, "DIE");

		if constexpr (p == stm32::peripherals::usart1)
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		if constexpr (p == stm32::peripherals::usart2)
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
		if constexpr (p == stm32::peripherals::usart3)
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
		if constexpr (p == stm32::peripherals::uart4)
			RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
		if constexpr (p == stm32::peripherals::uart5)
			RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
		if constexpr (p == stm32::peripherals::usart6)
			RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
	}
	template <stm32::peripherals p>
	static inline constexpr bool isSupported(void)
	{
		if constexpr (p == stm32::peripherals::usart1)
			return true;
		if constexpr (p == stm32::peripherals::usart2)
			return true;
		if constexpr (p == stm32::peripherals::usart3)
			return true;
		if constexpr (p == stm32::peripherals::uart4)
			return true;
		if constexpr (p == stm32::peripherals::uart5)
			return true;
		if constexpr (p == stm32::peripherals::usart6)
			return true;
		return false;
	}

	struct HSE
	{
		enum class Type
		{
			CRYSTAL,
			CLOCK
		};

		static inline void disable(uint32_t timeout = 2000)
		{
			RCC->CR &= ~RCC_CR_HSEON;
			RCC->CR &= ~RCC_CR_HSEBYP;
			while (isReady())
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}

		static inline void enable(Type typ = Type::CLOCK, uint32_t timeout = 2000)
		{
			if (typ == Type::CLOCK)
			{
				RCC->CR |= RCC_CR_HSEBYP | RCC_CR_HSEON;
			}
			else
			{
				RCC->CR |= RCC_CR_HSEON;
			}

			while (not isReady())
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}
		static inline bool isReady()
		{
			return RCC->CR & RCC_CR_HSERDY;
		}
	};

	struct HSI
	{
		static inline void disable(uint32_t timeout = 2000)
		{
			RCC->CR &= ~RCC_CR_HSION;

			while (isReady())
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}

		static inline void enable(uint32_t timeout = 2000)
		{
			RCC->CR |= RCC_CR_HSION;

			while (not isReady())
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}
		static inline bool isReady()
		{
			return RCC->CR & RCC_CR_HSIRDY;
		}
	};

	struct SystemClock
	{
		enum class Source : uint32_t
		{
			HSI = RCC_CFGR_SW_HSI,
			HSE = RCC_CFGR_SW_HSE,
			PLLCLK = RCC_CFGR_SW_PLL,
			PLLR = RCC_CFGR_SW_PLLR,
		};

		static inline void setSource(Source source = Source::PLLCLK, uint32_t timeout = 2000)
		{
			// set the System clock Switch
			RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW) | uint32_t(source);

			// Readback System Clock Switch Status
			while (getSource() != source)
			{
				if (--timeout < 0)
				{
					return;
				}
			}
		}

		static inline Source getSource()
		{
			return Source((RCC->CFGR & RCC_CFGR_SWS) >> (RCC_CFGR_SWS_Pos - RCC_CFGR_SW_Pos));
		}
	};

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

		struct config
		{
			Source src = Source::HSE;
			uint32_t M = 4;
			uint32_t N = 168;
			P Pval = P::DIV2;
			uint32_t Q = 7;
			uint32_t R = 2;
		};

		static inline void set(const config &cfg)
		{
			if (isReady())
			{
				disable();
			}
			setSource(cfg.src);
			setM(cfg.M);
			setN(cfg.N);
			setP(cfg.Pval);
			setQ(cfg.Q);
			setR(cfg.R);
			enable();
		}

		static inline Source getSource()
		{
			return Source(RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
		}

		static inline size_t getM()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> RCC_PLLCFGR_PLLM_Pos;
		}

		static inline size_t getN()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> RCC_PLLCFGR_PLLN_Pos;
		}

		static inline P getP()
		{
			return P((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >> RCC_PLLCFGR_PLLP_Pos);
		}

		static inline size_t getQ()
		{
			return (RCC->PLLCFGR & RCC_PLLCFGR_PLLQ) >> RCC_PLLCFGR_PLLQ_Pos;
		}

		static inline size_t getR()
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

		static inline void setSource(Source source = Source::HSE, uint32_t timeout = 2000)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLSRC) | uint32_t(source);
		}

		static inline void setM(const size_t value = 4)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | (value << RCC_PLLCFGR_PLLM_Pos);
		}

		static inline void setN(const size_t value = 168)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | (value << RCC_PLLCFGR_PLLN_Pos);
		}

		static inline void setP(const P value = P::DIV2)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | (uint32_t(value) << RCC_PLLCFGR_PLLP_Pos);
		}

		static inline void setQ(const size_t value = 7)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLQ) | (value << RCC_PLLCFGR_PLLQ_Pos);
		}

		static inline void setR(const size_t value = 2)
		{
			RCC->PLLCFGR = (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLR) | (value << RCC_PLLCFGR_PLLR_Pos);
		}
	};

	struct AHB
	{
		enum class DIV : uint32_t
		{
			DIV1 = RCC_CFGR_HPRE_DIV1,
			DIV2 = RCC_CFGR_HPRE_DIV2,
			DIV4 = RCC_CFGR_HPRE_DIV4,
			DIV8 = RCC_CFGR_HPRE_DIV8,
			DIV16 = RCC_CFGR_HPRE_DIV16,
			DIV64 = RCC_CFGR_HPRE_DIV64,
			DIV128 = RCC_CFGR_HPRE_DIV128,
			DIV256 = RCC_CFGR_HPRE_DIV256,
			DIV512 = RCC_CFGR_HPRE_DIV512,
		};

		static inline void set(const DIV div = DIV::DIV1)
		{
			RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_HPRE) | uint32_t(div);
		}

		static inline DIV get(void)
		{
			return DIV((RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos);
		}
	};

	struct AHB1
	{
		enum class DIV : uint32_t
		{
			DIV1 = RCC_CFGR_PPRE1_DIV1,
			DIV2 = RCC_CFGR_PPRE1_DIV2,
			DIV4 = RCC_CFGR_PPRE1_DIV4,
			DIV8 = RCC_CFGR_PPRE1_DIV8,
			DIV16 = RCC_CFGR_PPRE1_DIV16,
		};

		static inline void set(const DIV div = DIV::DIV4)
		{
			RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PPRE1) | uint32_t(div);
		}

		static inline DIV get(void)
		{
			return DIV((RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos);
		}
	};

	struct AHB2
	{
		enum class DIV : uint32_t
		{
			DIV1 = RCC_CFGR_PPRE2_DIV1,
			DIV2 = RCC_CFGR_PPRE2_DIV2,
			DIV4 = RCC_CFGR_PPRE2_DIV4,
			DIV8 = RCC_CFGR_PPRE2_DIV8,
			DIV16 = RCC_CFGR_PPRE2_DIV16,
		};

		static inline void set(const DIV div = DIV::DIV2)
		{
			RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PPRE2) | uint32_t(div);
		}

		static inline DIV get(void)
		{
			return DIV((RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos);
		}
	};

	struct PLL48CLK
	{
		enum class Source : uint32_t
		{
			PLLQ = 0,
			PLLSAIP = RCC_DCKCFGR2_CK48MSEL,
		};

		static inline void set(const Source src = Source::PLLQ)
		{
			RCC->DCKCFGR2 = (RCC->DCKCFGR2 & ~RCC_DCKCFGR2_CK48MSEL) | uint32_t(src);
		}

		static inline Source get(void)
		{
			return Source((RCC->CFGR & RCC_DCKCFGR2_CK48MSEL) >> RCC_DCKCFGR2_CK48MSEL_Pos);
		}
	};

	struct APB1
	{
		static inline void setPWR(const bool value)
		{
			if (value)
			{
				RCC->APB1ENR |= RCC_APB1ENR_PWREN;
			}
			else
			{
				RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;
			}
		}
	};
};
