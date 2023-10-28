#pragma once
#include "stm32f4.hpp"
#include "SI/frequency.h"
#include "SI/time.h"
#include "Usart.hpp"
#include "Gpio.hpp"
#include "Rcc.hpp"
#include "Flash.hpp"
#include "Pwr.hpp"
volatile uint32_t myTick;
template <SI::hertz_t<uint32_t> HSE, SI::hertz_t<uint32_t> target_SYSCLK, SI::hertz_t<uint32_t> systick>
struct stm32f446 : public stm32f4
{
    static constexpr SI::hertz_t<uint32_t> HSI = 16_MHz;
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
    template <peripherals p>
    constexpr static bool isUART()
    {
        if constexpr (p == peripherals::usart1)
            return true;
        if constexpr (p == peripherals::usart2)
            return true;
        if constexpr (p == peripherals::usart3)
            return true;
        if constexpr (p == peripherals::uart4)
            return true;
        if constexpr (p == peripherals::uart5)
            return true;
        if constexpr (p == peripherals::usart6)
            return true;
        return false;
    }

    template <peripherals p>
    constexpr static bool isGPIO()
    {
        if constexpr (p == peripherals::gpioa)
            return true;
        if constexpr (p == peripherals::gpiob)
            return true;
        if constexpr (p == peripherals::gpioc)
            return true;
        if constexpr (p == peripherals::gpiod)
            return true;
        if constexpr (p == peripherals::gpioe)
            return true;
        if constexpr (p == peripherals::gpiof)
            return true;
        if constexpr (p == peripherals::gpiog)
            return true;
        if constexpr (p == peripherals::gpioh)
            return true;
        return false;
    }
    
    template <peripherals p, typename Gpio>
    constexpr static uint32_t getAlternateFunctionNumber(void)
    {
        if constexpr (Gpio::getPeripheral() == peripherals::gpiod)
        {
            if constexpr (Gpio::getPinNumber() == 8)
            {
                if constexpr (p == peripherals::usart3)
                {
                    return 7;
                }
            }
            if constexpr (Gpio::getPinNumber() == 9)
            {
                if constexpr (p == peripherals::usart3)
                {
                    return 7;
                }
            }
        }
        return 0;
    }

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
            return getSYSCLK() / 1;
        }

        static constexpr SI::hertz_t<uint32_t> getPCLK1(void)
        {
            return getHCLK() / 4;
        }
        static constexpr SI::hertz_t<uint32_t> getPCLK2(void)
        {
            return getHCLK() / 2;
        }
    };

    static_assert(Clocktree::getHSE() < 50_MHz, "HSE is to fast");
    static_assert(Clocktree::getSYSCLK() < 180_MHz, "SYSCLK is to fast");
    static_assert(Clocktree::getPLLCLK() < 180_MHz, "PLLCLK (P) is to fast");
    static_assert(Clocktree::getPLLCLK() > 24_MHz, "PLLCLK (P) is to slow");
    static_assert(Clocktree::getPLLCLK() * 2 < 432_MHz, "PLLCLK (N) is to fast");
    static_assert(Clocktree::getPLLCLK() * 2 > 100_MHz, "PLLCLK (N) is to slow");
    static_assert(Clocktree::getPLLSourceMux() / Clocktree::calculate().pllcfg.M > 950_kHz, "PLLCLK (M) is to slow");
    static_assert(Clocktree::getPLLSourceMux() / Clocktree::calculate().pllcfg.M < 2'100_kHz, "PLLCLK (M) is to fast");
    static_assert(Clocktree::getHCLK() < 180_MHz, "HCLK is to fast");
    static_assert(Clocktree::getPCLK1() < 45_MHz, "PCLK1 is to fast");
    static_assert(Clocktree::getPCLK2() < 90_MHz, "PCLK2 is to fast");

    static void init(void)
    {
        constexpr auto ct_cfg = Clocktree::calculate();
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
        SystemCoreClock = Clocktree::getSYSCLK().value();
        SysTick_Config(SystemCoreClock / systick.value());
    }
    static void delay(SI::milli_seconds_t<uint32_t> delay)
    {
        uint32_t tickstart = myTick;
        uint32_t wait = delay.value();

        while ((myTick - tickstart) < wait)
        {
        }
    }
};

extern "C" void SysTick_Handler(void)
{
    myTick = myTick + 1;
}