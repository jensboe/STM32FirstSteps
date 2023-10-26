#pragma once
#include <stm32f446.hpp>

#include <SI/frequency.h>
namespace board
{
    using ld1 = Gpio<stm32f446::peripherals, stm32f446::peripherals::gpiob, 0>;
    using ld2 = Gpio<stm32f446::peripherals, stm32f446::peripherals::gpiob, 7>;
    using ld3 = Gpio<stm32f446::peripherals, stm32f446::peripherals::gpiob, 14>;

    constexpr static SI::hertz_t<uint32_t> HSE{8_MHz};
    constexpr static auto sysTick_freq = 1_kHz;
    using debug = Usart<stm32f446::peripherals, stm32f446::peripherals::usart3>;
    using stlk_rx = Gpio<stm32f446::peripherals, stm32f446::peripherals::gpiod, 8>;
    using stlk_tx = Gpio<stm32f446::peripherals, stm32f446::peripherals::gpiod, 9>;
    static void init(void)
    {
        stm32f446::init();
        SysTick_Config(SystemCoreClock / SI::hertz_t<uint32_t>(sysTick_freq).value());
        debug::init();
        ld1::init();
        ld2::init();
        ld3::init();
        stlk_rx::init();
        stlk_tx::init();
    }
}