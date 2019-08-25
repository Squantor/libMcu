# LibMcuLL example program for LPC812 MAX
This project contains a example program for the LPC812 MAX board and is intended as an example how to use LibMcuLL for the LPC812 microcontroller.
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
* [LPC812 MAX](https://www.embeddedartists.com/products/lpc812-max/)
# TODO
The following tasks are still open:
* create a HSI (Hardware Software Interface) for the LPC812 MAX
* starting implementing more and more of the microcontroller features