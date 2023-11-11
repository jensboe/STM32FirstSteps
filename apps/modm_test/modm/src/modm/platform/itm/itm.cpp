/*
 * Copyright (c) 2019, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/platform/device.hpp>
#include "itm.hpp"

#include <modm/architecture/driver/atomic/queue.hpp>

namespace
{
	static modm::atomic::Queue<uint8_t, 250> txBuffer;
}
namespace modm::platform
{

void
Itm::initialize()
{
	// Enable Tracing Debug Unit
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	// Enable the Trace SWO output
	DBGMCU->CR |= DBGMCU_CR_TRACE_IOEN;
}

void
Itm::enable(uint8_t prescaler)
{
	// Trace Port Interface Selected Pin Protocol Register
	TPI->ACPR = prescaler;

	// Trace Port Interface Selected Pin Protocol Register
	TPI->SPPR = (0b10 << TPI_SPPR_TXMODE_Pos);

	// Trace Port Interface Formatter and Flush Control Register
	TPI->FFCR = (1 << TPI_FFCR_TrigIn_Pos);

	// Trace Port Interface Current Parallel Port Size Register
	TPI->CSPSR = 0b1;

	// Enable write access to ITM registers
	ITM->LAR  = 0xC5ACCE55;

	// Trace Privilege Register
	ITM->TPR  = 0;

	// Trace Control Register
	ITM->TCR  = (1 << ITM_TCR_TraceBusID_Pos) |
				(1 << ITM_TCR_DWTENA_Pos)     |
				(1 << ITM_TCR_ITMENA_Pos);

	// Trace Enable Register
	ITM->TER = 0b1;
}

void
Itm::writeBlocking(uint8_t data)
{
	while(not write(data)) ;
}

void
Itm::flushWriteBuffer()
{
	while(!isWriteFinished()) update();
}

bool
Itm::write(uint8_t data)
{
	if (txBuffer.push(data)) return true;
	update();
	return txBuffer.push(data);
}

std::size_t
Itm::write(const uint8_t *data, std::size_t length)
{
	std::size_t sent = 0;
	for (; sent < length; sent++)
		if (not write(*data++))
			return sent;
	return sent;
}

bool
Itm::isWriteFinished()
{
	return txBuffer.isEmpty();
}

std::size_t
Itm::discardTransmitBuffer()
{
	std::size_t count = 0;
	for(; not txBuffer.isEmpty(); txBuffer.pop())
		++count;
	return count;
}

bool
Itm::write_itm(uint32_t data, uint8_t size)
{
	if ((ITM->TCR & ITM_TCR_ITMENA_Msk) and (ITM->TER & 0b1))
	{
		// still busy with previous write
		if (ITM->PORT[0].u32 == 0)
			return false;

		switch(size)
		{
			case 1:
				ITM->PORT[0].u8 = data >> 24;
				break;
			case 2:
				ITM->PORT[0].u16 = data >> 16;
				break;
			case 4:
				ITM->PORT[0].u32 = data;
				break;
			default:
				return false;
		}
		return true;
	}
	// if ITM is disabled, just discard any writes
	return true;
}

void
Itm::update()
{
	static uint32_t buffer{0};
	static uint8_t size{0};

	while (not txBuffer.isEmpty() and size < 4)
	{
		const uint8_t data = txBuffer.get();
		txBuffer.pop();

		buffer >>= 8;
		buffer |= (data << 24);
		size++;
	}
	if (size == 3) {
		if (write_itm(buffer << 8, 2)) {
			size = 1;
			buffer &= (0xff << 24);
		}
	}
	else if (write_itm(buffer, size)) {
		size = 0;
		buffer = 0;
	}
}

}	// namespace modm::platform
