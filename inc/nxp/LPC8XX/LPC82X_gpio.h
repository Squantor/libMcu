/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC820 series GPIO registers, defines and functions.
*/

#ifndef LPC82X_GPIO_H
#define LPC82X_GPIO_H

typedef volatile struct {
  uint8_t B[128]
           [32]; /* Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
  uint32_t W[32][32]; /* Word pin registers port 0 to n */
  uint32_t DIR[32];   /* Direction registers port n */
  uint32_t MASK[32];  /* Mask register port n */
  uint32_t PIN[32];   /* Portpin register port n */
  uint32_t MPIN[32];  /* Masked port register port n */
  uint32_t
      SET[32]; /* Write: Set register for port n Read: output bits for port n */
  uint32_t CLR[32];    /* Clear port n */
  uint32_t NOT[32];    /* Toggle port n */
  uint32_t DIRSET[32]; /* Set Direction */
  uint32_t DIRCLR[32]; /* Clear Direction */
  uint32_t DIRNOT[32]; /* Toggle Direction */
} GPIO_Type;

/** GPIO - available ports on LPC82X */
typedef enum {
  GPIO_PORT0 = 0x0u,
} GPIO_PORT_Type;

#include "nxp/LPC8XX/LPC82X_gpio_old.h"
#include "nxp/LPC8XX/LPC8XX_gpio.h"
#include "nxp/LPC8XX/LPC8XX_gpio_old.h"

#endif