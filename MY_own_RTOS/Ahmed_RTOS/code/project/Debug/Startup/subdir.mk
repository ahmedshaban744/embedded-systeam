################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c6tx.s 

OBJS += \
./Startup/startup_stm32f103c6tx.o 

S_DEPS += \
./Startup/startup_stm32f103c6tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -DDEBUG -c -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/CMISI_Arm" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/Ahmed_RTOS/inc" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/Inc" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc/keypad_driver" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc/lcd_driver" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc/seven_segmant_driver" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

