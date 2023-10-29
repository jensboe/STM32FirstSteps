#pragma once
#pragma once
#include <cstdint>

#include "stm32f446xx.h"
struct Nvic
{
    enum class Grouping
    {
        PG0 = 0b111,
        PG1 = 0b110,
        PG2 = 0b101,
        PG3 = 0b100,
        PG4 = 0b011,

    };

    static inline void setPriorityGrouping(const Grouping grouping)
    {
        NVIC_SetPriorityGrouping(uint32_t(grouping));
    }
};