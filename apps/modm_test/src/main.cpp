#include <modm/board.hpp>

int main()
{
    Board::initialize();
    Board::Leds::setOutput();

    while (true)
    {
        Board::Leds::toggle();
        modm::delay(Board::Button::read() ? 250ms : 500ms);

#ifdef MODM_BOARD_HAS_LOGGER
        static uint32_t counter(0);
        MODM_LOG_INFO << "Loop counter: " << (counter++) << modm::endl;
#endif
    }
    return 0;
}