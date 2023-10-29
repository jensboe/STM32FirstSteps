#pragma once
#include <cstdint>

#include "stm32f446xx.h"
template <typename controller, controller::peripherals p, uint32_t pin_nr>
struct Gpio
{
    using peripheral = controller::peripherals;

    static_assert(controller::template isGPIO<p>(), " Given peripheral isn't a GPIO");

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
    static constexpr uint32_t getPinNumber(void)
    {
        return pin_nr;
    }
    static constexpr controller::peripherals getPeripheral(void)
    {
        return p;
    }

    enum class Mode
    {
        input = 0b00,
        output = 0b01,
        alternate_function = 0b10,
        analog = 0b11,
    };

    enum class OutputType
    {
        push_pull = 0b0,
        open_train = 0b1,
    };

    enum class OutputSpeed
    {
        low = 0b00,
        medium = 0b01,
        fast = 0b10,
        high = 0b11,
    };

    enum class PullResistor
    {
        no = 0b00,
        up = 0b01,
        down = 0b10,
    };

    static inline void init(void)
    {
        Rcc::enable<controller, p>();
        setMode(Mode::input);
    }

    static inline void setMode(const Mode &mode)
    {
        reg()->MODER = (reg()->MODER & ~(0b11 << (pin_nr * 2))) | uint32_t(mode) << (pin_nr * 2);
    }

    static inline void setOutputType(const OutputType &outputType)
    {
        reg()->OTYPER = (reg()->OTYPER & ~(1 << (pin_nr))) | uint32_t(outputType) << (pin_nr);
    }

    static inline void setOutputSpeed(const OutputSpeed &outputSpeed)
    {
        reg()->OSPEEDR = (reg()->OSPEEDR & ~(0b11 << (pin_nr * 2))) | uint32_t(outputSpeed) << (pin_nr * 2);
    }

    static inline void setOutputSpeed(const PullResistor &pullresistor)
    {
        reg()->PUPDR = (reg()->PUPDR & ~(1 << (pin_nr))) | uint32_t(pullresistor) << (pin_nr);
    }

    static inline void setAlternativeFunction(const uint8_t &alternative_function)
    {
        reg()->AFR[(pin_nr / 8)] = (reg()->AFR[(pin_nr / 8)] & ~(0b1111 << ((pin_nr % 8) * 4))) | (alternative_function & 0x0F) << ((pin_nr % 8) * 4);
    }

    static inline bool read(void)
    {
        return reg()->IDR & (1 << pin_nr);
    }

    static inline void write(const bool &value)
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