#pragma once
#include <cstdint>

#include "stm32f446xx.h"
template <typename controller, controller::peripherals p, uint32_t pin_nr>
struct Gpio
{
    using peripheral = controller::peripherals;
    constexpr static bool isGPIO()
    {
        if constexpr (p == peripheral::gpioa)
            return true;
        if constexpr (p == peripheral::gpiob)
            return true;
        if constexpr (p == peripheral::gpioc)
            return true;
        if constexpr (p == peripheral::gpiod)
            return true;
        if constexpr (p == peripheral::gpioe)
            return true;
        if constexpr (p == peripheral::gpiof)
            return true;
        if constexpr (p == peripheral::gpiog)
            return true;
        if constexpr (p == peripheral::gpioh)
            return true;
        return false;
    }

    static_assert(isGPIO(), " Given peripheral isn't a GPIO");

    constexpr static GPIO_TypeDef *reg(void)
    {
        if constexpr (p == peripheral::gpioa)
            return GPIOA;
        if constexpr (p == peripheral::gpiob)
            return GPIOB;
        if constexpr (p == peripheral::gpioc)
            return GPIOC;
        if constexpr (p == peripheral::gpiod)
            return GPIOD;
        if constexpr (p == peripheral::gpioe)
            return GPIOE;
        if constexpr (p == peripheral::gpiof)
            return GPIOF;
        if constexpr (p == peripheral::gpiog)
            return GPIOG;
        if constexpr (p == peripheral::gpioh)
            return GPIOH;

        return nullptr;
    }
    constexpr static void init(void)
    {
        Rcc::enable<controller, p>();
        reg()->MODER |= 0b01 << (pin_nr * 2);
    }
    constexpr static void write(const bool &value)
    {
        if (value)
        {
            reg()->BSRR = (1 << pin_nr);
        }
        else
        {
            reg()->BSRR = (1 << pin_nr) << 16;
        }
    }
};