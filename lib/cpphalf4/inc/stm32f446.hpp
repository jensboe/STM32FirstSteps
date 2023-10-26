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

    static void init(void)
    {
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
        const Rcc::PLL::config cfg =
            {
                .src = Rcc::PLL::Source::HSE,
                .M = 4,
                .N = 168,
                .Pval = Rcc::PLL::P::DIV2,
                .Q = 7,
                .R = 2,
            };
        Rcc::PLL::set(cfg);
        Rcc::AHB::set(Rcc::AHB::DIV::DIV1);
        Rcc::AHB1::set(Rcc::AHB1::DIV::DIV4);
        Rcc::AHB2::set(Rcc::AHB2::DIV::DIV2);
        Rcc::PLL48CLK::set(Rcc::PLL48CLK::Source::PLLQ);
        Rcc::SystemClock::setSource(Rcc::SystemClock::Source::PLLCLK);

        updateSystemCoreClock();
    }
    static void delay(SI::milli_seconds_t<uint32_t> delay);
    static void updateSystemCoreClock();
};
extern "C" void SysTick_Handler(void);