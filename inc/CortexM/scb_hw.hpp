/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file SCB register interface
 */
#ifndef SCB_HW_HPP
#define SCB_HW_HPP
namespace libMcuLL {
namespace hw {
namespace scb {
struct peripheral {
  const volatile std::uint32_t CPUID; /**< CPUID Base Register */
  volatile std::uint32_t ICSR;        /**< Interrupt Control and State Register */
  volatile std::uint32_t VTOR;        /**< Vector Table Offset Register */
  volatile std::uint32_t AIRCR;       /**< Application Interrupt and Reset Control Register */
  volatile std::uint32_t SCR;         /**< System Control Register */
  volatile std::uint32_t CCR;         /**< Configuration Control Register */
  std::uint32_t RESERVED1;
  volatile std::uint32_t SHP[2U]; /**< System Handlers Priority Registers. [0] is RESERVED */
  volatile std::uint32_t SHCSR;   /**< System Handler Control and State Register */
};
namespace CPUID {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFUL;      /**< register mask for allowed bits */
constexpr inline std::uint32_t REVISION_MASK = (0xF) << 0;        /**< revision, implementation defined */
constexpr inline std::uint32_t PARTNO_MASK = (0xFFFUL) << 4;      /**< part number, implementation defined */
constexpr inline std::uint32_t ARCHITECTURE_MASK = (0xFUL) << 16; /**< architecture field, 0xC for ARMv6-M */
constexpr inline std::uint32_t VARIANT_MASK = (0xFUL) << 20;      /**< Variant field, implementation defined */
constexpr inline std::uint32_t IMPLEMENTER_MASK = (0xFFUL) << 24; /**< implementer field, 0x41('A') for ARM */
}  // namespace CPUID
namespace ICSR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFF1FF;        /**< register mask for allowed bits */
constexpr inline std::uint32_t VECTACTIVE_MASK = (0xFFUL) << 0;   /**< exception number currently executing */
constexpr inline std::uint32_t VECTPENDING_MASK = (0xFFUL) << 12; /**< highest priority pending exception */
constexpr inline std::uint32_t ISRPENDING_MASK = (0x1UL) << 22;   /**< NVIC interrupt is pending */
constexpr inline std::uint32_t ISRPREEMPT_MASK = (0x1UL) << 23;   /**< will service a pending exception */
constexpr inline std::uint32_t PENDSTCLR = (0x1UL) << 25;         /**< Clear pending systick */
constexpr inline std::uint32_t PENDSTSET = (0x1UL) << 26;         /**< Set pending systick */
constexpr inline std::uint32_t PENDSVCLR = (0x1UL) << 27;         /**< Clear pending PendSV */
constexpr inline std::uint32_t PENDSVSET = (0x1UL) << 28;         /**< Set pending PendSV interrupt */
constexpr inline std::uint32_t NMIPENDSET = (0x1UL) << 31;        /**< Activate NMI exception */
}  // namespace ICSR
namespace VTOR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFF80UL; /**< register mask for allowed bits */
constexpr inline std::uint32_t TBLOFF(std::uint32_t address) {
  return address & libMcuLL::hw::vtor::addressMask;
}
}  // namespace VTOR
namespace AIRCR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF8006UL;    /**< register mask for allowed bits */
constexpr inline std::uint32_t VECTCLRACTIVE = (0x1UL) << 1;    /**< clear state information */
constexpr inline std::uint32_t SYSRESETREQ = (0x1UL) << 2;      /**< request system reset */
constexpr inline std::uint32_t ENDIANNESS_MASK = (0x1UL) << 15; /**< system endianness, 0 little, 1 big */
constexpr inline std::uint32_t VECTKEY_MASK = (0xFFFFUL) << 16; /**< Vector key, 0x05FA must be written */
constexpr inline std::uint32_t VECTKEY_KEY = 0x05FA0000UL;      /**< Vector key, key value */

}  // namespace AIRCR
namespace SCR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000016UL; /**< register mask for allowed bits */
constexpr inline std::uint32_t SLEEPONEXIT = (0x1UL) << 1;   /**< enter sleep state after ISR exit */
constexpr inline std::uint32_t SLEEPDEEP = (0x1UL) << 2;     /**< sleep enters deep sleep */
constexpr inline std::uint32_t SEVONPEND = (0x1UL) << 4;     /**< transitions from inactive are wakeup events */
}  // namespace SCR
namespace CCR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000208; /**< register mask for allowed bits */
constexpr inline std::uint32_t UNALIGN_TRP = (0x1) << 3;   /**< unaligned accesses generate a hardfault */
constexpr inline std::uint32_t STKALIGN = (0x1) << 9;      /**< align stack on exception exit */
}  // namespace CCR
namespace SHP {
constexpr inline std::uint32_t RESERVED_MASK = 0xC0C0C0C0; /**< register mask for allowed bits */
}
namespace SHCSR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00008000;        /**< register mask for allowed bits */
constexpr inline std::uint32_t SVCALLPENDED_MASK = (0x1UL) << 15; /**< SVCALL is pending */
}  // namespace SHCSR
}  // namespace scb
}  // namespace hw
}  // namespace libMcuLL
#endif
