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
#include <test_gpio_master.hpp>
#include <mcu_ll.h>
#include <board.hpp>

static testStatus_t masterTestGpioCleanup(void)
{
    // set to pulled up, as this is default reset behaviour.
    IoconPinSetMode(LPC_IOCON, TEST_GPIO_IN_IOCON, PIN_MODE_PULLUP);
    IoconPinSetMode(LPC_IOCON, TEST_GPIO_OUT_IOCON, PIN_MODE_PULLUP);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_GPIO_IN_GPIO, false);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_GPIO_OUT_GPIO, false);
    return testCompleted;
}

static testStatus_t masterTestGpioOutSetup(void)
{
    IoconPinSetMode(LPC_IOCON, TEST_GPIO_IN_IOCON, PIN_MODE_INACTIVE);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_GPIO_IN_GPIO, false);
    return testCompleted;
}


testStatus_t masterTestGpioLowSetup(void)
{
    return masterTestGpioOutSetup();
}

testStatus_t masterTestGpioLowExec(void)
{
    // wait and sense if the input is low
    timeDelay_t lowWait;
    timeDelayInit(lowWait, 10);
    while(timeDelayCheck(lowWait) != delayNotReached)
        ;
    if(GpioGetPinState(LPC_GPIO_PORT, 0, TEST_GPIO_IN_GPIO) == false)
        return testCompleted;
    else
        return testFailed;
}

testStatus_t masterTestGpioLowClean(void)
{
    return masterTestGpioCleanup;
}

testStatus_t masterTestGpioHighSetup(void)
{
    return masterTestGpioOutSetup();
}

testStatus_t masterTestGpioHighExec(void)
{
    // wait and sense if the input is high
    timeDelay_t lowWait;
    timeDelayInit(lowWait, 10);
    while(timeDelayCheck(lowWait) != delayNotReached)
        ;
    if(GpioGetPinState(LPC_GPIO_PORT, 0, TEST_GPIO_IN_GPIO) == true)
        return testCompleted;
    else
        return testFailed;
}

testStatus_t masterTestGpioHighClean(void)
{
    return masterTestGpioCleanup;
}
