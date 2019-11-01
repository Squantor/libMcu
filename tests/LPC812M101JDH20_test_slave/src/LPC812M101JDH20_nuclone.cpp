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
#include <LPC812M101JDH20_nuclone.hpp>
#include <mcu_ll.h>

// current CPU clock
uint32_t SystemCoreClock;
// crystal frequency
const uint32_t OscRateIn = 12000000;
// external oscillator frequency
const uint32_t ExtRateIn = 0;

/* Setup crystal clocking */
void SetupXtalClocking(void)
{
    /* EXT oscillator < 15MHz */
    ClockSetPLLBypass(false, false);

    /* Turn on the SYSOSC by clearing the power down bit */
    SysctlPowerUp(SYSCTL_SLPWAKE_SYSOSC_PD);

    /* Select the PLL input to the external oscillator */
    ClockSetSystemPLLSource(SYSCTL_PLLCLKSRC_SYSOSC);

    /* Setup FLASH access to 2 clocks (up to 30MHz) */
    FmcSetFlashAccess(FLASHTIM_30MHZ_CPU);

    /* Power down PLL to change the PLL divider ratio */
    SysctlPowerDown(SYSCTL_SLPWAKE_SYSPLL_PD);

    /* Configure the PLL M and P dividers */
    /* Setup PLL for main oscillator rate ((FCLKIN = 12MHz) * 5)/2 = 30MHz */
    ClockSetupSystemPLL(4, 1);

    /* Turn on the PLL by clearing the power down bit */
    SysctlPowerUp(SYSCTL_SLPWAKE_SYSPLL_PD);

    /* Wait for PLL to lock */
    while (!ClockIsSystemPLLLocked()) {}

    ClockSetSysClockDiv(2);

    /* Set main clock source to the system PLL. This will drive 30MHz
       for the main clock and 30MHz for the system clock */
    ClockSetMainClockSource(SYSCTL_MAINCLKSRC_PLLOUT);
}

void boardInit(void)
{
    ClockEnablePeriphClock(SYSCTL_CLOCK_SWM);
    // setup crystal functionality
    SwmFixedPinEnable(SWM_FIXED_XTALIN, true);
    SwmFixedPinEnable(SWM_FIXED_XTALOUT, true);
    ClockDisablePeriphClock(SYSCTL_CLOCK_SWM);
    // setup IO control
    ClockEnablePeriphClock(SYSCTL_CLOCK_IOCON);
    // setup pins for crystal oscillator
    IoconPinSetMode(LPC_IOCON, IOCON_PIO8, PIN_MODE_INACTIVE);
    IoconPinSetMode(LPC_IOCON, IOCON_PIO9, PIN_MODE_INACTIVE);
    ClockDisablePeriphClock(SYSCTL_CLOCK_IOCON);
    // GPIO pins setup
    GpioInit(LPC_GPIO_PORT);
    SetupXtalClocking();
    SystemCoreClock = ClockGetSystemClockRate();
    // systick configuration
    SysTick_Config(SystemCoreClock / TICKS_PER_S);
}