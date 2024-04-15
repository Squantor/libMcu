/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Sysinfo register interface
 */
#ifndef RP2040_GPIO_BANK0_HW_HPP
#define RP2040_GPIO_BANK0_HW_HPP

namespace libMcuLL {
namespace hw {
namespace gpioBank0 {
/**
 * @brief GPIO  register definitions
 *
 */
struct peripheral {
  struct {
    const volatile std::uint32_t STATUS; /**< GPIO status */
    volatile std::uint32_t CTRL;         /**< GPIO control */
  } GPIO[30];
  volatile std::uint32_t INTR[4];              /**< Raw interrupts */
  volatile std::uint32_t PROC0_INTE[4];        /**< Interrupt Enable for proc0 */
  volatile std::uint32_t PROC0_INTF[4];        /**< Interrupt Force for proc0 */
  volatile const std::uint32_t PROC0_INTS[4];  /**< Interrupt status after masking & forcing for proc0 */
  volatile std::uint32_t PROC1_INTE[4];        /**< Interrupt Enable for proc1 */
  volatile std::uint32_t PROC1_INTF[4];        /**< Interrupt Force for proc1 */
  volatile const std::uint32_t PROC1_INTS[4];  /**< Interrupt status after masking & forcing for proc1 */
  volatile std::uint32_t DORMANT_WAKE_INTE[4]; /**< Interrupt Enable for dormant_wake */
  volatile std::uint32_t DORMANT_WAKE_INTF[4]; /**< Interrupt Force for dormant_wake */
  volatile std::uint32_t DORMANT_WAKE_INTS[4]; /**< Interrupt status after masking & forcing for dormant_wake */
};
namespace STATUS {
constexpr inline std::uint32_t RESERVED_MASK{0x050A'3300u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t IRQTOPROC_MASK{1u << 26};    /**< Interrupt to processors, after override */
constexpr inline std::uint32_t IRQFROMPAD_MASK{1u << 24};   /**< Interrupt to processors, before override */
constexpr inline std::uint32_t INTOPERI_MASK{1u << 19};     /**< Input signal to peripheral, after override */
constexpr inline std::uint32_t INFROMPAD_MASK{1u << 17};    /**< Input signal from pad, before override */
constexpr inline std::uint32_t OETOPAD_MASK{1u << 13};      /**< Output enable to pad after register override */
constexpr inline std::uint32_t OEFROMPERI_MASK{1u << 12};   /**< Output enable from selected peripheral, before override */
constexpr inline std::uint32_t OUTTOPAD_MASK{1u << 9};      /**< Output signal to pad after register override */
constexpr inline std::uint32_t OUTFROMPERI_MASK{1u << 8};   /**< Output signal from selected peripheral, before override */
}  // namespace STATUS
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t IRQOVER_NO_INV{0x0u};        /**< Dont invert the interrupt */
constexpr inline std::uint32_t IRQOVER_INV{0x1u};           /**< Invert the interrupt */
constexpr inline std::uint32_t IRQOVER_LOW{0x2u};           /**< Set interrupt low */
constexpr inline std::uint32_t IRQOVER_HIGH{0x3u};          /**< Set interrupt high */
/**
 * @brief Format IRQOVER field to CTRL register
 * @param setting IRQ override setting, look at IRQOVER_ settings
 * @return IRQOVER field formatted to CTRL register
 */
constexpr inline std::uint32_t IRQOVER(std::uint32_t setting) {
  return setting << 28;
}
constexpr inline std::uint32_t INOVER_NO_INV{0x0u}; /**< Dont invert the peripheral input */
constexpr inline std::uint32_t INOVER_INV{0x1u};    /**< Invert the peripheral input */
constexpr inline std::uint32_t INOVER_LOW{0x2u};    /**< Drive peripheral input low */
constexpr inline std::uint32_t INOVER_HIGH{0x3u};   /**< Drive peripheral input high */
/**
 * @brief Format INOVER field to CTRL register
 * @param setting peripheral input override setting, look at INOVER_ settings
 * @return INOVER field formatted to CTRL register
 */
constexpr inline std::uint32_t INOVER(std::uint32_t setting) {
  return setting << 16;
}
constexpr inline std::uint32_t OEOVER_NO_INV{0x0u}; /**< Dont invert the peripheral output enable */
constexpr inline std::uint32_t OEOVER_INV{0x1u};    /**< Invert the peripheral output enable */
constexpr inline std::uint32_t OEOVER_LOW{0x2u};    /**< Disable output */
constexpr inline std::uint32_t OEOVER_HIGH{0x3u};   /**< Enable output */
/**
 * @brief Format OEOVER field to CTRL register
 * @param setting peripheral output override setting, look at OEOVER_ settings
 * @return OEOVER field formatted to CTRL register
 */
constexpr inline std::uint32_t OEOVER(std::uint32_t setting) {
  return setting << 12;
}
constexpr inline std::uint32_t OUTOVER_NO_INV{0x0u}; /**< Dont invert the peripheral output */
constexpr inline std::uint32_t OUTOVER_INV{0x1u};    /**< Invert the peripheral output */
constexpr inline std::uint32_t OUTOVER_LOW{0x2u};    /**< Drive output low */
constexpr inline std::uint32_t OUTOVER_HIGH{0x3u};   /**< Drive output high */
/**
 * @brief Format OUTOVER field to CTRL register
 * @param setting peripheral output override setting, look at OUTOVER_ settings
 * @return OUTOVER field formatted to CTRL register
 */
constexpr inline std::uint32_t OUTOVER(std::uint32_t setting) {
  return setting << 8;
}
constexpr inline std::uint32_t F1{1u};    /**< Function 1 */
constexpr inline std::uint32_t F2{2u};    /**< Function 2 */
constexpr inline std::uint32_t F3{3u};    /**< Function 4 */
constexpr inline std::uint32_t F4{4u};    /**< Function 5 */
constexpr inline std::uint32_t F5{5u};    /**< Function 6 */
constexpr inline std::uint32_t F6{6u};    /**< Function 7 */
constexpr inline std::uint32_t F7{7u};    /**< Function 8 */
constexpr inline std::uint32_t F8{8u};    /**< Function 9 */
constexpr inline std::uint32_t F9{9u};    /**< Function 10 */
constexpr inline std::uint32_t NONE{31u}; /**< No function selected*/
/**
 * @brief Format FUNCSEL field to CTRL register
 * @param setting peripheral function select setting
 * @return FUNCSEL field formatted to CTRL register
 */
constexpr inline std::uint32_t FUNCSEL(std::uint32_t setting) {
  return setting << 0;
}
}  // namespace CTRL
namespace INTR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTR index
 * @param gpio gpio to map to a INTR index
 * @return index into the INTR array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTR register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTR register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTR register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTR register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace INTR
namespace PROC0_INTE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTE index
 * @param gpio gpio to map to a INTE index
 * @return index into the INTE array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace PROC0_INTE
namespace PROC0_INTF {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTF index
 * @param gpio gpio to map to a INTF index
 * @return index into the INTF array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace PROC0_INTF
namespace PROC0_INTS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTS index
 * @param gpio gpio to map to a INTS index
 * @return index into the INTS array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace PROC0_INTS
namespace PROC1_INTE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTE index
 * @param gpio gpio to map to a INTE index
 * @return index into the INTE array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTE register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace PROC1_INTE
namespace PROC1_INTF {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTF index
 * @param gpio gpio to map to a INTF index
 * @return index into the INTF array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTF register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace PROC1_INTF
namespace PROC1_INTS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/**
 * @brief Map gpio number to INTS index
 * @param gpio gpio to map to a INTS index
 * @return index into the INTS array
 */
constexpr inline std::uint32_t indexing(std::uint32_t gpio) {
  return gpio >> 3;
}
/**
 * @brief Generate mask for raw interrupt low level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t LEVEL_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 0);
}
/**
 * @brief Generate mask for raw interrupt high level sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t LEVEL_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 1);
}
/**
 * @brief Generate mask for raw interrupt falling edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t EDGE_LOW_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 2);
}
/**
 * @brief Generate mask for raw interrupt rising edge sensing
 * @param gpio gpio to generate the mask for
 * @return mask that can be applied to INTS register
 */
constexpr inline std::uint32_t EDGE_HIGH_MASK(std::uint32_t gpio) {
  return 1 << ((gpio >> 2) + 3);
}
}  // namespace PROC1_INTS
namespace DORMANT_WAKE_INTE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/* TODO: bit definitions */
}  // namespace DORMANT_WAKE_INTE
namespace DORMANT_WAKE_INTF {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/* TODO: bit definitions */
}  // namespace DORMANT_WAKE_INTF
namespace DORMANT_WAKE_INTS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFF}; /**< Mask for allowed bits */
/* TODO: bit definitions */
}  // namespace DORMANT_WAKE_INTS
}  // namespace gpioBank0
}  // namespace hw
}  // namespace libMcuLL
#endif