#pragma once
#include <cstdint>

#include "stm32f446xx.h"
template <typename aviableperipherals, aviableperipherals p, uint32_t pin_nr>
struct Gpio
{
    constexpr static bool isGPIO()
    {
        if constexpr (p == aviableperipherals::gpioa)
            return true;
        if constexpr (p == aviableperipherals::gpiob)
            return true;
        if constexpr (p == aviableperipherals::gpioc)
            return true;
        if constexpr (p == aviableperipherals::gpiod)
            return true;
        if constexpr (p == aviableperipherals::gpioe)
            return true;
        if constexpr (p == aviableperipherals::gpiof)
            return true;
        if constexpr (p == aviableperipherals::gpiog)
            return true;
        if constexpr (p == aviableperipherals::gpioh)
            return true;
        return false;
    }

    static_assert(isGPIO(), " Given peripheral isn't a GPIO");

    constexpr static GPIO_TypeDef *reg(void)
    {
        if constexpr (p == aviableperipherals::gpioa)
            return GPIOA;
        if constexpr (p == aviableperipherals::gpiob)
            return GPIOB;
        if constexpr (p == aviableperipherals::gpioc)
            return GPIOC;
        if constexpr (p == aviableperipherals::gpiod)
            return GPIOD;
        if constexpr (p == aviableperipherals::gpioe)
            return GPIOE;
        if constexpr (p == aviableperipherals::gpiof)
            return GPIOF;
        if constexpr (p == aviableperipherals::gpiog)
            return GPIOG;
        if constexpr (p == aviableperipherals::gpioh)
            return GPIOH;

        return nullptr;
    }
    constexpr static void init(void)
    {
        Rcc::enable<aviableperipherals, p>();
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