################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_\ drivers/I2C/stm32f103c6_I2C_drivers.c 

OBJS += \
./stm32f103c6_\ drivers/I2C/stm32f103c6_I2C_drivers.o 

C_DEPS += \
./stm32f103c6_\ drivers/I2C/stm32f103c6_I2C_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_\ drivers/I2C/stm32f103c6_I2C_drivers.o: ../stm32f103c6_\ drivers/I2C/stm32f103c6_I2C_drivers.c stm32f103c6_\ drivers/I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_ drivers/I2C/stm32f103c6_I2C_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

