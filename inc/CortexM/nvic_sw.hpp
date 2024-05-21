/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file nvic functions
 */
#ifndef NVIC_SW_HPP
#define NVIC_SW_HPP
namespace libMcuLL {
namespace sw {
namespace nvic {
using namespace hw::nvic;
using namespace hw::scb;
template <libMcuLL::nvicBaseAddress const& nvicAddress_, libMcuLL::scbBaseAddress const& scbAddress_>
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
  static hw::nvic::peripheral* nvicPeripheral() {
    return reinterpret_cast<hw::nvic::peripheral*>(nvicAddress);
  }

  /**
   * @brief get registers from SCB peripheral
   *
   * @return return pointer to scb peripheral
   */
  static hw::scb::peripheral* scbPeripheral() {
    return reinterpret_cast<hw::scb::peripheral*>(scbAddress);
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
  constexpr void enable(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ISER[index] = ISER::SETENA(bitIndex);
    }
  }

  /**
   * @brief disable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void disable(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ICER[index] = ICER::CLRENA(bitIndex);
      libMcu::sw::dsb();
      libMcu::sw::isb();
    }
  }
  /**
   * @brief Set interrupt pending status
   *
   * @param interrupt interrupt number
   */
  constexpr void setPending(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ISPR[index] = ISPR::SETPEND(bitIndex);
    }
  }

  /**
   * @brief Clear interrupt pending status
   *
   * @param interrupt interrupt number
   */
  constexpr void clearPending(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      nvicPeripheral()->ICPR[index] = ICPR::CLRPEND(bitIndex);
    }
  }

  /**
   * @brief Get interrupt pending status
   *
   * @param interrupt interrupt number
   * @return true interrupt pending
   * @return false interrupt not pending
   */
  constexpr bool getPending(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      if (ISPR::GETPEND(nvicPeripheral()->ISPR[index], bitIndex) == 0)
        return false;
      else
        return true;
    }
    return false;
  }

  constexpr void setPriority(libMcuLL::hw::interrupts interrupt, std::uint32_t priority) {
    std::int32_t number = static_cast<std::int32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptPrioIndex(number);
      nvicPeripheral()->IP[index] = IP::IPR(nvicPeripheral()->IP[index], static_cast<std::uint32_t>(number), priority);
    } else {
      number = number + 8;  // translate negative isrs to SCB priority field index with offset for first 8 ISR's
      std::uint32_t index = getInterruptPrioIndex(number);
      scbPeripheral()->SHP[index] = IP::IPR(scbPeripheral()->SHP[index], static_cast<std::uint32_t>(number), priority);
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
  constexpr uint32_t getInterruptIndex(libMcuLL::hw::interrupts interrupt) {
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
  constexpr uint32_t getInterruptBit(libMcuLL::hw::interrupts interrupt) {
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

  static constexpr libMcuLL::hwAddressType nvicAddress = nvicAddress_; /**< nvic peripheral address */
  static constexpr libMcuLL::hwAddressType scbAddress = scbAddress_;   /**< scb peripheral address */
};
}  // namespace nvic
}  // namespace sw
}  // namespace libMcuLL

#endif