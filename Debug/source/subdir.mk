################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Practica1.c \
../source/aes.c \
../source/encrypt_and_integrity.c \
../source/fsl_crc.c \
../source/fsl_enet.c \
../source/fsl_enet_mdio.c \
../source/fsl_phyksz8081.c \
../source/fsl_sysmpu.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/Practica1.d \
./source/aes.d \
./source/encrypt_and_integrity.d \
./source/fsl_crc.d \
./source/fsl_enet.d \
./source/fsl_enet_mdio.d \
./source/fsl_phyksz8081.d \
./source/fsl_sysmpu.d \
./source/semihost_hardfault.d 

OBJS += \
./source/Practica1.o \
./source/aes.o \
./source/encrypt_and_integrity.o \
./source/fsl_crc.o \
./source/fsl_enet.o \
./source/fsl_enet_mdio.o \
./source/fsl_phyksz8081.o \
./source/fsl_sysmpu.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\board" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\utilities" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\drivers" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\device" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\serial_manager" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\lists" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\CMSIS" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\uart" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\crc" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\CMSIS_driver" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\phy" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\mdio" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\source" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Practica1.d ./source/Practica1.o ./source/aes.d ./source/aes.o ./source/encrypt_and_integrity.d ./source/encrypt_and_integrity.o ./source/fsl_crc.d ./source/fsl_crc.o ./source/fsl_enet.d ./source/fsl_enet.o ./source/fsl_enet_mdio.d ./source/fsl_enet_mdio.o ./source/fsl_phyksz8081.d ./source/fsl_phyksz8081.o ./source/fsl_sysmpu.d ./source/fsl_sysmpu.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

