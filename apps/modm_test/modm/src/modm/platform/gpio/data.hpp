/*
 * Copyright (c) 2021, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#pragma once

#include "base.hpp"

/// @cond
namespace modm::platform::detail
{

template<class Signal, Peripheral p> struct SignalConnection;
template<class Data, Peripheral p> static constexpr int8_t AdcChannel = -1;
template<class Data, Peripheral p> static constexpr int8_t DacChannel = -1;

struct DataUnused {};

struct DataA0 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Af2 { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::Af2; };
	struct Ch1 { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Cts { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct Etr { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct In0 { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::In0; };
	struct Tx { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
	struct Wkup0 { using Data = DataA0; static constexpr Gpio::Signal Signal = Gpio::Signal::Wkup0; };
};
template<Peripheral p> struct SignalConnection<DataA0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA0::Af2, p> {
	static_assert((p == Peripheral::Rtc),"GpioA0::Af2 only connects to Rtc!"); };
template<Peripheral p> struct SignalConnection<DataA0::Ch1, p> {
	static_assert((p == Peripheral::Tim2) or (p == Peripheral::Tim5),
		"GpioA0::Ch1 only connects to Tim2 or Tim5!"); };
template<Peripheral p> struct SignalConnection<DataA0::Cts, p> {
	static_assert((p == Peripheral::Usart2),"GpioA0::Cts only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataA0::Etr, p> {
	static_assert((p == Peripheral::Tim2) or (p == Peripheral::Tim8),
		"GpioA0::Etr only connects to Tim2 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataA0::In0, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioA0::In0 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataA0::Tx, p> {
	static_assert((p == Peripheral::Uart4),"GpioA0::Tx only connects to Uart4!"); };
template<Peripheral p> struct SignalConnection<DataA0::Wkup0, p> {
	static_assert((p == Peripheral::Sys),"GpioA0::Wkup0 only connects to Sys!"); };
template<> struct SignalConnection<DataA0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA0::Af2, Peripheral::Rtc> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA0::Ch1, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA0::Ch1, Peripheral::Tim5> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataA0::Cts, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA0::Etr, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA0::Etr, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataA0::In0, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA0::In0, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA0::In0, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA0::Tx, Peripheral::Uart4> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataA0::Wkup0, Peripheral::Sys> { static constexpr int8_t af = -1; };
template<> constexpr int8_t AdcChannel<DataA0, Peripheral::Adc1> = 0;
template<> constexpr int8_t AdcChannel<DataA0, Peripheral::Adc2> = 0;
template<> constexpr int8_t AdcChannel<DataA0, Peripheral::Adc3> = 0;

struct DataA1 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io3 { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io3; };
	struct Ch2 { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct In1 { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::In1; };
	struct Mclkb { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::Mclkb; };
	struct Rts { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
	struct Rx { using Data = DataA1; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataA1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA1::Bk1io3, p> {
	static_assert((p == Peripheral::Quadspi),"GpioA1::Bk1io3 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataA1::Ch2, p> {
	static_assert((p == Peripheral::Tim2) or (p == Peripheral::Tim5),
		"GpioA1::Ch2 only connects to Tim2 or Tim5!"); };
template<Peripheral p> struct SignalConnection<DataA1::In1, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioA1::In1 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataA1::Mclkb, p> {
	static_assert((p == Peripheral::Sai2),"GpioA1::Mclkb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataA1::Rts, p> {
	static_assert((p == Peripheral::Usart2),"GpioA1::Rts only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataA1::Rx, p> {
	static_assert((p == Peripheral::Uart4),"GpioA1::Rx only connects to Uart4!"); };
template<> struct SignalConnection<DataA1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA1::Bk1io3, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataA1::Ch2, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA1::Ch2, Peripheral::Tim5> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataA1::In1, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA1::In1, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA1::In1, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA1::Mclkb, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataA1::Rts, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA1::Rx, Peripheral::Uart4> { static constexpr int8_t af = 8; };
template<> constexpr int8_t AdcChannel<DataA1, Peripheral::Adc1> = 1;
template<> constexpr int8_t AdcChannel<DataA1, Peripheral::Adc2> = 1;
template<> constexpr int8_t AdcChannel<DataA1, Peripheral::Adc3> = 1;

struct DataA2 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataA2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataA2; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ch3 { using Data = DataA2; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct In2 { using Data = DataA2; static constexpr Gpio::Signal Signal = Gpio::Signal::In2; };
	struct Sckb { using Data = DataA2; static constexpr Gpio::Signal Signal = Gpio::Signal::Sckb; };
	struct Tx { using Data = DataA2; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataA2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA2::Ch1, p> {
	static_assert((p == Peripheral::Tim9),"GpioA2::Ch1 only connects to Tim9!"); };
template<Peripheral p> struct SignalConnection<DataA2::Ch3, p> {
	static_assert((p == Peripheral::Tim2) or (p == Peripheral::Tim5),
		"GpioA2::Ch3 only connects to Tim2 or Tim5!"); };
template<Peripheral p> struct SignalConnection<DataA2::In2, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioA2::In2 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataA2::Sckb, p> {
	static_assert((p == Peripheral::Sai2),"GpioA2::Sckb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataA2::Tx, p> {
	static_assert((p == Peripheral::Usart2),"GpioA2::Tx only connects to Usart2!"); };
template<> struct SignalConnection<DataA2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA2::Ch1, Peripheral::Tim9> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataA2::Ch3, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA2::Ch3, Peripheral::Tim5> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataA2::In2, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA2::In2, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA2::In2, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA2::Sckb, Peripheral::Sai2> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataA2::Tx, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> constexpr int8_t AdcChannel<DataA2, Peripheral::Adc1> = 2;
template<> constexpr int8_t AdcChannel<DataA2, Peripheral::Adc2> = 2;
template<> constexpr int8_t AdcChannel<DataA2, Peripheral::Adc3> = 2;

struct DataA3 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Ch4 { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct Fsa { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsa; };
	struct In3 { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::In3; };
	struct Rx { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Ulpid0 { using Data = DataA3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid0; };
};
template<Peripheral p> struct SignalConnection<DataA3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA3::Ch2, p> {
	static_assert((p == Peripheral::Tim9),"GpioA3::Ch2 only connects to Tim9!"); };
template<Peripheral p> struct SignalConnection<DataA3::Ch4, p> {
	static_assert((p == Peripheral::Tim2) or (p == Peripheral::Tim5),
		"GpioA3::Ch4 only connects to Tim2 or Tim5!"); };
template<Peripheral p> struct SignalConnection<DataA3::Fsa, p> {
	static_assert((p == Peripheral::Sai1),"GpioA3::Fsa only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataA3::In3, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioA3::In3 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataA3::Rx, p> {
	static_assert((p == Peripheral::Usart2),"GpioA3::Rx only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataA3::Ulpid0, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioA3::Ulpid0 only connects to Usbotghs!"); };
template<> struct SignalConnection<DataA3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA3::Ch2, Peripheral::Tim9> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataA3::Ch4, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA3::Ch4, Peripheral::Tim5> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataA3::Fsa, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataA3::In3, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA3::In3, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA3::In3, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA3::Rx, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA3::Ulpid0, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataA3, Peripheral::Adc1> = 3;
template<> constexpr int8_t AdcChannel<DataA3, Peripheral::Adc2> = 3;
template<> constexpr int8_t AdcChannel<DataA3, Peripheral::Adc3> = 3;

struct DataA4 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ck { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Hsync { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::Hsync; };
	struct In4 { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::In4; };
	struct Nss { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Out1 { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::Out1; };
	struct Sof { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::Sof; };
	struct Ws { using Data = DataA4; static constexpr Gpio::Signal Signal = Gpio::Signal::Ws; };
};
template<Peripheral p> struct SignalConnection<DataA4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA4::Ck, p> {
	static_assert((p == Peripheral::Usart2),"GpioA4::Ck only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataA4::Hsync, p> {
	static_assert((p == Peripheral::Dcmi),"GpioA4::Hsync only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataA4::In4, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioA4::In4 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataA4::Nss, p> {
	static_assert((p == Peripheral::Spi1) or (p == Peripheral::Spi3),
		"GpioA4::Nss only connects to Spi1 or Spi3!"); };
template<Peripheral p> struct SignalConnection<DataA4::Out1, p> {
	static_assert((p == Peripheral::Dac),"GpioA4::Out1 only connects to Dac!"); };
template<Peripheral p> struct SignalConnection<DataA4::Sof, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioA4::Sof only connects to Usbotghs!"); };
template<Peripheral p> struct SignalConnection<DataA4::Ws, p> {
	static_assert((p == Peripheral::I2s1) or (p == Peripheral::I2s3),
		"GpioA4::Ws only connects to I2s1 or I2s3!"); };
template<> struct SignalConnection<DataA4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA4::Ck, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA4::Hsync, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataA4::In4, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA4::In4, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA4::Nss, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA4::Nss, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataA4::Out1, Peripheral::Dac> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA4::Sof, Peripheral::Usbotghs> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataA4::Ws, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA4::Ws, Peripheral::I2s3> { static constexpr int8_t af = 6; };
template<> constexpr int8_t AdcChannel<DataA4, Peripheral::Adc1> = 4;
template<> constexpr int8_t AdcChannel<DataA4, Peripheral::Adc2> = 4;
template<> constexpr int8_t DacChannel<DataA4, Peripheral::Dac> = 1;

struct DataA5 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ch1n { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1n; };
	struct Ck { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Etr { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct In5 { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::In5; };
	struct Out2 { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Out2; };
	struct Sck { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Ulpick { using Data = DataA5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpick; };
};
template<Peripheral p> struct SignalConnection<DataA5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA5::Ch1, p> {
	static_assert((p == Peripheral::Tim2),"GpioA5::Ch1 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataA5::Ch1n, p> {
	static_assert((p == Peripheral::Tim8),"GpioA5::Ch1n only connects to Tim8!"); };
template<Peripheral p> struct SignalConnection<DataA5::Ck, p> {
	static_assert((p == Peripheral::I2s1),"GpioA5::Ck only connects to I2s1!"); };
template<Peripheral p> struct SignalConnection<DataA5::Etr, p> {
	static_assert((p == Peripheral::Tim2),"GpioA5::Etr only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataA5::In5, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioA5::In5 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataA5::Out2, p> {
	static_assert((p == Peripheral::Dac),"GpioA5::Out2 only connects to Dac!"); };
template<Peripheral p> struct SignalConnection<DataA5::Sck, p> {
	static_assert((p == Peripheral::Spi1),"GpioA5::Sck only connects to Spi1!"); };
template<Peripheral p> struct SignalConnection<DataA5::Ulpick, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioA5::Ulpick only connects to Usbotghs!"); };
template<> struct SignalConnection<DataA5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA5::Ch1, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA5::Ch1n, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataA5::Ck, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA5::Etr, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA5::In5, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA5::In5, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA5::Out2, Peripheral::Dac> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA5::Sck, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA5::Ulpick, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataA5, Peripheral::Adc1> = 5;
template<> constexpr int8_t AdcChannel<DataA5, Peripheral::Adc2> = 5;
template<> constexpr int8_t DacChannel<DataA5, Peripheral::Dac> = 2;

struct DataA6 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bkin { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::Bkin; };
	struct Ch1 { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct In6 { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::In6; };
	struct Mck { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::Mck; };
	struct Miso { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Pixclk { using Data = DataA6; static constexpr Gpio::Signal Signal = Gpio::Signal::Pixclk; };
};
template<Peripheral p> struct SignalConnection<DataA6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA6::Bkin, p> {
	static_assert((p == Peripheral::Tim1) or (p == Peripheral::Tim8),
		"GpioA6::Bkin only connects to Tim1 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataA6::Ch1, p> {
	static_assert((p == Peripheral::Tim3) or (p == Peripheral::Tim13),
		"GpioA6::Ch1 only connects to Tim3 or Tim13!"); };
template<Peripheral p> struct SignalConnection<DataA6::In6, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioA6::In6 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataA6::Mck, p> {
	static_assert((p == Peripheral::I2s2),"GpioA6::Mck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataA6::Miso, p> {
	static_assert((p == Peripheral::Spi1),"GpioA6::Miso only connects to Spi1!"); };
template<Peripheral p> struct SignalConnection<DataA6::Pixclk, p> {
	static_assert((p == Peripheral::Dcmi),"GpioA6::Pixclk only connects to Dcmi!"); };
template<> struct SignalConnection<DataA6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA6::Bkin, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA6::Bkin, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataA6::Ch1, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataA6::Ch1, Peripheral::Tim13> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataA6::In6, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA6::In6, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA6::Mck, Peripheral::I2s2> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataA6::Miso, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA6::Pixclk, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> constexpr int8_t AdcChannel<DataA6, Peripheral::Adc1> = 6;
template<> constexpr int8_t AdcChannel<DataA6, Peripheral::Adc2> = 6;

struct DataA7 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ch1n { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1n; };
	struct Ch2 { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct In7 { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::In7; };
	struct Mosi { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sd { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sdnwe { using Data = DataA7; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdnwe; };
};
template<Peripheral p> struct SignalConnection<DataA7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA7::Ch1, p> {
	static_assert((p == Peripheral::Tim14),"GpioA7::Ch1 only connects to Tim14!"); };
template<Peripheral p> struct SignalConnection<DataA7::Ch1n, p> {
	static_assert((p == Peripheral::Tim1) or (p == Peripheral::Tim8),
		"GpioA7::Ch1n only connects to Tim1 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataA7::Ch2, p> {
	static_assert((p == Peripheral::Tim3),"GpioA7::Ch2 only connects to Tim3!"); };
template<Peripheral p> struct SignalConnection<DataA7::In7, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioA7::In7 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataA7::Mosi, p> {
	static_assert((p == Peripheral::Spi1),"GpioA7::Mosi only connects to Spi1!"); };
template<Peripheral p> struct SignalConnection<DataA7::Sd, p> {
	static_assert((p == Peripheral::I2s1),"GpioA7::Sd only connects to I2s1!"); };
template<Peripheral p> struct SignalConnection<DataA7::Sdnwe, p> {
	static_assert((p == Peripheral::Fmc),"GpioA7::Sdnwe only connects to Fmc!"); };
template<> struct SignalConnection<DataA7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA7::Ch1, Peripheral::Tim14> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataA7::Ch1n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA7::Ch1n, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataA7::Ch2, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataA7::In7, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA7::In7, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataA7::Mosi, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA7::Sd, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA7::Sdnwe, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> constexpr int8_t AdcChannel<DataA7, Peripheral::Adc1> = 7;
template<> constexpr int8_t AdcChannel<DataA7, Peripheral::Adc2> = 7;

struct DataA8 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataA8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataA8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ck { using Data = DataA8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Mco1 { using Data = DataA8; static constexpr Gpio::Signal Signal = Gpio::Signal::Mco1; };
	struct Scl { using Data = DataA8; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
	struct Sof { using Data = DataA8; static constexpr Gpio::Signal Signal = Gpio::Signal::Sof; };
};
template<Peripheral p> struct SignalConnection<DataA8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA8::Ch1, p> {
	static_assert((p == Peripheral::Tim1),"GpioA8::Ch1 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataA8::Ck, p> {
	static_assert((p == Peripheral::Usart1),"GpioA8::Ck only connects to Usart1!"); };
template<Peripheral p> struct SignalConnection<DataA8::Mco1, p> {
	static_assert((p == Peripheral::Rcc),"GpioA8::Mco1 only connects to Rcc!"); };
template<Peripheral p> struct SignalConnection<DataA8::Scl, p> {
	static_assert((p == Peripheral::I2c3),"GpioA8::Scl only connects to I2c3!"); };
template<Peripheral p> struct SignalConnection<DataA8::Sof, p> {
	static_assert((p == Peripheral::Usbotgfs),"GpioA8::Sof only connects to Usbotgfs!"); };
template<> struct SignalConnection<DataA8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA8::Ch1, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA8::Ck, Peripheral::Usart1> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA8::Mco1, Peripheral::Rcc> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataA8::Scl, Peripheral::I2c3> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataA8::Sof, Peripheral::Usbotgfs> { static constexpr int8_t af = 10; };

struct DataA9 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Ck { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D0 { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::D0; };
	struct Sck { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Sdb { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdb; };
	struct Smba { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Smba; };
	struct Tx { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
	struct Vbus { using Data = DataA9; static constexpr Gpio::Signal Signal = Gpio::Signal::Vbus; };
};
template<Peripheral p> struct SignalConnection<DataA9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA9::Ch2, p> {
	static_assert((p == Peripheral::Tim1),"GpioA9::Ch2 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataA9::Ck, p> {
	static_assert((p == Peripheral::I2s2),"GpioA9::Ck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataA9::D0, p> {
	static_assert((p == Peripheral::Dcmi),"GpioA9::D0 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataA9::Sck, p> {
	static_assert((p == Peripheral::Spi2),"GpioA9::Sck only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataA9::Sdb, p> {
	static_assert((p == Peripheral::Sai1),"GpioA9::Sdb only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataA9::Smba, p> {
	static_assert((p == Peripheral::I2c3),"GpioA9::Smba only connects to I2c3!"); };
template<Peripheral p> struct SignalConnection<DataA9::Tx, p> {
	static_assert((p == Peripheral::Usart1),"GpioA9::Tx only connects to Usart1!"); };
template<Peripheral p> struct SignalConnection<DataA9::Vbus, p> {
	static_assert((p == Peripheral::Usbotgfs),"GpioA9::Vbus only connects to Usbotgfs!"); };
template<> struct SignalConnection<DataA9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA9::Ch2, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA9::Ck, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA9::D0, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataA9::Sck, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA9::Sdb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataA9::Smba, Peripheral::I2c3> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataA9::Tx, Peripheral::Usart1> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA9::Vbus, Peripheral::Usbotgfs> { static constexpr int8_t af = -1; };

struct DataA10 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataA10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3 { using Data = DataA10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct D1 { using Data = DataA10; static constexpr Gpio::Signal Signal = Gpio::Signal::D1; };
	struct Id { using Data = DataA10; static constexpr Gpio::Signal Signal = Gpio::Signal::Id; };
	struct Rx { using Data = DataA10; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataA10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA10::Ch3, p> {
	static_assert((p == Peripheral::Tim1),"GpioA10::Ch3 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataA10::D1, p> {
	static_assert((p == Peripheral::Dcmi),"GpioA10::D1 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataA10::Id, p> {
	static_assert((p == Peripheral::Usbotgfs),"GpioA10::Id only connects to Usbotgfs!"); };
template<Peripheral p> struct SignalConnection<DataA10::Rx, p> {
	static_assert((p == Peripheral::Usart1),"GpioA10::Rx only connects to Usart1!"); };
template<> struct SignalConnection<DataA10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA10::Ch3, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA10::D1, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataA10::Id, Peripheral::Usbotgfs> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataA10::Rx, Peripheral::Usart1> { static constexpr int8_t af = 7; };

struct DataA11 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataA11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch4 { using Data = DataA11; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct Cts { using Data = DataA11; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct Dm { using Data = DataA11; static constexpr Gpio::Signal Signal = Gpio::Signal::Dm; };
	struct Rx { using Data = DataA11; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataA11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA11::Ch4, p> {
	static_assert((p == Peripheral::Tim1),"GpioA11::Ch4 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataA11::Cts, p> {
	static_assert((p == Peripheral::Usart1),"GpioA11::Cts only connects to Usart1!"); };
template<Peripheral p> struct SignalConnection<DataA11::Dm, p> {
	static_assert((p == Peripheral::Usbotgfs),"GpioA11::Dm only connects to Usbotgfs!"); };
template<Peripheral p> struct SignalConnection<DataA11::Rx, p> {
	static_assert((p == Peripheral::Can1),"GpioA11::Rx only connects to Can1!"); };
template<> struct SignalConnection<DataA11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA11::Ch4, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA11::Cts, Peripheral::Usart1> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA11::Dm, Peripheral::Usbotgfs> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataA11::Rx, Peripheral::Can1> { static constexpr int8_t af = 9; };

struct DataA12 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataA12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Dp { using Data = DataA12; static constexpr Gpio::Signal Signal = Gpio::Signal::Dp; };
	struct Etr { using Data = DataA12; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct Fsb { using Data = DataA12; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsb; };
	struct Rts { using Data = DataA12; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
	struct Tx { using Data = DataA12; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataA12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA12::Dp, p> {
	static_assert((p == Peripheral::Usbotgfs),"GpioA12::Dp only connects to Usbotgfs!"); };
template<Peripheral p> struct SignalConnection<DataA12::Etr, p> {
	static_assert((p == Peripheral::Tim1),"GpioA12::Etr only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataA12::Fsb, p> {
	static_assert((p == Peripheral::Sai2),"GpioA12::Fsb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataA12::Rts, p> {
	static_assert((p == Peripheral::Usart1),"GpioA12::Rts only connects to Usart1!"); };
template<Peripheral p> struct SignalConnection<DataA12::Tx, p> {
	static_assert((p == Peripheral::Can1),"GpioA12::Tx only connects to Can1!"); };
template<> struct SignalConnection<DataA12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA12::Dp, Peripheral::Usbotgfs> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataA12::Etr, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA12::Fsb, Peripheral::Sai2> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataA12::Rts, Peripheral::Usart1> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataA12::Tx, Peripheral::Can1> { static constexpr int8_t af = 9; };

struct DataA13 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataA13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Jtms { using Data = DataA13; static constexpr Gpio::Signal Signal = Gpio::Signal::Jtms; };
	struct Swdio { using Data = DataA13; static constexpr Gpio::Signal Signal = Gpio::Signal::Swdio; };
};
template<Peripheral p> struct SignalConnection<DataA13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA13::Jtms, p> {
	static_assert((p == Peripheral::Sys),"GpioA13::Jtms only connects to Sys!"); };
template<Peripheral p> struct SignalConnection<DataA13::Swdio, p> {
	static_assert((p == Peripheral::Sys),"GpioA13::Swdio only connects to Sys!"); };
template<> struct SignalConnection<DataA13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA13::Jtms, Peripheral::Sys> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataA13::Swdio, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataA14 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataA14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Jtck { using Data = DataA14; static constexpr Gpio::Signal Signal = Gpio::Signal::Jtck; };
	struct Swclk { using Data = DataA14; static constexpr Gpio::Signal Signal = Gpio::Signal::Swclk; };
};
template<Peripheral p> struct SignalConnection<DataA14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA14::Jtck, p> {
	static_assert((p == Peripheral::Sys),"GpioA14::Jtck only connects to Sys!"); };
template<Peripheral p> struct SignalConnection<DataA14::Swclk, p> {
	static_assert((p == Peripheral::Sys),"GpioA14::Swclk only connects to Sys!"); };
template<> struct SignalConnection<DataA14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA14::Jtck, Peripheral::Sys> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataA14::Swclk, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataA15 {
	static constexpr Gpio::Port port = Gpio::Port::A;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Cec { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Cec; };
	struct Ch1 { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Etr { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct Jtdi { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Jtdi; };
	struct Nss { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Rts { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
	struct Ws { using Data = DataA15; static constexpr Gpio::Signal Signal = Gpio::Signal::Ws; };
};
template<Peripheral p> struct SignalConnection<DataA15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioA15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataA15::Cec, p> {
	static_assert((p == Peripheral::Hdmicec),"GpioA15::Cec only connects to Hdmicec!"); };
template<Peripheral p> struct SignalConnection<DataA15::Ch1, p> {
	static_assert((p == Peripheral::Tim2),"GpioA15::Ch1 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataA15::Etr, p> {
	static_assert((p == Peripheral::Tim2),"GpioA15::Etr only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataA15::Jtdi, p> {
	static_assert((p == Peripheral::Sys),"GpioA15::Jtdi only connects to Sys!"); };
template<Peripheral p> struct SignalConnection<DataA15::Nss, p> {
	static_assert((p == Peripheral::Spi1) or (p == Peripheral::Spi3),
		"GpioA15::Nss only connects to Spi1 or Spi3!"); };
template<Peripheral p> struct SignalConnection<DataA15::Rts, p> {
	static_assert((p == Peripheral::Uart4),"GpioA15::Rts only connects to Uart4!"); };
template<Peripheral p> struct SignalConnection<DataA15::Ws, p> {
	static_assert((p == Peripheral::I2s1) or (p == Peripheral::I2s3),
		"GpioA15::Ws only connects to I2s1 or I2s3!"); };
template<> struct SignalConnection<DataA15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataA15::Cec, Peripheral::Hdmicec> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataA15::Ch1, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA15::Etr, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataA15::Jtdi, Peripheral::Sys> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataA15::Nss, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA15::Nss, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataA15::Rts, Peripheral::Uart4> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataA15::Ws, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataA15::Ws, Peripheral::I2s3> { static constexpr int8_t af = 6; };

struct DataB0 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2n { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2n; };
	struct Ch3 { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct Cts { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct D1 { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::D1; };
	struct In8 { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::In8; };
	struct Mosi { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sd { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Ulpid1 { using Data = DataB0; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid1; };
};
template<Peripheral p> struct SignalConnection<DataB0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB0::Ch2n, p> {
	static_assert((p == Peripheral::Tim1) or (p == Peripheral::Tim8),
		"GpioB0::Ch2n only connects to Tim1 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataB0::Ch3, p> {
	static_assert((p == Peripheral::Tim3),"GpioB0::Ch3 only connects to Tim3!"); };
template<Peripheral p> struct SignalConnection<DataB0::Cts, p> {
	static_assert((p == Peripheral::Uart4),"GpioB0::Cts only connects to Uart4!"); };
template<Peripheral p> struct SignalConnection<DataB0::D1, p> {
	static_assert((p == Peripheral::Sdio),"GpioB0::D1 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataB0::In8, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioB0::In8 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataB0::Mosi, p> {
	static_assert((p == Peripheral::Spi3),"GpioB0::Mosi only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataB0::Sd, p> {
	static_assert((p == Peripheral::I2s3),"GpioB0::Sd only connects to I2s3!"); };
template<Peripheral p> struct SignalConnection<DataB0::Ulpid1, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB0::Ulpid1 only connects to Usbotghs!"); };
template<> struct SignalConnection<DataB0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB0::Ch2n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB0::Ch2n, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB0::Ch3, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB0::Cts, Peripheral::Uart4> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataB0::D1, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB0::In8, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataB0::In8, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataB0::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB0::Sd, Peripheral::I2s3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB0::Ulpid1, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataB0, Peripheral::Adc1> = 8;
template<> constexpr int8_t AdcChannel<DataB0, Peripheral::Adc2> = 8;

struct DataB1 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataB1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3n { using Data = DataB1; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3n; };
	struct Ch4 { using Data = DataB1; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct D2 { using Data = DataB1; static constexpr Gpio::Signal Signal = Gpio::Signal::D2; };
	struct In9 { using Data = DataB1; static constexpr Gpio::Signal Signal = Gpio::Signal::In9; };
	struct Ulpid2 { using Data = DataB1; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid2; };
};
template<Peripheral p> struct SignalConnection<DataB1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB1::Ch3n, p> {
	static_assert((p == Peripheral::Tim1) or (p == Peripheral::Tim8),
		"GpioB1::Ch3n only connects to Tim1 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataB1::Ch4, p> {
	static_assert((p == Peripheral::Tim3),"GpioB1::Ch4 only connects to Tim3!"); };
template<Peripheral p> struct SignalConnection<DataB1::D2, p> {
	static_assert((p == Peripheral::Sdio),"GpioB1::D2 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataB1::In9, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioB1::In9 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataB1::Ulpid2, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB1::Ulpid2 only connects to Usbotghs!"); };
template<> struct SignalConnection<DataB1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB1::Ch3n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB1::Ch3n, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB1::Ch4, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB1::D2, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB1::In9, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataB1::In9, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataB1::Ulpid2, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataB1, Peripheral::Adc1> = 9;
template<> constexpr int8_t AdcChannel<DataB1, Peripheral::Adc2> = 9;

struct DataB2 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch4 { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct Ck { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Clk { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Clk; };
	struct Mosi { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sd { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sda { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Ulpid4 { using Data = DataB2; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid4; };
};
template<Peripheral p> struct SignalConnection<DataB2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB2::Ch4, p> {
	static_assert((p == Peripheral::Tim2),"GpioB2::Ch4 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataB2::Ck, p> {
	static_assert((p == Peripheral::Sdio),"GpioB2::Ck only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataB2::Clk, p> {
	static_assert((p == Peripheral::Quadspi),"GpioB2::Clk only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataB2::Mosi, p> {
	static_assert((p == Peripheral::Spi3),"GpioB2::Mosi only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataB2::Sd, p> {
	static_assert((p == Peripheral::I2s3),"GpioB2::Sd only connects to I2s3!"); };
template<Peripheral p> struct SignalConnection<DataB2::Sda, p> {
	static_assert((p == Peripheral::Sai1),"GpioB2::Sda only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataB2::Ulpid4, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB2::Ulpid4 only connects to Usbotghs!"); };
template<> struct SignalConnection<DataB2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB2::Ch4, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB2::Ck, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB2::Clk, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB2::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB2::Sd, Peripheral::I2s3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB2::Sda, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB2::Ulpid4, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };

struct DataB3 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Ck { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Jtdo { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::Jtdo; };
	struct Sck { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Sda { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Swo { using Data = DataB3; static constexpr Gpio::Signal Signal = Gpio::Signal::Swo; };
};
template<Peripheral p> struct SignalConnection<DataB3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB3::Ch2, p> {
	static_assert((p == Peripheral::Tim2),"GpioB3::Ch2 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataB3::Ck, p> {
	static_assert((p == Peripheral::I2s1) or (p == Peripheral::I2s3),
		"GpioB3::Ck only connects to I2s1 or I2s3!"); };
template<Peripheral p> struct SignalConnection<DataB3::Jtdo, p> {
	static_assert((p == Peripheral::Sys),"GpioB3::Jtdo only connects to Sys!"); };
template<Peripheral p> struct SignalConnection<DataB3::Sck, p> {
	static_assert((p == Peripheral::Spi1) or (p == Peripheral::Spi3),
		"GpioB3::Sck only connects to Spi1 or Spi3!"); };
template<Peripheral p> struct SignalConnection<DataB3::Sda, p> {
	static_assert((p == Peripheral::I2c2),"GpioB3::Sda only connects to I2c2!"); };
template<Peripheral p> struct SignalConnection<DataB3::Swo, p> {
	static_assert((p == Peripheral::Sys),"GpioB3::Swo only connects to Sys!"); };
template<> struct SignalConnection<DataB3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB3::Ch2, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB3::Ck, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB3::Ck, Peripheral::I2s3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB3::Jtdo, Peripheral::Sys> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataB3::Sck, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB3::Sck, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB3::Sda, Peripheral::I2c2> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB3::Swo, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataB4 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Jtrst { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::Jtrst; };
	struct Miso { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Nss { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Sda { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Ws { using Data = DataB4; static constexpr Gpio::Signal Signal = Gpio::Signal::Ws; };
};
template<Peripheral p> struct SignalConnection<DataB4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB4::Ch1, p> {
	static_assert((p == Peripheral::Tim3),"GpioB4::Ch1 only connects to Tim3!"); };
template<Peripheral p> struct SignalConnection<DataB4::Jtrst, p> {
	static_assert((p == Peripheral::Sys),"GpioB4::Jtrst only connects to Sys!"); };
template<Peripheral p> struct SignalConnection<DataB4::Miso, p> {
	static_assert((p == Peripheral::Spi1) or (p == Peripheral::Spi3),
		"GpioB4::Miso only connects to Spi1 or Spi3!"); };
template<Peripheral p> struct SignalConnection<DataB4::Nss, p> {
	static_assert((p == Peripheral::Spi2),"GpioB4::Nss only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB4::Sda, p> {
	static_assert((p == Peripheral::I2c3),"GpioB4::Sda only connects to I2c3!"); };
template<Peripheral p> struct SignalConnection<DataB4::Ws, p> {
	static_assert((p == Peripheral::I2s2),"GpioB4::Ws only connects to I2s2!"); };
template<> struct SignalConnection<DataB4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB4::Ch1, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB4::Jtrst, Peripheral::Sys> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataB4::Miso, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB4::Miso, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB4::Nss, Peripheral::Spi2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB4::Sda, Peripheral::I2c3> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB4::Ws, Peripheral::I2s2> { static constexpr int8_t af = 7; };

struct DataB5 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct D10 { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::D10; };
	struct Mosi { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Rx { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sd { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sdcke1 { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdcke1; };
	struct Smba { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Smba; };
	struct Ulpid7 { using Data = DataB5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid7; };
};
template<Peripheral p> struct SignalConnection<DataB5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB5::Ch2, p> {
	static_assert((p == Peripheral::Tim3),"GpioB5::Ch2 only connects to Tim3!"); };
template<Peripheral p> struct SignalConnection<DataB5::D10, p> {
	static_assert((p == Peripheral::Dcmi),"GpioB5::D10 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataB5::Mosi, p> {
	static_assert((p == Peripheral::Spi1) or (p == Peripheral::Spi3),
		"GpioB5::Mosi only connects to Spi1 or Spi3!"); };
template<Peripheral p> struct SignalConnection<DataB5::Rx, p> {
	static_assert((p == Peripheral::Can2),"GpioB5::Rx only connects to Can2!"); };
template<Peripheral p> struct SignalConnection<DataB5::Sd, p> {
	static_assert((p == Peripheral::I2s1) or (p == Peripheral::I2s3),
		"GpioB5::Sd only connects to I2s1 or I2s3!"); };
template<Peripheral p> struct SignalConnection<DataB5::Sdcke1, p> {
	static_assert((p == Peripheral::Fmc),"GpioB5::Sdcke1 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataB5::Smba, p> {
	static_assert((p == Peripheral::I2c1),"GpioB5::Smba only connects to I2c1!"); };
template<Peripheral p> struct SignalConnection<DataB5::Ulpid7, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB5::Ulpid7 only connects to Usbotghs!"); };
template<> struct SignalConnection<DataB5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB5::Ch2, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB5::D10, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataB5::Mosi, Peripheral::Spi1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB5::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB5::Rx, Peripheral::Can2> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB5::Sd, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB5::Sd, Peripheral::I2s3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB5::Sdcke1, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB5::Smba, Peripheral::I2c1> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB5::Ulpid7, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };

struct DataB6 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1ncs { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1ncs; };
	struct Cec { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::Cec; };
	struct Ch1 { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct D5 { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::D5; };
	struct Scl { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
	struct Sdne1 { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdne1; };
	struct Tx { using Data = DataB6; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataB6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB6::Bk1ncs, p> {
	static_assert((p == Peripheral::Quadspi),"GpioB6::Bk1ncs only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataB6::Cec, p> {
	static_assert((p == Peripheral::Hdmicec),"GpioB6::Cec only connects to Hdmicec!"); };
template<Peripheral p> struct SignalConnection<DataB6::Ch1, p> {
	static_assert((p == Peripheral::Tim4),"GpioB6::Ch1 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataB6::D5, p> {
	static_assert((p == Peripheral::Dcmi),"GpioB6::D5 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataB6::Scl, p> {
	static_assert((p == Peripheral::I2c1),"GpioB6::Scl only connects to I2c1!"); };
template<Peripheral p> struct SignalConnection<DataB6::Sdne1, p> {
	static_assert((p == Peripheral::Fmc),"GpioB6::Sdne1 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataB6::Tx, p> {
	static_assert((p == Peripheral::Usart1) or (p == Peripheral::Can2),
		"GpioB6::Tx only connects to Usart1 or Can2!"); };
template<> struct SignalConnection<DataB6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB6::Bk1ncs, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataB6::Cec, Peripheral::Hdmicec> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB6::Ch1, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB6::D5, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataB6::Scl, Peripheral::I2c1> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB6::Sdne1, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB6::Tx, Peripheral::Usart1> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB6::Tx, Peripheral::Can2> { static constexpr int8_t af = 9; };

struct DataB7 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct In0 { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::In0; };
	struct Nl { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::Nl; };
	struct Rx { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sda { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Vsync { using Data = DataB7; static constexpr Gpio::Signal Signal = Gpio::Signal::Vsync; };
};
template<Peripheral p> struct SignalConnection<DataB7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB7::Ch2, p> {
	static_assert((p == Peripheral::Tim4),"GpioB7::Ch2 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataB7::In0, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioB7::In0 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataB7::Nl, p> {
	static_assert((p == Peripheral::Fmc),"GpioB7::Nl only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataB7::Rx, p> {
	static_assert((p == Peripheral::Usart1),"GpioB7::Rx only connects to Usart1!"); };
template<Peripheral p> struct SignalConnection<DataB7::Sda, p> {
	static_assert((p == Peripheral::I2c1),"GpioB7::Sda only connects to I2c1!"); };
template<Peripheral p> struct SignalConnection<DataB7::Vsync, p> {
	static_assert((p == Peripheral::Dcmi),"GpioB7::Vsync only connects to Dcmi!"); };
template<> struct SignalConnection<DataB7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB7::Ch2, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB7::In0, Peripheral::Spdifrx> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataB7::Nl, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB7::Rx, Peripheral::Usart1> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB7::Sda, Peripheral::I2c1> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB7::Vsync, Peripheral::Dcmi> { static constexpr int8_t af = 13; };

struct DataB8 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ch3 { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct D4 { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::D4; };
	struct D6 { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::D6; };
	struct Etr { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct Rx { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Scl { using Data = DataB8; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
};
template<Peripheral p> struct SignalConnection<DataB8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB8::Ch1, p> {
	static_assert((p == Peripheral::Tim2) or (p == Peripheral::Tim10),
		"GpioB8::Ch1 only connects to Tim2 or Tim10!"); };
template<Peripheral p> struct SignalConnection<DataB8::Ch3, p> {
	static_assert((p == Peripheral::Tim4),"GpioB8::Ch3 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataB8::D4, p> {
	static_assert((p == Peripheral::Sdio),"GpioB8::D4 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataB8::D6, p> {
	static_assert((p == Peripheral::Dcmi),"GpioB8::D6 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataB8::Etr, p> {
	static_assert((p == Peripheral::Tim2),"GpioB8::Etr only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataB8::Rx, p> {
	static_assert((p == Peripheral::Can1),"GpioB8::Rx only connects to Can1!"); };
template<Peripheral p> struct SignalConnection<DataB8::Scl, p> {
	static_assert((p == Peripheral::I2c1),"GpioB8::Scl only connects to I2c1!"); };
template<> struct SignalConnection<DataB8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB8::Ch1, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB8::Ch1, Peripheral::Tim10> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB8::Ch3, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB8::D4, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB8::D6, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataB8::Etr, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB8::Rx, Peripheral::Can1> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB8::Scl, Peripheral::I2c1> { static constexpr int8_t af = 4; };

struct DataB9 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ch2 { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Ch4 { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct D5 { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::D5; };
	struct D7 { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::D7; };
	struct Fsb { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsb; };
	struct Nss { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Sda { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Tx { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
	struct Ws { using Data = DataB9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ws; };
};
template<Peripheral p> struct SignalConnection<DataB9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB9::Ch1, p> {
	static_assert((p == Peripheral::Tim11),"GpioB9::Ch1 only connects to Tim11!"); };
template<Peripheral p> struct SignalConnection<DataB9::Ch2, p> {
	static_assert((p == Peripheral::Tim2),"GpioB9::Ch2 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataB9::Ch4, p> {
	static_assert((p == Peripheral::Tim4),"GpioB9::Ch4 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataB9::D5, p> {
	static_assert((p == Peripheral::Sdio),"GpioB9::D5 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataB9::D7, p> {
	static_assert((p == Peripheral::Dcmi),"GpioB9::D7 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataB9::Fsb, p> {
	static_assert((p == Peripheral::Sai1),"GpioB9::Fsb only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataB9::Nss, p> {
	static_assert((p == Peripheral::Spi2),"GpioB9::Nss only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB9::Sda, p> {
	static_assert((p == Peripheral::I2c1),"GpioB9::Sda only connects to I2c1!"); };
template<Peripheral p> struct SignalConnection<DataB9::Tx, p> {
	static_assert((p == Peripheral::Can1),"GpioB9::Tx only connects to Can1!"); };
template<Peripheral p> struct SignalConnection<DataB9::Ws, p> {
	static_assert((p == Peripheral::I2s2),"GpioB9::Ws only connects to I2s2!"); };
template<> struct SignalConnection<DataB9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB9::Ch1, Peripheral::Tim11> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB9::Ch2, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB9::Ch4, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataB9::D5, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB9::D7, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataB9::Fsb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB9::Nss, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB9::Sda, Peripheral::I2c1> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB9::Tx, Peripheral::Can1> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB9::Ws, Peripheral::I2s2> { static constexpr int8_t af = 5; };

struct DataB10 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3 { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct Ck { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Sck { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Scka { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Scka; };
	struct Scl { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
	struct Tx { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
	struct Ulpid3 { using Data = DataB10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid3; };
};
template<Peripheral p> struct SignalConnection<DataB10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB10::Ch3, p> {
	static_assert((p == Peripheral::Tim2),"GpioB10::Ch3 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataB10::Ck, p> {
	static_assert((p == Peripheral::I2s2),"GpioB10::Ck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataB10::Sck, p> {
	static_assert((p == Peripheral::Spi2),"GpioB10::Sck only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB10::Scka, p> {
	static_assert((p == Peripheral::Sai1),"GpioB10::Scka only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataB10::Scl, p> {
	static_assert((p == Peripheral::I2c2),"GpioB10::Scl only connects to I2c2!"); };
template<Peripheral p> struct SignalConnection<DataB10::Tx, p> {
	static_assert((p == Peripheral::Usart3),"GpioB10::Tx only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataB10::Ulpid3, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB10::Ulpid3 only connects to Usbotghs!"); };
template<> struct SignalConnection<DataB10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB10::Ch3, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB10::Ck, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB10::Sck, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB10::Scka, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB10::Scl, Peripheral::I2c2> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB10::Tx, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB10::Ulpid3, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };

struct DataB11 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataB11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch4 { using Data = DataB11; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct Rx { using Data = DataB11; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sda { using Data = DataB11; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataB11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB11::Ch4, p> {
	static_assert((p == Peripheral::Tim2),"GpioB11::Ch4 only connects to Tim2!"); };
template<Peripheral p> struct SignalConnection<DataB11::Rx, p> {
	static_assert((p == Peripheral::Usart3),"GpioB11::Rx only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataB11::Sda, p> {
	static_assert((p == Peripheral::I2c2) or (p == Peripheral::Sai2),
		"GpioB11::Sda only connects to I2c2 or Sai2!"); };
template<> struct SignalConnection<DataB11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB11::Ch4, Peripheral::Tim2> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB11::Rx, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB11::Sda, Peripheral::I2c2> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB11::Sda, Peripheral::Sai2> { static constexpr int8_t af = 8; };

struct DataB12 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bkin { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Bkin; };
	struct Ck { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Id { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Id; };
	struct Nss { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Rx { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sckb { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Sckb; };
	struct Smba { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Smba; };
	struct Ulpid5 { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid5; };
	struct Ws { using Data = DataB12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ws; };
};
template<Peripheral p> struct SignalConnection<DataB12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB12::Bkin, p> {
	static_assert((p == Peripheral::Tim1),"GpioB12::Bkin only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataB12::Ck, p> {
	static_assert((p == Peripheral::Usart3),"GpioB12::Ck only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataB12::Id, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB12::Id only connects to Usbotghs!"); };
template<Peripheral p> struct SignalConnection<DataB12::Nss, p> {
	static_assert((p == Peripheral::Spi2),"GpioB12::Nss only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB12::Rx, p> {
	static_assert((p == Peripheral::Can2),"GpioB12::Rx only connects to Can2!"); };
template<Peripheral p> struct SignalConnection<DataB12::Sckb, p> {
	static_assert((p == Peripheral::Sai1),"GpioB12::Sckb only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataB12::Smba, p> {
	static_assert((p == Peripheral::I2c2),"GpioB12::Smba only connects to I2c2!"); };
template<Peripheral p> struct SignalConnection<DataB12::Ulpid5, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB12::Ulpid5 only connects to Usbotghs!"); };
template<Peripheral p> struct SignalConnection<DataB12::Ws, p> {
	static_assert((p == Peripheral::I2s2),"GpioB12::Ws only connects to I2s2!"); };
template<> struct SignalConnection<DataB12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB12::Bkin, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB12::Ck, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB12::Id, Peripheral::Usbotghs> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB12::Nss, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB12::Rx, Peripheral::Can2> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB12::Sckb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataB12::Smba, Peripheral::I2c2> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataB12::Ulpid5, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataB12::Ws, Peripheral::I2s2> { static constexpr int8_t af = 5; };

struct DataB13 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1n { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1n; };
	struct Ck { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Cts { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct Sck { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Tx { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
	struct Ulpid6 { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpid6; };
	struct Vbus { using Data = DataB13; static constexpr Gpio::Signal Signal = Gpio::Signal::Vbus; };
};
template<Peripheral p> struct SignalConnection<DataB13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB13::Ch1n, p> {
	static_assert((p == Peripheral::Tim1),"GpioB13::Ch1n only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataB13::Ck, p> {
	static_assert((p == Peripheral::I2s2),"GpioB13::Ck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataB13::Cts, p> {
	static_assert((p == Peripheral::Usart3),"GpioB13::Cts only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataB13::Sck, p> {
	static_assert((p == Peripheral::Spi2),"GpioB13::Sck only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB13::Tx, p> {
	static_assert((p == Peripheral::Can2),"GpioB13::Tx only connects to Can2!"); };
template<Peripheral p> struct SignalConnection<DataB13::Ulpid6, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB13::Ulpid6 only connects to Usbotghs!"); };
template<Peripheral p> struct SignalConnection<DataB13::Vbus, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB13::Vbus only connects to Usbotghs!"); };
template<> struct SignalConnection<DataB13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB13::Ch1n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB13::Ck, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB13::Cts, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataB13::Sck, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB13::Tx, Peripheral::Can2> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB13::Ulpid6, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataB13::Vbus, Peripheral::Usbotghs> { static constexpr int8_t af = -1; };

struct DataB14 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataB14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataB14; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Ch2n { using Data = DataB14; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2n; };
	struct Dm { using Data = DataB14; static constexpr Gpio::Signal Signal = Gpio::Signal::Dm; };
	struct Miso { using Data = DataB14; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Rts { using Data = DataB14; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
};
template<Peripheral p> struct SignalConnection<DataB14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB14::Ch1, p> {
	static_assert((p == Peripheral::Tim12),"GpioB14::Ch1 only connects to Tim12!"); };
template<Peripheral p> struct SignalConnection<DataB14::Ch2n, p> {
	static_assert((p == Peripheral::Tim1) or (p == Peripheral::Tim8),
		"GpioB14::Ch2n only connects to Tim1 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataB14::Dm, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB14::Dm only connects to Usbotghs!"); };
template<Peripheral p> struct SignalConnection<DataB14::Miso, p> {
	static_assert((p == Peripheral::Spi2),"GpioB14::Miso only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB14::Rts, p> {
	static_assert((p == Peripheral::Usart3),"GpioB14::Rts only connects to Usart3!"); };
template<> struct SignalConnection<DataB14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB14::Ch1, Peripheral::Tim12> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB14::Ch2n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB14::Ch2n, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB14::Dm, Peripheral::Usbotghs> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB14::Miso, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB14::Rts, Peripheral::Usart3> { static constexpr int8_t af = 7; };

struct DataB15 {
	static constexpr Gpio::Port port = Gpio::Port::B;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Ch3n { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3n; };
	struct Dp { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::Dp; };
	struct Mosi { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Refin { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::Refin; };
	struct Sd { using Data = DataB15; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
};
template<Peripheral p> struct SignalConnection<DataB15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioB15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataB15::Ch2, p> {
	static_assert((p == Peripheral::Tim12),"GpioB15::Ch2 only connects to Tim12!"); };
template<Peripheral p> struct SignalConnection<DataB15::Ch3n, p> {
	static_assert((p == Peripheral::Tim1) or (p == Peripheral::Tim8),
		"GpioB15::Ch3n only connects to Tim1 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataB15::Dp, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioB15::Dp only connects to Usbotghs!"); };
template<Peripheral p> struct SignalConnection<DataB15::Mosi, p> {
	static_assert((p == Peripheral::Spi2),"GpioB15::Mosi only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataB15::Refin, p> {
	static_assert((p == Peripheral::Rtc),"GpioB15::Refin only connects to Rtc!"); };
template<Peripheral p> struct SignalConnection<DataB15::Sd, p> {
	static_assert((p == Peripheral::I2s2),"GpioB15::Sd only connects to I2s2!"); };
template<> struct SignalConnection<DataB15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataB15::Ch2, Peripheral::Tim12> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataB15::Ch3n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataB15::Ch3n, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataB15::Dp, Peripheral::Usbotghs> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataB15::Mosi, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataB15::Refin, Peripheral::Rtc> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataB15::Sd, Peripheral::I2s2> { static constexpr int8_t af = 5; };

struct DataC0 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataC0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In10 { using Data = DataC0; static constexpr Gpio::Signal Signal = Gpio::Signal::In10; };
	struct Mclkb { using Data = DataC0; static constexpr Gpio::Signal Signal = Gpio::Signal::Mclkb; };
	struct Sdnwe { using Data = DataC0; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdnwe; };
	struct Ulpistp { using Data = DataC0; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpistp; };
};
template<Peripheral p> struct SignalConnection<DataC0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC0::In10, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioC0::In10 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataC0::Mclkb, p> {
	static_assert((p == Peripheral::Sai1),"GpioC0::Mclkb only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataC0::Sdnwe, p> {
	static_assert((p == Peripheral::Fmc),"GpioC0::Sdnwe only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataC0::Ulpistp, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioC0::Ulpistp only connects to Usbotghs!"); };
template<> struct SignalConnection<DataC0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC0::In10, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC0::In10, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC0::In10, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC0::Mclkb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC0::Sdnwe, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC0::Ulpistp, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataC0, Peripheral::Adc1> = 10;
template<> constexpr int8_t AdcChannel<DataC0, Peripheral::Adc2> = 10;
template<> constexpr int8_t AdcChannel<DataC0, Peripheral::Adc3> = 10;

struct DataC1 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataC1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In11 { using Data = DataC1; static constexpr Gpio::Signal Signal = Gpio::Signal::In11; };
	struct Mosi { using Data = DataC1; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sd { using Data = DataC1; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sda { using Data = DataC1; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataC1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC1::In11, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioC1::In11 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataC1::Mosi, p> {
	static_assert((p == Peripheral::Spi3) or (p == Peripheral::Spi2),
		"GpioC1::Mosi only connects to Spi3 or Spi2!"); };
template<Peripheral p> struct SignalConnection<DataC1::Sd, p> {
	static_assert((p == Peripheral::I2s3) or (p == Peripheral::I2s2),
		"GpioC1::Sd only connects to I2s3 or I2s2!"); };
template<Peripheral p> struct SignalConnection<DataC1::Sda, p> {
	static_assert((p == Peripheral::Sai1),"GpioC1::Sda only connects to Sai1!"); };
template<> struct SignalConnection<DataC1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC1::In11, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC1::In11, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC1::In11, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC1::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC1::Mosi, Peripheral::Spi2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC1::Sd, Peripheral::I2s3> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC1::Sd, Peripheral::I2s2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC1::Sda, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> constexpr int8_t AdcChannel<DataC1, Peripheral::Adc1> = 11;
template<> constexpr int8_t AdcChannel<DataC1, Peripheral::Adc2> = 11;
template<> constexpr int8_t AdcChannel<DataC1, Peripheral::Adc3> = 11;

struct DataC2 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataC2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In12 { using Data = DataC2; static constexpr Gpio::Signal Signal = Gpio::Signal::In12; };
	struct Miso { using Data = DataC2; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Sdne0 { using Data = DataC2; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdne0; };
	struct Ulpidir { using Data = DataC2; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpidir; };
};
template<Peripheral p> struct SignalConnection<DataC2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC2::In12, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioC2::In12 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataC2::Miso, p> {
	static_assert((p == Peripheral::Spi2),"GpioC2::Miso only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataC2::Sdne0, p> {
	static_assert((p == Peripheral::Fmc),"GpioC2::Sdne0 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataC2::Ulpidir, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioC2::Ulpidir only connects to Usbotghs!"); };
template<> struct SignalConnection<DataC2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC2::In12, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC2::In12, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC2::In12, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC2::Miso, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC2::Sdne0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC2::Ulpidir, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataC2, Peripheral::Adc1> = 12;
template<> constexpr int8_t AdcChannel<DataC2, Peripheral::Adc2> = 12;
template<> constexpr int8_t AdcChannel<DataC2, Peripheral::Adc3> = 12;

struct DataC3 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataC3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In13 { using Data = DataC3; static constexpr Gpio::Signal Signal = Gpio::Signal::In13; };
	struct Mosi { using Data = DataC3; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sd { using Data = DataC3; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sdcke0 { using Data = DataC3; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdcke0; };
	struct Ulpinxt { using Data = DataC3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ulpinxt; };
};
template<Peripheral p> struct SignalConnection<DataC3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC3::In13, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2) or (p == Peripheral::Adc3),
		"GpioC3::In13 only connects to Adc1 or Adc2 or Adc3!"); };
template<Peripheral p> struct SignalConnection<DataC3::Mosi, p> {
	static_assert((p == Peripheral::Spi2),"GpioC3::Mosi only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataC3::Sd, p> {
	static_assert((p == Peripheral::I2s2),"GpioC3::Sd only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataC3::Sdcke0, p> {
	static_assert((p == Peripheral::Fmc),"GpioC3::Sdcke0 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataC3::Ulpinxt, p> {
	static_assert((p == Peripheral::Usbotghs),"GpioC3::Ulpinxt only connects to Usbotghs!"); };
template<> struct SignalConnection<DataC3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC3::In13, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC3::In13, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC3::In13, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC3::Mosi, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC3::Sd, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC3::Sdcke0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC3::Ulpinxt, Peripheral::Usbotghs> { static constexpr int8_t af = 10; };
template<> constexpr int8_t AdcChannel<DataC3, Peripheral::Adc1> = 13;
template<> constexpr int8_t AdcChannel<DataC3, Peripheral::Adc2> = 13;
template<> constexpr int8_t AdcChannel<DataC3, Peripheral::Adc3> = 13;

struct DataC4 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataC4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In14 { using Data = DataC4; static constexpr Gpio::Signal Signal = Gpio::Signal::In14; };
	struct In2 { using Data = DataC4; static constexpr Gpio::Signal Signal = Gpio::Signal::In2; };
	struct Mck { using Data = DataC4; static constexpr Gpio::Signal Signal = Gpio::Signal::Mck; };
	struct Sdne0 { using Data = DataC4; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdne0; };
};
template<Peripheral p> struct SignalConnection<DataC4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC4::In14, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioC4::In14 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataC4::In2, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioC4::In2 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataC4::Mck, p> {
	static_assert((p == Peripheral::I2s1),"GpioC4::Mck only connects to I2s1!"); };
template<Peripheral p> struct SignalConnection<DataC4::Sdne0, p> {
	static_assert((p == Peripheral::Fmc),"GpioC4::Sdne0 only connects to Fmc!"); };
template<> struct SignalConnection<DataC4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC4::In14, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC4::In14, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC4::In2, Peripheral::Spdifrx> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataC4::Mck, Peripheral::I2s1> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC4::Sdne0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> constexpr int8_t AdcChannel<DataC4, Peripheral::Adc1> = 14;
template<> constexpr int8_t AdcChannel<DataC4, Peripheral::Adc2> = 14;

struct DataC5 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataC5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In15 { using Data = DataC5; static constexpr Gpio::Signal Signal = Gpio::Signal::In15; };
	struct In3 { using Data = DataC5; static constexpr Gpio::Signal Signal = Gpio::Signal::In3; };
	struct Rx { using Data = DataC5; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sdcke0 { using Data = DataC5; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdcke0; };
};
template<Peripheral p> struct SignalConnection<DataC5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC5::In15, p> {
	static_assert((p == Peripheral::Adc1) or (p == Peripheral::Adc2),
		"GpioC5::In15 only connects to Adc1 or Adc2!"); };
template<Peripheral p> struct SignalConnection<DataC5::In3, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioC5::In3 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataC5::Rx, p> {
	static_assert((p == Peripheral::Usart3),"GpioC5::Rx only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataC5::Sdcke0, p> {
	static_assert((p == Peripheral::Fmc),"GpioC5::Sdcke0 only connects to Fmc!"); };
template<> struct SignalConnection<DataC5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC5::In15, Peripheral::Adc1> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC5::In15, Peripheral::Adc2> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataC5::In3, Peripheral::Spdifrx> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataC5::Rx, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC5::Sdcke0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> constexpr int8_t AdcChannel<DataC5, Peripheral::Adc1> = 15;
template<> constexpr int8_t AdcChannel<DataC5, Peripheral::Adc2> = 15;

struct DataC6 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch1 { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct D0 { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::D0; };
	struct D6 { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::D6; };
	struct Mck { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::Mck; };
	struct Scl { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
	struct Tx { using Data = DataC6; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataC6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC6::Ch1, p> {
	static_assert((p == Peripheral::Tim3) or (p == Peripheral::Tim8),
		"GpioC6::Ch1 only connects to Tim3 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataC6::D0, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC6::D0 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC6::D6, p> {
	static_assert((p == Peripheral::Sdio),"GpioC6::D6 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC6::Mck, p> {
	static_assert((p == Peripheral::I2s2),"GpioC6::Mck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataC6::Scl, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioC6::Scl only connects to Fmpi2c1!"); };
template<Peripheral p> struct SignalConnection<DataC6::Tx, p> {
	static_assert((p == Peripheral::Usart6),"GpioC6::Tx only connects to Usart6!"); };
template<> struct SignalConnection<DataC6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC6::Ch1, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataC6::Ch1, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataC6::D0, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC6::D6, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC6::Mck, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC6::Scl, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataC6::Tx, Peripheral::Usart6> { static constexpr int8_t af = 8; };

struct DataC7 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Ck { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D1 { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::D1; };
	struct D7 { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::D7; };
	struct In1 { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::In1; };
	struct Mck { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::Mck; };
	struct Rx { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sck { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Sda { using Data = DataC7; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataC7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC7::Ch2, p> {
	static_assert((p == Peripheral::Tim3) or (p == Peripheral::Tim8),
		"GpioC7::Ch2 only connects to Tim3 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataC7::Ck, p> {
	static_assert((p == Peripheral::I2s2),"GpioC7::Ck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataC7::D1, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC7::D1 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC7::D7, p> {
	static_assert((p == Peripheral::Sdio),"GpioC7::D7 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC7::In1, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioC7::In1 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataC7::Mck, p> {
	static_assert((p == Peripheral::I2s3),"GpioC7::Mck only connects to I2s3!"); };
template<Peripheral p> struct SignalConnection<DataC7::Rx, p> {
	static_assert((p == Peripheral::Usart6),"GpioC7::Rx only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataC7::Sck, p> {
	static_assert((p == Peripheral::Spi2),"GpioC7::Sck only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataC7::Sda, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioC7::Sda only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataC7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC7::Ch2, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataC7::Ch2, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataC7::Ck, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC7::D1, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC7::D7, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC7::In1, Peripheral::Spdifrx> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC7::Mck, Peripheral::I2s3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC7::Rx, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataC7::Sck, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC7::Sda, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataC8 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3 { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct Ck { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D0 { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::D0; };
	struct D2 { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::D2; };
	struct Rts { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
	struct Traced0 { using Data = DataC8; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced0; };
};
template<Peripheral p> struct SignalConnection<DataC8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC8::Ch3, p> {
	static_assert((p == Peripheral::Tim3) or (p == Peripheral::Tim8),
		"GpioC8::Ch3 only connects to Tim3 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataC8::Ck, p> {
	static_assert((p == Peripheral::Usart6),"GpioC8::Ck only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataC8::D0, p> {
	static_assert((p == Peripheral::Sdio),"GpioC8::D0 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC8::D2, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC8::D2 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC8::Rts, p> {
	static_assert((p == Peripheral::Uart5),"GpioC8::Rts only connects to Uart5!"); };
template<Peripheral p> struct SignalConnection<DataC8::Traced0, p> {
	static_assert((p == Peripheral::Sys),"GpioC8::Traced0 only connects to Sys!"); };
template<> struct SignalConnection<DataC8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC8::Ch3, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataC8::Ch3, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataC8::Ck, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataC8::D0, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC8::D2, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC8::Rts, Peripheral::Uart5> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC8::Traced0, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataC9 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io0 { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io0; };
	struct Ch4 { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct Ckin { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ckin; };
	struct Cts { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct D1 { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::D1; };
	struct D3 { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::D3; };
	struct Mco2 { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::Mco2; };
	struct Sda { using Data = DataC9; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataC9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC9::Bk1io0, p> {
	static_assert((p == Peripheral::Quadspi),"GpioC9::Bk1io0 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataC9::Ch4, p> {
	static_assert((p == Peripheral::Tim3) or (p == Peripheral::Tim8),
		"GpioC9::Ch4 only connects to Tim3 or Tim8!"); };
template<Peripheral p> struct SignalConnection<DataC9::Ckin, p> {
	static_assert((p == Peripheral::I2s),"GpioC9::Ckin only connects to I2s!"); };
template<Peripheral p> struct SignalConnection<DataC9::Cts, p> {
	static_assert((p == Peripheral::Uart5),"GpioC9::Cts only connects to Uart5!"); };
template<Peripheral p> struct SignalConnection<DataC9::D1, p> {
	static_assert((p == Peripheral::Sdio),"GpioC9::D1 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC9::D3, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC9::D3 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC9::Mco2, p> {
	static_assert((p == Peripheral::Rcc),"GpioC9::Mco2 only connects to Rcc!"); };
template<Peripheral p> struct SignalConnection<DataC9::Sda, p> {
	static_assert((p == Peripheral::I2c3),"GpioC9::Sda only connects to I2c3!"); };
template<> struct SignalConnection<DataC9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC9::Bk1io0, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataC9::Ch4, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataC9::Ch4, Peripheral::Tim8> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataC9::Ckin, Peripheral::I2s> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataC9::Cts, Peripheral::Uart5> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC9::D1, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC9::D3, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC9::Mco2, Peripheral::Rcc> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataC9::Sda, Peripheral::I2c3> { static constexpr int8_t af = 4; };

struct DataC10 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io1 { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io1; };
	struct Ck { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D2 { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::D2; };
	struct D8 { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::D8; };
	struct Sck { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Tx { using Data = DataC10; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataC10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC10::Bk1io1, p> {
	static_assert((p == Peripheral::Quadspi),"GpioC10::Bk1io1 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataC10::Ck, p> {
	static_assert((p == Peripheral::I2s3),"GpioC10::Ck only connects to I2s3!"); };
template<Peripheral p> struct SignalConnection<DataC10::D2, p> {
	static_assert((p == Peripheral::Sdio),"GpioC10::D2 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC10::D8, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC10::D8 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC10::Sck, p> {
	static_assert((p == Peripheral::Spi3),"GpioC10::Sck only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataC10::Tx, p> {
	static_assert((p == Peripheral::Usart3) or (p == Peripheral::Uart4),
		"GpioC10::Tx only connects to Usart3 or Uart4!"); };
template<> struct SignalConnection<DataC10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC10::Bk1io1, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataC10::Ck, Peripheral::I2s3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC10::D2, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC10::D8, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC10::Sck, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC10::Tx, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC10::Tx, Peripheral::Uart4> { static constexpr int8_t af = 8; };

struct DataC11 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataC11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk2ncs { using Data = DataC11; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2ncs; };
	struct D3 { using Data = DataC11; static constexpr Gpio::Signal Signal = Gpio::Signal::D3; };
	struct D4 { using Data = DataC11; static constexpr Gpio::Signal Signal = Gpio::Signal::D4; };
	struct Miso { using Data = DataC11; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Rx { using Data = DataC11; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataC11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC11::Bk2ncs, p> {
	static_assert((p == Peripheral::Quadspi),"GpioC11::Bk2ncs only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataC11::D3, p> {
	static_assert((p == Peripheral::Sdio),"GpioC11::D3 only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC11::D4, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC11::D4 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC11::Miso, p> {
	static_assert((p == Peripheral::Spi3),"GpioC11::Miso only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataC11::Rx, p> {
	static_assert((p == Peripheral::Usart3) or (p == Peripheral::Uart4),
		"GpioC11::Rx only connects to Usart3 or Uart4!"); };
template<> struct SignalConnection<DataC11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC11::Bk2ncs, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataC11::D3, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC11::D4, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC11::Miso, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC11::Rx, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC11::Rx, Peripheral::Uart4> { static constexpr int8_t af = 8; };

struct DataC12 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ck { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D9 { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::D9; };
	struct Mosi { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sd { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sda { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Tx { using Data = DataC12; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataC12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC12::Ck, p> {
	static_assert((p == Peripheral::Usart3) or (p == Peripheral::Sdio),
		"GpioC12::Ck only connects to Usart3 or Sdio!"); };
template<Peripheral p> struct SignalConnection<DataC12::D9, p> {
	static_assert((p == Peripheral::Dcmi),"GpioC12::D9 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataC12::Mosi, p> {
	static_assert((p == Peripheral::Spi3),"GpioC12::Mosi only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataC12::Sd, p> {
	static_assert((p == Peripheral::I2s3),"GpioC12::Sd only connects to I2s3!"); };
template<Peripheral p> struct SignalConnection<DataC12::Sda, p> {
	static_assert((p == Peripheral::I2c2),"GpioC12::Sda only connects to I2c2!"); };
template<Peripheral p> struct SignalConnection<DataC12::Tx, p> {
	static_assert((p == Peripheral::Uart5),"GpioC12::Tx only connects to Uart5!"); };
template<> struct SignalConnection<DataC12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC12::Ck, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataC12::Ck, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataC12::D9, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataC12::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC12::Sd, Peripheral::I2s3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataC12::Sda, Peripheral::I2c2> { static constexpr int8_t af = 4; };
template<> struct SignalConnection<DataC12::Tx, Peripheral::Uart5> { static constexpr int8_t af = 8; };

struct DataC13 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataC13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Af1 { using Data = DataC13; static constexpr Gpio::Signal Signal = Gpio::Signal::Af1; };
	struct Wkup1 { using Data = DataC13; static constexpr Gpio::Signal Signal = Gpio::Signal::Wkup1; };
};
template<Peripheral p> struct SignalConnection<DataC13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC13::Af1, p> {
	static_assert((p == Peripheral::Rtc),"GpioC13::Af1 only connects to Rtc!"); };
template<Peripheral p> struct SignalConnection<DataC13::Wkup1, p> {
	static_assert((p == Peripheral::Sys),"GpioC13::Wkup1 only connects to Sys!"); };
template<> struct SignalConnection<DataC13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC13::Af1, Peripheral::Rtc> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC13::Wkup1, Peripheral::Sys> { static constexpr int8_t af = -1; };

struct DataC14 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataC14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Osc32in { using Data = DataC14; static constexpr Gpio::Signal Signal = Gpio::Signal::Osc32in; };
};
template<Peripheral p> struct SignalConnection<DataC14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC14::Osc32in, p> {
	static_assert((p == Peripheral::Rcc),"GpioC14::Osc32in only connects to Rcc!"); };
template<> struct SignalConnection<DataC14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC14::Osc32in, Peripheral::Rcc> { static constexpr int8_t af = -1; };

struct DataC15 {
	static constexpr Gpio::Port port = Gpio::Port::C;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataC15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Osc32out { using Data = DataC15; static constexpr Gpio::Signal Signal = Gpio::Signal::Osc32out; };
};
template<Peripheral p> struct SignalConnection<DataC15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioC15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataC15::Osc32out, p> {
	static_assert((p == Peripheral::Rcc),"GpioC15::Osc32out only connects to Rcc!"); };
template<> struct SignalConnection<DataC15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataC15::Osc32out, Peripheral::Rcc> { static constexpr int8_t af = -1; };

struct DataD0 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D2 { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::D2; };
	struct Da2 { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::Da2; };
	struct Miso { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Mosi { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Rx { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sd { using Data = DataD0; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
};
template<Peripheral p> struct SignalConnection<DataD0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD0::D2, p> {
	static_assert((p == Peripheral::Fmc),"GpioD0::D2 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD0::Da2, p> {
	static_assert((p == Peripheral::Fmc),"GpioD0::Da2 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD0::Miso, p> {
	static_assert((p == Peripheral::Spi4),"GpioD0::Miso only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataD0::Mosi, p> {
	static_assert((p == Peripheral::Spi3),"GpioD0::Mosi only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataD0::Rx, p> {
	static_assert((p == Peripheral::Can1),"GpioD0::Rx only connects to Can1!"); };
template<Peripheral p> struct SignalConnection<DataD0::Sd, p> {
	static_assert((p == Peripheral::I2s3),"GpioD0::Sd only connects to I2s3!"); };
template<> struct SignalConnection<DataD0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD0::D2, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD0::Da2, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD0::Miso, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataD0::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataD0::Rx, Peripheral::Can1> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataD0::Sd, Peripheral::I2s3> { static constexpr int8_t af = 6; };

struct DataD1 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataD1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D3 { using Data = DataD1; static constexpr Gpio::Signal Signal = Gpio::Signal::D3; };
	struct Da3 { using Data = DataD1; static constexpr Gpio::Signal Signal = Gpio::Signal::Da3; };
	struct Nss { using Data = DataD1; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Tx { using Data = DataD1; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
	struct Ws { using Data = DataD1; static constexpr Gpio::Signal Signal = Gpio::Signal::Ws; };
};
template<Peripheral p> struct SignalConnection<DataD1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD1::D3, p> {
	static_assert((p == Peripheral::Fmc),"GpioD1::D3 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD1::Da3, p> {
	static_assert((p == Peripheral::Fmc),"GpioD1::Da3 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD1::Nss, p> {
	static_assert((p == Peripheral::Spi2),"GpioD1::Nss only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataD1::Tx, p> {
	static_assert((p == Peripheral::Can1),"GpioD1::Tx only connects to Can1!"); };
template<Peripheral p> struct SignalConnection<DataD1::Ws, p> {
	static_assert((p == Peripheral::I2s2),"GpioD1::Ws only connects to I2s2!"); };
template<> struct SignalConnection<DataD1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD1::D3, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD1::Da3, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD1::Nss, Peripheral::Spi2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD1::Tx, Peripheral::Can1> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataD1::Ws, Peripheral::I2s2> { static constexpr int8_t af = 7; };

struct DataD2 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataD2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Cmd { using Data = DataD2; static constexpr Gpio::Signal Signal = Gpio::Signal::Cmd; };
	struct D11 { using Data = DataD2; static constexpr Gpio::Signal Signal = Gpio::Signal::D11; };
	struct Etr { using Data = DataD2; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct Rx { using Data = DataD2; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataD2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD2::Cmd, p> {
	static_assert((p == Peripheral::Sdio),"GpioD2::Cmd only connects to Sdio!"); };
template<Peripheral p> struct SignalConnection<DataD2::D11, p> {
	static_assert((p == Peripheral::Dcmi),"GpioD2::D11 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataD2::Etr, p> {
	static_assert((p == Peripheral::Tim3),"GpioD2::Etr only connects to Tim3!"); };
template<Peripheral p> struct SignalConnection<DataD2::Rx, p> {
	static_assert((p == Peripheral::Uart5),"GpioD2::Rx only connects to Uart5!"); };
template<> struct SignalConnection<DataD2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD2::Cmd, Peripheral::Sdio> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD2::D11, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataD2::Etr, Peripheral::Tim3> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataD2::Rx, Peripheral::Uart5> { static constexpr int8_t af = 8; };

struct DataD3 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ck { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct Clk { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::Clk; };
	struct Cts { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct D5 { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::D5; };
	struct Sck { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Traced1 { using Data = DataD3; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced1; };
};
template<Peripheral p> struct SignalConnection<DataD3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD3::Ck, p> {
	static_assert((p == Peripheral::I2s2),"GpioD3::Ck only connects to I2s2!"); };
template<Peripheral p> struct SignalConnection<DataD3::Clk, p> {
	static_assert((p == Peripheral::Quadspi) or (p == Peripheral::Fmc),
		"GpioD3::Clk only connects to Quadspi or Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD3::Cts, p> {
	static_assert((p == Peripheral::Usart2),"GpioD3::Cts only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataD3::D5, p> {
	static_assert((p == Peripheral::Dcmi),"GpioD3::D5 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataD3::Sck, p> {
	static_assert((p == Peripheral::Spi2),"GpioD3::Sck only connects to Spi2!"); };
template<Peripheral p> struct SignalConnection<DataD3::Traced1, p> {
	static_assert((p == Peripheral::Sys),"GpioD3::Traced1 only connects to Sys!"); };
template<> struct SignalConnection<DataD3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD3::Ck, Peripheral::I2s2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataD3::Clk, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataD3::Clk, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD3::Cts, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD3::D5, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataD3::Sck, Peripheral::Spi2> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataD3::Traced1, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataD4 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataD4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Noe { using Data = DataD4; static constexpr Gpio::Signal Signal = Gpio::Signal::Noe; };
	struct Rts { using Data = DataD4; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
};
template<Peripheral p> struct SignalConnection<DataD4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD4::Noe, p> {
	static_assert((p == Peripheral::Fmc),"GpioD4::Noe only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD4::Rts, p> {
	static_assert((p == Peripheral::Usart2),"GpioD4::Rts only connects to Usart2!"); };
template<> struct SignalConnection<DataD4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD4::Noe, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD4::Rts, Peripheral::Usart2> { static constexpr int8_t af = 7; };

struct DataD5 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataD5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Nwe { using Data = DataD5; static constexpr Gpio::Signal Signal = Gpio::Signal::Nwe; };
	struct Tx { using Data = DataD5; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataD5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD5::Nwe, p> {
	static_assert((p == Peripheral::Fmc),"GpioD5::Nwe only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD5::Tx, p> {
	static_assert((p == Peripheral::Usart2),"GpioD5::Tx only connects to Usart2!"); };
template<> struct SignalConnection<DataD5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD5::Nwe, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD5::Tx, Peripheral::Usart2> { static constexpr int8_t af = 7; };

struct DataD6 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D10 { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::D10; };
	struct Mosi { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Nwait { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::Nwait; };
	struct Rx { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Sd { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::Sd; };
	struct Sda { using Data = DataD6; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataD6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD6::D10, p> {
	static_assert((p == Peripheral::Dcmi),"GpioD6::D10 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataD6::Mosi, p> {
	static_assert((p == Peripheral::Spi3),"GpioD6::Mosi only connects to Spi3!"); };
template<Peripheral p> struct SignalConnection<DataD6::Nwait, p> {
	static_assert((p == Peripheral::Fmc),"GpioD6::Nwait only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD6::Rx, p> {
	static_assert((p == Peripheral::Usart2),"GpioD6::Rx only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataD6::Sd, p> {
	static_assert((p == Peripheral::I2s3),"GpioD6::Sd only connects to I2s3!"); };
template<Peripheral p> struct SignalConnection<DataD6::Sda, p> {
	static_assert((p == Peripheral::Sai1),"GpioD6::Sda only connects to Sai1!"); };
template<> struct SignalConnection<DataD6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD6::D10, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataD6::Mosi, Peripheral::Spi3> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataD6::Nwait, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD6::Rx, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD6::Sd, Peripheral::I2s3> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataD6::Sda, Peripheral::Sai1> { static constexpr int8_t af = 6; };

struct DataD7 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataD7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ck { using Data = DataD7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct In0 { using Data = DataD7; static constexpr Gpio::Signal Signal = Gpio::Signal::In0; };
	struct Ne1 { using Data = DataD7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ne1; };
};
template<Peripheral p> struct SignalConnection<DataD7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD7::Ck, p> {
	static_assert((p == Peripheral::Usart2),"GpioD7::Ck only connects to Usart2!"); };
template<Peripheral p> struct SignalConnection<DataD7::In0, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioD7::In0 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataD7::Ne1, p> {
	static_assert((p == Peripheral::Fmc),"GpioD7::Ne1 only connects to Fmc!"); };
template<> struct SignalConnection<DataD7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD7::Ck, Peripheral::Usart2> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD7::In0, Peripheral::Spdifrx> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataD7::Ne1, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataD8 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataD8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D13 { using Data = DataD8; static constexpr Gpio::Signal Signal = Gpio::Signal::D13; };
	struct Da13 { using Data = DataD8; static constexpr Gpio::Signal Signal = Gpio::Signal::Da13; };
	struct In1 { using Data = DataD8; static constexpr Gpio::Signal Signal = Gpio::Signal::In1; };
	struct Tx { using Data = DataD8; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataD8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD8::D13, p> {
	static_assert((p == Peripheral::Fmc),"GpioD8::D13 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD8::Da13, p> {
	static_assert((p == Peripheral::Fmc),"GpioD8::Da13 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD8::In1, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioD8::In1 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataD8::Tx, p> {
	static_assert((p == Peripheral::Usart3),"GpioD8::Tx only connects to Usart3!"); };
template<> struct SignalConnection<DataD8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD8::D13, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD8::Da13, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD8::In1, Peripheral::Spdifrx> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataD8::Tx, Peripheral::Usart3> { static constexpr int8_t af = 7; };

struct DataD9 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataD9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D14 { using Data = DataD9; static constexpr Gpio::Signal Signal = Gpio::Signal::D14; };
	struct Da14 { using Data = DataD9; static constexpr Gpio::Signal Signal = Gpio::Signal::Da14; };
	struct Rx { using Data = DataD9; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataD9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD9::D14, p> {
	static_assert((p == Peripheral::Fmc),"GpioD9::D14 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD9::Da14, p> {
	static_assert((p == Peripheral::Fmc),"GpioD9::Da14 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD9::Rx, p> {
	static_assert((p == Peripheral::Usart3),"GpioD9::Rx only connects to Usart3!"); };
template<> struct SignalConnection<DataD9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD9::D14, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD9::Da14, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD9::Rx, Peripheral::Usart3> { static constexpr int8_t af = 7; };

struct DataD10 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataD10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ck { using Data = DataD10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D15 { using Data = DataD10; static constexpr Gpio::Signal Signal = Gpio::Signal::D15; };
	struct Da15 { using Data = DataD10; static constexpr Gpio::Signal Signal = Gpio::Signal::Da15; };
};
template<Peripheral p> struct SignalConnection<DataD10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD10::Ck, p> {
	static_assert((p == Peripheral::Usart3),"GpioD10::Ck only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataD10::D15, p> {
	static_assert((p == Peripheral::Fmc),"GpioD10::D15 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD10::Da15, p> {
	static_assert((p == Peripheral::Fmc),"GpioD10::Da15 only connects to Fmc!"); };
template<> struct SignalConnection<DataD10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD10::Ck, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD10::D15, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD10::Da15, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataD11 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A16 { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::A16; };
	struct Bk1io0 { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io0; };
	struct Cle { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::Cle; };
	struct Cts { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct Sda { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Smba { using Data = DataD11; static constexpr Gpio::Signal Signal = Gpio::Signal::Smba; };
};
template<Peripheral p> struct SignalConnection<DataD11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD11::A16, p> {
	static_assert((p == Peripheral::Fmc),"GpioD11::A16 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD11::Bk1io0, p> {
	static_assert((p == Peripheral::Quadspi),"GpioD11::Bk1io0 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataD11::Cle, p> {
	static_assert((p == Peripheral::Fmc),"GpioD11::Cle only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD11::Cts, p> {
	static_assert((p == Peripheral::Usart3),"GpioD11::Cts only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataD11::Sda, p> {
	static_assert((p == Peripheral::Sai2),"GpioD11::Sda only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataD11::Smba, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioD11::Smba only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataD11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD11::A16, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD11::Bk1io0, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataD11::Cle, Peripheral::Fmc> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD11::Cts, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD11::Sda, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataD11::Smba, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataD12 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A17 { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::A17; };
	struct Ale { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ale; };
	struct Bk1io1 { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io1; };
	struct Ch1 { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Fsa { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsa; };
	struct Rts { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
	struct Scl { using Data = DataD12; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
};
template<Peripheral p> struct SignalConnection<DataD12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD12::A17, p> {
	static_assert((p == Peripheral::Fmc),"GpioD12::A17 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD12::Ale, p> {
	static_assert((p == Peripheral::Fmc),"GpioD12::Ale only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD12::Bk1io1, p> {
	static_assert((p == Peripheral::Quadspi),"GpioD12::Bk1io1 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataD12::Ch1, p> {
	static_assert((p == Peripheral::Tim4),"GpioD12::Ch1 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataD12::Fsa, p> {
	static_assert((p == Peripheral::Sai2),"GpioD12::Fsa only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataD12::Rts, p> {
	static_assert((p == Peripheral::Usart3),"GpioD12::Rts only connects to Usart3!"); };
template<Peripheral p> struct SignalConnection<DataD12::Scl, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioD12::Scl only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataD12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD12::A17, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD12::Ale, Peripheral::Fmc> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD12::Bk1io1, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataD12::Ch1, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataD12::Fsa, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataD12::Rts, Peripheral::Usart3> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataD12::Scl, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataD13 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataD13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A18 { using Data = DataD13; static constexpr Gpio::Signal Signal = Gpio::Signal::A18; };
	struct Bk1io3 { using Data = DataD13; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io3; };
	struct Ch2 { using Data = DataD13; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct Scka { using Data = DataD13; static constexpr Gpio::Signal Signal = Gpio::Signal::Scka; };
	struct Sda { using Data = DataD13; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataD13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD13::A18, p> {
	static_assert((p == Peripheral::Fmc),"GpioD13::A18 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD13::Bk1io3, p> {
	static_assert((p == Peripheral::Quadspi),"GpioD13::Bk1io3 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataD13::Ch2, p> {
	static_assert((p == Peripheral::Tim4),"GpioD13::Ch2 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataD13::Scka, p> {
	static_assert((p == Peripheral::Sai2),"GpioD13::Scka only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataD13::Sda, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioD13::Sda only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataD13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD13::A18, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD13::Bk1io3, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataD13::Ch2, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataD13::Scka, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataD13::Sda, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataD14 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataD14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3 { using Data = DataD14; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct D0 { using Data = DataD14; static constexpr Gpio::Signal Signal = Gpio::Signal::D0; };
	struct Da0 { using Data = DataD14; static constexpr Gpio::Signal Signal = Gpio::Signal::Da0; };
	struct Scka { using Data = DataD14; static constexpr Gpio::Signal Signal = Gpio::Signal::Scka; };
	struct Scl { using Data = DataD14; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
};
template<Peripheral p> struct SignalConnection<DataD14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD14::Ch3, p> {
	static_assert((p == Peripheral::Tim4),"GpioD14::Ch3 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataD14::D0, p> {
	static_assert((p == Peripheral::Fmc),"GpioD14::D0 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD14::Da0, p> {
	static_assert((p == Peripheral::Fmc),"GpioD14::Da0 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD14::Scka, p> {
	static_assert((p == Peripheral::Sai2),"GpioD14::Scka only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataD14::Scl, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioD14::Scl only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataD14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD14::Ch3, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataD14::D0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD14::Da0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD14::Scka, Peripheral::Sai2> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataD14::Scl, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataD15 {
	static constexpr Gpio::Port port = Gpio::Port::D;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataD15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch4 { using Data = DataD15; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct D1 { using Data = DataD15; static constexpr Gpio::Signal Signal = Gpio::Signal::D1; };
	struct Da1 { using Data = DataD15; static constexpr Gpio::Signal Signal = Gpio::Signal::Da1; };
	struct Sda { using Data = DataD15; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataD15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioD15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataD15::Ch4, p> {
	static_assert((p == Peripheral::Tim4),"GpioD15::Ch4 only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataD15::D1, p> {
	static_assert((p == Peripheral::Fmc),"GpioD15::D1 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD15::Da1, p> {
	static_assert((p == Peripheral::Fmc),"GpioD15::Da1 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataD15::Sda, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioD15::Sda only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataD15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataD15::Ch4, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataD15::D1, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD15::Da1, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataD15::Sda, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataE0 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataE0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D2 { using Data = DataE0; static constexpr Gpio::Signal Signal = Gpio::Signal::D2; };
	struct Etr { using Data = DataE0; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct Mclka { using Data = DataE0; static constexpr Gpio::Signal Signal = Gpio::Signal::Mclka; };
	struct Nbl0 { using Data = DataE0; static constexpr Gpio::Signal Signal = Gpio::Signal::Nbl0; };
};
template<Peripheral p> struct SignalConnection<DataE0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE0::D2, p> {
	static_assert((p == Peripheral::Dcmi),"GpioE0::D2 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataE0::Etr, p> {
	static_assert((p == Peripheral::Tim4),"GpioE0::Etr only connects to Tim4!"); };
template<Peripheral p> struct SignalConnection<DataE0::Mclka, p> {
	static_assert((p == Peripheral::Sai2),"GpioE0::Mclka only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataE0::Nbl0, p> {
	static_assert((p == Peripheral::Fmc),"GpioE0::Nbl0 only connects to Fmc!"); };
template<> struct SignalConnection<DataE0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE0::D2, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataE0::Etr, Peripheral::Tim4> { static constexpr int8_t af = 2; };
template<> struct SignalConnection<DataE0::Mclka, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE0::Nbl0, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataE1 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataE1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D3 { using Data = DataE1; static constexpr Gpio::Signal Signal = Gpio::Signal::D3; };
	struct Nbl1 { using Data = DataE1; static constexpr Gpio::Signal Signal = Gpio::Signal::Nbl1; };
};
template<Peripheral p> struct SignalConnection<DataE1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE1::D3, p> {
	static_assert((p == Peripheral::Dcmi),"GpioE1::D3 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataE1::Nbl1, p> {
	static_assert((p == Peripheral::Fmc),"GpioE1::Nbl1 only connects to Fmc!"); };
template<> struct SignalConnection<DataE1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE1::D3, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataE1::Nbl1, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataE2 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataE2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A23 { using Data = DataE2; static constexpr Gpio::Signal Signal = Gpio::Signal::A23; };
	struct Bk1io2 { using Data = DataE2; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io2; };
	struct Mclka { using Data = DataE2; static constexpr Gpio::Signal Signal = Gpio::Signal::Mclka; };
	struct Sck { using Data = DataE2; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Traceclk { using Data = DataE2; static constexpr Gpio::Signal Signal = Gpio::Signal::Traceclk; };
};
template<Peripheral p> struct SignalConnection<DataE2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE2::A23, p> {
	static_assert((p == Peripheral::Fmc),"GpioE2::A23 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE2::Bk1io2, p> {
	static_assert((p == Peripheral::Quadspi),"GpioE2::Bk1io2 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataE2::Mclka, p> {
	static_assert((p == Peripheral::Sai1),"GpioE2::Mclka only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataE2::Sck, p> {
	static_assert((p == Peripheral::Spi4),"GpioE2::Sck only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataE2::Traceclk, p> {
	static_assert((p == Peripheral::Sys),"GpioE2::Traceclk only connects to Sys!"); };
template<> struct SignalConnection<DataE2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE2::A23, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE2::Bk1io2, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataE2::Mclka, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataE2::Sck, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataE2::Traceclk, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataE3 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataE3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A19 { using Data = DataE3; static constexpr Gpio::Signal Signal = Gpio::Signal::A19; };
	struct Sdb { using Data = DataE3; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdb; };
	struct Traced0 { using Data = DataE3; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced0; };
};
template<Peripheral p> struct SignalConnection<DataE3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE3::A19, p> {
	static_assert((p == Peripheral::Fmc),"GpioE3::A19 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE3::Sdb, p> {
	static_assert((p == Peripheral::Sai1),"GpioE3::Sdb only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataE3::Traced0, p> {
	static_assert((p == Peripheral::Sys),"GpioE3::Traced0 only connects to Sys!"); };
template<> struct SignalConnection<DataE3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE3::A19, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE3::Sdb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataE3::Traced0, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataE4 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataE4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A20 { using Data = DataE4; static constexpr Gpio::Signal Signal = Gpio::Signal::A20; };
	struct D4 { using Data = DataE4; static constexpr Gpio::Signal Signal = Gpio::Signal::D4; };
	struct Fsa { using Data = DataE4; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsa; };
	struct Nss { using Data = DataE4; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Traced1 { using Data = DataE4; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced1; };
};
template<Peripheral p> struct SignalConnection<DataE4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE4::A20, p> {
	static_assert((p == Peripheral::Fmc),"GpioE4::A20 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE4::D4, p> {
	static_assert((p == Peripheral::Dcmi),"GpioE4::D4 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataE4::Fsa, p> {
	static_assert((p == Peripheral::Sai1),"GpioE4::Fsa only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataE4::Nss, p> {
	static_assert((p == Peripheral::Spi4),"GpioE4::Nss only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataE4::Traced1, p> {
	static_assert((p == Peripheral::Sys),"GpioE4::Traced1 only connects to Sys!"); };
template<> struct SignalConnection<DataE4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE4::A20, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE4::D4, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataE4::Fsa, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataE4::Nss, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataE4::Traced1, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataE5 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A21 { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::A21; };
	struct Ch1 { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct D6 { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::D6; };
	struct Miso { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Scka { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::Scka; };
	struct Traced2 { using Data = DataE5; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced2; };
};
template<Peripheral p> struct SignalConnection<DataE5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE5::A21, p> {
	static_assert((p == Peripheral::Fmc),"GpioE5::A21 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE5::Ch1, p> {
	static_assert((p == Peripheral::Tim9),"GpioE5::Ch1 only connects to Tim9!"); };
template<Peripheral p> struct SignalConnection<DataE5::D6, p> {
	static_assert((p == Peripheral::Dcmi),"GpioE5::D6 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataE5::Miso, p> {
	static_assert((p == Peripheral::Spi4),"GpioE5::Miso only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataE5::Scka, p> {
	static_assert((p == Peripheral::Sai1),"GpioE5::Scka only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataE5::Traced2, p> {
	static_assert((p == Peripheral::Sys),"GpioE5::Traced2 only connects to Sys!"); };
template<> struct SignalConnection<DataE5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE5::A21, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE5::Ch1, Peripheral::Tim9> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataE5::D6, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataE5::Miso, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataE5::Scka, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataE5::Traced2, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataE6 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A22 { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::A22; };
	struct Ch2 { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct D7 { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::D7; };
	struct Mosi { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Sda { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
	struct Traced3 { using Data = DataE6; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced3; };
};
template<Peripheral p> struct SignalConnection<DataE6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE6::A22, p> {
	static_assert((p == Peripheral::Fmc),"GpioE6::A22 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE6::Ch2, p> {
	static_assert((p == Peripheral::Tim9),"GpioE6::Ch2 only connects to Tim9!"); };
template<Peripheral p> struct SignalConnection<DataE6::D7, p> {
	static_assert((p == Peripheral::Dcmi),"GpioE6::D7 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataE6::Mosi, p> {
	static_assert((p == Peripheral::Spi4),"GpioE6::Mosi only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataE6::Sda, p> {
	static_assert((p == Peripheral::Sai1),"GpioE6::Sda only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataE6::Traced3, p> {
	static_assert((p == Peripheral::Sys),"GpioE6::Traced3 only connects to Sys!"); };
template<> struct SignalConnection<DataE6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE6::A22, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE6::Ch2, Peripheral::Tim9> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataE6::D7, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataE6::Mosi, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataE6::Sda, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataE6::Traced3, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataE7 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataE7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk2io0 { using Data = DataE7; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2io0; };
	struct D4 { using Data = DataE7; static constexpr Gpio::Signal Signal = Gpio::Signal::D4; };
	struct Da4 { using Data = DataE7; static constexpr Gpio::Signal Signal = Gpio::Signal::Da4; };
	struct Etr { using Data = DataE7; static constexpr Gpio::Signal Signal = Gpio::Signal::Etr; };
	struct Rx { using Data = DataE7; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
};
template<Peripheral p> struct SignalConnection<DataE7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE7::Bk2io0, p> {
	static_assert((p == Peripheral::Quadspi),"GpioE7::Bk2io0 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataE7::D4, p> {
	static_assert((p == Peripheral::Fmc),"GpioE7::D4 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE7::Da4, p> {
	static_assert((p == Peripheral::Fmc),"GpioE7::Da4 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE7::Etr, p> {
	static_assert((p == Peripheral::Tim1),"GpioE7::Etr only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE7::Rx, p> {
	static_assert((p == Peripheral::Uart5),"GpioE7::Rx only connects to Uart5!"); };
template<> struct SignalConnection<DataE7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE7::Bk2io0, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE7::D4, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE7::Da4, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE7::Etr, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE7::Rx, Peripheral::Uart5> { static constexpr int8_t af = 8; };

struct DataE8 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataE8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk2io1 { using Data = DataE8; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2io1; };
	struct Ch1n { using Data = DataE8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1n; };
	struct D5 { using Data = DataE8; static constexpr Gpio::Signal Signal = Gpio::Signal::D5; };
	struct Da5 { using Data = DataE8; static constexpr Gpio::Signal Signal = Gpio::Signal::Da5; };
	struct Tx { using Data = DataE8; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataE8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE8::Bk2io1, p> {
	static_assert((p == Peripheral::Quadspi),"GpioE8::Bk2io1 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataE8::Ch1n, p> {
	static_assert((p == Peripheral::Tim1),"GpioE8::Ch1n only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE8::D5, p> {
	static_assert((p == Peripheral::Fmc),"GpioE8::D5 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE8::Da5, p> {
	static_assert((p == Peripheral::Fmc),"GpioE8::Da5 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE8::Tx, p> {
	static_assert((p == Peripheral::Uart5),"GpioE8::Tx only connects to Uart5!"); };
template<> struct SignalConnection<DataE8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE8::Bk2io1, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE8::Ch1n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE8::D5, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE8::Da5, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE8::Tx, Peripheral::Uart5> { static constexpr int8_t af = 8; };

struct DataE9 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataE9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk2io2 { using Data = DataE9; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2io2; };
	struct Ch1 { using Data = DataE9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct D6 { using Data = DataE9; static constexpr Gpio::Signal Signal = Gpio::Signal::D6; };
	struct Da6 { using Data = DataE9; static constexpr Gpio::Signal Signal = Gpio::Signal::Da6; };
};
template<Peripheral p> struct SignalConnection<DataE9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE9::Bk2io2, p> {
	static_assert((p == Peripheral::Quadspi),"GpioE9::Bk2io2 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataE9::Ch1, p> {
	static_assert((p == Peripheral::Tim1),"GpioE9::Ch1 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE9::D6, p> {
	static_assert((p == Peripheral::Fmc),"GpioE9::D6 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE9::Da6, p> {
	static_assert((p == Peripheral::Fmc),"GpioE9::Da6 only connects to Fmc!"); };
template<> struct SignalConnection<DataE9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE9::Bk2io2, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE9::Ch1, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE9::D6, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE9::Da6, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataE10 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataE10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk2io3 { using Data = DataE10; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2io3; };
	struct Ch2n { using Data = DataE10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2n; };
	struct D7 { using Data = DataE10; static constexpr Gpio::Signal Signal = Gpio::Signal::D7; };
	struct Da7 { using Data = DataE10; static constexpr Gpio::Signal Signal = Gpio::Signal::Da7; };
};
template<Peripheral p> struct SignalConnection<DataE10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE10::Bk2io3, p> {
	static_assert((p == Peripheral::Quadspi),"GpioE10::Bk2io3 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataE10::Ch2n, p> {
	static_assert((p == Peripheral::Tim1),"GpioE10::Ch2n only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE10::D7, p> {
	static_assert((p == Peripheral::Fmc),"GpioE10::D7 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE10::Da7, p> {
	static_assert((p == Peripheral::Fmc),"GpioE10::Da7 only connects to Fmc!"); };
template<> struct SignalConnection<DataE10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE10::Bk2io3, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE10::Ch2n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE10::D7, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE10::Da7, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataE11 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataE11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch2 { using Data = DataE11; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch2; };
	struct D8 { using Data = DataE11; static constexpr Gpio::Signal Signal = Gpio::Signal::D8; };
	struct Da8 { using Data = DataE11; static constexpr Gpio::Signal Signal = Gpio::Signal::Da8; };
	struct Nss { using Data = DataE11; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Sdb { using Data = DataE11; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdb; };
};
template<Peripheral p> struct SignalConnection<DataE11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE11::Ch2, p> {
	static_assert((p == Peripheral::Tim1),"GpioE11::Ch2 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE11::D8, p> {
	static_assert((p == Peripheral::Fmc),"GpioE11::D8 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE11::Da8, p> {
	static_assert((p == Peripheral::Fmc),"GpioE11::Da8 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE11::Nss, p> {
	static_assert((p == Peripheral::Spi4),"GpioE11::Nss only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataE11::Sdb, p> {
	static_assert((p == Peripheral::Sai2),"GpioE11::Sdb only connects to Sai2!"); };
template<> struct SignalConnection<DataE11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE11::Ch2, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE11::D8, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE11::Da8, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE11::Nss, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataE11::Sdb, Peripheral::Sai2> { static constexpr int8_t af = 10; };

struct DataE12 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataE12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3n { using Data = DataE12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3n; };
	struct D9 { using Data = DataE12; static constexpr Gpio::Signal Signal = Gpio::Signal::D9; };
	struct Da9 { using Data = DataE12; static constexpr Gpio::Signal Signal = Gpio::Signal::Da9; };
	struct Sck { using Data = DataE12; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
	struct Sckb { using Data = DataE12; static constexpr Gpio::Signal Signal = Gpio::Signal::Sckb; };
};
template<Peripheral p> struct SignalConnection<DataE12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE12::Ch3n, p> {
	static_assert((p == Peripheral::Tim1),"GpioE12::Ch3n only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE12::D9, p> {
	static_assert((p == Peripheral::Fmc),"GpioE12::D9 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE12::Da9, p> {
	static_assert((p == Peripheral::Fmc),"GpioE12::Da9 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE12::Sck, p> {
	static_assert((p == Peripheral::Spi4),"GpioE12::Sck only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataE12::Sckb, p> {
	static_assert((p == Peripheral::Sai2),"GpioE12::Sckb only connects to Sai2!"); };
template<> struct SignalConnection<DataE12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE12::Ch3n, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE12::D9, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE12::Da9, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE12::Sck, Peripheral::Spi4> { static constexpr int8_t af = 5; };
template<> struct SignalConnection<DataE12::Sckb, Peripheral::Sai2> { static constexpr int8_t af = 10; };

struct DataE13 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataE13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch3 { using Data = DataE13; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch3; };
	struct D10 { using Data = DataE13; static constexpr Gpio::Signal Signal = Gpio::Signal::D10; };
	struct Da10 { using Data = DataE13; static constexpr Gpio::Signal Signal = Gpio::Signal::Da10; };
	struct Fsb { using Data = DataE13; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsb; };
	struct Miso { using Data = DataE13; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
};
template<Peripheral p> struct SignalConnection<DataE13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE13::Ch3, p> {
	static_assert((p == Peripheral::Tim1),"GpioE13::Ch3 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE13::D10, p> {
	static_assert((p == Peripheral::Fmc),"GpioE13::D10 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE13::Da10, p> {
	static_assert((p == Peripheral::Fmc),"GpioE13::Da10 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE13::Fsb, p> {
	static_assert((p == Peripheral::Sai2),"GpioE13::Fsb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataE13::Miso, p> {
	static_assert((p == Peripheral::Spi4),"GpioE13::Miso only connects to Spi4!"); };
template<> struct SignalConnection<DataE13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE13::Ch3, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE13::D10, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE13::Da10, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE13::Fsb, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE13::Miso, Peripheral::Spi4> { static constexpr int8_t af = 5; };

struct DataE14 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataE14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ch4 { using Data = DataE14; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch4; };
	struct D11 { using Data = DataE14; static constexpr Gpio::Signal Signal = Gpio::Signal::D11; };
	struct Da11 { using Data = DataE14; static constexpr Gpio::Signal Signal = Gpio::Signal::Da11; };
	struct Mclkb { using Data = DataE14; static constexpr Gpio::Signal Signal = Gpio::Signal::Mclkb; };
	struct Mosi { using Data = DataE14; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
};
template<Peripheral p> struct SignalConnection<DataE14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE14::Ch4, p> {
	static_assert((p == Peripheral::Tim1),"GpioE14::Ch4 only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE14::D11, p> {
	static_assert((p == Peripheral::Fmc),"GpioE14::D11 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE14::Da11, p> {
	static_assert((p == Peripheral::Fmc),"GpioE14::Da11 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE14::Mclkb, p> {
	static_assert((p == Peripheral::Sai2),"GpioE14::Mclkb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataE14::Mosi, p> {
	static_assert((p == Peripheral::Spi4),"GpioE14::Mosi only connects to Spi4!"); };
template<> struct SignalConnection<DataE14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE14::Ch4, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE14::D11, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE14::Da11, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE14::Mclkb, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataE14::Mosi, Peripheral::Spi4> { static constexpr int8_t af = 5; };

struct DataE15 {
	static constexpr Gpio::Port port = Gpio::Port::E;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataE15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bkin { using Data = DataE15; static constexpr Gpio::Signal Signal = Gpio::Signal::Bkin; };
	struct D12 { using Data = DataE15; static constexpr Gpio::Signal Signal = Gpio::Signal::D12; };
	struct Da12 { using Data = DataE15; static constexpr Gpio::Signal Signal = Gpio::Signal::Da12; };
};
template<Peripheral p> struct SignalConnection<DataE15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioE15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataE15::Bkin, p> {
	static_assert((p == Peripheral::Tim1),"GpioE15::Bkin only connects to Tim1!"); };
template<Peripheral p> struct SignalConnection<DataE15::D12, p> {
	static_assert((p == Peripheral::Fmc),"GpioE15::D12 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataE15::Da12, p> {
	static_assert((p == Peripheral::Fmc),"GpioE15::Da12 only connects to Fmc!"); };
template<> struct SignalConnection<DataE15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataE15::Bkin, Peripheral::Tim1> { static constexpr int8_t af = 1; };
template<> struct SignalConnection<DataE15::D12, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataE15::Da12, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataF0 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataF0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A0 { using Data = DataF0; static constexpr Gpio::Signal Signal = Gpio::Signal::A0; };
	struct Sda { using Data = DataF0; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataF0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF0::A0, p> {
	static_assert((p == Peripheral::Fmc),"GpioF0::A0 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF0::Sda, p> {
	static_assert((p == Peripheral::I2c2),"GpioF0::Sda only connects to I2c2!"); };
template<> struct SignalConnection<DataF0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF0::A0, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF0::Sda, Peripheral::I2c2> { static constexpr int8_t af = 4; };

struct DataF1 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataF1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A1 { using Data = DataF1; static constexpr Gpio::Signal Signal = Gpio::Signal::A1; };
	struct Scl { using Data = DataF1; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
};
template<Peripheral p> struct SignalConnection<DataF1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF1::A1, p> {
	static_assert((p == Peripheral::Fmc),"GpioF1::A1 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF1::Scl, p> {
	static_assert((p == Peripheral::I2c2),"GpioF1::Scl only connects to I2c2!"); };
template<> struct SignalConnection<DataF1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF1::A1, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF1::Scl, Peripheral::I2c2> { static constexpr int8_t af = 4; };

struct DataF2 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataF2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A2 { using Data = DataF2; static constexpr Gpio::Signal Signal = Gpio::Signal::A2; };
	struct Smba { using Data = DataF2; static constexpr Gpio::Signal Signal = Gpio::Signal::Smba; };
};
template<Peripheral p> struct SignalConnection<DataF2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF2::A2, p> {
	static_assert((p == Peripheral::Fmc),"GpioF2::A2 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF2::Smba, p> {
	static_assert((p == Peripheral::I2c2),"GpioF2::Smba only connects to I2c2!"); };
template<> struct SignalConnection<DataF2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF2::A2, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF2::Smba, Peripheral::I2c2> { static constexpr int8_t af = 4; };

struct DataF3 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataF3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A3 { using Data = DataF3; static constexpr Gpio::Signal Signal = Gpio::Signal::A3; };
	struct In9 { using Data = DataF3; static constexpr Gpio::Signal Signal = Gpio::Signal::In9; };
};
template<Peripheral p> struct SignalConnection<DataF3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF3::A3, p> {
	static_assert((p == Peripheral::Fmc),"GpioF3::A3 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF3::In9, p> {
	static_assert((p == Peripheral::Adc3),"GpioF3::In9 only connects to Adc3!"); };
template<> struct SignalConnection<DataF3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF3::A3, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF3::In9, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> constexpr int8_t AdcChannel<DataF3, Peripheral::Adc3> = 9;

struct DataF4 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataF4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A4 { using Data = DataF4; static constexpr Gpio::Signal Signal = Gpio::Signal::A4; };
	struct In14 { using Data = DataF4; static constexpr Gpio::Signal Signal = Gpio::Signal::In14; };
};
template<Peripheral p> struct SignalConnection<DataF4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF4::A4, p> {
	static_assert((p == Peripheral::Fmc),"GpioF4::A4 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF4::In14, p> {
	static_assert((p == Peripheral::Adc3),"GpioF4::In14 only connects to Adc3!"); };
template<> struct SignalConnection<DataF4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF4::A4, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF4::In14, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> constexpr int8_t AdcChannel<DataF4, Peripheral::Adc3> = 14;

struct DataF5 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataF5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A5 { using Data = DataF5; static constexpr Gpio::Signal Signal = Gpio::Signal::A5; };
	struct In15 { using Data = DataF5; static constexpr Gpio::Signal Signal = Gpio::Signal::In15; };
};
template<Peripheral p> struct SignalConnection<DataF5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF5::A5, p> {
	static_assert((p == Peripheral::Fmc),"GpioF5::A5 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF5::In15, p> {
	static_assert((p == Peripheral::Adc3),"GpioF5::In15 only connects to Adc3!"); };
template<> struct SignalConnection<DataF5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF5::A5, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF5::In15, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> constexpr int8_t AdcChannel<DataF5, Peripheral::Adc3> = 15;

struct DataF6 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataF6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io3 { using Data = DataF6; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io3; };
	struct Ch1 { using Data = DataF6; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct In4 { using Data = DataF6; static constexpr Gpio::Signal Signal = Gpio::Signal::In4; };
	struct Sdb { using Data = DataF6; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdb; };
};
template<Peripheral p> struct SignalConnection<DataF6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF6::Bk1io3, p> {
	static_assert((p == Peripheral::Quadspi),"GpioF6::Bk1io3 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataF6::Ch1, p> {
	static_assert((p == Peripheral::Tim10),"GpioF6::Ch1 only connects to Tim10!"); };
template<Peripheral p> struct SignalConnection<DataF6::In4, p> {
	static_assert((p == Peripheral::Adc3),"GpioF6::In4 only connects to Adc3!"); };
template<Peripheral p> struct SignalConnection<DataF6::Sdb, p> {
	static_assert((p == Peripheral::Sai1),"GpioF6::Sdb only connects to Sai1!"); };
template<> struct SignalConnection<DataF6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF6::Bk1io3, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataF6::Ch1, Peripheral::Tim10> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataF6::In4, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataF6::Sdb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> constexpr int8_t AdcChannel<DataF6, Peripheral::Adc3> = 4;

struct DataF7 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataF7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io2 { using Data = DataF7; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io2; };
	struct Ch1 { using Data = DataF7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct In5 { using Data = DataF7; static constexpr Gpio::Signal Signal = Gpio::Signal::In5; };
	struct Mclkb { using Data = DataF7; static constexpr Gpio::Signal Signal = Gpio::Signal::Mclkb; };
};
template<Peripheral p> struct SignalConnection<DataF7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF7::Bk1io2, p> {
	static_assert((p == Peripheral::Quadspi),"GpioF7::Bk1io2 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataF7::Ch1, p> {
	static_assert((p == Peripheral::Tim11),"GpioF7::Ch1 only connects to Tim11!"); };
template<Peripheral p> struct SignalConnection<DataF7::In5, p> {
	static_assert((p == Peripheral::Adc3),"GpioF7::In5 only connects to Adc3!"); };
template<Peripheral p> struct SignalConnection<DataF7::Mclkb, p> {
	static_assert((p == Peripheral::Sai1),"GpioF7::Mclkb only connects to Sai1!"); };
template<> struct SignalConnection<DataF7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF7::Bk1io2, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataF7::Ch1, Peripheral::Tim11> { static constexpr int8_t af = 3; };
template<> struct SignalConnection<DataF7::In5, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataF7::Mclkb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> constexpr int8_t AdcChannel<DataF7, Peripheral::Adc3> = 5;

struct DataF8 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataF8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io0 { using Data = DataF8; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io0; };
	struct Ch1 { using Data = DataF8; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct In6 { using Data = DataF8; static constexpr Gpio::Signal Signal = Gpio::Signal::In6; };
	struct Sckb { using Data = DataF8; static constexpr Gpio::Signal Signal = Gpio::Signal::Sckb; };
};
template<Peripheral p> struct SignalConnection<DataF8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF8::Bk1io0, p> {
	static_assert((p == Peripheral::Quadspi),"GpioF8::Bk1io0 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataF8::Ch1, p> {
	static_assert((p == Peripheral::Tim13),"GpioF8::Ch1 only connects to Tim13!"); };
template<Peripheral p> struct SignalConnection<DataF8::In6, p> {
	static_assert((p == Peripheral::Adc3),"GpioF8::In6 only connects to Adc3!"); };
template<Peripheral p> struct SignalConnection<DataF8::Sckb, p> {
	static_assert((p == Peripheral::Sai1),"GpioF8::Sckb only connects to Sai1!"); };
template<> struct SignalConnection<DataF8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF8::Bk1io0, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataF8::Ch1, Peripheral::Tim13> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataF8::In6, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> struct SignalConnection<DataF8::Sckb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> constexpr int8_t AdcChannel<DataF8, Peripheral::Adc3> = 6;

struct DataF9 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataF9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1io1 { using Data = DataF9; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1io1; };
	struct Ch1 { using Data = DataF9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ch1; };
	struct Fsb { using Data = DataF9; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsb; };
	struct In7 { using Data = DataF9; static constexpr Gpio::Signal Signal = Gpio::Signal::In7; };
};
template<Peripheral p> struct SignalConnection<DataF9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF9::Bk1io1, p> {
	static_assert((p == Peripheral::Quadspi),"GpioF9::Bk1io1 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataF9::Ch1, p> {
	static_assert((p == Peripheral::Tim14),"GpioF9::Ch1 only connects to Tim14!"); };
template<Peripheral p> struct SignalConnection<DataF9::Fsb, p> {
	static_assert((p == Peripheral::Sai1),"GpioF9::Fsb only connects to Sai1!"); };
template<Peripheral p> struct SignalConnection<DataF9::In7, p> {
	static_assert((p == Peripheral::Adc3),"GpioF9::In7 only connects to Adc3!"); };
template<> struct SignalConnection<DataF9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF9::Bk1io1, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataF9::Ch1, Peripheral::Tim14> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataF9::Fsb, Peripheral::Sai1> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataF9::In7, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> constexpr int8_t AdcChannel<DataF9, Peripheral::Adc3> = 7;

struct DataF10 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataF10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D11 { using Data = DataF10; static constexpr Gpio::Signal Signal = Gpio::Signal::D11; };
	struct In8 { using Data = DataF10; static constexpr Gpio::Signal Signal = Gpio::Signal::In8; };
};
template<Peripheral p> struct SignalConnection<DataF10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF10::D11, p> {
	static_assert((p == Peripheral::Dcmi),"GpioF10::D11 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataF10::In8, p> {
	static_assert((p == Peripheral::Adc3),"GpioF10::In8 only connects to Adc3!"); };
template<> struct SignalConnection<DataF10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF10::D11, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataF10::In8, Peripheral::Adc3> { static constexpr int8_t af = -2; };
template<> constexpr int8_t AdcChannel<DataF10, Peripheral::Adc3> = 8;

struct DataF11 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataF11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D12 { using Data = DataF11; static constexpr Gpio::Signal Signal = Gpio::Signal::D12; };
	struct Sdb { using Data = DataF11; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdb; };
	struct Sdnras { using Data = DataF11; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdnras; };
};
template<Peripheral p> struct SignalConnection<DataF11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF11::D12, p> {
	static_assert((p == Peripheral::Dcmi),"GpioF11::D12 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataF11::Sdb, p> {
	static_assert((p == Peripheral::Sai2),"GpioF11::Sdb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataF11::Sdnras, p> {
	static_assert((p == Peripheral::Fmc),"GpioF11::Sdnras only connects to Fmc!"); };
template<> struct SignalConnection<DataF11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF11::D12, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataF11::Sdb, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataF11::Sdnras, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataF12 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataF12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A6 { using Data = DataF12; static constexpr Gpio::Signal Signal = Gpio::Signal::A6; };
};
template<Peripheral p> struct SignalConnection<DataF12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF12::A6, p> {
	static_assert((p == Peripheral::Fmc),"GpioF12::A6 only connects to Fmc!"); };
template<> struct SignalConnection<DataF12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF12::A6, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataF13 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataF13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A7 { using Data = DataF13; static constexpr Gpio::Signal Signal = Gpio::Signal::A7; };
	struct Smba { using Data = DataF13; static constexpr Gpio::Signal Signal = Gpio::Signal::Smba; };
};
template<Peripheral p> struct SignalConnection<DataF13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF13::A7, p> {
	static_assert((p == Peripheral::Fmc),"GpioF13::A7 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF13::Smba, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioF13::Smba only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataF13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF13::A7, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF13::Smba, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataF14 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataF14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A8 { using Data = DataF14; static constexpr Gpio::Signal Signal = Gpio::Signal::A8; };
	struct Scl { using Data = DataF14; static constexpr Gpio::Signal Signal = Gpio::Signal::Scl; };
};
template<Peripheral p> struct SignalConnection<DataF14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF14::A8, p> {
	static_assert((p == Peripheral::Fmc),"GpioF14::A8 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF14::Scl, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioF14::Scl only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataF14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF14::A8, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF14::Scl, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataF15 {
	static constexpr Gpio::Port port = Gpio::Port::F;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataF15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A9 { using Data = DataF15; static constexpr Gpio::Signal Signal = Gpio::Signal::A9; };
	struct Sda { using Data = DataF15; static constexpr Gpio::Signal Signal = Gpio::Signal::Sda; };
};
template<Peripheral p> struct SignalConnection<DataF15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioF15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataF15::A9, p> {
	static_assert((p == Peripheral::Fmc),"GpioF15::A9 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataF15::Sda, p> {
	static_assert((p == Peripheral::Fmpi2c1),"GpioF15::Sda only connects to Fmpi2c1!"); };
template<> struct SignalConnection<DataF15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataF15::A9, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataF15::Sda, Peripheral::Fmpi2c1> { static constexpr int8_t af = 4; };

struct DataG0 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataG0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A10 { using Data = DataG0; static constexpr Gpio::Signal Signal = Gpio::Signal::A10; };
};
template<Peripheral p> struct SignalConnection<DataG0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG0::A10, p> {
	static_assert((p == Peripheral::Fmc),"GpioG0::A10 only connects to Fmc!"); };
template<> struct SignalConnection<DataG0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG0::A10, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG1 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataG1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A11 { using Data = DataG1; static constexpr Gpio::Signal Signal = Gpio::Signal::A11; };
};
template<Peripheral p> struct SignalConnection<DataG1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG1::A11, p> {
	static_assert((p == Peripheral::Fmc),"GpioG1::A11 only connects to Fmc!"); };
template<> struct SignalConnection<DataG1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG1::A11, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG2 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 2;
	struct BitBang { using Data = DataG2; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A12 { using Data = DataG2; static constexpr Gpio::Signal Signal = Gpio::Signal::A12; };
};
template<Peripheral p> struct SignalConnection<DataG2::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG2::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG2::A12, p> {
	static_assert((p == Peripheral::Fmc),"GpioG2::A12 only connects to Fmc!"); };
template<> struct SignalConnection<DataG2::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG2::A12, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG3 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 3;
	struct BitBang { using Data = DataG3; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A13 { using Data = DataG3; static constexpr Gpio::Signal Signal = Gpio::Signal::A13; };
};
template<Peripheral p> struct SignalConnection<DataG3::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG3::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG3::A13, p> {
	static_assert((p == Peripheral::Fmc),"GpioG3::A13 only connects to Fmc!"); };
template<> struct SignalConnection<DataG3::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG3::A13, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG4 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 4;
	struct BitBang { using Data = DataG4; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A14 { using Data = DataG4; static constexpr Gpio::Signal Signal = Gpio::Signal::A14; };
	struct Ba0 { using Data = DataG4; static constexpr Gpio::Signal Signal = Gpio::Signal::Ba0; };
};
template<Peripheral p> struct SignalConnection<DataG4::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG4::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG4::A14, p> {
	static_assert((p == Peripheral::Fmc),"GpioG4::A14 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG4::Ba0, p> {
	static_assert((p == Peripheral::Fmc),"GpioG4::Ba0 only connects to Fmc!"); };
template<> struct SignalConnection<DataG4::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG4::A14, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG4::Ba0, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG5 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 5;
	struct BitBang { using Data = DataG5; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A15 { using Data = DataG5; static constexpr Gpio::Signal Signal = Gpio::Signal::A15; };
	struct Ba1 { using Data = DataG5; static constexpr Gpio::Signal Signal = Gpio::Signal::Ba1; };
};
template<Peripheral p> struct SignalConnection<DataG5::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG5::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG5::A15, p> {
	static_assert((p == Peripheral::Fmc),"GpioG5::A15 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG5::Ba1, p> {
	static_assert((p == Peripheral::Fmc),"GpioG5::Ba1 only connects to Fmc!"); };
template<> struct SignalConnection<DataG5::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG5::A15, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG5::Ba1, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG6 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 6;
	struct BitBang { using Data = DataG6; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk1ncs { using Data = DataG6; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk1ncs; };
	struct D12 { using Data = DataG6; static constexpr Gpio::Signal Signal = Gpio::Signal::D12; };
};
template<Peripheral p> struct SignalConnection<DataG6::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG6::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG6::Bk1ncs, p> {
	static_assert((p == Peripheral::Quadspi),"GpioG6::Bk1ncs only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataG6::D12, p> {
	static_assert((p == Peripheral::Dcmi),"GpioG6::D12 only connects to Dcmi!"); };
template<> struct SignalConnection<DataG6::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG6::Bk1ncs, Peripheral::Quadspi> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataG6::D12, Peripheral::Dcmi> { static constexpr int8_t af = 13; };

struct DataG7 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 7;
	struct BitBang { using Data = DataG7; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Ck { using Data = DataG7; static constexpr Gpio::Signal Signal = Gpio::Signal::Ck; };
	struct D13 { using Data = DataG7; static constexpr Gpio::Signal Signal = Gpio::Signal::D13; };
	struct Int3 { using Data = DataG7; static constexpr Gpio::Signal Signal = Gpio::Signal::Int3; };
};
template<Peripheral p> struct SignalConnection<DataG7::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG7::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG7::Ck, p> {
	static_assert((p == Peripheral::Usart6),"GpioG7::Ck only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataG7::D13, p> {
	static_assert((p == Peripheral::Dcmi),"GpioG7::D13 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataG7::Int3, p> {
	static_assert((p == Peripheral::Fmc),"GpioG7::Int3 only connects to Fmc!"); };
template<> struct SignalConnection<DataG7::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG7::Ck, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataG7::D13, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataG7::Int3, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG8 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 8;
	struct BitBang { using Data = DataG8; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In2 { using Data = DataG8; static constexpr Gpio::Signal Signal = Gpio::Signal::In2; };
	struct Rts { using Data = DataG8; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
	struct Sdclk { using Data = DataG8; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdclk; };
};
template<Peripheral p> struct SignalConnection<DataG8::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG8::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG8::In2, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioG8::In2 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataG8::Rts, p> {
	static_assert((p == Peripheral::Usart6),"GpioG8::Rts only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataG8::Sdclk, p> {
	static_assert((p == Peripheral::Fmc),"GpioG8::Sdclk only connects to Fmc!"); };
template<> struct SignalConnection<DataG8::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG8::In2, Peripheral::Spdifrx> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataG8::Rts, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataG8::Sdclk, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataG9 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 9;
	struct BitBang { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Bk2io2 { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2io2; };
	struct Fsb { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::Fsb; };
	struct In3 { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::In3; };
	struct Nce3 { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::Nce3; };
	struct Ne2 { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::Ne2; };
	struct Rx { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::Rx; };
	struct Vsync { using Data = DataG9; static constexpr Gpio::Signal Signal = Gpio::Signal::Vsync; };
};
template<Peripheral p> struct SignalConnection<DataG9::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG9::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG9::Bk2io2, p> {
	static_assert((p == Peripheral::Quadspi),"GpioG9::Bk2io2 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataG9::Fsb, p> {
	static_assert((p == Peripheral::Sai2),"GpioG9::Fsb only connects to Sai2!"); };
template<Peripheral p> struct SignalConnection<DataG9::In3, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioG9::In3 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataG9::Nce3, p> {
	static_assert((p == Peripheral::Fmc),"GpioG9::Nce3 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG9::Ne2, p> {
	static_assert((p == Peripheral::Fmc),"GpioG9::Ne2 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG9::Rx, p> {
	static_assert((p == Peripheral::Usart6),"GpioG9::Rx only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataG9::Vsync, p> {
	static_assert((p == Peripheral::Dcmi),"GpioG9::Vsync only connects to Dcmi!"); };
template<> struct SignalConnection<DataG9::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG9::Bk2io2, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataG9::Fsb, Peripheral::Sai2> { static constexpr int8_t af = 10; };
template<> struct SignalConnection<DataG9::In3, Peripheral::Spdifrx> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataG9::Nce3, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG9::Ne2, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG9::Rx, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataG9::Vsync, Peripheral::Dcmi> { static constexpr int8_t af = 13; };

struct DataG10 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 10;
	struct BitBang { using Data = DataG10; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D2 { using Data = DataG10; static constexpr Gpio::Signal Signal = Gpio::Signal::D2; };
	struct Ne3 { using Data = DataG10; static constexpr Gpio::Signal Signal = Gpio::Signal::Ne3; };
	struct Sdb { using Data = DataG10; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdb; };
};
template<Peripheral p> struct SignalConnection<DataG10::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG10::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG10::D2, p> {
	static_assert((p == Peripheral::Dcmi),"GpioG10::D2 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataG10::Ne3, p> {
	static_assert((p == Peripheral::Fmc),"GpioG10::Ne3 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG10::Sdb, p> {
	static_assert((p == Peripheral::Sai2),"GpioG10::Sdb only connects to Sai2!"); };
template<> struct SignalConnection<DataG10::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG10::D2, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataG10::Ne3, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG10::Sdb, Peripheral::Sai2> { static constexpr int8_t af = 10; };

struct DataG11 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 11;
	struct BitBang { using Data = DataG11; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct D3 { using Data = DataG11; static constexpr Gpio::Signal Signal = Gpio::Signal::D3; };
	struct In0 { using Data = DataG11; static constexpr Gpio::Signal Signal = Gpio::Signal::In0; };
	struct Sck { using Data = DataG11; static constexpr Gpio::Signal Signal = Gpio::Signal::Sck; };
};
template<Peripheral p> struct SignalConnection<DataG11::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG11::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG11::D3, p> {
	static_assert((p == Peripheral::Dcmi),"GpioG11::D3 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataG11::In0, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioG11::In0 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataG11::Sck, p> {
	static_assert((p == Peripheral::Spi4),"GpioG11::Sck only connects to Spi4!"); };
template<> struct SignalConnection<DataG11::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG11::D3, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataG11::In0, Peripheral::Spdifrx> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataG11::Sck, Peripheral::Spi4> { static constexpr int8_t af = 6; };

struct DataG12 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 12;
	struct BitBang { using Data = DataG12; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct In1 { using Data = DataG12; static constexpr Gpio::Signal Signal = Gpio::Signal::In1; };
	struct Miso { using Data = DataG12; static constexpr Gpio::Signal Signal = Gpio::Signal::Miso; };
	struct Ne4 { using Data = DataG12; static constexpr Gpio::Signal Signal = Gpio::Signal::Ne4; };
	struct Rts { using Data = DataG12; static constexpr Gpio::Signal Signal = Gpio::Signal::Rts; };
};
template<Peripheral p> struct SignalConnection<DataG12::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG12::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG12::In1, p> {
	static_assert((p == Peripheral::Spdifrx),"GpioG12::In1 only connects to Spdifrx!"); };
template<Peripheral p> struct SignalConnection<DataG12::Miso, p> {
	static_assert((p == Peripheral::Spi4),"GpioG12::Miso only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataG12::Ne4, p> {
	static_assert((p == Peripheral::Fmc),"GpioG12::Ne4 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG12::Rts, p> {
	static_assert((p == Peripheral::Usart6),"GpioG12::Rts only connects to Usart6!"); };
template<> struct SignalConnection<DataG12::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG12::In1, Peripheral::Spdifrx> { static constexpr int8_t af = 7; };
template<> struct SignalConnection<DataG12::Miso, Peripheral::Spi4> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataG12::Ne4, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG12::Rts, Peripheral::Usart6> { static constexpr int8_t af = 8; };

struct DataG13 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 13;
	struct BitBang { using Data = DataG13; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A24 { using Data = DataG13; static constexpr Gpio::Signal Signal = Gpio::Signal::A24; };
	struct Cts { using Data = DataG13; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct Mosi { using Data = DataG13; static constexpr Gpio::Signal Signal = Gpio::Signal::Mosi; };
	struct Traced2 { using Data = DataG13; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced2; };
};
template<Peripheral p> struct SignalConnection<DataG13::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG13::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG13::A24, p> {
	static_assert((p == Peripheral::Fmc),"GpioG13::A24 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG13::Cts, p> {
	static_assert((p == Peripheral::Usart6),"GpioG13::Cts only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataG13::Mosi, p> {
	static_assert((p == Peripheral::Spi4),"GpioG13::Mosi only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataG13::Traced2, p> {
	static_assert((p == Peripheral::Sys),"GpioG13::Traced2 only connects to Sys!"); };
template<> struct SignalConnection<DataG13::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG13::A24, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG13::Cts, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataG13::Mosi, Peripheral::Spi4> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataG13::Traced2, Peripheral::Sys> { static constexpr int8_t af = 0; };

struct DataG14 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 14;
	struct BitBang { using Data = DataG14; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct A25 { using Data = DataG14; static constexpr Gpio::Signal Signal = Gpio::Signal::A25; };
	struct Bk2io3 { using Data = DataG14; static constexpr Gpio::Signal Signal = Gpio::Signal::Bk2io3; };
	struct Nss { using Data = DataG14; static constexpr Gpio::Signal Signal = Gpio::Signal::Nss; };
	struct Traced3 { using Data = DataG14; static constexpr Gpio::Signal Signal = Gpio::Signal::Traced3; };
	struct Tx { using Data = DataG14; static constexpr Gpio::Signal Signal = Gpio::Signal::Tx; };
};
template<Peripheral p> struct SignalConnection<DataG14::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG14::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG14::A25, p> {
	static_assert((p == Peripheral::Fmc),"GpioG14::A25 only connects to Fmc!"); };
template<Peripheral p> struct SignalConnection<DataG14::Bk2io3, p> {
	static_assert((p == Peripheral::Quadspi),"GpioG14::Bk2io3 only connects to Quadspi!"); };
template<Peripheral p> struct SignalConnection<DataG14::Nss, p> {
	static_assert((p == Peripheral::Spi4),"GpioG14::Nss only connects to Spi4!"); };
template<Peripheral p> struct SignalConnection<DataG14::Traced3, p> {
	static_assert((p == Peripheral::Sys),"GpioG14::Traced3 only connects to Sys!"); };
template<Peripheral p> struct SignalConnection<DataG14::Tx, p> {
	static_assert((p == Peripheral::Usart6),"GpioG14::Tx only connects to Usart6!"); };
template<> struct SignalConnection<DataG14::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG14::A25, Peripheral::Fmc> { static constexpr int8_t af = 12; };
template<> struct SignalConnection<DataG14::Bk2io3, Peripheral::Quadspi> { static constexpr int8_t af = 9; };
template<> struct SignalConnection<DataG14::Nss, Peripheral::Spi4> { static constexpr int8_t af = 6; };
template<> struct SignalConnection<DataG14::Traced3, Peripheral::Sys> { static constexpr int8_t af = 0; };
template<> struct SignalConnection<DataG14::Tx, Peripheral::Usart6> { static constexpr int8_t af = 8; };

struct DataG15 {
	static constexpr Gpio::Port port = Gpio::Port::G;
	static constexpr uint8_t pin = 15;
	struct BitBang { using Data = DataG15; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Cts { using Data = DataG15; static constexpr Gpio::Signal Signal = Gpio::Signal::Cts; };
	struct D13 { using Data = DataG15; static constexpr Gpio::Signal Signal = Gpio::Signal::D13; };
	struct Sdncas { using Data = DataG15; static constexpr Gpio::Signal Signal = Gpio::Signal::Sdncas; };
};
template<Peripheral p> struct SignalConnection<DataG15::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioG15::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataG15::Cts, p> {
	static_assert((p == Peripheral::Usart6),"GpioG15::Cts only connects to Usart6!"); };
template<Peripheral p> struct SignalConnection<DataG15::D13, p> {
	static_assert((p == Peripheral::Dcmi),"GpioG15::D13 only connects to Dcmi!"); };
template<Peripheral p> struct SignalConnection<DataG15::Sdncas, p> {
	static_assert((p == Peripheral::Fmc),"GpioG15::Sdncas only connects to Fmc!"); };
template<> struct SignalConnection<DataG15::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataG15::Cts, Peripheral::Usart6> { static constexpr int8_t af = 8; };
template<> struct SignalConnection<DataG15::D13, Peripheral::Dcmi> { static constexpr int8_t af = 13; };
template<> struct SignalConnection<DataG15::Sdncas, Peripheral::Fmc> { static constexpr int8_t af = 12; };

struct DataH0 {
	static constexpr Gpio::Port port = Gpio::Port::H;
	static constexpr uint8_t pin = 0;
	struct BitBang { using Data = DataH0; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Oscin { using Data = DataH0; static constexpr Gpio::Signal Signal = Gpio::Signal::Oscin; };
};
template<Peripheral p> struct SignalConnection<DataH0::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioH0::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataH0::Oscin, p> {
	static_assert((p == Peripheral::Rcc),"GpioH0::Oscin only connects to Rcc!"); };
template<> struct SignalConnection<DataH0::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataH0::Oscin, Peripheral::Rcc> { static constexpr int8_t af = -1; };

struct DataH1 {
	static constexpr Gpio::Port port = Gpio::Port::H;
	static constexpr uint8_t pin = 1;
	struct BitBang { using Data = DataH1; static constexpr Gpio::Signal Signal = Gpio::Signal::BitBang; };
	struct Oscout { using Data = DataH1; static constexpr Gpio::Signal Signal = Gpio::Signal::Oscout; };
};
template<Peripheral p> struct SignalConnection<DataH1::BitBang, p> {
	static_assert(p == Peripheral::BitBang, "GpioH1::BitBang only connects to software drivers!"); };
template<Peripheral p> struct SignalConnection<DataH1::Oscout, p> {
	static_assert((p == Peripheral::Rcc),"GpioH1::Oscout only connects to Rcc!"); };
template<> struct SignalConnection<DataH1::BitBang, Peripheral::BitBang> { static constexpr int8_t af = -1; };
template<> struct SignalConnection<DataH1::Oscout, Peripheral::Rcc> { static constexpr int8_t af = -1; };

} // namespace modm::platform::detail
/// @endcond