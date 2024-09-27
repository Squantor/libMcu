/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file nvic functions
 */
#ifndef NVIC_LL_HPP
#define NVIC_LL_HPP
namespace libMcuLL::nvic {
namespace hardware = libMcuHw::nvic;
namespace hardwareScb = libMcuHw::scb;
template <libMcu::nvicBaseAddress const& nvicAddress_, libMcu::scbBaseAddress const& scbAddress_>
struct nvic {
  /**
   * @brief Construct a new systick object
   *
   */
  nvic() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to nvic peripheral
   */
  static hardware::nvic* nvicPeripheral() {
    return reinterpret_cast<hardware::nvic*>(nvicAddress);
  }

  /**
   * @brief get registers from SCB peripheral
   *
   * @return return pointer to scb peripheral
   */
  static hardwareScb::scb* scbPeripheral() {
    return reinterpret_cast<hardwareScb::scb*>(scbAddress);
  }

  /**
   * @brief Setup nvic
   *
   * Nothing to setup here
   */
  constexpr void init() {}

  /**
   * @brief enable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void enable(libMcuHw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ISER[index] = hardware::ISER::SETENA(bitIndex);
    }
  }

  /**
   * @brief disable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void disable(libMcuHw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ICER[index] = hardware::ICER::CLRENA(bitIndex);
      libMcuLL::dsb();
      libMcuLL::isb();
    }
  }
  /**
   * @brief Set interrupt pending status
   *
   * @param interrupt interrupt number
   */
  constexpr void setPending(libMcuHw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ISPR[index] = hardware::ISPR::SETPEND(bitIndex);
    }
  }

  /**
   * @brief Clear interrupt pending status
   *
   * @param interrupt interrupt number
   */
  constexpr void clearPending(libMcuHw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ICPR[index] = hardware::ICPR::CLRPEND(bitIndex);
    }
  }

  /**
   * @brief Get interrupt pending status
   *
   * @param interrupt interrupt number
   * @return true interrupt pending
   * @return false interrupt not pending
   */
  constexpr bool getPending(libMcuHw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      if (hardware::ISPR::GETPEND(nvicPeripheral()->ISPR[index], bitIndex) == 0)
        return false;
      else
        return true;
    }
    return false;
  }

  constexpr void setPriority(libMcuHw::interrupts interrupt, std::uint32_t priority) {
    std::int32_t number = static_cast<std::int32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptPrioIndex(number);
      nvicPeripheral()->IP[index] = hardware::IP::IPR(nvicPeripheral()->IP[index], static_cast<std::uint32_t>(number), priority);
    } else {
      number = number + 8;  // translate negative isrs to SCB priority field index with offset for first 8 ISR's
      std::uint32_t index = getInterruptPrioIndex(number);
      scbPeripheral()->SHP[index] = hardware::IP::IPR(scbPeripheral()->SHP[index], static_cast<std::uint32_t>(number), priority);
    }
  }

  /**
   * @brief Extract the interrupt index register from interrupt value
   *
   * be sure that the interrupt value is positive!
   *
   * @param interrupt interrupt number, MUST BE POSITIVE
   * @return interrupt register index
   */
  constexpr uint32_t getInterruptIndex(libMcuHw::interrupts interrupt) {
    return static_cast<std::uint32_t>(interrupt) >> 5;
  }

  /**
   * @brief Extract the interrupt bit from interrupt value
   *
   * be sure that the interrupt value is positive!
   *
   * @param interrupt interrupt number, MUST BE POSITIVE
   * @return interrupt register bit
   */
  constexpr uint32_t getInterruptBit(libMcuHw::interrupts interrupt) {
    return static_cast<std::uint32_t>(interrupt) & 0x1F;
  }

  /**
   * @brief Extract the interrupt priority index register from interrupt value
   *
   * be sure that the interrupt value is positive!
   *
   * @param interrupt interrupt number, MUST BE POSITIVE
   * @return interrupt priority register index
   */
  constexpr uint32_t getInterruptPrioIndex(std::int32_t interrupt) {
    return static_cast<std::uint32_t>(interrupt) >> 2;
  }

  static constexpr libMcu::hwAddressType nvicAddress = nvicAddress_; /**< nvic peripheral address */
  static constexpr libMcu::hwAddressType scbAddress = scbAddress_;   /**< scb peripheral address */
};
}  // namespace libMcuLL::nvic
#endif