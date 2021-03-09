#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=arm-none-eabi-gcc
CCC=arm-none-eabi-g++
CXX=arm-none-eabi-g++
FC=gfortran
AS=arm-none-eabi-gcc

# Macros
CND_PLATFORM=CodeSourceryARM-Linux-x86
CND_DLIB_EXT=so
CND_CONF=SC-KIT
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/834592578/stm32f2x7_eth.o \
	${OBJECTDIR}/_ext/540162733/misc.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_adc.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_can.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_dac.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_dma.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_exti.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_flash.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_fsmc.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_gpio.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_i2c.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_rcc.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_sdio.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_spi.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_syscfg.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_tim.o \
	${OBJECTDIR}/_ext/540162733/stm32f2xx_usart.o \
	${OBJECTDIR}/_ext/860902683/lcd_st7565p.o \
	${OBJECTDIR}/_ext/860902683/stm32_eval_i2c_ee.o \
	${OBJECTDIR}/_ext/860902683/stm32_eval_sdio_sd.o \
	${OBJECTDIR}/_ext/860902683/stm32_eval_spi_accel.o \
	${OBJECTDIR}/_ext/1557409105/sckit_eval_eth.o \
	${OBJECTDIR}/_ext/1085738613/stm32_eval.o \
	${OBJECTDIR}/_ext/513150005/crc16.o \
	${OBJECTDIR}/_ext/513150005/sckit_debug.o \
	${OBJECTDIR}/_ext/513150005/serial_driver.o \
	${OBJECTDIR}/_ext/513150005/syscalls.o \
	${OBJECTDIR}/_ext/1939945793/ethernetif.o \
	${OBJECTDIR}/_ext/1842557796/api_lib.o \
	${OBJECTDIR}/_ext/1842557796/api_msg.o \
	${OBJECTDIR}/_ext/1842557796/err.o \
	${OBJECTDIR}/_ext/1842557796/netbuf.o \
	${OBJECTDIR}/_ext/1842557796/netdb.o \
	${OBJECTDIR}/_ext/1842557796/netifapi.o \
	${OBJECTDIR}/_ext/1842557796/sockets.o \
	${OBJECTDIR}/_ext/1842557796/tcpip.o \
	${OBJECTDIR}/_ext/1284775829/def.o \
	${OBJECTDIR}/_ext/1284775829/dhcp.o \
	${OBJECTDIR}/_ext/1284775829/dns.o \
	${OBJECTDIR}/_ext/1284775829/init.o \
	${OBJECTDIR}/_ext/1462834207/autoip.o \
	${OBJECTDIR}/_ext/1462834207/icmp.o \
	${OBJECTDIR}/_ext/1462834207/igmp.o \
	${OBJECTDIR}/_ext/1462834207/inet.o \
	${OBJECTDIR}/_ext/1462834207/inet_chksum.o \
	${OBJECTDIR}/_ext/1462834207/ip.o \
	${OBJECTDIR}/_ext/1462834207/ip_addr.o \
	${OBJECTDIR}/_ext/1462834207/ip_frag.o \
	${OBJECTDIR}/_ext/1284775829/mem.o \
	${OBJECTDIR}/_ext/1284775829/memp.o \
	${OBJECTDIR}/_ext/1284775829/netif.o \
	${OBJECTDIR}/_ext/1284775829/pbuf.o \
	${OBJECTDIR}/_ext/1284775829/raw.o \
	${OBJECTDIR}/_ext/1284775829/stats.o \
	${OBJECTDIR}/_ext/1284775829/sys.o \
	${OBJECTDIR}/_ext/1284775829/tcp.o \
	${OBJECTDIR}/_ext/1284775829/tcp_in.o \
	${OBJECTDIR}/_ext/1284775829/tcp_out.o \
	${OBJECTDIR}/_ext/1284775829/timers.o \
	${OBJECTDIR}/_ext/1284775829/udp.o \
	${OBJECTDIR}/_ext/1183208004/etharp.o \
	${OBJECTDIR}/_ext/1360937237/fs.o \
	${OBJECTDIR}/_ext/1360937237/httpd.o \
	${OBJECTDIR}/_ext/1360937237/httpd_cgi_ssi.o \
	${OBJECTDIR}/_ext/1360937237/main.o \
	${OBJECTDIR}/_ext/1360937237/netconf.o \
	${OBJECTDIR}/_ext/1360937237/stm32f2x7_eth_bsp.o \
	${OBJECTDIR}/_ext/1360937237/stm32f2xx_it.o \
	${OBJECTDIR}/_ext/1360937237/system_stm32f2xx.o \
	${OBJECTDIR}/startup_stm32f2xx.o


# C Compiler Flags
CFLAGS=-mthumb -mcpu=cortex-m3 -ggdb -Wextra -ffunction-sections -fdata-sections -O1

# CC Compiler Flags
CCFLAGS=-mthumb -mcpu=cortex-m3 -ggdb -Wextra -ffunction-sections -fdata-sections -O1
CXXFLAGS=-mthumb -mcpu=cortex-m3 -ggdb -Wextra -ffunction-sections -fdata-sections -O1

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=-c -mthumb -mcpu=cortex-m3 -g3 -Wa,--warn -x assembler-with-cpp

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/Application.elf

${CND_DISTDIR}/${CND_CONF}/Application.elf: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/Application.elf ${OBJECTFILES} ${LDLIBSOPTIONS} -mthumb -mcpu=cortex-m3 -Tstm32_flash.ld -Wl,-Map=${CND_DISTDIR}/${CND_CONF}/Application.map -Wl,--gc-sections

${OBJECTDIR}/_ext/834592578/stm32f2x7_eth.o: ../../../../Libraries/STM32F2x7_ETH_Driver/src/stm32f2x7_eth.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/834592578
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/834592578/stm32f2x7_eth.o ../../../../Libraries/STM32F2x7_ETH_Driver/src/stm32f2x7_eth.c

${OBJECTDIR}/_ext/540162733/misc.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/misc.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/misc.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/misc.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_adc.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_adc.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_adc.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_adc.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_can.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_can.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_can.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_can.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_dac.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_dac.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_dac.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_dac.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_dma.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_dma.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_dma.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_dma.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_exti.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_exti.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_exti.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_exti.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_flash.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_flash.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_flash.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_flash.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_fsmc.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_fsmc.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_fsmc.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_fsmc.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_gpio.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_gpio.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_gpio.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_gpio.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_i2c.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_i2c.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_i2c.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_i2c.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_rcc.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_rcc.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_rcc.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_rcc.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_sdio.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_sdio.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_sdio.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_sdio.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_spi.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_spi.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_spi.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_spi.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_syscfg.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_syscfg.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_syscfg.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_syscfg.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_tim.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_tim.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_tim.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_tim.c

${OBJECTDIR}/_ext/540162733/stm32f2xx_usart.o: ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_usart.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/540162733
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/540162733/stm32f2xx_usart.o ../../../../Libraries/STM32F2xx_StdPeriph_Driver/src/stm32f2xx_usart.c

${OBJECTDIR}/_ext/860902683/lcd_st7565p.o: ../../../../Utilities/STM32_EVAL/Common/lcd_st7565p.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/860902683
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/860902683/lcd_st7565p.o ../../../../Utilities/STM32_EVAL/Common/lcd_st7565p.c

${OBJECTDIR}/_ext/860902683/stm32_eval_i2c_ee.o: ../../../../Utilities/STM32_EVAL/Common/stm32_eval_i2c_ee.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/860902683
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/860902683/stm32_eval_i2c_ee.o ../../../../Utilities/STM32_EVAL/Common/stm32_eval_i2c_ee.c

${OBJECTDIR}/_ext/860902683/stm32_eval_sdio_sd.o: ../../../../Utilities/STM32_EVAL/Common/stm32_eval_sdio_sd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/860902683
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/860902683/stm32_eval_sdio_sd.o ../../../../Utilities/STM32_EVAL/Common/stm32_eval_sdio_sd.c

${OBJECTDIR}/_ext/860902683/stm32_eval_spi_accel.o: ../../../../Utilities/STM32_EVAL/Common/stm32_eval_spi_accel.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/860902683
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/860902683/stm32_eval_spi_accel.o ../../../../Utilities/STM32_EVAL/Common/stm32_eval_spi_accel.c

${OBJECTDIR}/_ext/1557409105/sckit_eval_eth.o: ../../../../Utilities/STM32_EVAL/SCKIT_EVAL/sckit_eval_eth.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1557409105
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1557409105/sckit_eval_eth.o ../../../../Utilities/STM32_EVAL/SCKIT_EVAL/sckit_eval_eth.c

${OBJECTDIR}/_ext/1085738613/stm32_eval.o: ../../../../Utilities/STM32_EVAL/stm32_eval.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1085738613
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1085738613/stm32_eval.o ../../../../Utilities/STM32_EVAL/stm32_eval.c

${OBJECTDIR}/_ext/513150005/crc16.o: ../../../../Utilities/Third_Party/System/crc16.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/513150005
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/513150005/crc16.o ../../../../Utilities/Third_Party/System/crc16.c

${OBJECTDIR}/_ext/513150005/sckit_debug.o: ../../../../Utilities/Third_Party/System/sckit_debug.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/513150005
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/513150005/sckit_debug.o ../../../../Utilities/Third_Party/System/sckit_debug.c

${OBJECTDIR}/_ext/513150005/serial_driver.o: ../../../../Utilities/Third_Party/System/serial_driver.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/513150005
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/513150005/serial_driver.o ../../../../Utilities/Third_Party/System/serial_driver.c

${OBJECTDIR}/_ext/513150005/syscalls.o: ../../../../Utilities/Third_Party/System/syscalls.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/513150005
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/513150005/syscalls.o ../../../../Utilities/Third_Party/System/syscalls.c

${OBJECTDIR}/_ext/1939945793/ethernetif.o: ../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone/ethernetif.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1939945793
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1939945793/ethernetif.o ../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone/ethernetif.c

${OBJECTDIR}/_ext/1842557796/api_lib.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/api_lib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/api_lib.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/api_lib.c

${OBJECTDIR}/_ext/1842557796/api_msg.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/api_msg.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/api_msg.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/api_msg.c

${OBJECTDIR}/_ext/1842557796/err.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/err.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/err.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/err.c

${OBJECTDIR}/_ext/1842557796/netbuf.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/netbuf.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/netbuf.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/netbuf.c

${OBJECTDIR}/_ext/1842557796/netdb.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/netdb.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/netdb.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/netdb.c

${OBJECTDIR}/_ext/1842557796/netifapi.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/netifapi.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/netifapi.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/netifapi.c

${OBJECTDIR}/_ext/1842557796/sockets.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/sockets.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/sockets.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/sockets.c

${OBJECTDIR}/_ext/1842557796/tcpip.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/tcpip.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1842557796
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1842557796/tcpip.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/api/tcpip.c

${OBJECTDIR}/_ext/1284775829/def.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/def.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/def.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/def.c

${OBJECTDIR}/_ext/1284775829/dhcp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/dhcp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/dhcp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/dhcp.c

${OBJECTDIR}/_ext/1284775829/dns.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/dns.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/dns.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/dns.c

${OBJECTDIR}/_ext/1284775829/init.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/init.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/init.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/init.c

${OBJECTDIR}/_ext/1462834207/autoip.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/autoip.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/autoip.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/autoip.c

${OBJECTDIR}/_ext/1462834207/icmp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/icmp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/icmp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/icmp.c

${OBJECTDIR}/_ext/1462834207/igmp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/igmp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/igmp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/igmp.c

${OBJECTDIR}/_ext/1462834207/inet.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/inet.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/inet.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/inet.c

${OBJECTDIR}/_ext/1462834207/inet_chksum.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/inet_chksum.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/inet_chksum.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/inet_chksum.c

${OBJECTDIR}/_ext/1462834207/ip.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/ip.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/ip.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/ip.c

${OBJECTDIR}/_ext/1462834207/ip_addr.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/ip_addr.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/ip_addr.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/ip_addr.c

${OBJECTDIR}/_ext/1462834207/ip_frag.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/ip_frag.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1462834207
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1462834207/ip_frag.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/ipv4/ip_frag.c

${OBJECTDIR}/_ext/1284775829/mem.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/mem.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/mem.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/mem.c

${OBJECTDIR}/_ext/1284775829/memp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/memp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/memp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/memp.c

${OBJECTDIR}/_ext/1284775829/netif.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/netif.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/netif.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/netif.c

${OBJECTDIR}/_ext/1284775829/pbuf.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/pbuf.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/pbuf.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/pbuf.c

${OBJECTDIR}/_ext/1284775829/raw.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/raw.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/raw.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/raw.c

${OBJECTDIR}/_ext/1284775829/stats.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/stats.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/stats.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/stats.c

${OBJECTDIR}/_ext/1284775829/sys.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/sys.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/sys.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/sys.c

${OBJECTDIR}/_ext/1284775829/tcp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/tcp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/tcp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/tcp.c

${OBJECTDIR}/_ext/1284775829/tcp_in.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/tcp_in.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/tcp_in.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/tcp_in.c

${OBJECTDIR}/_ext/1284775829/tcp_out.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/tcp_out.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/tcp_out.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/tcp_out.c

${OBJECTDIR}/_ext/1284775829/timers.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/timers.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/timers.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/timers.c

${OBJECTDIR}/_ext/1284775829/udp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/udp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1284775829
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1284775829/udp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/core/udp.c

${OBJECTDIR}/_ext/1183208004/etharp.o: ../../../../Utilities/Third_Party/lwip-1.4.0/src/netif/etharp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1183208004
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1183208004/etharp.o ../../../../Utilities/Third_Party/lwip-1.4.0/src/netif/etharp.c

${OBJECTDIR}/_ext/1360937237/fs.o: ../src/fs.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/fs.o ../src/fs.c

${OBJECTDIR}/_ext/1360937237/httpd.o: ../src/httpd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/httpd.o ../src/httpd.c

${OBJECTDIR}/_ext/1360937237/httpd_cgi_ssi.o: ../src/httpd_cgi_ssi.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/httpd_cgi_ssi.o ../src/httpd_cgi_ssi.c

${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c

${OBJECTDIR}/_ext/1360937237/netconf.o: ../src/netconf.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/netconf.o ../src/netconf.c

${OBJECTDIR}/_ext/1360937237/stm32f2x7_eth_bsp.o: ../src/stm32f2x7_eth_bsp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/stm32f2x7_eth_bsp.o ../src/stm32f2x7_eth_bsp.c

${OBJECTDIR}/_ext/1360937237/stm32f2xx_it.o: ../src/stm32f2xx_it.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/stm32f2xx_it.o ../src/stm32f2xx_it.c

${OBJECTDIR}/_ext/1360937237/system_stm32f2xx.o: ../src/system_stm32f2xx.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.c) -Wall -DSTM32F2XX -DUSE_SCKIT_EVAL -DUSE_STDPERIPH_DRIVER -I../inc -I../../../../Libraries/CMSIS/Include -I../../../../Libraries/CMSIS/Device/ST/STM32F2xx/Include -I../../../../Libraries/STM32F2xx_StdPeriph_Driver/inc -I../../../../Libraries/STM32F2x7_ETH_Driver/inc -I../../../../Utilities/STM32_EVAL -I../../../../Utilities/STM32_EVAL/Common -I../../../../Utilities/STM32_EVAL/SCKIT_EVAL -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include -I../../../../Utilities/Third_Party/lwip-1.4.0/src/include/ipv4 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7 -I../../../../Utilities/Third_Party/lwip-1.4.0/port/STM32F2x7/Standalone -I../../../../Utilities/Third_Party/System -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/system_stm32f2xx.o ../src/system_stm32f2xx.c

${OBJECTDIR}/startup_stm32f2xx.o: startup_stm32f2xx.s 
	${MKDIR} -p ${OBJECTDIR}
	$(AS) $(ASFLAGS) -o ${OBJECTDIR}/startup_stm32f2xx.o startup_stm32f2xx.s

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/Application.elf

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
