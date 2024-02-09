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
template <libMcuLL::nvicBaseAddress const& address_>
struct nvic {
  /**
   * @brief Construct a new systick object
   *
   */
  nvic() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static hw::nvic::peripheral* peripheral() {
    return reinterpret_cast<hw::nvic::peripheral*>(address);
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
      peripheral()->ISER[index] = ISER::SETENA(bitIndex);
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
      peripheral()->ICER[index] = ICER::CLRENA(bitIndex);
      libMcuLL::sw::dsb();
      libMcuLL::sw::isb();
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
      peripheral()->ISPR[index] = ISPR::SETPEND(bitIndex);
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
      peripheral()->ICPR[index] = ICPR::CLRPEND(bitIndex);
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
      if (ISPR::GETPEND(peripheral()->ISPR[index], bitIndex) == 0)
        return false;
      else
        return true;
    }
    return false;
  }

  constexpr void setPriority(libMcuLL::hw::interrupts interrupt, std::uint32_t priority) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      // NVIC->IP[_IP_IDX(IRQn)] = ((uint32_t)(NVIC->IP[_IP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
      //                          (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
      std::uint32_t index = getInterruptPrioIndex(interrupt);
      peripheral()->IP[index] = IP::IPR(peripheral()->IP[index], static_cast<std::uint32_t>(interrupt), priority);
    } else {
      // TODO for other interrupts
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
  constexpr uint32_t getInterruptPrioIndex(libMcuLL::hw::interrupts interrupt) {
    return static_cast<std::uint32_t>(interrupt) >> 2;
  }

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace nvic
}  // namespace sw
}  // namespace libMcuLL

#endif