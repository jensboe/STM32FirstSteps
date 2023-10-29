#pragma once
#include <cstdint>

#include "stm32f446xx.h"
#include <SI/baudrate.h>
#include "Rcc.hpp"
#include "Gpio.hpp"
using namespace SI::literals;
template <typename controller, controller::peripherals p, SI::baudrate_t<uint32_t> baud, typename rx, typename tx>
struct Usart
{
    using peripheral = controller::peripherals;

    static_assert(controller::template isUART<p>(), " Given peripheral isn't a UART");

    constexpr static USART_TypeDef *reg(void)
    {
        if constexpr (p == peripheral::usart1)
            return USART1;
        if constexpr (p == peripheral::usart2)
            return USART2;
        if constexpr (p == peripheral::usart3)
            return USART3;
        if constexpr (p == peripheral::uart4)
            return UART4;
        if constexpr (p == peripheral::uart5)
            return UART5;
        if constexpr (p == peripheral::usart6)
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
        BY_8 = USART_CR1_OVER8,
        BY_16 = 0,
    };

    enum class WORDLENGHT
    {
        WL_8 = 0,
        WL_9 = USART_CR1_M,
    };
    constexpr static void init(void)
    {
        Rcc::enable<controller, p>();
        disable();
        setStopbits(STOPBITS::STOP_1_0);
        setOversampling(OVERSAMPLING::BY_8);
        setWordlength(WORDLENGHT::WL_8);
        setTransmitterEnable(true);
        setReceiverEnable(true);
        setBaudRate(baud);
        rx::init();
        tx::init();
        tx::setMode(tx::Mode::alternate_function);
        tx::setAlternativeFunction(controller::template getAlternateFunctionNumber<p, tx>());
        rx::setMode(rx::Mode::alternate_function);
        rx::setAlternativeFunction(controller::template getAlternateFunctionNumber<p, rx>());

        enable();
    }

    static inline void enable(void)
    {
        reg()->CR1 |= USART_CR1_UE;
    }

    static inline void disable(void)
    {
        reg()->CR1 &= ~USART_CR1_UE;
    }

    static inline void setStopbits(const STOPBITS &value)
    {
        reg()->CR2 = (reg()->CR2 & ~USART_CR2_STOP) | uint32_t(value);
    }

    static inline void setOversampling(const OVERSAMPLING &value)
    {
        reg()->CR1 = (reg()->CR1 & ~USART_CR1_OVER8_Msk) | uint32_t(value);
    }

    static inline void setWordlength(const WORDLENGHT &value)
    {
        reg()->CR1 = (reg()->CR1 & ~USART_CR1_M_Msk) | uint32_t(value);
    }

    static inline void setTransmitterEnable(const bool &value)
    {
        if (value)
        {
            reg()->CR1 |= USART_CR1_TE;
        }
        else
        {
            reg()->CR1 &= ~USART_CR1_TE;
        }
    }

    static inline void setReceiverEnable(const bool &value)
    {
        if (value)
        {
            reg()->CR1 |= USART_CR1_RE;
        }
        else
        {
            reg()->CR1 &= ~USART_CR1_RE;
        }
    }

    static inline void setBaudRate(const SI::baudrate_t<uint32_t> &baudrate)
    {
        setBRR(convertBaudrate2BRR_8(controller::Clocktree::getPCLK1().value(), baudrate.value()));
    }

    static void write(const std::string_view &str)
    {
        for (const auto &c : str)
        {
            write(c);
        }
        write('\n');
    }

    static void write(const char &c)
    {
        while (((reg()->SR & USART_SR_TXE) == USART_SR_TXE) != true)
        {
        }
        reg()->DR = c;
    }

private:
    constexpr static uint32_t convertBaudrate2BRR_8(const uint32_t &clk, const uint32_t &baudrate)
    {
        return ((calculateMantisse_8((clk), (baudrate)) << 4u) +
                ((calculate_fraq_8((clk), (baudrate)) & 0xF8u) << 1U) +
                (calculate_fraq_8((clk), (baudrate)) & 0x07u));
    }
    constexpr static uint32_t calculateMantisse_8(const uint32_t &clk, const uint32_t &baudrate)
    {
        return (calculate_div_8((clk), (baudrate)) / 100U);
    }

    constexpr static uint32_t calculate_div_8(const uint32_t &clk, const uint32_t &baudrate)
    {
        return ((uint32_t)((((uint64_t)(clk)) * 25u) / (2u * ((uint64_t)(baudrate)))));
    }

    constexpr static uint32_t calculate_fraq_8(const uint32_t &clk, const uint32_t &baudrate)
    {
        return ((((calculate_div_8(clk, baudrate) - (calculate_divmant_8(clk, baudrate) * 100u)) * 8u) + 50u) / 100U);
    }

    constexpr static uint32_t calculate_divmant_8(const uint32_t &clk, const uint32_t &baudrate)
    {
        return (calculate_div_8(clk, baudrate) / 100U);
    }

    constexpr static void setBRR(const uint32_t &baudrate)
    {
        reg()->BRR = baudrate;
    }
};
