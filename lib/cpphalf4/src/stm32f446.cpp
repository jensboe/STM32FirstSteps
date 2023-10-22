#include "stm32f446.hpp"
#include "Rcc.hpp"
#include "Flash.hpp"
#include "Pwr.hpp"

void stm32f446::init(void)
{
    stm32f4::init();
    Flash::setICEN(true);
    Flash::setDCEN(true);
    Flash::setPRFTEN(true);
    Rcc::APB1::setPWR(true);
    Pwr::setVOS(Pwr::VOS::SCALE1);
    Flash::setLatency(5);
    Rcc::HSI::enable();
    Rcc::SystemClock::setSource(Rcc::SystemClock::Source::HSI);
    Rcc::HSE::enable(Rcc::HSE::Type::CLOCK);
    const Rcc::PLL::config cfg =
        {
            .src = Rcc::PLL::Source::HSE,
            .M = 4,
            .N = 168,
            .Pval = Rcc::PLL::P::DIV2,
            .Q = 7,
            .R = 2,
        };
    Rcc::PLL::set(cfg);
    Rcc::AHB::set(Rcc::AHB::DIV::DIV1);
    Rcc::AHB1::set(Rcc::AHB1::DIV::DIV4);
    Rcc::AHB2::set(Rcc::AHB2::DIV::DIV2);
    Rcc::PLL48CLK::set(Rcc::PLL48CLK::Source::PLLQ);
    Rcc::SystemClock::setSource(Rcc::SystemClock::Source::PLLCLK);

    updateSystemCoreClock();
}

	void stm32f446::updateSystemCoreClock()
	{
		SI::hertz_t<uint32_t> clk = 16_MHz;

		switch (Rcc::SystemClock::getSource())
		{
		case Rcc::SystemClock::Source::HSI:
			clk = 16_MHz;
			break;
		case Rcc::SystemClock::Source::HSE:
			clk = HSE;
			break;
		case Rcc::SystemClock::Source::PLLCLK:
		case Rcc::SystemClock::Source::PLLR:
			switch (Rcc::PLL::getSource())
			{
			case Rcc::PLL::Source::HSI:
				clk = 16_MHz;
				break;
			case Rcc::PLL::Source::HSE:
				clk = HSE;
				break;
			}
			clk = (clk / Rcc::PLL::getM()) * Rcc::PLL::getN();
			break;
		}
		switch (Rcc::SystemClock::getSource())
		{
		case Rcc::SystemClock::Source::PLLCLK:
			switch (Rcc::PLL::getP())
			{
			case Rcc::PLL::P::DIV2:
				clk = clk / 2;
				break;
			case Rcc::PLL::P::DIV4:
				clk = clk / 4;
				break;
			case Rcc::PLL::P::DIV6:
				clk = clk / 6;
				break;
			case Rcc::PLL::P::DIV8:
				clk = clk / 8;
				break;
			}
			break;
		case Rcc::SystemClock::Source::PLLR:
			clk = clk / Rcc::PLL::getR();
			break;
		}
		SystemCoreClock = clk.value();
	}