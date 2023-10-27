#pragma once
#include <stm32f446.hpp>

#include <SI/frequency.h>
namespace board
{
    using controller = stm32f446;
    using peripheral = controller::peripherals;
    using ld1 = Gpio<controller, peripheral::gpiob, 0>;
    using ld2 = Gpio<controller, peripheral::gpiob, 7>;
    using ld3 = Gpio<controller, peripheral::gpiob, 14>;

    constexpr static SI::hertz_t<uint32_t> HSE{8_MHz};
    constexpr static SI::hertz_t<uint32_t> sysTick_freq = 1_kHz;
    using debug = Usart<controller, peripheral::usart3>;
    using stlk_rx = Gpio<controller, peripheral::gpiod, 8>;
    using stlk_tx = Gpio<controller, peripheral::gpiod, 9>;

    static void init(void)
    {
        controller::init<HSE, 168_MHz>();
        SysTick_Config(SystemCoreClock / sysTick_freq.value());
        debug::init();
        ld1::init();
        ld2::init();
        ld3::init();
        stlk_rx::init();
        stlk_tx::init();
    }
}