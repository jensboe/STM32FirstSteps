#include <modm/board.hpp>
#include <modm/processing/rtos.hpp>
#include <modm/processing/timer/periodic_timer.hpp>

modm::IODeviceWrapper<modm::platform::Itm,
                      modm::IOBuffer::DiscardIfFull>
    itm_device;
modm::IOStream stream(itm_device);

template <typename Led, int wait>
class BlinkerTask : modm::rtos::Thread
{
public:
    BlinkerTask() : Thread(2, 2048, "blinker task") {}

    void run()
    {
        modm::PeriodicTimer tmr{std::chrono::milliseconds(wait)};
        uint8_t counter{0};
        Led::setOutput();
        while (1)
        {
            if (tmr.execute())
            {
                Led::toggle();
                MODM_LOG_WARNING << "Led status changed." << modm::endl;
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
        modm::PeriodicTimer tmr{std::chrono::milliseconds(1000ms)};
        uint8_t counter{0};
        while (1)
        {
            if (tmr.execute())
            {

                stream << "I am an info message" << modm::endl;
            }

            vTaskDelay(1);
        }

        vTaskDelete(0);
    }
};

BlinkerTask<Board::LedGreen, 900> blinker1;
BlinkerTask<Board::LedRed, 1100> blinker2;
BlinkerTask<Board::LedBlue, 1600> blinker3;
BeepTask beep;
int main()
{
    Board::initialize();
    modm::platform::Itm::initialize();
    modm::rtos::Scheduler::schedule();
    return 0;
}