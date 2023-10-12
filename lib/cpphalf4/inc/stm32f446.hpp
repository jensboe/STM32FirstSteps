#pragma once
#include "stm32f4.hpp"

struct stm32f446 : public stm32f4
{
    constexpr static SI::hertz_t<uint32_t> HSE{};
    enum class peripherals
    {
        usart1,
        usart2,
        usart3,
        uart4,
        uart5,
        usart6,
    };
};
