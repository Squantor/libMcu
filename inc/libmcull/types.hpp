/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file types used by libMcuLL
 */
#ifndef TYPES_HPP
#define TYPES_HPP

namespace libMcuLL {

/**
 * @brief defines a constant for typesafety
 *
 * @tparam C_ type of constant
 */
template <typename C_>
struct constant {
  using type = C_;

  constexpr operator C_() const {
    return value;
  }

  C_ value;
};

/**
 * @brief Peripheral base class that all peripherals should inherit from
 *
 * You will never copy/move a peripheral, they are "eternal" with respect to program lifetime
 *
 */
struct peripheralBase {
  peripheralBase() = default;
  ~peripheralBase() = default;
  peripheralBase(const peripheralBase&) = delete;
  peripheralBase& operator=(const peripheralBase&) = delete;
  peripheralBase(peripheralBase&&) = delete;
  peripheralBase& operator=(peripheralBase&&) = delete;
};

using hwAddressBase = constant<std::uint32_t>;      /**< base type definition of a memory address */
using hwAddressType = typename hwAddressBase::type; /**< type definition of a memory address */

struct memoryAddress : hwAddressBase {}; /**< generic memory address */

/* Peripheral address types used by CortexM microcontrollers */
struct scsBaseAddress : hwAddressBase {};     /**< SCS */
struct systickBaseAddress : hwAddressBase {}; /**< SYSTICK */
struct nvicBaseAddress : hwAddressBase {};    /**< NVIC */
struct scbBaseAddress : hwAddressBase {};     /**< SCB */
struct mpuBaseAddress : hwAddressBase {};     /**< MPU */
struct mtbBaseAddress : hwAddressBase {};     /**< MTB */

/* Peripheral address types used by all microcontrollers */
struct i2cBaseAddress : hwAddressBase {};  /**< I2C */
struct spiBaseAddress : hwAddressBase {};  /**< SPI */
struct uartBaseAddress : hwAddressBase {}; /**< UART */
struct crcBaseAddress : hwAddressBase {};  /**< CRC engine */
struct gpioBaseAddress : hwAddressBase {}; /**< GPIO */
struct dmaBaseAddress : hwAddressBase {};  /**< DMA */
struct dacBaseAddress : hwAddressBase {};  /**< DAC */
struct adcBaseAddress : hwAddressBase {};  /**< ADC */

/* Peripheral address types used by NXP LPC microcontrollers */
struct wwdtBaseAddress : hwAddressBase {};     /**< NXP LPC Windowed watchdog */
struct mrtBaseAddress : hwAddressBase {};      /**< NXP LPC Multi rate timer*/
struct wktBaseAddress : hwAddressBase {};      /**< NXP LPC Wakeup timer */
struct swmBaseAddress : hwAddressBase {};      /**< NXP LPC Switch Matrix */
struct pmuBaseAddress : hwAddressBase {};      /**< NXP LPC Power management unit */
struct acmpBaseAddress : hwAddressBase {};     /**< NXP LPC Analog comparator */
struct fmcBaseAddress : hwAddressBase {};      /**< NXP LPC Flash controller */
struct ioconBaseAddress : hwAddressBase {};    /**< NXP LPC IO control */
struct sysconBaseAddress : hwAddressBase {};   /**< NXP LPC System control*/
struct sctBaseAddress : hwAddressBase {};      /**< NXP LPC state configurable timer */
struct pinintBaseAddress : hwAddressBase {};   /**< NXP LPC Pin interrupt */
struct faimBaseAddress : hwAddressBase {};     /**< NXP LPC fast memory initialization */
struct inputMuxBaseAddress : hwAddressBase {}; /**< NXP LPC input multiplexer  */
struct ctimerBaseAddress : hwAddressBase {};   /**< NXP LPC standard counter/timer */
struct captBaseAddress : hwAddressBase {};     /**< NXP LPC capacitive touch */

/* Peripheral address types used by STM32 microcontrollers */

/* Peripheral address types used by Raspberry Pi microcontrollers */
struct xipCtrlBaseAddress : hwAddressBase {};
struct xipSsiBaseAddress : hwAddressBase {};
struct sysinfoBaseAddress : hwAddressBase {};
struct syscfgBaseAddress : hwAddressBase {};
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

/* I2C general definitions */
using i2cDeviceAddressBase = constant<std::uint8_t>;
using i2cDeviceAddressType = typename i2cDeviceAddressBase::type;

struct i2cDeviceAddress : i2cDeviceAddressBase {}; /**< General purpose I2C address type */

using isrLambda = std::add_pointer<void()>::type;

}  // namespace libMcuLL
namespace libMcuHal {
/**
 * @brief Hal base class that all Hal classes should inherit from
 *
 * You will never copy/move a hal object, they are "eternal" with respect to program lifetime
 *
 */
struct halBase {
  halBase() = default;
  ~halBase() = default;
  halBase(const halBase&) = delete;
  halBase& operator=(const halBase&) = delete;
  halBase(halBase&&) = delete;
  halBase& operator=(halBase&&) = delete;
};
/* Hal base classes */
struct halGpioBase : halBase {};
}  // namespace libMcuHal

#endif