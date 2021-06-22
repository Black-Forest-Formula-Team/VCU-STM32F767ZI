################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/BFFT/device_layer/inverter/Inverter.cpp 

OBJS += \
./Core/BFFT/device_layer/inverter/Inverter.o 

CPP_DEPS += \
./Core/BFFT/device_layer/inverter/Inverter.d 


# Each subdirectory must supply rules for building sources it contributes
Core/BFFT/device_layer/inverter/Inverter.o: ../Core/BFFT/device_layer/inverter/Inverter.cpp Core/BFFT/device_layer/inverter/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g -DUSE_HAL_DRIVER -DMALLOCS_INSIDE_ISRs -DSTM32F767xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"E:/software/BFFT/branches/Refactoring_VCU_Core_BFFT_myMain/Core/BFFT/control_system_layer/double_buffering" -I"E:/software/BFFT/branches/Refactoring_VCU_Core_BFFT_myMain/Core/BFFT/frutil" -I"E:/software/BFFT/branches/Refactoring_VCU_Core_BFFT_myMain/Core/BFFT" -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Core/src -I"E:/software/BFFT/branches/Refactoring_VCU_Core_BFFT_myMain/Core/BFFT/middleware_layer/can/inc" -I"E:/software/BFFT/branches/Refactoring_VCU_Core_BFFT_myMain/Core/BFFT/middleware_layer/can/src" -O0 -ffunction-sections -fdata-sections -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Core/BFFT/device_layer/inverter/Inverter.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

