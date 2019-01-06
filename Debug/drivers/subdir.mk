################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCR_INTEGER_PRINTF -DDEBUG -DPRINTF_FLOAT_ENABLE=1 -DSCANF_FLOAT_ENABLE=1 -DPRINTF_ADVANCED_ENABLE=1 -DSCANF_ADVANCED_ENABLE=1 -DFRDM_KL25Z -DFREEDOM -D__MCUXPRESSO -D__USE_CMSIS -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -D__REDLIB__ -DSDK_DEBUGCONSOLE=1 -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\source" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\drivers" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\board" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\startup" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\CMSIS" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\utilities" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\TFC" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

