#pragma once
#include "generics.hpp"

struct stm32 : public generic_controller
{
    constexpr static SI::hertz_t<uint32_t> HSE{};
};
struct stm32f4 : public stm32
{
    constexpr static SI::hertz_t<uint32_t> HSE{};
};