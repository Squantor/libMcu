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
#include <test_gpio_slave.hpp>
#include <mcu_ll.h>
#include <board.hpp>


static testStatus_t cleanupGpioTests(void)
{
    // set to pulled up, as this is default reset behaviour.
    IoconPinSetMode(LPC_IOCON, TEST_GPIO_IN_IOCON, PIN_MODE_PULLUP);
    IoconPinSetMode(LPC_IOCON, TEST_GPIO_OUT_IOCON, PIN_MODE_PULLUP);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_GPIO_IN_GPIO, false);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_GPIO_OUT_GPIO, false);
    return testCompleted;
}

static testStatus_t outSetup(PIN_MODE_T mode,bool output, bool setting)
{
    IoconPinSetMode(LPC_IOCON, TEST_GPIO_OUT_IOCON, mode);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_GPIO_OUT_GPIO, output);
    GpioSetPinState(LPC_GPIO_PORT, 0, TEST_GPIO_OUT_GPIO, setting);
    return testCompleted;
}

testStatus_t testGpioOutHighSetup(void)
{   
    return outSetup(PIN_MODE_INACTIVE, true, true);
}

testStatus_t testGpioOutHighExec(void)
{    

}

testStatus_t testGpioOutHighClean(void)
{    
    return cleanupGpioTests();
}

testStatus_t testGpioOutLowSetup(void)
{
    return outSetup(PIN_MODE_INACTIVE, true, false);
}

testStatus_t testGpioOutLowExec(void)
{
    
}

testStatus_t testGpioOutLowClean(void)
{
    return cleanupGpioTests();
}

testStatus_t testGpioPullHighSetup(void)
{
    return outSetup(PIN_MODE_PULLUP, false, true);
}

testStatus_t testGpioPullHighExec(void)
{

}

testStatus_t testGpioPullHighClean(void)
{
    return cleanupGpioTests();
}

testStatus_t testGpioPullLowSetup(void)
{
    return outSetup(PIN_MODE_PULLDN, false, true);
}

testStatus_t testGpioPullLowExec(void)
{

}

testStatus_t testGpioPullLowClean(void)
{
    return cleanupGpioTests();
}