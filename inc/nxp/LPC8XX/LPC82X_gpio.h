/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/
/* 
LPC820 series GPIO registers, defines and functions.
*/

#ifndef LPC82X_GPIO_H
#define LPC82X_GPIO_H

typedef struct {
    __IO uint8_t  B[128][32];    /* Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
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

static inline void GPIO_SetPinDIROutput(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->DIRSET[port] = 1UL << pin;
}

static inline void GPIO_SetPinDIRInput(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->DIRCLR[port] = 1UL << pin;
}

static inline void GPIO_TogglePinDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->DIRNOT[port] = 1UL << pin;
}

static inline void GPIO_SetPortDIROutput(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask)
{
    pGPIO->DIRSET[port] = pinMask;
}

static inline void GPIO_SetPortDIRInput(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask)
{
    pGPIO->DIRCLR[port] = pinMask;
}

static inline void GPIO_TogglePortDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask)
{
    pGPIO->DIRNOT[port] = pinMask;
}

// include common functions
#include <nxp/LPC8XX/LPC8XX_gpio.h>

#endif