################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../HALL \
../MCAL \
../Srevices


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../HALL/keypad.c \
../HALL/lcd.c \
../main.c \
../MCAL/UART.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
HALL/keypad.o \
HALL/lcd.o \
main.o \
MCAL/UART.o

OBJS_AS_ARGS +=  \
HALL/keypad.o \
HALL/lcd.o \
main.o \
MCAL/UART.o

C_DEPS +=  \
HALL/keypad.d \
HALL/lcd.d \
main.d \
MCAL/UART.d

C_DEPS_AS_ARGS +=  \
HALL/keypad.d \
HALL/lcd.d \
main.d \
MCAL/UART.d

OUTPUT_FILE_PATH +=ATMEGA_32.elf

OUTPUT_FILE_PATH_AS_ARGS +=ATMEGA_32.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
HALL/keypad.o: ../HALL/keypad.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../Srevices" -I"../HALL" -I"../MCAL" -I".."  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

HALL/lcd.o: ../HALL/lcd.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../Srevices" -I"../HALL" -I"../MCAL" -I".."  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../Srevices" -I"../HALL" -I"../MCAL" -I".."  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

MCAL/UART.o: ../MCAL/UART.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../Srevices" -I"../HALL" -I"../MCAL" -I".."  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ATMEGA_32.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "D:\Program Files\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ATMEGA_32.elf" "ATMEGA_32.hex"
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ATMEGA_32.elf" "ATMEGA_32.eep" || exit 0
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ATMEGA_32.elf" > "ATMEGA_32.lss"
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ATMEGA_32.elf" "ATMEGA_32.srec"
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .user_signatures --set-section-flags=.user_signatures=alloc,load --change-section-lma .user_signatures=0 --no-change-warnings -O ihex "ATMEGA_32.elf" "ATMEGA_32.usersignatures" || exit 0
	"D:\Program Files\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "ATMEGA_32.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ATMEGA_32.elf" "ATMEGA_32.a" "ATMEGA_32.hex" "ATMEGA_32.lss" "ATMEGA_32.eep" "ATMEGA_32.map" "ATMEGA_32.srec" "ATMEGA_32.usersignatures"
	