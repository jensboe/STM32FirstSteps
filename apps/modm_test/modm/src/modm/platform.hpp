/*
 * Copyright (c) 2016, Sascha Schade
 * Copyright (c) 2017, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/architecture.hpp>

#include "platform/clock/rcc.hpp"
#include "platform/clock/systick_timer.hpp"
#include "platform/core/delay_ns.hpp"
#include "platform/core/hardware_init.hpp"
#include "platform/core/heap_table.hpp"
#include "platform/core/peripherals.hpp"
#include "platform/core/vectors.hpp"
#include "platform/gpio/base.hpp"
#include "platform/gpio/connector.hpp"
#include "platform/gpio/data.hpp"
#include "platform/gpio/inverted.hpp"
#include "platform/gpio/pins.hpp"
#include "platform/gpio/port.hpp"
#include "platform/gpio/port_shim.hpp"
#include "platform/gpio/set.hpp"
#include "platform/gpio/software_port.hpp"
#include "platform/gpio/static.hpp"
#include "platform/gpio/unused.hpp"
#include "platform/uart/uart_3.hpp"
#include "platform/uart/uart_base.hpp"
#include "platform/uart/uart_hal_3.hpp"
#include "platform/usb/usb_fs.hpp"
