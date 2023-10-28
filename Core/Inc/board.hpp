#pragma once
#include <stm32f446.hpp>

#include <SI/frequency.h>
namespace board
{
    constexpr static SI::hertz_t<uint32_t> HSE{8_MHz};

    using controller = stm32f446<HSE, 168_MHz, 1_kHz>;
    using peripheral = controller::peripherals;
    using ld1 = Gpio<controller, peripheral::gpiob, 0>;
    using ld2 = Gpio<controller, peripheral::gpiob, 7>;
    using ld3 = Gpio<controller, peripheral::gpiob, 14>;

    using debug = Usart<controller, peripheral::usart3>;
    using stlk_rx = Gpio<controller, peripheral::gpiod, 8>;
    using stlk_tx = Gpio<controller, peripheral::gpiod, 9>;

    static void init(void)
    {
        controller::init();
        debug::init();
        ld1::init();
        ld2::init();
        ld3::init();
        stlk_rx::init();
        stlk_tx::init();
    }
}