################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TFC/TFC.c \
../TFC/TFC_ADC.c \
../TFC/TFC_ARM_SysTick.c \
../TFC/TFC_BoardSupport.c \
../TFC/TFC_LineScanCamera.c \
../TFC/TFC_Motor.c \
../TFC/TFC_Servo.c 

OBJS += \
./TFC/TFC.o \
./TFC/TFC_ADC.o \
./TFC/TFC_ARM_SysTick.o \
./TFC/TFC_BoardSupport.o \
./TFC/TFC_LineScanCamera.o \
./TFC/TFC_Motor.o \
./TFC/TFC_Servo.o 

C_DEPS += \
./TFC/TFC.d \
./TFC/TFC_ADC.d \
./TFC/TFC_ARM_SysTick.d \
./TFC/TFC_BoardSupport.d \
./TFC/TFC_LineScanCamera.d \
./TFC/TFC_Motor.d \
./TFC/TFC_Servo.d 


# Each subdirectory must supply rules for building sources it contributes
TFC/%.o: ../TFC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCR_INTEGER_PRINTF -DDEBUG -DPRINTF_FLOAT_ENABLE=1 -DSCANF_FLOAT_ENABLE=1 -DPRINTF_ADVANCED_ENABLE=1 -DSCANF_ADVANCED_ENABLE=1 -DFRDM_KL25Z -DFREEDOM -D__MCUXPRESSO -D__USE_CMSIS -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -D__REDLIB__ -DSDK_DEBUGCONSOLE=1 -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\source" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\drivers" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\board" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\startup" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\CMSIS" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\utilities" -I"C:\Users\nxf36044\Desktop\CUP_Car\FRDM_TFC\TFC" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


