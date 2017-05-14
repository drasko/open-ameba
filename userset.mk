#=============================================
# User defined
#=============================================
SDK_PATH ?= sdk/
#GCC_PATH = d:/MCU/GNU_Tools_ARM_Embedded/5.2_2015q4/bin/# + or set in PATH
#OPENOCD_PATH = d:/MCU/OpenOCD/bin/# + or set in PATH
TOOLS_PATH ?= $(SDK_PATH)component/soc/realtek/8195a/misc/iar_utility/common/tools/
FLASHER_TYPE = OCD
FLASHER_PATH ?= $(SDK_PATH)flasher/
