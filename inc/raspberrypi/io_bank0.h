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

/**
 * @brief Bank0 gpio function selects
 *
 */
typedef enum {
  BANK0_GPIO0_FUNC_JTAG_TCK = (0),      /**< GPIO0 is JTAG TCK */
  BANK0_GPIO0_FUNC_SPI0_RX = (1),       /**< GPIO0 is SPI0 RX */
  BANK0_GPIO0_FUNC_UART0_TX = (2),      /**< GPIO0 is UART0 TX */
  BANK0_GPIO0_FUNC_I2C0_SDA = (3),      /**< GPIO0 is I2C0 SDA */
  BANK0_GPIO0_FUNC_PWM0_A = (4),        /**< GPIO0 is PWM0 A */
  BANK0_GPIO0_FUNC_SIO = (5),           /**< GPIO0 is SIO */
  BANK0_GPIO0_FUNC_PIO0 = (6),          /**< GPIO0 is PIO0 */
  BANK0_GPIO0_FUNC_PIO1 = (7),          /**< GPIO0 is PIO1 */
  BANK0_GPIO0_FUNC_USB_OVCUR_DET = (9), /**< GPIO0 is USB overcurrent detect */
  BANK0_GPIO0_FUNC_NULL = (31),         /**< GPIO0 is not connected */

  BANK0_GPIO1_FUNC_JTAG_TMS = (0),     /**< GPIO1 is JTAG TMS */
  BANK0_GPIO1_FUNC_SPI0_CS = (1),      /**< GPIO1 is SPI0 Chip select */
  BANK0_GPIO1_FUNC_UART0_RX = (2),     /**< GPIO1 is UART0 RX */
  BANK0_GPIO1_FUNC_I2C0_SCL = (3),     /**< GPIO1 is I2C0 SCL */
  BANK0_GPIO1_FUNC_PWM0_B = (4),       /**< GPIO1 is PWM0 B */
  BANK0_GPIO1_FUNC_SIO = (5),          /**< GPIO1 is SIO */
  BANK0_GPIO1_FUNC_PIO0 = (6),         /**< GPIO1 is PIO0 */
  BANK0_GPIO1_FUNC_PIO1 = (7),         /**< GPIO1 is PIO1 */
  BANK0_GPIO1_FUNC_USB_VBUS_DET = (9), /**< GPIO1 is USB VBUS detect */
  BANK0_GPIO1_FUNC_NULL = (31),        /**< GPIO1 is not connected  */

  BANK0_GPIO2_FUNC_JTAG_TDI = (0),    /**< GPIO2 is JTAG TDI */
  BANK0_GPIO2_FUNC_SPI0_SCK = (1),    /**< GPIO2 is SPI0 SCK */
  BANK0_GPIO2_FUNC_UART0_CTS = (2),   /**< GPIO2 is UART0 CTS */
  BANK0_GPIO2_FUNC_I2C1_SDA = (3),    /**< GPIO2 is I2C1 SDA */
  BANK0_GPIO2_FUNC_PWM1_A = (4),      /**< GPIO2 is PWM1 A */
  BANK0_GPIO2_FUNC_SIO = (5),         /**< GPIO2 is SIO */
  BANK0_GPIO2_FUNC_PIO0 = (6),        /**< GPIO2 is PIO0 */
  BANK0_GPIO2_FUNC_PIO1 = (7),        /**< GPIO2 is PIO1 */
  BANK0_GPIO2_FUNC_USB_VBUS_EN = (9), /**< GPIO2 is USB VBUS enable */
  BANK0_GPIO2_FUNC_NULL = (31),       /**< GPIO2 is not connected  */

  BANK0_GPIO3_FUNC_JTAG_TDO = (0),      /**< GPIO3 is JTAG TDO */
  BANK0_GPIO3_FUNC_SPI0_TX = (1),       /**< GPIO3 is SPI0 TX */
  BANK0_GPIO3_FUNC_UART0_RTS = (2),     /**< GPIO3 is UART0 RTS */
  BANK0_GPIO3_FUNC_I2C1_SCL = (3),      /**< GPIO3 is I2C1 SCL */
  BANK0_GPIO3_FUNC_PWM1_B = (4),        /**< GPIO3 is PWM1 B */
  BANK0_GPIO3_FUNC_SIO = (5),           /**< GPIO3 is SIO */
  BANK0_GPIO3_FUNC_PIO0 = (6),          /**< GPIO3 is PIO0 */
  BANK0_GPIO3_FUNC_PIO1 = (7),          /**< GPIO3 is PIO1 */
  BANK0_GPIO3_FUNC_USB_OVCUR_DET = (9), /**< GPIO3 is USB overcurrent detect */
  BANK0_GPIO3_FUNC_NULL = (31),         /**< GPIO3 is not connected  */

  BANK0_GPIO4_FUNC_SPI0_RX = (1),      /**< GPIO4 is SPI0 RX */
  BANK0_GPIO4_FUNC_UART1_TX = (2),     /**< GPIO4 is UART1 TX */
  BANK0_GPIO4_FUNC_I2C0_SDA = (3),     /**< GPIO4 is I2C0 SDA */
  BANK0_GPIO4_FUNC_PWM2_A = (4),       /**< GPIO4 is PWM2 A */
  BANK0_GPIO4_FUNC_SIO = (5),          /**< GPIO4 is SIO */
  BANK0_GPIO4_FUNC_PIO0 = (6),         /**< GPIO4 is PIO0 */
  BANK0_GPIO4_FUNC_PIO1 = (7),         /**< GPIO4 is PIO1 */
  BANK0_GPIO4_FUNC_USB_VBUS_DET = (9), /**< GPIO4 is USB VBUS detect */
  BANK0_GPIO4_FUNC_NULL = (31),        /**< GPIO4 is not connected */

  BANK0_GPIO5_FUNC_SPI0_CS = (1),     /**< GPIO5 is SPI0 Chip select */
  BANK0_GPIO5_FUNC_UART1_RX = (2),    /**< GPIO5 is UART1 RX */
  BANK0_GPIO5_FUNC_I2C0_SCL = (3),    /**< GPIO5 is I2C0 SCL */
  BANK0_GPIO5_FUNC_PWM2_B = (4),      /**< GPIO5 is PWM2 B */
  BANK0_GPIO5_FUNC_SIO = (5),         /**< GPIO5 is SIO */
  BANK0_GPIO5_FUNC_PIO0 = (6),        /**< GPIO5 is PIO0 */
  BANK0_GPIO5_FUNC_PIO1 = (7),        /**< GPIO5 is PIO1 */
  BANK0_GPIO5_FUNC_USB_VBUS_EN = (9), /**< GPIO5 is USB VBUS enable*/
  BANK0_GPIO5_FUNC_NULL = (31),       /**< GPIO5 is not connected */

  BANK0_GPIO6_FUNC_SPI0_SCK = (1),      /**< GPIO6 is SPI0 SCK */
  BANK0_GPIO6_FUNC_UART1_CTS = (2),     /**< GPIO6 is UART1 CTS */
  BANK0_GPIO6_FUNC_I2C1_SDA = (3),      /**< GPIO6 is I2C1 SDA */
  BANK0_GPIO6_FUNC_PWM3_A = (4),        /**< GPIO6 is PWM3 A */
  BANK0_GPIO6_FUNC_SIO = (5),           /**< GPIO6 is SIO */
  BANK0_GPIO6_FUNC_PIO0 = (6),          /**< GPIO6 is PIO0 */
  BANK0_GPIO6_FUNC_PIO1 = (7),          /**< GPIO6 is PIO1 */
  BANK0_GPIO6_FUNC_USB_OVCUR_DET = (9), /**< GPIO6 is USB Overcurrent detect */
  BANK0_GPIO6_FUNC_NULL = (31),         /**< GPIO6 is not connected */

  BANK0_GPIO7_FUNC_SPI0_TX = (1),      /**< GPIO7 is SPI0 TX */
  BANK0_GPIO7_FUNC_UART1_RTS = (2),    /**< GPIO7 is UART1 RTS */
  BANK0_GPIO7_FUNC_I2C1_SCL = (3),     /**< GPIO7 is I2C1 SCL */
  BANK0_GPIO7_FUNC_PWM3_B = (4),       /**< GPIO7 is PWM3 B */
  BANK0_GPIO7_FUNC_SIO = (5),          /**< GPIO7 is SIO */
  BANK0_GPIO7_FUNC_PIO0 = (6),         /**< GPIO7 is PIO0 */
  BANK0_GPIO7_FUNC_PIO1 = (7),         /**< GPIO7 is PIO1 */
  BANK0_GPIO7_FUNC_USB_VBUS_DET = (9), /**< GPIO7 is USB VBUS detect */
  BANK0_GPIO7_FUNC_NULL = (31),        /**< GPIO7 is not connected */

  BANK0_GPIO8_FUNC_SPI1_RX = (1),     /**< GPIO8 is SPI1 RX */
  BANK0_GPIO8_FUNC_UART1_TX = (2),    /**< GPIO8 is UART1 TX */
  BANK0_GPIO8_FUNC_I2C0_SDA = (3),    /**< GPIO8 is I2C0 SDA */
  BANK0_GPIO8_FUNC_PWM4_A = (4),      /**< GPIO8 is PWM4 A */
  BANK0_GPIO8_FUNC_SIO = (5),         /**< GPIO8 is SIO */
  BANK0_GPIO8_FUNC_PIO0 = (6),        /**< GPIO8 is PIO0 */
  BANK0_GPIO8_FUNC_PIO1 = (7),        /**< GPIO8 is PIO1 */
  BANK0_GPIO8_FUNC_USB_VBUS_EN = (9), /**< GPIO8 is USB VBUS enable*/
  BANK0_GPIO8_FUNC_NULL = (31),       /**< GPIO8 is not connected */

  BANK0_GPIO9_FUNC_SPI1_CS = (1),       /**< GPIO9 is SPI1 CS */
  BANK0_GPIO9_FUNC_UART1_RX = (2),      /**< GPIO9 is UART1 RX */
  BANK0_GPIO9_FUNC_I2C0_SCL = (3),      /**< GPIO9 is I2C0 SCL */
  BANK0_GPIO9_FUNC_PWM4_B = (4),        /**< GPIO9 is PWM4 B */
  BANK0_GPIO9_FUNC_SIO = (5),           /**< GPIO9 is SIO */
  BANK0_GPIO9_FUNC_PIO0 = (6),          /**< GPIO9 is PIO0 */
  BANK0_GPIO9_FUNC_PIO1 = (7),          /**< GPIO9 is PIO1 */
  BANK0_GPIO9_FUNC_USB_OVCUR_DET = (9), /**< GPIO9 is USB Overcurrent detect */
  BANK0_GPIO9_FUNC_NULL = (31),         /**< GPIO9 is not connected */

  BANK0_GPIO10_FUNC_SPI1_SCK = (1),     /**< GPIO10 is SPI1 SCK */
  BANK0_GPIO10_FUNC_UART1_CTS = (2),    /**< GPIO10 is UART1 CTS */
  BANK0_GPIO10_FUNC_I2C1_SDA = (3),     /**< GPIO10 is I2C1 SDA */
  BANK0_GPIO10_FUNC_PWM5_A = (4),       /**< GPIO10 is PWM5 A */
  BANK0_GPIO10_FUNC_SIO = (5),          /**< GPIO10 is SIO */
  BANK0_GPIO10_FUNC_PIO0 = (6),         /**< GPIO10 is PIO0 */
  BANK0_GPIO10_FUNC_PIO1 = (7),         /**< GPIO10 is PIO1 */
  BANK0_GPIO10_FUNC_USB_VBUS_DET = (9), /**< GPIO10 is USB VBUS detect*/
  BANK0_GPIO10_FUNC_NULL = (31),        /**< GPIO10 is not connected */

  BANK0_GPIO11_FUNC_SPI1_TX = (1),     /**< GPIO11 is SPI1 TX */
  BANK0_GPIO11_FUNC_UART1_RTS = (2),   /**< GPIO11 is UART1 RTS */
  BANK0_GPIO11_FUNC_I2C1_SCL = (3),    /**< GPIO11 is I2C1 SCL */
  BANK0_GPIO11_FUNC_PWM5_B = (4),      /**< GPIO11 is PWM5 B */
  BANK0_GPIO11_FUNC_SIO = (5),         /**< GPIO11 is SIO */
  BANK0_GPIO11_FUNC_PIO0 = (6),        /**< GPIO11 is PIO0 */
  BANK0_GPIO11_FUNC_PIO1 = (7),        /**< GPIO11 is PIO1 */
  BANK0_GPIO11_FUNC_USB_VBUS_EN = (9), /**< GPIO11 is VBUS enable */
  BANK0_GPIO11_FUNC_NULL = (31),       /**< GPIO11 is not connected */

  BANK0_GPIO12_FUNC_SPI1_RX = (1),         /**< GPIO12 is SPI1 RX */
  BANK0_GPIO12_FUNC_UART0_TX = (2),        /**< GPIO12 is UART0 TX */
  BANK0_GPIO12_FUNC_I2C0_SDA = (3),        /**< GPIO12 is I2C0 SDA */
  BANK0_GPIO12_FUNC_PWM6_A = (4),          /**< GPIO12 is PWM6 A */
  BANK0_GPIO12_FUNC_SIO = (5),             /**< GPIO12 is SIO */
  BANK0_GPIO12_FUNC_PIO0 = (6),            /**< GPIO12 is PIO0 */
  BANK0_GPIO12_FUNC_PIO1 = (7),            /**< GPIO12 is PIO1 */
  BANK0_GPIO12_FUNC_USB_OVERCUR_DET = (9), /**< GPIO12 is USB overcurrent detect */
  BANK0_GPIO12_FUNC_NULL = (31),           /**< GPIO12 is not connected */

  BANK0_GPIO13_FUNC_SPI1_CS = (1),      /**< GPIO13 is SPI1 CS */
  BANK0_GPIO13_FUNC_UART0_RX = (2),     /**< GPIO13 is UART0 RX */
  BANK0_GPIO13_FUNC_I2C0_SCL = (3),     /**< GPIO13 is I2C0 SCL */
  BANK0_GPIO13_FUNC_PWM6_B = (4),       /**< GPIO13 is PWM6 B */
  BANK0_GPIO13_FUNC_SIO = (5),          /**< GPIO13 is SIO */
  BANK0_GPIO13_FUNC_PIO0 = (6),         /**< GPIO13 is PIO0 */
  BANK0_GPIO13_FUNC_PIO1 = (7),         /**< GPIO13 is PIO1 */
  BANK0_GPIO13_FUNC_USB_VBUS_DET = (9), /**< GPIO13 is USB VBUS detect */
  BANK0_GPIO13_FUNC_NULL = (31),        /**< GPIO13 is not connected */

  BANK0_GPIO14_FUNC_SPI1_SCK = (1),    /**< GPIO14 is SPI1 SCK */
  BANK0_GPIO14_FUNC_UART0_CTS = (2),   /**< GPIO14 is UART0 CTS */
  BANK0_GPIO14_FUNC_I2C1_SDA = (3),    /**< GPIO14 is I2C1 SDA */
  BANK0_GPIO14_FUNC_PWM7_A = (4),      /**< GPIO14 is PWM7 A */
  BANK0_GPIO14_FUNC_SIO = (5),         /**< GPIO14 is SIO */
  BANK0_GPIO14_FUNC_PIO0 = (6),        /**< GPIO14 is PIO0 */
  BANK0_GPIO14_FUNC_PIO1 = (7),        /**< GPIO14 is PIO1 */
  BANK0_GPIO14_FUNC_USB_VBUS_EN = (9), /**< GPIO14 is VBUS enable */
  BANK0_GPIO14_FUNC_NULL = (31),       /**< GPIO14 is not connected */

  BANK0_GPIO15_FUNC_SPI1_TX = (1),       /**< GPIO15 is SPI1 TX */
  BANK0_GPIO15_FUNC_UART0_RTS = (2),     /**< GPIO15 is UART0 RTS */
  BANK0_GPIO15_FUNC_I2C1_SCL = (3),      /**< GPIO15 is I2C1 SCL */
  BANK0_GPIO15_FUNC_PWM7_B = (4),        /**< GPIO15 is PWM7 B */
  BANK0_GPIO15_FUNC_SIO = (5),           /**< GPIO15 is SIO */
  BANK0_GPIO15_FUNC_PIO0 = (6),          /**< GPIO15 is PIO0 */
  BANK0_GPIO15_FUNC_PIO1 = (7),          /**< GPIO15 is PIO1 */
  BANK0_GPIO15_FUNC_USB_OVCUR_DET = (9), /**< GPIO15 is USB overcurrent detect */
  BANK0_GPIO15_FUNC_NULL = (31),         /**< GPIO15 is not connected */

  BANK0_GPIO16_FUNC_SPI0_RX = (1),      /**< GPIO16 is SPI0 RX */
  BANK0_GPIO16_FUNC_UART0_TX = (2),     /**< GPIO16 is UART0 TX */
  BANK0_GPIO16_FUNC_I2C0_SDA = (3),     /**< GPIO16 is I2C0 SDA */
  BANK0_GPIO16_FUNC_PWM0_A = (4),       /**< GPIO16 is PWM0 A */
  BANK0_GPIO16_FUNC_SIO = (5),          /**< GPIO16 is SIO */
  BANK0_GPIO16_FUNC_PIO0 = (6),         /**< GPIO16 is PIO0 */
  BANK0_GPIO16_FUNC_PIO1 = (7),         /**< GPIO16 is PIO1 */
  BANK0_GPIO16_FUNC_USB_VBUS_DET = (9), /**< GPIO16 is USB VBUS detect */
  BANK0_GPIO16_FUNC_NULL = (31),        /**< GPIO16 is not connected */

  BANK0_GPIO17_FUNC_SPI0_CS = (1),     /**< GPIO17 is SPI0 CS */
  BANK0_GPIO17_FUNC_UART0_RX = (2),    /**< GPIO17 is UART0 RX */
  BANK0_GPIO17_FUNC_I2C0_SCL = (3),    /**< GPIO17 is I2C0 SCL */
  BANK0_GPIO17_FUNC_PWM0_B = (4),      /**< GPIO17 is PWM0 B */
  BANK0_GPIO17_FUNC_SIO = (5),         /**< GPIO17 is SIO */
  BANK0_GPIO17_FUNC_PIO0 = (6),        /**< GPIO17 is PIO0 */
  BANK0_GPIO17_FUNC_PIO1 = (7),        /**< GPIO17 is PIO1 */
  BANK0_GPIO17_FUNC_USB_VBUS_EN = (9), /**< GPIO17 is USB VBUS enable */
  BANK0_GPIO17_FUNC_NULL = (31),       /**< GPIO17 is not connected */

  BANK0_GPIO18_FUNC_SPI0_SCK = (1),      /**< GPIO18 is SPI0 SCK */
  BANK0_GPIO18_FUNC_UART0_CTS = (2),     /**< GPIO18 is UART0 CTS */
  BANK0_GPIO18_FUNC_I2C1_SDA = (3),      /**< GPIO18 is I2C1 SDA */
  BANK0_GPIO18_FUNC_PWM1_A = (4),        /**< GPIO18 is PWM1 A */
  BANK0_GPIO18_FUNC_SIO = (5),           /**< GPIO18 is SIO */
  BANK0_GPIO18_FUNC_PIO0 = (6),          /**< GPIO18 is PIO0 */
  BANK0_GPIO18_FUNC_PIO1 = (7),          /**< GPIO18 is PIO1 */
  BANK0_GPIO18_FUNC_USB_OVCUR_DET = (9), /**< GPIO18 is USB overcurrent detect */
  BANK0_GPIO18_FUNC_NULL = (31),         /**< GPIO18 is not connected */

  BANK0_GPIO19_FUNC_SPI0_TX = (1),      /**< GPIO19 is SPI0 TX */
  BANK0_GPIO19_FUNC_UART0_RTS = (2),    /**< GPIO19 is UART0 RTS */
  BANK0_GPIO19_FUNC_I2C1_SCL = (3),     /**< GPIO19 is I2C1 SCL */
  BANK0_GPIO19_FUNC_PWM1_B = (4),       /**< GPIO19 is PWM1 B */
  BANK0_GPIO19_FUNC_SIO = (5),          /**< GPIO19 is SIO */
  BANK0_GPIO19_FUNC_PIO0 = (6),         /**< GPIO19 is PIO0 */
  BANK0_GPIO19_FUNC_PIO1 = (7),         /**< GPIO19 is PIO1 */
  BANK0_GPIO19_FUNC_USB_VBUS_DET = (9), /**< GPIO19 is USB VBUS detect */
  BANK0_GPIO19_FUNC_NULL = (31),        /**< GPIO19 is not connected */

  BANK0_GPIO20_FUNC_SPI0_RX = (1),     /**< GPIO20 is SPI0 RX */
  BANK0_GPIO20_FUNC_UART1_TX = (2),    /**< GPIO20 is UART1 TX */
  BANK0_GPIO20_FUNC_I2C0_SDA = (3),    /**< GPIO20 is I2C0 SDA */
  BANK0_GPIO20_FUNC_PWM2_A = (4),      /**< GPIO20 is PWM2 A */
  BANK0_GPIO20_FUNC_SIO = (5),         /**< GPIO20 is SIO */
  BANK0_GPIO20_FUNC_PIO0 = (6),        /**< GPIO20 is PIO0 */
  BANK0_GPIO20_FUNC_PIO1 = (7),        /**< GPIO20 is PIO1 */
  BANK0_GPIO20_FUNC_CLOCK_GPIN0 = (8), /**< GPIO20 is CLOCK GPIN0 */
  BANK0_GPIO20_FUNC_USB_VBUS_EN = (9), /**< GPIO20 is USB VBUS enable*/
  BANK0_GPIO20_FUNC_NULL = (31),       /**< GPIO20 is not connected */

  BANK0_GPIO21_FUNC_SPI0_CS = (1),       /**< GPIO21 is SPI0 CS */
  BANK0_GPIO21_FUNC_UART1_RX = (2),      /**< GPIO21 is UART1 RX */
  BANK0_GPIO21_FUNC_I2C0_SCL = (3),      /**< GPIO21 is I2C0 SCL */
  BANK0_GPIO21_FUNC_PWM2_B = (4),        /**< GPIO21 is PWM2 B */
  BANK0_GPIO21_FUNC_SIO = (5),           /**< GPIO21 is SIO */
  BANK0_GPIO21_FUNC_PIO0 = (6),          /**< GPIO21 is PIO0 */
  BANK0_GPIO21_FUNC_PIO1 = (7),          /**< GPIO21 is PIO1 */
  BANK0_GPIO21_FUNC_CLOCK_GPOUT0 = (8),  /**< GPIO21 is CLOCK GPOUT0 */
  BANK0_GPIO21_FUNC_USB_OVCUR_DET = (9), /**< GPIO21 is USB overcurrent detect */
  BANK0_GPIO21_FUNC_NULL = (31),         /**< GPIO21 is not connected */

  BANK0_GPIO22_FUNC_SPI0_SCK = (1),     /**< GPIO22 is SPI0 SCK */
  BANK0_GPIO22_FUNC_UART1_CTS = (2),    /**< GPIO22 is UART1 CTS */
  BANK0_GPIO22_FUNC_I2C1_SDA = (3),     /**< GPIO22 is I2C1 SDA */
  BANK0_GPIO22_FUNC_PWM3_A = (4),       /**< GPIO22 is PWM3 A */
  BANK0_GPIO22_FUNC_SIO = (5),          /**< GPIO22 is SIO */
  BANK0_GPIO22_FUNC_PIO0 = (6),         /**< GPIO22 is PIO0 */
  BANK0_GPIO22_FUNC_PIO1 = (7),         /**< GPIO22 is PIO1 */
  BANK0_GPIO21_FUNC_CLOCK_GPIN1 = (8),  /**< GPIO22 is CLOCK GPIN1 */
  BANK0_GPIO22_FUNC_USB_VBUS_DET = (9), /**< GPIO22 is USB VBUS detect */
  BANK0_GPIO22_FUNC_NULL = (31),        /**< GPIO22 is not connected */

  BANK0_GPIO23_FUNC_SPI0_TX = (1),      /**< GPIO23 is SPI0 TX */
  BANK0_GPIO23_FUNC_UART1_RTS = (2),    /**< GPIO23 is UART1 RTS */
  BANK0_GPIO23_FUNC_I2C1_SCL = (3),     /**< GPIO23 is I2C1 SCL */
  BANK0_GPIO23_FUNC_PWM3_B = (4),       /**< GPIO23 is PWM3 B */
  BANK0_GPIO23_FUNC_SIO = (5),          /**< GPIO23 is SIO */
  BANK0_GPIO23_FUNC_PIO0 = (6),         /**< GPIO23 is PIO0 */
  BANK0_GPIO23_FUNC_PIO1 = (7),         /**< GPIO23 is PIO1 */
  BANK0_GPIO23_FUNC_CLOCK_GPOUT1 = (8), /**< GPIO23 is CLOCK GPOUT1 */
  BANK0_GPIO23_FUNC_USB_VBUS_EN = (9),  /**< GPIO23 is USB VBUS enable */
  BANK0_GPIO23_FUNC_NULL = (31),        /**< GPIO23 is not connected */

  BANK0_GPIO24_FUNC_SPI1_RX = (1),       /**< GPIO24 is SPI1 RX */
  BANK0_GPIO24_FUNC_UART1_TX = (2),      /**< GPIO24 is UART1 TX */
  BANK0_GPIO24_FUNC_I2C0_SDA = (3),      /**< GPIO24 is I2C0 SDA */
  BANK0_GPIO24_FUNC_PWM4_A = (4),        /**< GPIO24 is PWM4 A */
  BANK0_GPIO24_FUNC_SIO = (5),           /**< GPIO24 is SIO */
  BANK0_GPIO24_FUNC_PIO0 = (6),          /**< GPIO24 is PIO0 */
  BANK0_GPIO24_FUNC_PIO1 = (7),          /**< GPIO24 is PIO1 */
  BANK0_GPIO24_FUNC_CLOCK_GPOUT2 = (8),  /**< GPIO24 is CLOCK GPOUT2 */
  BANK0_GPIO24_FUNC_USB_OVCUR_DET = (9), /**< GPIO24 is USB overcurrent detect */
  BANK0_GPIO24_FUNC_NULL = (31),         /**< GPIO24 is not connected */

  BANK0_GPIO25_FUNC_SPI1_CS = (1),      /**< GPIO25 is SPI1 CS */
  BANK0_GPIO25_FUNC_UART1_RX = (2),     /**< GPIO25 is UART1 RX */
  BANK0_GPIO25_FUNC_I2C0_SCL = (3),     /**< GPIO25 is I2C0 SCL */
  BANK0_GPIO25_FUNC_PWM4_B = (4),       /**< GPIO25 is PWM4 B */
  BANK0_GPIO25_FUNC_SIO = (5),          /**< GPIO25 is SIO */
  BANK0_GPIO25_FUNC_PIO0 = (6),         /**< GPIO25 is PIO0 */
  BANK0_GPIO25_FUNC_PIO1 = (7),         /**< GPIO25 is PIO1 */
  BANK0_GPIO25_FUNC_CLOCK_GPOUT3 = (8), /**< GPIO25 is CLOCK GPOUT3 */
  BANK0_GPIO25_FUNC_USB_VBUS_DET = (9), /**< GPIO25 is USB VBUS detect */
  BANK0_GPIO25_FUNC_NULL = (31),        /**< GPIO25 is not connected */

  BANK0_GPIO26_FUNC_SPI1_SCK = (1),    /**< GPIO26 is SPI1 SCK */
  BANK0_GPIO26_FUNC_UART1_CTS = (2),   /**< GPIO26 is UART1 CTS */
  BANK0_GPIO26_FUNC_I2C1_SDA = (3),    /**< GPIO26 is I2C1 SDA */
  BANK0_GPIO26_FUNC_PWM5_A = (4),      /**< GPIO26 is PWM5 A */
  BANK0_GPIO26_FUNC_SIO = (5),         /**< GPIO26 is SIO */
  BANK0_GPIO26_FUNC_PIO0 = (6),        /**< GPIO26 is PIO0 */
  BANK0_GPIO26_FUNC_PIO1 = (7),        /**< GPIO26 is PIO1 */
  BANK0_GPIO26_FUNC_USB_VBUS_EN = (9), /**< GPIO26 is USB VBUS enable */
  BANK0_GPIO26_FUNC_NULL = (31),       /**< GPIO26 is not connected */

  BANK0_GPIO27_FUNC_SPI1_TX = (1),       /**< GPIO27 is SPI1 TX */
  BANK0_GPIO27_FUNC_UART1_RTS = (2),     /**< GPIO27 is UART1 RTS */
  BANK0_GPIO27_FUNC_I2C1_SCL = (3),      /**< GPIO27 is I2C1 SCL */
  BANK0_GPIO27_FUNC_PWM5_B = (4),        /**< GPIO27 is PWM5 B */
  BANK0_GPIO27_FUNC_SIO = (5),           /**< GPIO27 is SIO */
  BANK0_GPIO27_FUNC_PIO0 = (6),          /**< GPIO27 is PIO0 */
  BANK0_GPIO27_FUNC_PIO1 = (7),          /**< GPIO27 is PIO1 */
  BANK0_GPIO27_FUNC_USB_OVCUR_DET = (9), /**< GPIO27 is USB overcurrent detect */
  BANK0_GPIO27_FUNC_NULL = (31),         /**< GPIO27 is not connected */

  BANK0_GPIO28_FUNC_SPI1_RX = (1),      /**< GPIO28 is SPI1 RX */
  BANK0_GPIO28_FUNC_UART0_TX = (2),     /**< GPIO28 is UART0 TX */
  BANK0_GPIO28_FUNC_I2C0_SDA = (3),     /**< GPIO28 is I2C0 SDA */
  BANK0_GPIO28_FUNC_PWM6_A = (4),       /**< GPIO28 is PWM6 A */
  BANK0_GPIO28_FUNC_SIO = (5),          /**< GPIO28 is SIO */
  BANK0_GPIO28_FUNC_PIO0 = (6),         /**< GPIO28 is PIO0 */
  BANK0_GPIO28_FUNC_PIO1 = (7),         /**< GPIO28 is PIO1 */
  BANK0_GPIO28_FUNC_USB_VBUS_DET = (9), /**< GPIO28 is USB VBUS detect */
  BANK0_GPIO28_FUNC_NULL = (31),        /**< GPIO28 is not connected */

  BANK0_GPIO29_FUNC_SPI1_CS = (1),     /**< GPIO29 is SPI1 CS */
  BANK0_GPIO29_FUNC_UART0_RX = (2),    /**< GPIO29 is UART0 RX */
  BANK0_GPIO29_FUNC_I2C0_SCL = (3),    /**< GPIO29 is I2C0 SCL */
  BANK0_GPIO29_FUNC_PWM6_B = (4),      /**< GPIO29 is PWM6 B */
  BANK0_GPIO29_FUNC_SIO = (5),         /**< GPIO29 is SIO */
  BANK0_GPIO29_FUNC_PIO0 = (6),        /**< GPIO29 is PIO0 */
  BANK0_GPIO29_FUNC_PIO1 = (7),        /**< GPIO29 is PIO1 */
  BANK0_GPIO29_FUNC_USB_VBUS_EN = (9), /**< GPIO29 is USB VBUS enable */
  BANK0_GPIO29_FUNC_NULL = (31),       /**< GPIO29 is not connected */

} IO_BANK0_CTRLN_FUNCSEL_Enum;

#endif