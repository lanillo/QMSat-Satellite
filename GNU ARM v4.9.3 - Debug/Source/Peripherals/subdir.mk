################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Peripherals/LED.cpp \
../Source/Peripherals/MCP9808.cpp 

OBJS += \
./Source/Peripherals/LED.o \
./Source/Peripherals/MCP9808.o 

CPP_DEPS += \
./Source/Peripherals/LED.d \
./Source/Peripherals/MCP9808.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Peripherals/LED.o: ../Source/Peripherals/LED.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/Peripherals/LED.d" -MT"Source/Peripherals/LED.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Peripherals/MCP9808.o: ../Source/Peripherals/MCP9808.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/Peripherals/MCP9808.d" -MT"Source/Peripherals/MCP9808.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


