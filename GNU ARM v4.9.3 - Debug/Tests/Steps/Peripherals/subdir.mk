################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Tests/Steps/Peripherals/LED-evaluator.cpp 

OBJS += \
./Tests/Steps/Peripherals/LED-evaluator.o 

CPP_DEPS += \
./Tests/Steps/Peripherals/LED-evaluator.d 


# Each subdirectory must supply rules for building sources it contributes
Tests/Steps/Peripherals/LED-evaluator.o: ../Tests/Steps/Peripherals/LED-evaluator.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\SourceTree\QMSat_embeded\Factory" -I"C:\SourceTree\QMSat_embeded\Include\Interface" -I"C:\SourceTree\QMSat_embeded\Include\Application" -I"C:\SourceTree\QMSat_embeded\Include\EFM32" -I"C:\SourceTree\QMSat_embeded\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Tests/Steps/Peripherals/LED-evaluator.d" -MT"Tests/Steps/Peripherals/LED-evaluator.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


