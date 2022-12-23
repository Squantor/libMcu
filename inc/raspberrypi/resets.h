/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Resets peripheral definitions */
#ifndef RESETS_H
#define RESETS_H

/**
 * @brief
 *
 */
typedef volatile struct {
  uint32_t RESET;            /*!< Reset control. set means the peripheral in reset, unset means deasserted. */
  uint32_t WDSEL;            /*!< Watchdog select. If a bit is set, the watchdog will reset that peripheral */
  const uint32_t RESET_DONE; /*!< Reset done. If bit is set, reset is done and peripheral can be accessed */
} RESETS_Type;

#define RESETS_RESET_RESERVED 0xFE000000      /**< Reset control reserved bits */
#define RESETS_WDSEL_RESERVED 0xFE000000      /**< Reset control reserved bits */
#define RESETS_RESET_DONE_RESERVED 0xFE000000 /**< Reset control reserved bits */
/**
 * @brief Peripheral reset bits, usable for RESET, WDSEL and RESET_DONE
 */
typedef enum {
  RESETS_ADC_MASK = (1 << 0),        /**< ADC */
  RESETS_BUSCTRL_MASK = (1 << 1),    /**< BUSCTRL */
  RESETS_DMA_MASK = (1 << 2),        /**< DMA */
  RESETS_I2C0_MASK = (1 << 3),       /**< I2C0 */
  RESETS_I2C1_MASK = (1 << 4),       /**< I2C1 */
  RESETS_IO_BANK0_MASK = (1 << 5),   /**< IO Bank0 */
  RESETS_IO_QSPI_MASK = (1 << 6),    /**< IO QSPI */
  RESETS_JTAG_MASK = (1 << 7),       /**< JTAG */
  RESETS_PADS_BANK0_MASK = (1 << 8), /**< Bank0 pads */
  RESETS_PADS_QSPI_MASK = (1 << 9),  /**< QSPI pads */
  RESETS_PIO0_MASK = (1 << 10),      /**< PIO0 */
  RESETS_PIO1_MASK = (1 << 11),      /**< PIO1 */
  RESETS_PLL_SYS_MASK = (1 << 12),   /**< System PLL */
  RESETS_PLL_USB_MASK = (1 << 13),   /**< USB PLL */
  RESETS_PWM_MASK = (1 << 14),       /**< PWM */
  RESETS_RTC_MASK = (1 << 15),       /**< RTC */
  RESETS_SPI0_MASK = (1 << 16),      /**< SPI0 */
  RESETS_SPI1_MASK = (1 << 17),      /**< SPI1 */
  RESETS_SYSCFG_MASK = (1 << 18),    /**< SYSCFG */
  RESETS_SYSINFO_MASK = (1 << 19),   /**< SYSINFO */
  RESETS_TBMAN_MASK = (1 << 20),     /**< TBMAN */
  RESETS_TIMER_MASK = (1 << 21),     /**< TIMER */
  RESETS_UART0_MASK = (1 << 22),     /**< UART0 */
  RESETS_UART1_MASK = (1 << 23),     /**< UART1 */
  RESETS_USBCTRL_MASK = (1 << 24),   /**< USBCTRL */
} RESETS_RESET_Enum;

/**
 * @brief
 *
 * @param peripheral  resets peripheral
 * @param setting
 */

/**
 * @brief Resets peripherals and waits until they have been reset
 *
 * @param peripheral  resets peripheral
 * @param setting     bit set of peripherals to reset, see RESETS_RESET_Enum for peripherals
 * @param timeout     how many times to check if the status set
 * @return uint32_t        returns zero when timed out or nonzero when resets are executed
 */
static inline uint32_t resetsReset(uint32_t setting, uint32_t timeout) {
  RESETS_CLR->RESET = setting;
  uint32_t value = RESETS->RESET_DONE;
  while (((value & setting) == setting) && (timeout > 0)) {
    timeout--;
    value = RESETS->RESET_DONE;
  }
  return timeout;
}

#endif