    #include "stm32f4.hpp"
    #include "Nvic.hpp"
    
    void stm32::init(void)
    {
        generic_controller::init();
        Nvic::setPriorityGrouping(Nvic::Grouping::PG4);
    }