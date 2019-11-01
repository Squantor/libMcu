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

/*
Module to keep the tests in sync by using two GPIO pins, one output and one input.
Step plan to request a new test is as follows:
Output 0, input 0: Test in progress
Output 1, input 0: Test done from master side, requesting next test
Output 1, input 1: Slave is ready for next test
Do our setup as the slave has done its setup too
Output 0, input 1: Master is ready for next test
Output 0, input 0: Slave acknowledges that master is ready for next test.
*/

#include <test_sync.hpp>
#include <mcu_ll.h>

void testSyncInit()
{
    GpioSetPinOutLow(LPC_GPIO_PORT, 0, TEST_SYNC_OUT);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_SYNC_OUT, true);
    GpioSetPinDir(LPC_GPIO_PORT, 0, TEST_SYNC_IN, false);
}

testSyncResult_t testSyncSetup(timeTicks timeout)
{
    timeDelay_t timeoutDelay;
    timeDelayInit(timeoutDelay, timeout);
    
    // check if we are in initial state, out:0, in:0
    if(GpioGetPinState(LPC_GPIO_PORT, 0, TEST_SYNC_IN) == true)
        return testSyncInvalid;
    // request that we go to setup state
    GpioSetPinOutHigh(LPC_GPIO_PORT, 0, TEST_SYNC_OUT);
    // wait for acknowledge/timeout
    while(timeDelayCheck(timeoutDelay) == delayNotReached && 
        GpioGetPinState(LPC_GPIO_PORT, 0, TEST_SYNC_IN) == 0)
        ;
    // report if we timed out
    if(timeDelayCheck(timeoutDelay) != delayNotReached)
        return testSyncTimeout;
    else  
        return testSyncReady;
}

testSyncResult_t testSyncStart(timeTicks timeout)
{
    timeDelay_t timeoutDelay;
    timeDelayInit(timeoutDelay, timeout);
    
    // check if the slave is ready we are in initial state, out:0, in:0
    if(GpioGetPinState(LPC_GPIO_PORT, 0, TEST_SYNC_IN) == false)
        return testSyncInvalid;
    // request that we go to test state
    GpioSetPinOutHigh(LPC_GPIO_PORT, 0, TEST_SYNC_OUT);
    // wait for acknowledge/timeout
    while(timeDelayCheck(timeoutDelay) == delayNotReached && 
        GpioGetPinState(LPC_GPIO_PORT, 0, TEST_SYNC_IN) == 1)
        ;
    // report if we timed out
    if(timeDelayCheck(timeoutDelay) != delayNotReached)
        return testSyncTimeout;
    else  
        return testSyncReady;
}