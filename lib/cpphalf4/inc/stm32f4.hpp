#pragma once
#include "generics.hpp"
#include "Nvic.hpp"
#include "SI/frequency.h"
using namespace SI::literals;
struct stm32 : public generic_controller
{
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