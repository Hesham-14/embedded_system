################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32_F103C6_Driver/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
unit7_L4_lab1_STM32F103C6_Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
unit7_L4_lab1_STM32F103C6_Driver.list \

OBJCOPY_BIN += \
unit7_L4_lab1_STM32F103C6_Driver.bin \


# All Target
all: unit7_L4_lab1_STM32F103C6_Driver.elf secondary-outputs

# Tool invocations
unit7_L4_lab1_STM32F103C6_Driver.elf: $(OBJS) $(USER_OBJS) C:\Users\hesham\ mohamed\STM32CubeIDE\workspace_2_1.4.0\unit7_L4_lab1_STM32F103C6_Driver\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "unit7_L4_lab1_STM32F103C6_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\hesham mohamed\STM32CubeIDE\workspace_2_1.4.0\unit7_L4_lab1_STM32F103C6_Driver\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="unit7_L4_lab1_STM32F103C6_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

unit7_L4_lab1_STM32F103C6_Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "unit7_L4_lab1_STM32F103C6_Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

unit7_L4_lab1_STM32F103C6_Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "unit7_L4_lab1_STM32F103C6_Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
