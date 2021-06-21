################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/BFFT/middleware_layer/can/src/test.cpp 

OBJS += \
./Core/BFFT/middleware_layer/can/src/test.o 

CPP_DEPS += \
./Core/BFFT/middleware_layer/can/src/test.d 


# Each subdirectory must supply rules for building sources it contributes
Core/BFFT/middleware_layer/can/src/test.o: ../Core/BFFT/middleware_layer/can/src/test.cpp Core/BFFT/middleware_layer/can/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g -DUSE_HAL_DRIVER -DMALLOCS_INSIDE_ISRs -DSTM32F767xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"E:/SoftwareWorkingFolder/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/Core/BFFT/control_system_layer/double_buffering" -I"E:/SoftwareWorkingFolder/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/Core/BFFT/frutil" -I"E:/SoftwareWorkingFolder/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/Core/BFFT" -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Core/src -I"E:/SoftwareWorkingFolder/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/Core/BFFT/middleware_layer/can/inc" -I"E:/SoftwareWorkingFolder/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/VCU-STM32F767ZI-ae3c02b518f05f899225808f2aeb64a55390be0c/Core/BFFT/middleware_layer/can/src" -O0 -ffunction-sections -fdata-sections -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Core/BFFT/middleware_layer/can/src/test.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

