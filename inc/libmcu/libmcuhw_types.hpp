/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcuhw_types.hpp
 * @brief Types used by libMcuHw
 */
#ifndef LIBMCUHW_TYPES_HPP
#define LIBMCUHW_TYPES_HPP

//! @todo work in progress to change to namespace libmcuhw below
namespace libmcu {

using HwAddressBase = libmcu::Constant<std::uint32_t>; /*!< base type definition of a memory address */
using HwAddressType = typename HwAddressBase::type;    /*!< type definition of a memory address */

struct memoryAddress : HwAddressBase {}; /*!< generic memory address */

/* Peripheral address types used by CortexM microcontrollers */
struct scsBaseAddress : HwAddressBase {};     /*!< SCS */
struct systickBaseAddress : HwAddressBase {}; /*!< SYSTICK */
struct nvicBaseAddress : HwAddressBase {};    /*!< NVIC */
struct scbBaseAddress : HwAddressBase {};     /*!< SCB */
struct mpuBaseAddress : HwAddressBase {};     /*!< MPU */
struct mtbBaseAddress : HwAddressBase {};     /*!< MTB */

/* Peripheral address types used by all microcontrollers */
struct I2cBaseAddress : HwAddressBase {};    /*!< I2C */
struct spiBaseAddress : HwAddressBase {};    /*!< SPI */
struct uartBaseAddress : HwAddressBase {};   /*!< UART */
struct CrcBaseAddress : HwAddressBase {};    /*!< CRC engine */
struct gpioBaseAddress : HwAddressBase {};   /*!< GPIO */
struct dmaBaseAddress : HwAddressBase {};    /*!< DMA */
struct dacBaseAddress : HwAddressBase {};    /*!< DAC */
struct adcBaseAddress : HwAddressBase {};    /*!< ADC */
struct syscfgBaseAddress : HwAddressBase {}; /*!< SYSCFG */

/* Peripheral address types used by NXP LPC microcontrollers */
struct wwdtBaseAddress : HwAddressBase {};   /*!< NXP LPC Windowed watchdog */
struct MrtBaseAddress : HwAddressBase {};    /*!< NXP LPC Multi rate timer*/
struct wktBaseAddress : HwAddressBase {};    /*!< NXP LPC Wakeup timer */
struct swmBaseAddress : HwAddressBase {};    /*!< NXP LPC Switch Matrix */
struct pmuBaseAddress : HwAddressBase {};    /*!< NXP LPC Power management unit */
struct AcmpBaseAddress : HwAddressBase {};   /*!< NXP LPC Analog comparator */
struct FmcBaseAddress : HwAddressBase {};    /*!< NXP LPC Flash controller */
struct ioconBaseAddress : HwAddressBase {};  /*!< NXP LPC IO control */
struct sysconBaseAddress : HwAddressBase {}; /*!< NXP LPC System control*/
struct SctBaseAddress : HwAddressBase {};    /*!< NXP LPC state configurable timer */
struct pinintBaseAddress : HwAddressBase {}; /*!< NXP LPC Pin interrupt */
struct faimBaseAddress : HwAddressBase {};   /*!< NXP LPC fast memory initialization */
struct inmuxBaseAddress : HwAddressBase {};  /*!< NXP LPC input multiplexer  */
struct ctimerBaseAddress : HwAddressBase {}; /*!< NXP LPC standard counter/timer */
struct captBaseAddress : HwAddressBase {};   /*!< NXP LPC capacitive touch */

/* Peripheral address types used by STM32 microcontrollers */
struct stmBaseAddress : HwAddressBase {}; /*!< STM generic peripheral */

/* Peripheral address types used by Raspberry Pi microcontrollers */
struct xipCtrlBaseAddress : HwAddressBase {};
struct xipSsiBaseAddress : HwAddressBase {};
struct sysinfoBaseAddress : HwAddressBase {};
struct clocksBaseAddress : HwAddressBase {};
struct resetsBaseAddress : HwAddressBase {};
struct psmBaseAddress : HwAddressBase {};
struct ioBank0BaseAddress : HwAddressBase {};
struct ioQspiBaseAddress : HwAddressBase {};
struct padsBank0BaseAddress : HwAddressBase {};
struct padsQspiBaseAddress : HwAddressBase {};
struct xoscBaseAddress : HwAddressBase {};
struct pllBaseAddress : HwAddressBase {};
struct busCtrlBaseAddress : HwAddressBase {};
struct pwmBaseAddress : HwAddressBase {};
struct timerBaseAddress : HwAddressBase {};
struct watchdogBaseAddress : HwAddressBase {};
struct rtcBaseAddress : HwAddressBase {};
struct roscBaseAddress : HwAddressBase {};
struct vregChipResetBaseAddress : HwAddressBase {};
struct tbmanBaseAddress : HwAddressBase {};
struct usbCtrlDPramBaseAddress : HwAddressBase {};
struct usbCtrlRegsBaseAddress : HwAddressBase {};
struct pioBaseAddress : HwAddressBase {};
struct sioBaseAddress : HwAddressBase {};
struct ppbBaseAddress : HwAddressBase {};

}  // namespace libmcu

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