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
LPC800 series common switch matrix control registers, defines and
functions.
*/
#ifndef LPC8XX_SWM_H
#define LPC8XX_SWM_H

/**
 * @brief   Enable fixed SWM pin functions
 * @param   peripheral  SWM peripheral to use
 * @param   function    Function to assign
 * @param   pin         Pin to assign the function to
 * @return  Nothing
 */
static inline void SwmMovablePinAssign(SWM_Type *peripheral, SWM_MOVABLE_Type function, SWM_PORTPIN_Type pin) {
  int index = function >> 2;
  int shiftIndex = ((function & 0x3) << 3);
  uint32_t mask = ~(0xFF << shiftIndex);
  peripheral->PINASSIGN[index] = (peripheral->PINASSIGN[index] & mask) | (pin << shiftIndex);
}

/**
 * @brief   Enable fixed SWM pin functions
 * @param   peripheral  SWM peripheral to use
 * @param   setting0    setting for PINENABLE0 register
 * @return  Nothing
 */
static inline void swmEnableFixedPin(SWM_Type *peripheral, uint32_t setting0) {
  uint32_t pinEnable0 = peripheral->PINENABLE0;
  pinEnable0 &= ~setting0;
  peripheral->PINENABLE0 = pinEnable0;
}

/**
 * @brief   Disable fixed SWM pin functions
 * @param   peripheral  SWM peripheral to use
 * @param   setting0    setting for PINENABLE0 register
 * @return  Nothing
 */
static inline void swmDisableFixedPin(SWM_Type *peripheral, uint32_t setting0) {
  uint32_t pinEnable0 = peripheral->PINENABLE0;
  pinEnable0 |= setting0;
  peripheral->PINENABLE0 = pinEnable0;
}

#endif