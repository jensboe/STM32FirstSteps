#pragma once
#include <cstdint>

#include "stm32f446xx.h"
struct Flash
{
    static inline void setLatency(uint32_t value)
    {
        FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY) | ((value &0xF) << FLASH_ACR_LATENCY_Pos);
    }
};