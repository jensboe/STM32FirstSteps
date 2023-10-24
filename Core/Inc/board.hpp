#pragma once
#include <stm32f446.hpp>

#include <SI/frequency.h>
namespace board
{
    struct mycontroller : public stm32f446
    {
        constexpr static SI::hertz_t<uint32_t> HSE {8_MHz};
        using debug = Usart<peripherals, peripherals::usart3>;
        static void init(void)
        {
            stm32f446::init();
            debug::init();
        }
    };
}