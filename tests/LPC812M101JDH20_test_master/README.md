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
Two GPIOS are present for communication between master and slave: ```test_sync_out``` and ```test_sync_in``` respectivly. This process goes as following:
1. Both pins are low value when a test in progress. When the master is done with the test, it will first cleanup the test then it will set its test_sync_out to high. 
2. As test_sync_out from the master is connected to test_sync_in to the slave, it will detect this and start its cleanup of the test. When done is will set its test_sync_out to high.
3. The master now will detect its test_sync_in is high, now it can perform setup of the next test, when this is done it will set its test_sync_out to low.
4. The slave detects that its test_sync_in is low, it will perform the setup of the next test, when this is done it will set its test_sync_out to low.
5. as both pins are now low, the master can start its next test.
This process will repeats until all tests have been executed.
## I2C
## UART
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

