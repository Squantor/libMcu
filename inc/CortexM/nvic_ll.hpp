/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file nvic_ll.hpp
 * @brief NVIC interface class and definitions
 */
#ifndef NVIC_LL_HPP
#define NVIC_LL_HPP
namespace libmcull::nvic {
namespace hardware = libmcuhw::nvic;
namespace hardwareScb = libmcuhw::scb;
template <libmcu::NvicBaseAddress const& nvicAddress_, libmcu::ScbBaseAddress const& scbAddress_>
struct Nvic {
  /**
   * @brief Construct a new systick object
   */
  Nvic() {}

  /**
   * @brief Setup nvic
   * Nothing to setup here
   */
  constexpr void init() {}

  /**
   * @brief enable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void enable(libmcuhw::Interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      GetPeripheral()->ISER[index] = hardware::ISER::SETENA(bitIndex);
    }
  }

  /**
   * @brief disable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void disable(libmcuhw::Interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      GetPeripheral()->ICER[index] = hardware::ICER::CLRENA(bitIndex);
      libmcull::dsb();
      libmcull::isb();
    }
  }
  /**
   * @brief Set interrupt pending status
   *
   * @param interrupt interrupt number
   */
  constexpr void setPending(libmcuhw::Interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      GetPeripheral()->ISPR[index] = hardware::ISPR::SETPEND(bitIndex);
    }
  }

  /**
   * @brief Clear interrupt pending status
   *
   * @param interrupt interrupt number
   */
  constexpr void clearPending(libmcuhw::Interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      GetPeripheral()->ICPR[index] = hardware::ICPR::CLRPEND(bitIndex);
    }
  }

  /**
   * @brief Get interrupt pending status
   *
   * @param interrupt interrupt number
   * @return true interrupt pending
   * @return false interrupt not pending
   */
  constexpr bool getPending(libmcuhw::Interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptIndex(interrupt);
      std::uint32_t bitIndex = getInterruptBit(interrupt);
      if (hardware::ISPR::GETPEND(GetPeripheral()->ISPR[index], bitIndex) == 0)
        return false;
      else
        return true;
    }
    return false;
  }

  constexpr void setPriority(libmcuhw::Interrupts interrupt, std::uint32_t priority) {
    std::int32_t number = static_cast<std::int32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = getInterruptPrioIndex(number);
      GetPeripheral()->IP[index] = hardware::IP::IPR(GetPeripheral()->IP[index], static_cast<std::uint32_t>(number), priority);
    } else {
      number = number + 8;  // translate negative isrs to SCB priority field index with offset for first 8 ISR's
      std::uint32_t index = getInterruptPrioIndex(number);
      GetScbPeripheral()->SHP[index] =
        hardware::IP::IPR(GetScbPeripheral()->SHP[index], static_cast<std::uint32_t>(number), priority);
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
  constexpr uint32_t getInterruptIndex(libmcuhw::Interrupts interrupt) {
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
  constexpr uint32_t getInterruptBit(libmcuhw::Interrupts interrupt) {
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

  /**
   * @brief get registers from peripheral
   * @return return pointer to nvic peripheral
   */
  static hardware::nvic* GetPeripheral() {
    return reinterpret_cast<hardware::nvic*>(nvic_address_);
  }
  /**
   * @brief get registers from SCB peripheral
   * @return return pointer to scb peripheral
   */
  static hardwareScb::Scb* GetScbPeripheral() {
    return reinterpret_cast<hardwareScb::Scb*>(scb_address_);
  }

  static constexpr libmcu::HwAddressType nvic_address_ = nvicAddress_; /*!< nvic peripheral address */
  static constexpr libmcu::HwAddressType scb_address_ = scbAddress_;   /*!< scb peripheral address */
};
}  // namespace libmcull::nvic
#endif