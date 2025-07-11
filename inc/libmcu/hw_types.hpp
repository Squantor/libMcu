/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file hw_types.hpp
 * @brief Types used by libMcuHw
 */
#ifndef HW_TYPES_HPP
#define HW_TYPES_HPP

//! @todo work in progress to change to namespace libmcuhw below
namespace libmcu {

using HwAddressBase = libmcu::Constant<std::uint32_t>; /*!< base type definition of a memory address */
using HwAddressType = typename HwAddressBase::type;    /*!< type definition of a memory address */

struct MemoryAddress : HwAddressBase {}; /*!< generic memory address */

/* Peripheral address types used by CortexM microcontrollers */
struct ScsBaseAddress : HwAddressBase {};     /*!< SCS */
struct SystickBaseAddress : HwAddressBase {}; /*!< SYSTICK */
struct NvicBaseAddress : HwAddressBase {};    /*!< NVIC */
struct ScbBaseAddress : HwAddressBase {};     /*!< SCB */
struct MpuBaseAddress : HwAddressBase {};     /*!< MPU */
struct MtbBaseAddress : HwAddressBase {};     /*!< MTB */

/* Peripheral address types used by all microcontrollers */
struct I2cBaseAddress : HwAddressBase {};    /*!< I2C */
struct SpiBaseAddress : HwAddressBase {};    /*!< SPI */
struct UartBaseAddress : HwAddressBase {};   /*!< UART */
struct CrcBaseAddress : HwAddressBase {};    /*!< CRC engine */
struct GpioBaseAddress : HwAddressBase {};   /*!< GPIO */
struct DmaBaseAddress : HwAddressBase {};    /*!< DMA */
struct DacBaseAddress : HwAddressBase {};    /*!< DAC */
struct AdcBaseAddress : HwAddressBase {};    /*!< ADC */
struct SyscfgBaseAddress : HwAddressBase {}; /*!< SYSCFG */

/* Peripheral address types used by NXP LPC microcontrollers */
struct WwdtBaseAddress : HwAddressBase {};   /*!< NXP LPC Windowed watchdog */
struct MrtBaseAddress : HwAddressBase {};    /*!< NXP LPC Multi rate timer*/
struct WktBaseAddress : HwAddressBase {};    /*!< NXP LPC Wakeup timer */
struct SwmBaseAddress : HwAddressBase {};    /*!< NXP LPC Switch Matrix */
struct PmuBaseAddress : HwAddressBase {};    /*!< NXP LPC Power management unit */
struct AcmpBaseAddress : HwAddressBase {};   /*!< NXP LPC Analog comparator */
struct FmcBaseAddress : HwAddressBase {};    /*!< NXP LPC Flash controller */
struct IoconBaseAddress : HwAddressBase {};  /*!< NXP LPC IO control */
struct SysconBaseAddress : HwAddressBase {}; /*!< NXP LPC System control*/
struct SctBaseAddress : HwAddressBase {};    /*!< NXP LPC state configurable timer */
struct PinintBaseAddress : HwAddressBase {}; /*!< NXP LPC Pin interrupt */
struct FaimBaseAddress : HwAddressBase {};   /*!< NXP LPC fast memory initialization */
struct InmuxBaseAddress : HwAddressBase {};  /*!< NXP LPC input multiplexer  */
struct CtimerBaseAddress : HwAddressBase {}; /*!< NXP LPC standard counter/timer */
struct CaptBaseAddress : HwAddressBase {};   /*!< NXP LPC capacitive touch */

/* Peripheral address types used by STM32 microcontrollers */
struct stmBaseAddress : HwAddressBase {}; /*!< STM generic peripheral */

/* Peripheral address types used by Raspberry Pi microcontrollers */
struct XipCtrlBaseAddress : HwAddressBase {};
struct XipSsiBaseAddress : HwAddressBase {};
struct SysinfoBaseAddress : HwAddressBase {};
struct ClocksBaseAddress : HwAddressBase {};
struct ResetsBaseAddress : HwAddressBase {};
struct PsmBaseAddress : HwAddressBase {};
struct IoBank0BaseAddress : HwAddressBase {};
struct IoQspiBaseAddress : HwAddressBase {};
struct PadsBank0BaseAddress : HwAddressBase {};
struct PadsQspiBaseAddress : HwAddressBase {};
struct XoscBaseAddress : HwAddressBase {};
struct PllBaseAddress : HwAddressBase {};
struct BusCtrlBaseAddress : HwAddressBase {};
struct PwmBaseAddress : HwAddressBase {};
struct TimerBaseAddress : HwAddressBase {};
struct WatchdogBaseAddress : HwAddressBase {};
struct RtcBaseAddress : HwAddressBase {};
struct RoscBaseAddress : HwAddressBase {};
struct VregChipResetBaseAddress : HwAddressBase {};
struct TbmanBaseAddress : HwAddressBase {};
struct UsbCtrlDPramBaseAddress : HwAddressBase {};
struct UsbCtrlRegsBaseAddress : HwAddressBase {};
struct PioBaseAddress : HwAddressBase {};
struct SioBaseAddress : HwAddressBase {};
struct PpbBaseAddress : HwAddressBase {};

}  // namespace libmcu

//! types used by libmcu hardware layer
namespace libmcuhw {
using HwAddressBase = libmcu::Constant<std::uint32_t>; /*!< base type definition of a memory address */
using HwAddressType = typename HwAddressBase::type;    /*!< type definition of a memory address */

struct MemoryAddress : HwAddressBase {}; /*!< generic memory address */

/* Peripheral address types used by all microcontrollers */
struct I2cBaseAddress : HwAddressBase {};  /*!< I2C */
struct SpiBaseAddress : HwAddressBase {};  /*!< SPI */
struct UartBaseAddress : HwAddressBase {}; /*!< UART */
struct GpioBaseAddress : HwAddressBase {}; /*!< GPIO */

}  // namespace libmcuhw

#endif