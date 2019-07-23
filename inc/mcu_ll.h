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
Main entry point, one giant list of microcontroller targets that are supported
*/
#ifndef MCU_LL_H
#define MCU_LL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MCU_LPC824M201JHI33)
#warning "Microcontroller LPC824M201JHI33 support is WIP"
#elif defined(MCU_LPC824M201JDH20)
#warning "Microcontroller LPC824M201JDH20 support is WIP"
#elif defined(MCU_LPC812M101JDH20)
#warning "Microcontroller LPC812M101JDH20 support is WIP"
#elif defined(MCU_LPC812M101JTB16)
#warning "Microcontroller LPC812M101JTB16 support is WIP"
#else
#error "Unknown or unsupported microcontroller defined, use MCU_Microcontroller"
#endif

#ifdef __cplusplus
}
#endif

#endif