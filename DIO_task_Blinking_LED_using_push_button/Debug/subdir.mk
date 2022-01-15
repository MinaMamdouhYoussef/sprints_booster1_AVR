################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../buttons_program.c \
../dio_program.c \
../led_program.c \
../main.c \
../timers_program.c 

OBJS += \
./buttons_program.o \
./dio_program.o \
./led_program.o \
./main.o \
./timers_program.o 

C_DEPS += \
./buttons_program.d \
./dio_program.d \
./led_program.d \
./main.d \
./timers_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


