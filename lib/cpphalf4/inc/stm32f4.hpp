#pragma once
#include "generics.hpp"
#include "Nvic.hpp"
struct stm32 : public generic_controller
{
    constexpr static auto sysTick_freq = 1_kHz;
    static void init(void)
    {
        generic_controller::init();
        Nvic::setPriorityGrouping(Nvic::Grouping::PG4);
    }
};
struct stm32f4 : public stm32
{
    static void init(void)
    {
        stm32::init();
    }
};