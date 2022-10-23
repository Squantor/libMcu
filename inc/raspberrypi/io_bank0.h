/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file GPIO bank 0 peripheral definitions */
#ifndef IO_BANK0_H
#define IO_BANK0_H

/**
 * @brief GPIO bank 0 peripheral register definitions
 *
 */
typedef volatile struct {
  struct {
    const uint32_t STATUS; /**< GPIO status */
    uint32_t CTRL;         /**< GPIO control */
  } GPIO[30];
  uint32_t INTR[4];              /**< Raw interrupts */
  uint32_t PROC0_INTE[4];        /**< Interrupt Enable for proc0 */
  uint32_t PROC0_INTF[4];        /**< Interrupt Force for proc0 */
  const uint32_t PROC0_INTS[4];  /**< Interrupt status after masking & forcing for proc0 */
  uint32_t PROC1_INTE[4];        /**< Interrupt Enable for proc1 */
  uint32_t PROC1_INTF[4];        /**< Interrupt Force for proc1 */
  const uint32_t PROC1_INTS[4];  /**< Interrupt status after masking & forcing for proc1 */
  uint32_t DORMANT_WAKE_INTE[4]; /**< Interrupt Enable for dormant_wake */
  uint32_t DORMANT_WAKE_INTF[4]; /**< Interrupt Force for dormant_wake */
  uint32_t DORMANT_WAKE_INTS[4]; /**< Interrupt status after masking & forcing for dormant_wake */
} IO_BANK0_Type;

#define IO_BANK0_STATUS_RESERVED (0xFAF5CCFF)   /**< GPIO status reserved bits */
#define IO_BANK0_STATUS_OUTFROMPERI (0x01 << 8) /**< output signal from selected peripheral, before override */
#define IO_BANK0_STATUS_OUTTOPAD (0x01 << 9)    /**< output signal to pad after override */
#define IO_BANK0_STATUS_OEFROMPERI (0x01 << 12) /**< output enable from selected peripheral, before override */
#define IO_BANK0_STATUS_OETOPAD (0x01 << 13)    /**< output enable to pad after override */
#define IO_BANK0_STATUS_INFROMPAD (0x01 << 17)  /**< input signal from pad, before override */
#define IO_BANK0_STATUS_INTOPERI (0x01 << 19)   /**< input signal to peripheral, after override */
#define IO_BANK0_STATUS_IRQFROMPAD (0x01 << 24) /**< interrupt from pad before override */
#define IO_BANK0_STATUS_IRQTOPROC (0x01 << 26)  /**< interrupt to processors, after override */

#define IO_BANK0_CTRL_RESERVED (0xCFFCCCE0)                       /**< GPIO control reserved bits */
#define IO_BANK0_FUNCSEL_OUTOVER(setting) (((setting)&0x1F) << 0) /**< Peripheral output override */
#define IO_BANK0_CTRL_OUTOVER(setting) (((setting)&0x03) << 8)    /**< Peripheral output override */
/**
 * @brief Peripheral output override settings
 */
typedef enum {
  IO_BANK0_CTRL_OUTOVER_OUT_SEL = (0x0),  /**< drive output from peripheral signal */
  IO_BANK0_CTRL_OUTOVER_OUT_INV = (0x1),  /**< drive output from inverse of peripheral signal */
  IO_BANK0_CTRL_OUTOVER_OUT_LOW = (0x2),  /**< drive output low */
  IO_BANK0_CTRL_OUTOVER_OUT_HIGH = (0x3), /**< drive output high */
} IO_BANK0_CTRL_OUTOVER_Enum;
#define IO_BANK0_CTRL_OEOVER(setting) (((setting)&0x03) << 12) /**< Peripheral output enable override */
/**
 * @brief Peripheral output enable override settings
 */
typedef enum {
  IO_BANK0_CTRL_OEOVER_OUT_SEL = (0x0), /**< drive output enable from peripheral signal */
  IO_BANK0_CTRL_OEOVER_OUT_INV = (0x1), /**< drive output enable from inverse of peripheral signal */
  IO_BANK0_CTRL_OEOVER_OUT_DIS = (0x2), /**< disable output */
  IO_BANK0_CTRL_OEOVER_OUT_EN = (0x3),  /**< enable output */
} IO_BANK0_CTRL_OEOVER_Enum;
#define IO_BANK0_CTRL_INOVER(setting) (((setting)&0x03) << 16) /**< Peripheral input override */
/**
 * @brief Peripheral input override settings
 */
typedef enum {
  IO_BANK0_CTRL_INOVER_NOT_INV = (0x0),    /**< don’t invert the peripheral input */
  IO_BANK0_CTRL_INOVER_INVERT = (0x1),     /**< invert the peripheral input */
  IO_BANK0_CTRL_INOVER_DRIVE_LOW = (0x2),  /**< drive peripheral input low */
  IO_BANK0_CTRL_INOVER_DRIVE_HIGH = (0x3), /**< drive peripheral input high */
} IO_BANK0_CTRL_INOVER_Enum;
#define IO_BANK0_CTRL_IRQOVER(setting) (((setting)&0x03) << 28) /**< IRQ override */
/**
 * @brief IRQ override settings
 */
typedef enum {
  IO_BANK0_CTRL_IRQOVER_NOT_INV = (0x0),    /**< don’t invert the interrupt */
  IO_BANK0_CTRL_IRQOVER_INVERT = (0x1),     /**< invert the interrupt */
  IO_BANK0_CTRL_IRQOVER_DRIVE_LOW = (0x2),  /**< drive interrupt low */
  IO_BANK0_CTRL_IRQOVER_DRIVE_HIGH = (0x3), /**< drive interrupt high */
} IO_BANK0_CTRL_IRQOVER_Enum;

#define IO_BANK0_INTR_RESERVED (0x00000000)              /**< Raw interrupts reserved bits */
#define IO_BANK0_PROC0_INTE_RESERVED (0x00000000)        /**< Interrupt Enable for proc0 reserved bits */
#define IO_BANK0_PROC0_INTF_RESERVED (0x00000000)        /**< Interrupt Force for proc0 reserved bits */
#define IO_BANK0_PROC0_INTS_RESERVED (0x00000000)        /**< Interrupt status for proc0 reserved bits */
#define IO_BANK0_PROC1_INTE_RESERVED (0x00000000)        /**< Interrupt Enable for proc1 reserved bits */
#define IO_BANK0_PROC1_INTF_RESERVED (0x00000000)        /**< Interrupt Force for proc1 reserved bits */
#define IO_BANK0_PROC1_INTS_RESERVED (0x00000000)        /**< Interrupt status for proc1 reserved bits */
#define IO_BANK0_DORMANT_WAKE_INTE_RESERVED (0x00000000) /**< Interrupt Enable for dormant_wake reserved bits */
#define IO_BANK0_DORMANT_WAKE_INTF_RESERVED (0x00000000) /**< Interrupt Force for dormant_wake reserved bits */
#define IO_BANK0_DORMANT_WAKE_INTS_RESERVED (0x00000000) /**< Interrupt status reserved bits */

#endif