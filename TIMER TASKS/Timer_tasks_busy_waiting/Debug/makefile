################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Timer_tasks_busy_waiting.lss \

FLASH_IMAGE += \
Timer_tasks_busy_waiting.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer_tasks_busy_waiting.elf secondary-outputs

# Tool invocations
Timer_tasks_busy_waiting.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer_tasks_busy_waiting.map -mmcu=atmega32 -o "Timer_tasks_busy_waiting.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer_tasks_busy_waiting.lss: Timer_tasks_busy_waiting.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer_tasks_busy_waiting.elf  >"Timer_tasks_busy_waiting.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer_tasks_busy_waiting.hex: Timer_tasks_busy_waiting.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer_tasks_busy_waiting.elf  "Timer_tasks_busy_waiting.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer_tasks_busy_waiting.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer_tasks_busy_waiting.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer_tasks_busy_waiting.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
