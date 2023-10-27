#pragma once
#include "stm32f4.hpp"
#include "SI/frequency.h"
#include "SI/time.h"
#include "Usart.hpp"
#include "Gpio.hpp"
#include "Rcc.hpp"
#include "Flash.hpp"
#include "Pwr.hpp"

struct stm32f446 : public stm32f4
{
    enum class peripherals
    {
        gpioa,
        gpiob,
        gpioc,
        gpiod,
        gpioe,
        gpiof,
        gpiog,
        gpioh,
        usart1,
        usart2,
        usart3,
        uart4,
        uart5,
        usart6,
    };
    static constexpr SI::hertz_t<uint32_t> HSI = 16_MHz;
    
    template<SI::hertz_t<uint32_t> HSE, SI::hertz_t<uint32_t> target_SYSCLK>
    struct Clocktree
    {
        Rcc::SystemClock::Source SysClkMux;
        Rcc::PLL::config pllcfg;
        Rcc::AHB::DIV ahb;
        Rcc::AHB1::DIV ahb1;
        Rcc::AHB2::DIV ahb2;

        static constexpr Clocktree calculate()
        {
            constexpr Clocktree cfg = {
                .SysClkMux = Rcc::SystemClock::Source::PLLCLK,
                .pllcfg = {
                    .src = Rcc::PLL::Source::HSE,
                    .M = 4,
                    .N = target_SYSCLK / (HSE / (2 * 4)),
                    .Pval = Rcc::PLL::P::DIV2,
                    .Q = 7,
                    .R = 2,
                },
                .ahb = Rcc::AHB::DIV::DIV1,
                .ahb1 = Rcc::AHB1::DIV::DIV4,
                .ahb2 = Rcc::AHB2::DIV::DIV2,
            };
            return cfg;
        }

        static constexpr SI::hertz_t<uint32_t> getHSI(void)
        {
            return HSI;
        }

        static constexpr SI::hertz_t<uint32_t> getHSE(void)
        {
            return HSE;
        }

        static constexpr SI::hertz_t<uint32_t> getPLLSourceMux(void)
        {
            constexpr auto cfg = calculate();
            if constexpr (cfg.pllcfg.src == Rcc::PLL::Source::HSE)
            {
                return getHSE();
            }
            if constexpr (cfg.pllcfg.src == Rcc::PLL::Source::HSI)
            {
                return getHSI();
            }
        }

        static constexpr SI::hertz_t<uint32_t> getPLLCLK(void)
        {
            constexpr auto cfg = calculate();
            return getPLLSourceMux() / (2 * cfg.pllcfg.M) * cfg.pllcfg.N;
        }

        static constexpr SI::hertz_t<uint32_t> getPLLR(void)
        {
            constexpr auto cfg = calculate();
            return getPLLSourceMux() / (cfg.pllcfg.R * cfg.pllcfg.M) * cfg.pllcfg.N;
        }

        static constexpr SI::hertz_t<uint32_t> getSYSCLK(void)
        {
            constexpr auto cfg = calculate();
            if constexpr (cfg.SysClkMux == Rcc::SystemClock::Source::HSI)
            {
                return getHSI();
            }
            if constexpr (cfg.SysClkMux == Rcc::SystemClock::Source::HSE)
            {
                return getHSE();
            }
            if constexpr (cfg.SysClkMux == Rcc::SystemClock::Source::PLLCLK)
            {
                return getPLLCLK();
            }
            if constexpr (cfg.SysClkMux == Rcc::SystemClock::Source::PLLR)
            {
                return getPLLR();
            }
        }
        static constexpr SI::hertz_t<uint32_t> getHCLK(void)
        {
            constexpr auto cfg = calculate();
            return getSYSCLK() / cfg.ahb;
        }

        static constexpr SI::hertz_t<uint32_t> getPCLK1(void)
        {
            constexpr auto cfg = calculate();
            return getHCLK() / cfg.ahb1;
        }
        static constexpr SI::hertz_t<uint32_t> getPCLK2(void)
        {
            constexpr auto cfg = calculate();
            return getHCLK() / cfg.ahb2;
        }
    };

    template<SI::hertz_t<uint32_t> HSE, SI::hertz_t<uint32_t> target_SYSCLK>
    static void init(void)
    {
        using clocktree = Clocktree<HSE, target_SYSCLK>;
        constexpr auto ct_cfg = clocktree::calculate();
        stm32f4::init();
        Flash::setICEN(true);
        Flash::setDCEN(true);
        Flash::setPRFTEN(true);
        Rcc::APB1::setPWR(true);
        Pwr::setVOS(Pwr::VOS::SCALE1);
        Flash::setLatency(5);

        Rcc::HSI::enable();
        Rcc::SystemClock::setSource(Rcc::SystemClock::Source::HSI);
        Rcc::HSE::enable(Rcc::HSE::Type::CLOCK);
        Rcc::PLL::set(ct_cfg.pllcfg);
        Rcc::AHB::set(Rcc::AHB::DIV::DIV1);
        Rcc::AHB1::set(Rcc::AHB1::DIV::DIV4);
        Rcc::AHB2::set(Rcc::AHB2::DIV::DIV2);
        Rcc::SystemClock::setSource(ct_cfg.SysClkMux);
        SystemCoreClock = clocktree::getSYSCLK().value();
    }

    static void delay(SI::milli_seconds_t<uint32_t> delay);
};
extern "C" void SysTick_Handler(void);