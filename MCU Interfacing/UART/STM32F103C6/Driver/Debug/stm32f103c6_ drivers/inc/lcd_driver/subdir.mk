################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_\ drivers/inc/lcd_driver/lcd.c 

OBJS += \
./stm32f103c6_\ drivers/inc/lcd_driver/lcd.o 

C_DEPS += \
./stm32f103c6_\ drivers/inc/lcd_driver/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_\ drivers/inc/lcd_driver/lcd.o: ../stm32f103c6_\ drivers/inc/lcd_driver/lcd.c stm32f103c6_\ drivers/inc/lcd_driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc/seven_segmant_driver" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc/lcd_driver" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc/keypad_driver" -I"C:/Users/ahmed/Desktop/stm project/stm32/Driver/stm32f103c6_ drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_ drivers/inc/lcd_driver/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

