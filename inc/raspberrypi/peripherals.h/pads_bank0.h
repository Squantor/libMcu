/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file bank0 pads peripheral definitions */
#ifndef PADS_BANK0_H
#define PADS_BANK0_H

/**
 * @brief Bank 0 pads definition
 *
 */
typedef volatile struct {
  uint32_t VOLTAGE_SELECT; /**< Voltage select. Per bank control */
  uint32_t GPIO[30];       /**< Pad control register */
  uint32_t SWCLK;          /**< Pad control register */
  uint32_t SWD;            /**< Pad control register */
} PADS_BANK0_Type;

#define PADS_BANK0_VOLTAGE_SELECT_RESERVED (0xFFFFFFFE)   /**< Voltage select reseved bits */
#define PADS_BANK0_GPIO_RESERVED (0xFFFFFF00)             /**< Pad control register select reseved bits */
#define PADS_BANK0_GPIO_SLEWFAST_EN (0x01 << 0)           /**< Fast slewrate enable */
#define PADS_BANK0_GPIO_SLEWFAST_DIS (0x00 << 0)          /**< Fast slewrate disable */
#define PADS_BANK0_GPIO_SCHMITT_EN (0x01 << 1)            /**< Schmitt trigger enable */
#define PADS_BANK0_GPIO_SCHMITT_DIS (0x00 << 1)           /**< Schmitt trigger disable */
#define PADS_BANK0_GPIO_PDE_EN (0x01 << 2)                /**< Pull down enable */
#define PADS_BANK0_GPIO_PDE_DIS (0x00 << 2)               /**< Pull down disable */
#define PADS_BANK0_GPIO_PUE_EN (0x01 << 3)                /**< Pull up enable */
#define PADS_BANK0_GPIO_PUE_DIS (0x00 << 3)               /**< Pull up disable */
#define PADS_BANK0_GPIO_DRIVE(strength) ((strength) << 4) /**< Drive strength */
typedef enum {
  PADS_BANK0_DRIVE_2MA = 0x0,  /**< 2 milliampere drive*/
  PADS_BANK0_DRIVE_4MA = 0x1,  /**< 4 milliampere drive*/
  PADS_BANK0_DRIVE_8MA = 0x2,  /**< 8 milliampere drive*/
  PADS_BANK0_DRIVE_12MA = 0x03 /**< 12 milliampere drive*/
} PADS_BANK0_DRIVE_Enum;
#define PADS_BANK0_GPIO_IE_EN (0x01 << 6)      /**< Input enable */
#define PADS_BANK0_GPIO_IE_DIS (0x00 << 6)     /**< Input disable */
#define PADS_BANK0_GPIO_OD_EN (0x01 << 7)      /**< Output disable, priority over peripherals */
#define PADS_BANK0_GPIO_OD_DIS (0x00 << 7)     /**< Output enable, priority over peripherals */
#define PADS_BANK0_SWCLK_RESERVED (0xFFFFFF00) /**< Pad control register select reseved bits */
#define PADS_BANK0_SWD_RESERVED (0xFFFFFF00)   /**< Pad control register select reseved bits */

static inline void padsBank0Gpio(PADS_BANK0_Type* const peripheral, BANK0_GPIO_Enum pin, uint32_t settings) {
  peripheral->GPIO[pin] = settings;
}

#endif