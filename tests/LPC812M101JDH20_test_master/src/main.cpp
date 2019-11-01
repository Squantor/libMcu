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

#include <mcu_ll.h>
#include <board.hpp>
#include <systick.hpp>
#include <test_sync.hpp>

volatile int var;


void testsPassed(void)
{
    __BKPT(0);
    while(1)
        ;
}

void testsFailed(void)
{
    __BKPT(1);
    while(1)
        ;
}

int main()
{
    int result = 0;
    timeDelay_t testDelay;
    boardInit();
    // Setup test synchronisation pins
    testSyncInit();
    
    while(1)
    {
        testSyncSetup(SEC2TICKS(0.1));
        timeDelayInit(testDelay, SEC2TICKS(0.1));
        while(timeDelayCheck(testDelay) == delayNotReached)
            ;
        testSyncStart(SEC2TICKS(0.1));
        timeDelayInit(testDelay, SEC2TICKS(0.1));
        while(timeDelayCheck(testDelay) == delayNotReached)
            ;
    }
}
