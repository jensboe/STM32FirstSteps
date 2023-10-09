#pragma once
#include <cstdint>

#include "stm32f446xx.h"

template <stm32f446::peripherals p>
struct Usart
{
    static constexpr bool isUART()
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

    static_assert(isUART(), " Given peripheral isn't a UART");

};
