################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/aes.c \
../source/encrypt_and_integrity.c \
../source/enet_txrx_transfer.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/aes.d \
./source/encrypt_and_integrity.d \
./source/enet_txrx_transfer.d \
./source/semihost_hardfault.d 

OBJS += \
./source/aes.o \
./source/encrypt_and_integrity.o \
./source/enet_txrx_transfer.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DPRINTF_ADVANCED_ENABLE=1 -DFRDM_K64F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\source" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\mdio" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\phy" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\utilities" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\drivers" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\device" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\component\uart" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\component\lists" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\CMSIS" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\board" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EthernetPractica1_enet_txrx_transfer\frdmk64f\driver_examples\enet\txrx_transfer" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/aes.d ./source/aes.o ./source/encrypt_and_integrity.d ./source/encrypt_and_integrity.o ./source/enet_txrx_transfer.d ./source/enet_txrx_transfer.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

