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
#ifndef TEST_GPIO_MASTER_HPP
#define TEST_GPIO_MASTER_HPP

#include <hw_tests_common.hpp>

// test output high operation
testStatus_t testGpioOutHighSetup(void);
testStatus_t testGpioOutHighExec(void);
testStatus_t testGpioOutHighClean(void);

// test output low operation
testStatus_t testGpioOutLowSetup(void);
testStatus_t testGpioOutLowExec(void);
testStatus_t testGpioOutLowClean(void);

// test input high operation
// test input low operation
// not needed as both code paths are tested by master and slave

// test input high pull up operation
testStatus_t testGpioPullHighSetup(void);
testStatus_t testGpioPullHighExec(void);
testStatus_t testGpioPullHighClean(void);

// test input low pull up operation
testStatus_t testGpioPullLowSetup(void);
testStatus_t testGpioPullLowExec(void);
testStatus_t testGpioPullLowClean(void);

// test output high glitch operation

#endif