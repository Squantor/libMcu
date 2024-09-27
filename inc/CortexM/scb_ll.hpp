/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file scb functions
 */
#ifndef SCB_LL_HPP
#define SCB_LL_HPP
namespace libMcuLL::scb {
namespace hardware = libMcuHw::scb;
template <libMcu::scbBaseAddress const& scbAddress_>
struct scb {
  /**
   * @brief Construct a new systick object
   *
   */
  scb() {}
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
    static_assert(libMcuHw::vtor::present == true);
    std::uint32_t vtorAddress = reinterpret_cast<std::uint32_t>(vectorTable);
    scbPeripheral()->VTOR = hardware::VTOR::TBLOFF(vtorAddress);
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
      newScr |= hardware::SCR::SEVONPEND;
    if (sleepIsDeep)
      newScr |= hardware::SCR::SLEEPDEEP;
    if (sleepOnIsrExit)
      newScr |= hardware::SCR::SLEEPONEXIT;
    scbPeripheral()->SCR = newScr;
  }
  /**
   * @brief Resets the system
   *
   */
  [[noreturn]] constexpr void reset() {
    libMcuLL::dsb();
    scbPeripheral()->AIRCR = hardware::AIRCR::VECTKEY_KEY | hardware::AIRCR::SYSRESETREQ;
    libMcuLL::dsb();
    while (1) {
      libMcuLL::nop();
    }
  }
  /**
   * @brief get registers from SCB peripheral
   *
   * @return return pointer to scb peripheral
   */
  static hardware::scb* scbPeripheral() {
    return reinterpret_cast<hardware::scb*>(scbAddress);
  }

  static constexpr libMcu::hwAddressType scbAddress = scbAddress_; /**< scb peripheral address */
};
}  // namespace libMcuLL::scb
#endif