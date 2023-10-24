#pragma once
#include <cstdint>

#include "stm32f446xx.h"
#include <SI/baudrate.h>
#include "Rcc.hpp"
using namespace SI::literals;
template <typename aviableperipherals, aviableperipherals p>
struct Usart
{
    constexpr static bool isUART()
    {
        if constexpr (p == aviableperipherals::usart1)
            return true;
        if constexpr (p == aviableperipherals::usart2)
            return true;
        if constexpr (p == aviableperipherals::usart3)
            return true;
        if constexpr (p == aviableperipherals::uart4)
            return true;
        if constexpr (p == aviableperipherals::uart5)
            return true;
        if constexpr (p == aviableperipherals::usart6)
            return true;
        return false;
    }

    static_assert(isUART(), " Given peripheral isn't a UART");

    constexpr static USART_TypeDef *reg(void)
    {
        if constexpr (p == aviableperipherals::usart1)
            return USART1;
        if constexpr (p == aviableperipherals::usart2)
            return USART2;
        if constexpr (p == aviableperipherals::usart3)
            return USART3;
        if constexpr (p == aviableperipherals::uart4)
            return UART4;
        if constexpr (p == aviableperipherals::uart5)
            return UART5;
        if constexpr (p == aviableperipherals::usart6)
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
        Rcc::enable<aviableperipherals, p>();
        disable();
        setStopbits(STOPBITS::STOP_1_0);
        setOversampling(OVERSAMPLING::BY_8);
        setWordlength(WORDLENGHT::WL_8);
        setTransmitterEnable(true);
        setReceiverEnable(true);
        setBaudRate(115'200_Bd);
        enable();
    }

    constexpr static void enable(void)
    {
        reg()->CR1 |= USART_CR1_UE;
    }

    constexpr static void disable(void)
    {
        reg()->CR1 &= ~USART_CR1_UE;
    }

    constexpr static void setStopbits(const STOPBITS &value)
    {
        reg()->CR2 = (reg()->CR2 & ~USART_CR2_STOP) | uint32_t(value);
    }

    constexpr static void setOversampling(const OVERSAMPLING &value)
    {
        reg()->CR1 = (reg()->CR1 & ~USART_CR1_OVER8_Msk) | uint32_t(value);
    }

    constexpr static void setWordlength(const WORDLENGHT &value)
    {
        reg()->CR1 = (reg()->CR1 & ~USART_CR1_M_Msk) | uint32_t(value);
    }

    constexpr static void setTransmitterEnable(const bool &value)
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

    constexpr static void setReceiverEnable(const bool &value)
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
    constexpr static void setBaudRate(const SI::baudrate_t<uint32_t> &baudrate)
    {
        setBRR(convertBaudrate2BRR_8(168000000 / 4, baudrate.value()));
    }

    static void write(const std::string_view& str)
    {
        for(const auto &c : str)
        {
            write(c);
        }
        write('\n');
    }

    static void write(const char& c)
    {
        while(((reg()->SR & USART_SR_TXE) == USART_SR_TXE) != true)
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
