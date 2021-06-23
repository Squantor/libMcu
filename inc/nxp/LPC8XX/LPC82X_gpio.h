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

typedef struct {
    __IO uint8_t  B[128][32];   /* Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
    __IO uint32_t W[32][32];    /* Word pin registers port 0 to n */
    __IO uint32_t DIR[32];      /* Direction registers port n */
    __IO uint32_t MASK[32];     /* Mask register port n */
    __IO uint32_t PIN[32];      /* Portpin register port n */
    __IO uint32_t MPIN[32];     /* Masked port register port n */
    __IO uint32_t SET[32];      /* Write: Set register for port n Read: output bits for port n */
    __O  uint32_t CLR[32];      /* Clear port n */
    __O  uint32_t NOT[32];      /* Toggle port n */
    __O  uint32_t DIRSET[32];   /* Set Direction */
    __O  uint32_t DIRCLR[32];   /* Clear Direction */
    __O  uint32_t DIRNOT[32];   /* Toggle Direction */
} LPC_GPIO_T;

#endif