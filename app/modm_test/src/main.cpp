#include <modm/board.hpp>
#include <modm/processing/rtos.hpp>
#include <modm/processing/timer/periodic_timer.hpp>

template <typename Led, int wait>
class BlinkerTask : modm::rtos::Thread
{
public:
    BlinkerTask() : Thread(2, 2048, "blinker task") {}

    void run()
    {
        modm::PeriodicTimer tmr{std::chrono::milliseconds(wait)};
        size_t counter{0};
        Led::setOutput();
        while (1)
        {
            if (tmr.execute())
            {
                Led::toggle();
                MODM_LOG_WARNING << "Led status changed." << counter << modm::endl;
                ++counter;
            }

            vTaskDelay(1);
        }

        vTaskDelete(0);
    }
};
class BeepTask : modm::rtos::Thread
{
public:
    BeepTask() : Thread(2, 2048, "blinker task") {}
    void run()
    {
        modm::PeriodicTimer tmr{std::chrono::milliseconds(100ms)};
        size_t counter{0};
        while (1)
        {
            if (tmr.execute())
            {
                MODM_LOG_INFO << counter << modm::endl;
                counter += 10;
            }

            vTaskDelay(1);
        }

        vTaskDelete(0);
    }
};

BlinkerTask<Board::LedGreen, 100> blinker1;
BlinkerTask<Board::LedRed, 100> blinker2;
BlinkerTask<Board::LedBlue, 100> blinker3;
BeepTask beep;
int main()
{
    Board::initialize();
    modm::rtos::Scheduler::schedule();
    return 0;
}