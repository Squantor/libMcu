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
LPC800 series common switch matrix control
*/
#ifndef LPC8XX_SWM_H
#define LPC8XX_SWM_H

static inline void SWM_Init(void)
{
    Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);
}

static inline void SWM_Deinit(void)
{
    Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);
}

void SWM_MovablePinAssign(CHIP_SWM_PIN_MOVABLE_T movable, uint8_t assign);

void SWM_FixedPinEnable(CHIP_SWM_PIN_FIXED_T pin, bool enable);

static inline void SWM_EnableFixedPin(CHIP_SWM_PIN_FIXED_T pin)
{
    LPC_SWM->PINENABLE0 &= ~((1 << (uint32_t) pin) | SWM_PINENABLE0_RESERVED);
}

static inline void SWM_DisableFixedPin(CHIP_SWM_PIN_FIXED_T pin)
{
    LPC_SWM->PINENABLE0 = (1 << (uint32_t) pin) | (LPC_SWM->PINENABLE0 & ~SWM_PINENABLE0_RESERVED);
}

static inline bool SWM_IsEnabled(CHIP_SWM_PIN_FIXED_T pin)
{
    return (bool) ((LPC_SWM->PINENABLE0 & (1 << (uint32_t) pin)) == 0);
}

#endif