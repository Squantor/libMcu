/*
MIT License

Copyright (c) 2019 Bart Bilos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <board.hpp>
#include <mcu_ll.h>

void boardInit(void)
{
    Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);
    // setup crystal functionality
    SWM_FixedPinEnable(SWM_FIXED_XTALIN, true);
    SWM_FixedPinEnable(SWM_FIXED_XTALOUT, true);
    Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);
    // setup IO control
    Clock_EnablePeriphClock(SYSCTL_CLOCK_IOCON);
    // setup pins for crystal oscillator
    IOCON_PinSetMode(LPC_IOCON, IOCON_PIO8, PIN_MODE_INACTIVE);
    IOCON_PinSetMode(LPC_IOCON, IOCON_PIO9, PIN_MODE_INACTIVE);
    // setup LED pins
    IOCON_PinSetMode(LPC_IOCON, ALIVE_LED_IOCON, PIN_MODE_INACTIVE);
    IOCON_PinSetMode(LPC_IOCON, STATE_LED_IOCON, PIN_MODE_INACTIVE);
    Clock_DisablePeriphClock(SYSCTL_CLOCK_IOCON);
    // GPIO pins setup
    GPIO_Init(LPC_GPIO_PORT);
    GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, STATE_LED_PIN);
    GPIO_SetPinState(LPC_GPIO_PORT, 0, STATE_LED_PIN, true);
    GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, ALIVE_LED_PIN);
    GPIO_SetPinState(LPC_GPIO_PORT, 0, ALIVE_LED_PIN, false);
    //SetupXtalClocking();
    //SystemCoreClockUpdate();
    // systick configuration
    //SysTick_Config(SystemCoreClock / TICKS_PER_S);
    SysTick_Config(12000000 / TICKS_PER_S);
}

void toggleAliveLed(void)
{
    GPIO_SetPinToggle(LPC_GPIO_PORT, 0, ALIVE_LED_PIN);
}

void toggleStatusLed(void)
{
    GPIO_SetPinToggle(LPC_GPIO_PORT, 0, STATE_LED_PIN);
}

void offStatusLed(void)
{
    GPIO_SetPinState(LPC_GPIO_PORT, 0, STATE_LED_PIN, true);
}