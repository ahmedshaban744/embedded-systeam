################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_\ drivers/EXTI/stm32f103c6_\ EXTI_drivers.c 

OBJS += \
./stm32f103c6_\ drivers/EXTI/stm32f103c6_\ EXTI_drivers.o 

C_DEPS += \
./stm32f103c6_\ drivers/EXTI/stm32f103c6_\ EXTI_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_\ drivers/EXTI/stm32f103c6_\ EXTI_drivers.o: ../stm32f103c6_\ drivers/EXTI/stm32f103c6_\ EXTI_drivers.c stm32f103c6_\ drivers/EXTI/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc/seven_segmant_driver" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc/lcd_driver" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc/keypad_driver" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_ drivers/EXTI/stm32f103c6_ EXTI_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

