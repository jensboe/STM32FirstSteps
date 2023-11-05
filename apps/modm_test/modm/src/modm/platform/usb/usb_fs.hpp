/*
* Copyright (c) 2020, Erik Henriksson
* Copyright (c) 2020, Niklas Hauser
*
* This file is part of the modm project.
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
// ----------------------------------------------------------------------------

#pragma once

#include <modm/platform/device.hpp>
#include <modm/platform/gpio/connector.hpp>

namespace modm::platform
{

/// @ingroup modm_platform_usb modm_platform_usb_fs
class UsbFs
{
public:
	template< class SystemClock >
	static void
	initialize(uint8_t priority=3)
	{
		static_assert(SystemClock::Usb == 48_MHz, "UsbFs must have a 48MHz clock!");
		Rcc::enable<Peripheral::Usbotgfs>();
		NVIC_SetPriority(OTG_FS_IRQn, priority);
		NVIC_SetPriority(OTG_FS_WKUP_IRQn, priority);
	}

	template< class... Signals >
	static void
	connect()
	{
		using Connector = GpioConnector<Peripheral::Usbotgfs, Signals...>;
		using Dp = typename Connector::template GetSignal< Gpio::Signal::Dp >;
		using Dm = typename Connector::template GetSignal< Gpio::Signal::Dm >;
		using Id = typename Connector::template GetSignal< Gpio::Signal::Id >;
		static_assert(((Connector::template IsValid<Dp> and Connector::template IsValid<Dm>) and sizeof...(Signals) >= 2),
					  "UsbFs::connect() requires at least one Dp and one Dm signal!");

		Id::configure(Gpio::OutputType::OpenDrain, Gpio::OutputSpeed::High);
		Id::configure(Gpio::InputType::PullUp);
		Connector::connect();
	}
};

} // namespace modm::platform