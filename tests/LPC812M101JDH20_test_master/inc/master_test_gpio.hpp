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

// check if we can set a low level and sense it
testStatus_t masterTestGpioLowSetup(void);
testStatus_t masterTestGpioLowExec(void);
testStatus_t masterTestGpioLowClean(void);

// check if we can set high level and sense it
testStatus_t masterTestGpioHighSetup(void);
testStatus_t masterTestGpioHighExec(void);
testStatus_t masterTestGpioHighClean(void);



// check if we can pull up and sense it
// check if we can pull down and sense it
// see datasheet/includes what we can test more like glitches


#endif