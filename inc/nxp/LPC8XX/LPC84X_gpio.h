/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series General Purpose I/O registers, defines and functions.
 */
#ifndef LPC84X_GPIO_H
#define LPC84X_GPIO_H

/** GPIO - Register Layout Typedef */
typedef volatile struct GPIO_Struct {
  uint8_t B[2][32]; /**< Byte pin registers for all port 0 and 1 GPIO pins,
                       array offset: 0x0, array step: index*0x20, index2*0x1 */
  uint8_t RESERVED_0[4032];
  uint32_t W[2][32]; /**< Word pin registers for all port 0 and 1 GPIO pins, array
                        offset: 0x1000, array step: index*0x80, index2*0x4 */
  uint8_t RESERVED_1[3840];
  uint32_t DIR[2]; /**< Direction registers, array offset: 0x2000, array step: 0x4 */
  uint8_t RESERVED_2[120];
  uint32_t MASK[2]; /**< Mask register, array offset: 0x2080, array step: 0x4 */
  uint8_t RESERVED_3[120];
  uint32_t PIN[2]; /**< Port pin register, array offset: 0x2100, array step: 0x4 */
  uint8_t RESERVED_4[120];
  uint32_t MPIN[2]; /**< Masked port register, array offset: 0x2180, array step:
                       0x4 */
  uint8_t RESERVED_5[120];
  uint32_t SET[2]; /**< Write: Set register for port Read: output bits for port,
                      array offset: 0x2200, array step: 0x4 */
  uint8_t RESERVED_6[120];
  uint32_t CLR[2]; /**< Clear port, array offset: 0x2280, array step: 0x4 */
  uint8_t RESERVED_7[120];
  uint32_t NOT[2]; /**< Toggle port, array offset: 0x2300, array step: 0x4 */
  uint8_t RESERVED_8[120];
  uint32_t DIRSET[2]; /**< Set pin direction bits for port, array offset:
                         0x2380, array step: 0x4 */
  uint8_t RESERVED_9[120];
  uint32_t DIRCLR[2]; /**< Clear pin direction bits for port, array offset:
                         0x2400, array step: 0x4 */
  uint8_t RESERVED_10[120];
  uint32_t DIRNOT[2]; /**< Toggle pin direction bits for port, array offset:
                         0x2480, array step: 0x4 */
} GPIO_Type;

/** GPIO - available ports on LPC84X */
typedef enum {
  GPIO_PORT0 = 0x0u,
  GPIO_PORT1 = 0x1u,
} GPIO_PORT_Type;

#include "nxp/LPC8XX/LPC8XX_gpio.h"

#endif
