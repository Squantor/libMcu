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
namespace libMcu {

using hwAddressBase = libMcu::constant<std::uint32_t>; /*!< base type definition of a memory address */
using hwAddressType = typename hwAddressBase::type;    /*!< type definition of a memory address */

struct memoryAddress : hwAddressBase {}; /*!< generic memory address */

/* Peripheral address types used by CortexM microcontrollers */
struct scsBaseAddress : hwAddressBase {};     /*!< SCS */
struct systickBaseAddress : hwAddressBase {}; /*!< SYSTICK */
struct nvicBaseAddress : hwAddressBase {};    /*!< NVIC */
struct scbBaseAddress : hwAddressBase {};     /*!< SCB */
struct mpuBaseAddress : hwAddressBase {};     /*!< MPU */
struct mtbBaseAddress : hwAddressBase {};     /*!< MTB */

/* Peripheral address types used by all microcontrollers */
struct i2cBaseAddress : hwAddressBase {};    /*!< I2C */
struct spiBaseAddress : hwAddressBase {};    /*!< SPI */
struct uartBaseAddress : hwAddressBase {};   /*!< UART */
struct crcBaseAddress : hwAddressBase {};    /*!< CRC engine */
struct gpioBaseAddress : hwAddressBase {};   /*!< GPIO */
struct dmaBaseAddress : hwAddressBase {};    /*!< DMA */
struct dacBaseAddress : hwAddressBase {};    /*!< DAC */
struct adcBaseAddress : hwAddressBase {};    /*!< ADC */
struct syscfgBaseAddress : hwAddressBase {}; /*!< SYSCFG */

/* Peripheral address types used by NXP LPC microcontrollers */
struct wwdtBaseAddress : hwAddressBase {};   /*!< NXP LPC Windowed watchdog */
struct mrtBaseAddress : hwAddressBase {};    /*!< NXP LPC Multi rate timer*/
struct wktBaseAddress : hwAddressBase {};    /*!< NXP LPC Wakeup timer */
struct swmBaseAddress : hwAddressBase {};    /*!< NXP LPC Switch Matrix */
struct pmuBaseAddress : hwAddressBase {};    /*!< NXP LPC Power management unit */
struct acmpBaseAddress : hwAddressBase {};   /*!< NXP LPC Analog comparator */
struct fmcBaseAddress : hwAddressBase {};    /*!< NXP LPC Flash controller */
struct ioconBaseAddress : hwAddressBase {};  /*!< NXP LPC IO control */
struct sysconBaseAddress : hwAddressBase {}; /*!< NXP LPC System control*/
struct sctBaseAddress : hwAddressBase {};    /*!< NXP LPC state configurable timer */
struct pinintBaseAddress : hwAddressBase {}; /*!< NXP LPC Pin interrupt */
struct faimBaseAddress : hwAddressBase {};   /*!< NXP LPC fast memory initialization */
struct inmuxBaseAddress : hwAddressBase {};  /*!< NXP LPC input multiplexer  */
struct ctimerBaseAddress : hwAddressBase {}; /*!< NXP LPC standard counter/timer */
struct captBaseAddress : hwAddressBase {};   /*!< NXP LPC capacitive touch */

/* Peripheral address types used by STM32 microcontrollers */
struct stmBaseAddress : hwAddressBase {}; /*!< STM generic peripheral */

/* Peripheral address types used by Raspberry Pi microcontrollers */
struct xipCtrlBaseAddress : hwAddressBase {};
struct xipSsiBaseAddress : hwAddressBase {};
struct sysinfoBaseAddress : hwAddressBase {};
struct clocksBaseAddress : hwAddressBase {};
struct resetsBaseAddress : hwAddressBase {};
struct psmBaseAddress : hwAddressBase {};
struct ioBank0BaseAddress : hwAddressBase {};
struct ioQspiBaseAddress : hwAddressBase {};
struct padsBank0BaseAddress : hwAddressBase {};
struct padsQspiBaseAddress : hwAddressBase {};
struct xoscBaseAddress : hwAddressBase {};
struct pllBaseAddress : hwAddressBase {};
struct busCtrlBaseAddress : hwAddressBase {};
struct pwmBaseAddress : hwAddressBase {};
struct timerBaseAddress : hwAddressBase {};
struct watchdogBaseAddress : hwAddressBase {};
struct rtcBaseAddress : hwAddressBase {};
struct roscBaseAddress : hwAddressBase {};
struct vregChipResetBaseAddress : hwAddressBase {};
struct tbmanBaseAddress : hwAddressBase {};
struct usbCtrlDPramBaseAddress : hwAddressBase {};
struct usbCtrlRegsBaseAddress : hwAddressBase {};
struct pioBaseAddress : hwAddressBase {};
struct sioBaseAddress : hwAddressBase {};
struct ppbBaseAddress : hwAddressBase {};

}  // namespace libMcu

namespace libmcuhw {
using HwAddressBase = libMcu::constant<std::uint32_t>; /*!< base type definition of a memory address */
using HwAddressType = typename HwAddressBase::type;    /*!< type definition of a memory address */

struct MemoryAddress : HwAddressBase {}; /*!< generic memory address */

/* Peripheral address types used by all microcontrollers */
struct I2cBaseAddress : HwAddressBase {};  /*!< I2C */
struct SpiBaseAddress : HwAddressBase {};  /*!< SPI */
struct UartBaseAddress : HwAddressBase {}; /*!< UART */
struct GpioBaseAddress : HwAddressBase {}; /*!< GPIO */

}  // namespace libmcuhw

#endif