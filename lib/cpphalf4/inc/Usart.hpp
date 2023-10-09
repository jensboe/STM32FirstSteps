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

    static USART_TypeDef *reg(void)
    {
        if constexpr (p == stm32::peripherals::usart1)
            return USART1;
        if constexpr (p == stm32::peripherals::usart2)
            return USART2;
        if constexpr (p == stm32::peripherals::usart3)
            return USART3;
        if constexpr (p == stm32::peripherals::uart4)
            return UART4;
        if constexpr (p == stm32::peripherals::uart5)
            return UART5;
        if constexpr (p == stm32::peripherals::usart6)
            return USART6;
        return nullptr;
    }
};
