#pragma once
#include <cstdint>

#include "stm32f446xx.h"
struct Pwr
{
    enum class VOS{
        SCALE1 = PWR_CR_VOS,
        SCALE2 = PWR_CR_VOS_1,
        SCALE3 = PWR_CR_VOS_0,
    };
    static inline void setVOS(VOS scale)
    {
        PWR->CR = (PWR->CR & ~PWR_CR_VOS) | uint32_t(scale);
    }
};