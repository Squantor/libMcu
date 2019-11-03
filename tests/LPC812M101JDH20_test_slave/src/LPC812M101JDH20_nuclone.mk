# update per change V0002
# board specific settings
PLATFORM = LPC812
MCU = MCU_LPC812M101JDH20
C_SOURCES +=
CXX_SOURCES += ../common/src/$(BOARD).cpp
S_SOURCES +=
DEFINES += -D$(BOARD) -D$(MCU)
INCLUDES += -Iinc -I../../inc
ALIBS +=
RLIBS +=
DLIBS +=
ALIBDIR +=
RLIBDIR += 
DLIBDIR += 

#custom build rules
pre-clean:

pre-release:

pre-debug:

#project hardware specific commands
gdbusbdebug: debug
	$(TOOLCHAIN_PREFIX)$(GDB) -x ./gdb_scripts/bmpUSBdebug.txt

gdbusbrelease: release
	$(TOOLCHAIN_PREFIX)$(GDB) -x ./gdb_scripts/bmpUSBrelease.txt

tpwrdisable:
	$(TOOLCHAIN_PREFIX)$(GDB) -x ./gdb_scripts/bmpusb_tpwr_disable.txt

tpwrenable:
	$(TOOLCHAIN_PREFIX)$(GDB) -x ./gdb_scripts/bmpusb_tpwr_enable.txt

.PHONY: pre-clean pre-release pre-debug gdbusbdebug gdbusbrelease tpwrdisable tpwrenable
