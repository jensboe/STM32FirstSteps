#include <board.hpp>
#include <modm/processing/rtos.hpp>
#include <modm/processing/timer/periodic_timer.hpp>

template <typename Led, int wait>
class BlinkerTask : modm::rtos::Thread
{
public:
    BlinkerTask() : Thread(2, 2048, "blinker task") {}

    void run()
    {
        MODM_LOG_INFO << "Scheduler was called. Start blinking." << modm::endl;
        modm::PeriodicTimer tmr{std::chrono::milliseconds(wait)};
        size_t counter{0};
        Led::setOutput();
        while (1)
        {
            if (tmr.execute())
            {
                Led::toggle();

                ++counter;
            }

            vTaskDelay(1);
        }

        vTaskDelete(0);
    }
};

BlinkerTask<Board::LedGreen, 200> blinker1;

int main()
{
    Board::initialize();
    MODM_LOG_INFO << "Booting..." << modm::endl;
    modm::rtos::Scheduler::schedule();
    return 0;
}