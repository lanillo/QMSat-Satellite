################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/EFM32/EFM32_Timer0.cpp 

OBJS += \
./Source/EFM32/EFM32_Timer0.o 

CPP_DEPS += \
./Source/EFM32/EFM32_Timer0.d 


# Each subdirectory must supply rules for building sources it contributes
Source/EFM32/EFM32_Timer0.o: ../Source/EFM32/EFM32_Timer0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\SourceTree\QMSat_embeded\Factory" -I"C:\SourceTree\QMSat_embeded\Include\Interface" -I"C:\SourceTree\QMSat_embeded\Include\Application" -I"C:\SourceTree\QMSat_embeded\Include\EFM32" -I"C:\SourceTree\QMSat_embeded\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_Timer0.d" -MT"Source/EFM32/EFM32_Timer0.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


