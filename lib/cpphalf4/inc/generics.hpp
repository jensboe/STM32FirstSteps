#pragma once
#include <SI/frequency.h>

using namespace SI::literals;


    struct generic_clocktree
    {
        constexpr static uint32_t setting{};
    };
    struct generic_controller
    {
        constexpr static SI::hertz_t<uint32_t> HSE{};
        constexpr static generic_clocktree clocktree{};
    };

