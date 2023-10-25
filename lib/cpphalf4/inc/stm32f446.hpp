#pragma once
#include "stm32f4.hpp"
#include "SI/frequency.h"
#include "Usart.hpp"
#include "Gpio.hpp"
#include "Rcc.hpp"
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
    static void init(void);
    static void updateSystemCoreClock();
};
