################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ahmed_RTOS/My_RTOS_FIFO.c \
../Ahmed_RTOS/cortex_mx_porting.c \
../Ahmed_RTOS/scheduler.c 

OBJS += \
./Ahmed_RTOS/My_RTOS_FIFO.o \
./Ahmed_RTOS/cortex_mx_porting.o \
./Ahmed_RTOS/scheduler.o 

C_DEPS += \
./Ahmed_RTOS/My_RTOS_FIFO.d \
./Ahmed_RTOS/cortex_mx_porting.d \
./Ahmed_RTOS/scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Ahmed_RTOS/%.o: ../Ahmed_RTOS/%.c Ahmed_RTOS/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/Ahmed_RTOS/inc" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/CMISI_Arm" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/Inc" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc/keypad_driver" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc/lcd_driver" -I"C:/Users/ahmed/Desktop/stm32/STM32F103C6/stm32f103c6_ drivers/inc/seven_segmant_driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

