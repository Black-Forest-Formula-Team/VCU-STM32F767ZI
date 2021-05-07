################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/BFFT/middleware_layer/can/src/subdir.mk
-include Core/BFFT/middleware_layer/can/subdir.mk
-include Core/BFFT/frutil/subdir.mk
-include Core/BFFT/device_layer/inverter/subdir.mk
-include Core/BFFT/control_system_layer/double_buffering/subdir.mk
-include Core/BFFT/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := BFFT_Architecture_STM32_FreeRTOS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
BFFT_Architecture_STM32_FreeRTOS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BFFT_Architecture_STM32_FreeRTOS.list \

OBJCOPY_BIN += \
BFFT_Architecture_STM32_FreeRTOS.bin \


# All Target
all: main-build

# Main-build Target
main-build: BFFT_Architecture_STM32_FreeRTOS.elf secondary-outputs

# Tool invocations
BFFT_Architecture_STM32_FreeRTOS.elf: $(OBJS) $(USER_OBJS) E:\OneDrive\OneDrive\ -\ Hochschule\ Offenburg\Studium\Semester\ 6\Formula\ Student\Repository\VCU-STM32F767ZI\VCU-STM32F767ZI\STM32F767ZITX_FLASH.ld
	arm-none-eabi-g++ -o "BFFT_Architecture_STM32_FreeRTOS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"E:\OneDrive\OneDrive - Hochschule Offenburg\Studium\Semester 6\Formula Student\Repository\VCU-STM32F767ZI\VCU-STM32F767ZI\STM32F767ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BFFT_Architecture_STM32_FreeRTOS.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BFFT_Architecture_STM32_FreeRTOS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BFFT_Architecture_STM32_FreeRTOS.list"
	@echo 'Finished building: $@'
	@echo ' '

BFFT_Architecture_STM32_FreeRTOS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "BFFT_Architecture_STM32_FreeRTOS.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
