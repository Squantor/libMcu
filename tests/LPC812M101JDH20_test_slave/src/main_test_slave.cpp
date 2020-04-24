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
#include <cstddef>
#include <mcu_ll.h>
#include <board.hpp>
#include <systick.hpp>
#include <test_sync.hpp>
#include <slave_test_gpio.hpp>

const testEntry_t testListSlave[] = 
{
    // check if we can set a low level and sense it
    {slaveTestGpioLowSetup, slaveTestGpioLowExec, slaveTestGpioLowClean},
    // check if we can set high level and sense it
    {slaveTestGpioHighSetup, slaveTestGpioHighExec, slaveTestGpioHighClean},
    // check if we can pull up and sense it
    // check if we can pull down and sense it
    {NULL, NULL, NULL}
};


void testsPassed(void)
{
    __BKPT(0);
}

void testsFailed(void)
{
    __BKPT(1);
}

int main()
{
    boardInit();
    testSyncInit();
    resetPinSet(false);
    timeDelaySimple(10);
    resetPinSet(true);
    timeDelaySimple(10);
    int i = 0;
    do
    {
        if(testListSlave[i].setup() != testCompleted)
            testsFailed();
        testSyncWaitStart();
        if(testListSlave[i].execute() != testCompleted)
            testsFailed();
        testSyncWaitSetup();
        if(testListSlave[i].cleanup() != testCompleted)
            testsFailed();
        i++;
        if(testListSlave[i].setup == NULL)
            i = 0;
    // for testing purposes, lets go for an infinite loop, okay?
    //} while(1);
    } while(testListSlave[i].setup != NULL);
    //testsPassed();
}
