################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/fsl_adapter_uart.c 

C_DEPS += \
./component/uart/fsl_adapter_uart.d 

OBJS += \
./component/uart/fsl_adapter_uart.o 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c component/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\board" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\utilities" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\drivers" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\device" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\serial_manager" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\lists" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\CMSIS" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\uart" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\component\crc" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\CMSIS_driver" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\phy" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\mdio" -I"C:\Users\grtre\Documents\MCUXpressoIDE_25.6.136\workspace\EmbeddedIoT\source" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-uart

clean-component-2f-uart:
	-$(RM) ./component/uart/fsl_adapter_uart.d ./component/uart/fsl_adapter_uart.o

.PHONY: clean-component-2f-uart

