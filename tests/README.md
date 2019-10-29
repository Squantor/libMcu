# LibMcuLl test directory
Testing LibMcuLl is a bit complicated as there is a lot of depedencies on the microcontroller hardware. This makes unittesting difficult and you would be testing your own implementation and not the actual hardware.
This directory holds a bunch of projects that will test the LibMcuLl for the specific controller. One test per controller type and not per package.
## Testing structure
Each microcontroller test consists of two parts. One controller will act like the test slave and one the test master. This is useful for testing bus hardware like I2C, SPI etcetera. The test slave will instantiate a slave SPI or I2C device and exercise the code of LibMcuLl, the master hardware is often used but the slave parts not so much.
## Testing Hardware
As mentioned there are two hardware boards connected to eachother. Specific connections are mentioned per project but they all have a few things in common:
* Two boards with the same controller connected to eachother
* Test initiate handshake, two lines, test ready and test acknowledge will progress each test. This also tests the GPIO library per controller.
* Busses connected to eachother where applicable, for example I2C or SPI
* ADC's are usually tested with PWM signals that are filtered with a RC circuit or if available to a DAC.
## Testing Software
Each peripheral test is put in a separate file.