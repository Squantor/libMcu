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
LPC810 series common analog comparator registers,definitions and
functions.
*/
#ifndef LPC81X_ACMP_H
#define LPC81X_ACMP_H

/* Analog Comparator positive input values */
typedef enum ACMP_POS_INPUT {
  ACMP_POSIN_VLO = (0 << 8),     /* Voltage ladder output */
  ACMP_POSIN_ACMP_I1 = (1 << 8), /* ACMP_I1 pin */
  ACMP_POSIN_ACMP_I2 = (2 << 8), /* ACMP_I2 pin */
  ACMP_POSIN_ACMP_I3 = (3 << 8), /* ACMP_I3 pin */
  ACMP_POSIN_ACMP_I4 = (4 << 8), /* ACMP_I4 pin */
  ACMP_POSIN_INT_REF = (6 << 8), /* Internal reference voltage */
} ACMP_POS_INPUT_T;

/* Analog Comparator negative input values */
typedef enum ACMP_NEG_INPUT {
  ACMP_NEGIN_VLO = (0 << 11),     /* Voltage ladder output */
  ACMP_NEGIN_ACMP_I1 = (1 << 11), /* ACMP_I1 pin */
  ACMP_NEGIN_ACMP_I2 = (2 << 11), /* ACMP_I2 pin */
  ACMP_NEGIN_ACMP_I3 = (3 << 11), /* ACMP_I3 pin */
  ACMP_NEGIN_ACMP_I4 = (4 << 11), /* ACMP_I4 pin */
  ACMP_NEGIN_INT_REF = (6 << 11)  /* Internal reference voltage */
} ACMP_NEG_INPUT_T;

#include "nxp/LPC8XX/LPC8XX_acmp.h"

#endif