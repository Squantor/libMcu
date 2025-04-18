/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file cm0p_scb_hw.hpp
 * \brief Register structure and bit definitions for the Cortex M0+ System Control Block
 */
#ifndef CM0P_SCB_HW_HPP
#define CM0P_SCB_HW_HPP

namespace libmcuhw::scb {
/**
 * @brief Register interface for the System Control Block
 */
struct Scb {
  const volatile std::uint32_t CPUID; /*!< CPUID Base Register */
  volatile std::uint32_t ICSR;        /*!< Interrupt Control and State Register */
  volatile std::uint32_t VTOR;        /*!< Vector Table Offset Register */
  volatile std::uint32_t AIRCR;       /*!< Application Interrupt and Reset Control Register */
  volatile std::uint32_t SCR;         /*!< System Control Register */
  volatile std::uint32_t CCR;         /*!< Configuration Control Register */
  std::uint32_t RESERVED1;
  volatile std::uint32_t SHP[2U]; /*!< System Handlers Priority Registers. [0] is RESERVED */
  volatile std::uint32_t SHCSR;   /*!< System Handler Control and State Register */
};
namespace CPUID {
constexpr inline std::uint32_t kkRESERVED_MASK{0xFFFFFFFFu};   /*!< register mask for allowed bits */
constexpr inline std::uint32_t kREVISION_MASK{0xFu << 0};      /*!< revision, implementation defined */
constexpr inline std::uint32_t kPARTNO_MASK{0xFFFu << 4};      /*!< part number, implementation defined */
constexpr inline std::uint32_t kARCHITECTURE_MASK{0xFu << 16}; /*!< architecture field, 0xC for ARMv6-M */
constexpr inline std::uint32_t kVARIANT_MASK{0xFu << 20};      /*!< Variant field, implementation defined */
constexpr inline std::uint32_t kIMPLEMENTER_MASK{0xFFu << 24}; /*!< implementer field, 0x41('A') for ARM */
}  // namespace CPUID
namespace ICSR {
constexpr inline std::uint32_t kkRESERVED_MASK{0xFFFFF1FFu};   /*!< register mask for allowed bits */
constexpr inline std::uint32_t kVECTACTIVE_MASK{0xFFu << 0};   /*!< exception number currently executing */
constexpr inline std::uint32_t kVECTPENDING_MASK{0xFFu << 12}; /*!< highest priority pending exception */
constexpr inline std::uint32_t kISRPENDING_MASK{0x1u << 22};   /*!< NVIC interrupt is pending */
constexpr inline std::uint32_t kISRPREEMPT_MASK{0x1u << 23};   /*!< will service a pending exception */
constexpr inline std::uint32_t kPENDSTCLR{0x1u << 25};         /*!< Clear pending systick */
constexpr inline std::uint32_t kPENDSTSET{0x1u << 26};         /*!< Set pending systick */
constexpr inline std::uint32_t kPENDSVCLR{0x1u << 27};         /*!< Clear pending PendSV */
constexpr inline std::uint32_t kPENDSVSET{0x1u << 28};         /*!< Set pending PendSV interrupt */
constexpr inline std::uint32_t kNMIPENDSET{0x1u << 31};        /*!< Activate NMI exception */
}  // namespace ICSR
namespace VTOR {
constexpr inline std::uint32_t kkRESERVED_MASK{0xFFFFFF80u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t TBLOFF(std::uint32_t address) {
  return address & libmcuhw::vtor::kAddressMask;
}
}  // namespace VTOR
namespace AIRCR {
constexpr inline std::uint32_t kkRESERVED_MASK{0xFFFF8006u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kVECTCLRACTIVE{0x1u << 1};    /*!< clear state information */
constexpr inline std::uint32_t kSYSRESETREQ{0x1u << 2};      /*!< request system reset */
constexpr inline std::uint32_t kENDIANNESS_MASK{0x1u << 15}; /*!< system endianness, 0 little, 1 big */
constexpr inline std::uint32_t kVECTKEY_MASK{0xFFFFu << 16}; /*!< Vector key, 0x05FA must be written */
constexpr inline std::uint32_t kVECTKEY_KEY{0x05FA0000u};    /*!< Vector key, key value */

}  // namespace AIRCR
namespace SCR {
constexpr inline std::uint32_t kkRESERVED_MASK{0x00000016u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kSLEEPONEXIT{0x1u << 1};      /*!< enter sleep state after ISR exit */
constexpr inline std::uint32_t kSLEEPDEEP{0x1u << 2};        /*!< sleep enters deep sleep */
constexpr inline std::uint32_t kSEVONPEND{0x1u << 4};        /*!< transitions from inactive are wakeup events */
}  // namespace SCR
namespace CCR {
constexpr inline std::uint32_t kkRESERVED_MASK{0x00000208u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kUNALIGN_TRP{0x1u << 3};      /*!< unaligned accesses generate a hardfault */
constexpr inline std::uint32_t kSTKALIGN{0x1u << 9};         /*!< align stack on exception exit */
}  // namespace CCR
namespace SHP {
constexpr inline std::uint32_t kkRESERVED_MASK{0xC0C0C0C0u}; /*!< register mask for allowed bits */
}
namespace SHCSR {
constexpr inline std::uint32_t kkRESERVED_MASK{0x00008000u};   /*!< register mask for allowed bits */
constexpr inline std::uint32_t kSVCALLPENDED_MASK{0x1u << 15}; /*!< SVCALL is pending */
}  // namespace SHCSR
}  // namespace libmcuhw::scb
#endif
