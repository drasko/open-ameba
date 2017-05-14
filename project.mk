#=============================================
# SDK CONFIG
#=============================================
#USE_AT = 1
#USE_FATFS = 1
#USE_SDIOH = 1
#USE_POLARSSL = 1
#USE_P2P_WPS = 1
#USE_GCC_LIB = 1
USE_MBED = 1

ifndef USE_AT
USE_NEWCONSOLE = 1
USE_WIFI_API = 1
endif

#RTOSDIR=freertos_v8.1.2
RTOSDIR=freertos_v9.0.0
LWIPDIR=lwip_v1.4.1
include $(SDK_PATH)sdkset.mk
#compile
CFLAGS += -DLOGUART_STACK_SIZE=1024
#CFLAGS += -DDEFAULT_BAUDRATE=1562500
#=============================================
# User Files
#=============================================
#user main
ADD_SRC_C += project/src/user/main.c

