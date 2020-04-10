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
#include <hw_tests_common.hpp>
#include <master_test_gpio.hpp>

/*
The functions are being tested by both the slave and master
 */
const testEntry_t testListMaster[] = 
{
    // check if we can set a low level and sense it
    {masterTestGpioLowSetup, masterTestGpioLowExec, masterTestGpioLowClean},
    // check if we can set high level and sense it
    {masterTestGpioHighSetup, masterTestGpioHighExec, masterTestGpioHighClean},
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
    timeDelay_t resetTimer;
    // reset the other side controller
    timeDelayInit(resetTimer, 10);
    resetPinSet(false);
    // wait
    while(timeDelayCheck(resetTimer) != delayNotReached)
        ;
    resetPinSet(true);
    // wait again
    timeDelayInit(resetTimer, 100);
    while(timeDelayCheck(resetTimer) != delayNotReached)
        ;
    // we prepare by going to the ready state
    // so we can enter the loop ready to setup
    testSyncRequestSetup();
    int i = 0;
    do
    {
        // setup test
        if(testListMaster[i].setup() != testCompleted)
            testsFailed();
        testSyncRequestStart();
        if(testListMaster[i].execute() != testCompleted)
            testsFailed();
        testSyncRequestSetup();
        if(testListMaster[i].cleanup() != testCompleted)
            testsFailed();
        i++;
    // infinite loop just to test
    //} while(1);
    } while(testListMaster[i].setup != NULL);
    
    testsPassed();
}
