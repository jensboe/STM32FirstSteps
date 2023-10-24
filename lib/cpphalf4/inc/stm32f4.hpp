#pragma once
#include "generics.hpp"
struct stm32 : public generic_controller
{
    static void init(void);
};
struct stm32f4 : public stm32
{
    static void init(void)
    {
        stm32::init();
    }
};