# LibMcuLL test program for LPC812, master side
This project contains tests for libMcuLl targeting the LPC812 microcontroller, this is the master side of the tests.
## Checking out
use ```git clone --recurse-submodules https://github.com/Squantor/$(PROJECT).git``` to clone the repository and its submodules.
## Compiling
This project uses gnu make as its build system on a Linux platform. There are two build targets: release and debug. Release builds with optimizations and minimal debugging information. Debug builds with no optimization and full debug information.
```
$ make debug
$ make release
```
### Embedded targets
For debugging on embedded targets, the [Black Magic Probe](https://github.com/blacksphere/blackmagic/wiki) is used, scripts to use this debugger are present in the ```gdb_scripts``` directory. make can be used to invoke debugging:
```
make gdbusbdebug
make gdbusbrelease
```
This will build, if needed, the debug or release build respectivly and load it into the target.
```
make tpwrdisable
make tpwrenable
```
The black magic probe is capable of powering the target, these commands enable/disable this function.
### Depedencies
This program depends TODO. This is automatically checked out when using ```git clone --recurse-submodules```.
## Usage
To use the software you need the following hardware:
* [Black magic probe](https://github.com/blacksphere/blackmagic)
* LPC812 test board, see HSI for more information on connections
# Hardware
The hardware consists of two LPC812 microcontroller breakout boards connected to eachother. One controller is the slave controller, another the master controller. The master initiates each tests and the slave follows.

Communication between the slave and the master consists of one output pin and one input pin, we call them ```test_sync_out``` and ```test_sync_in``` respectivly. 

Testing peripherals would require connections too:
* I2C would require a connection between SDA and SCL on the master and slave, the master would be the I2C master and the slave would respond in slave mode.
* UART would require a cross connection between TXD and RXD.
* SPI would require a cross connection between MISO and MOSI
* To test an ADC, a PWM output from the master would need to be filtered to create a variable voltage.
# HSI
Hardware Software interface
## Test sychronisation pins
Two GPIOS are present for communication between master and slave: ```test_sync_out``` and ```test_sync_in``` respectivly. On the LPC812 test pins ```GPIO0_17``` and ```GPIO0_14``` are allocated for this purpose. The whole synchronisation process is as follows:
1. Both pins are low value when a test in progress. When the master is done with the test, it will first cleanup the test then it will set its test_sync_out to high. 
2. As test_sync_out from the master is connected to test_sync_in to the slave, it will detect this and start its cleanup of the test. When done is will set its test_sync_out to high.
3. The master now will detect its test_sync_in is high, now it can perform setup of the next test, when this is done it will set its test_sync_out to low.
4. The slave detects that its test_sync_in is low, it will perform the setup of the next test, when this is done it will set its test_sync_out to low.
5. as both pins are now low, the master can start its next test.
This process will repeats until all tests have been executed.
## I2C
## UART
## Pin connections
* ```PIO0_5```: Microcontroller reset, default setting, pulled up with 47K
* ```PIO0_3```: Microcontroller SWCLK, default setting, pulled down with 47K
* ```PIO0_2```: Microcontroller SWDIO, default setting, pulled up with 47K
* ```PIO0_8```: Crystal oscillator input, setup and started on startup
* ```PIO0_9```: Crystal oscillator output, setup and started on startup
* ```PIO0_12```: debug UART TXD, connected to FTDI cable RXD, set as output
* ```PIO0_13```: debug UART RXD, connected to FTDI cable TXD, set as input
* ```PIO0_17```: Test Synchronisation output, connected to slave test sync input, set as output
* ```PIO0_14```: Test Synchronisation intput, connected to slave test sync output, set as input
* ```PIO0_10```: test I2C SDA, connected to I2C SDA of slave, pulled up externally with 2.2K
* ```PIO0_11```: test I2C SCL, connected to I2C SCL of slave, pulled up externally with 2.2K
* ```PIO0_16```: test UART TXD, connected to the UART RXD of the slave, set as output
* ```PIO0_15```: test UART RXD, connected to the UART TXD of the slave, set as input
* ```PIO0_6```: VDDCMP, connected to 3.3V as reference for the comparator
* ```PIO0_0```: ACMP_I1, comparator input, connected to PWM DAC of the slave
* ```PIO0_7```: PWM_DAC, PWM output, filtered with 1K 10uF capacitor, creating a 10mS filtering constant

# Software
## Tests
Each test entry contains three function pointers ```testSetup```, ```testExecute```, ```testTeardown```.
### Peripheral tests
We generally try to test as many peripherals where feasable, this entails, GPIO, UART, I2C, SPI and more. This is highly dependent on what microcontroller. If it has two variants of a peripheral and they differ in operation, they should be tested individually.

We test all the microcontroller peripherals in all its modes:
* Polling based, simplest way
* Interrupt based
* if available DMA based
* if available ROM based, if there are multiple variants like interrupt/dma based, these are tested too.
# TODO

