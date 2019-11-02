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
#include <board.hpp>

void testSyncInit()
{
    syncSetupGpio();
}

testSyncResult_t testSyncRequestSetup(void)
{
    // request that we go to setup state
    syncOutSet(true);
    // wait for acknowledge
    while(syncInGet() == true)
        ;
    return testSyncReady;
}

testSyncResult_t testSyncRequestStart(void)
{ 
    // request that we go to test state
    syncOutSet(false);
    // wait for acknowledge/timeout
    while(syncInGet() == false)
        ;
    return testSyncReady;
}

testSyncResult_t testSyncWaitSetup(void)
{
    // wait for test setup
    while(syncInGet() == true)
        ;
    // acknowledge we are ready to go to setup
    syncOutSet(true);
    return testSyncReady;
}

testSyncResult_t testSyncWaitStart(void)
{
    // wait for test start
    while(syncInGet() == false)
        ;
    // acknowledge we are ready to start
    syncOutSet(false);
    return testSyncReady;
}