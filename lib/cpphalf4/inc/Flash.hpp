#pragma once
#include <cstdint>

#include "stm32f446xx.h"
struct Flash
{
    static inline void setLatency(const uint32_t value)
    {
        FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY) | ((value &0xF) << FLASH_ACR_LATENCY_Pos);
    }
    static inline void setICEN(const bool value)
    {
        if(value)
        {
            FLASH->ACR |= FLASH_ACR_ICEN;
        }
        else
        {
            FLASH->ACR &= ~FLASH_ACR_ICEN;
        }
    }

    static inline void setDCEN(const bool value)
    {
        if(value)
        {
            FLASH->ACR |= FLASH_ACR_DCEN;
        }
        else
        {
            FLASH->ACR &= ~FLASH_ACR_DCEN;
        }
    }

    static inline void setPRFTEN(const bool value)
    {
        if(value)
        {
            FLASH->ACR |= FLASH_ACR_PRFTEN;
        }
        else
        {
            FLASH->ACR &= ~FLASH_ACR_PRFTEN;
        }
    }
};