/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file scb functions
 */
#ifndef SCB_SW_HPP
#define SCB_SW_HPP
namespace libMcuLL::sw::scb {
using namespace hw::scb;
template <libMcuLL::scbBaseAddress const& scbAddress_>
struct scb {
  /**
   * @brief Construct a new systick object
   *
   */
  scb() {}

  /**
   * @brief get registers from SCB peripheral
   *
   * @return return pointer to scb peripheral
   */
  static hw::scb::peripheral* scbPeripheral() {
    return reinterpret_cast<hw::scb::peripheral*>(scbAddress);
  }

  /**
   * @brief Setup scb
   *
   * Nothing to setup here
   */
  constexpr void init() {}

  /**
   * @brief Get the allowed bits mask from the VTOR register
   *
   * @return enabled bits in the VTOR register
   */
  constexpr std::uint32_t getVtorMask() {
    uint32_t backupRegister = scbPeripheral()->VTOR;
    scbPeripheral()->VTOR = 0xFFFFFFFFUL;
    uint32_t vtorMask = scbPeripheral()->VTOR;
    scbPeripheral()->VTOR = backupRegister;
    return vtorMask;
  }

  /**
   * @brief set vector table to specific address
   *
   * Be aware that 7 LSB's are ignored so it needs to be aligned on a 128byte boundary
   *
   * @param vectorTable address to an array of uint32_t's that contains the interrupt vector table
   */
  constexpr void setVtor(std::uint32_t* vectorTable) {
    static_assert(hw::vtor::present == true);
    std::uint32_t vtorAddress = reinterpret_cast<std::uint32_t>(vectorTable);
    scbPeripheral()->VTOR = VTOR::TBLOFF(vtorAddress);
  }

  /**
   * @brief Set the system sleep behaviour in various conditions
   *
   * @param eventIsWakeup Do not sleep after a WFE (relevant for multiprocessors)
   * @param sleepIsDeep Sleep mode is deep sleep (deep sleep is implementation defined)
   * @param sleepOnIsrExit Sleep after ISR exit
   */
  constexpr void setSleepBehaviour(bool eventIsWakeup, bool sleepIsDeep, bool sleepOnIsrExit) {
    std::uint32_t newScr = 0UL;
    if (eventIsWakeup)
      newScr |= SCR::SEVONPEND;
    if (sleepIsDeep)
      newScr |= SCR::SLEEPDEEP;
    if (sleepOnIsrExit)
      newScr |= SCR::SLEEPONEXIT;
    scbPeripheral()->SCR = newScr;
  }

  /**
   * @brief Resets the system
   *
   */
  [[noreturn]] constexpr void reset() {
    libMcu::sw::dsb();
    scbPeripheral()->AIRCR = AIRCR::VECTKEY_KEY | AIRCR::SYSRESETREQ;
    libMcu::sw::dsb();
    while (1) {
      libMcu::sw::nop();
    }
  }

  static constexpr libMcuLL::hwAddressType scbAddress = scbAddress_; /**< scb peripheral address */
};
}  // namespace libMcuLL::sw::scb
#endif