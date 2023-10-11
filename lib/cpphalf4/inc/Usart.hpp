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

    enum class STOPBITS
    {
        STOP_1_0 = 0,
        STOP_0_5 = USART_CR2_STOP_0,
        STOP_2_0 = USART_CR2_STOP_1,
        STOP_1_5 = USART_CR2_STOP,
    };

    enum class OVERSAMPLING
    {
        BY_8     = UART_OVERSAMPLING_8,
        BY_16    = UART_OVERSAMPLING_16,
    };

    enum class WORDLENGHT
    {
        WL_8     = 0,
        WL_9    = USART_CR1_M,
    };

    static inline void init(void)
    {
        Rcc::enable<p>();
        disable();
        setStopbits(STOPBITS::STOP_1_0);
        setOversampling(OVERSAMPLING::BY_8);
        setWordlength(WORDLENGHT::WL_8);
        setTransmitterEnable(true);
        setReceiverEnable(true);
        setBaudRate(725);
        enable();
    }

    constexpr static inline void enable(void)
    {
        reg()->CR1 |= USART_CR1_UE;
    }

    constexpr static inline void disable(void)
    {
        reg()->CR1 &= ~USART_CR1_UE;
    }

    constexpr static inline void setStopbits(const STOPBITS &value)
    {
        reg()->CR2 = (reg()->CR2 & ~USART_CR2_STOP) | uint32_t(value);
    }

    constexpr static inline void setOversampling(const OVERSAMPLING &value)
    {
        reg()->CR1 = (reg()->CR1 & ~USART_CR1_OVER8_Msk) | uint32_t(value);
    }

    constexpr static inline void setWordlength(const WORDLENGHT &value)
    {
        reg()->CR1 = (reg()->CR1 & ~USART_CR1_M_Msk) | uint32_t(value); 
    }

    constexpr static inline void setTransmitterEnable(const bool &value)
    {
        if(value)
        {
            reg()->CR1 |= USART_CR1_TE;
        }
        else
        {
            reg()->CR1 &= ~USART_CR1_TE;
        }
    }

    constexpr static inline void setReceiverEnable(const bool &value)
    {
        if(value)
        {
            reg()->CR1 |= USART_CR1_RE;
        }
        else
        {
            reg()->CR1 &= ~USART_CR1_RE;
        }
    }
    constexpr static inline void setBaudRate(const uint32_t &baudrate)
    {
        reg()->BRR = baudrate;
    }
};
