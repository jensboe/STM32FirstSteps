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

BlinkerTask<Board::LedGreen, 200> blinker1;

int main()
{
    Board::initialize();
    modm::rtos::Scheduler::schedule();
    return 0;
}