################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Application/InitState.cpp \
../Source/Application/RunState.cpp \
../Source/Application/StateManager.cpp \
../Source/Application/main.cpp 

OBJS += \
./Source/Application/InitState.o \
./Source/Application/RunState.o \
./Source/Application/StateManager.o \
./Source/Application/main.o 

CPP_DEPS += \
./Source/Application/InitState.d \
./Source/Application/RunState.d \
./Source/Application/StateManager.d \
./Source/Application/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Application/InitState.o: ../Source/Application/InitState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/Application/InitState.d" -MT"Source/Application/InitState.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Application/RunState.o: ../Source/Application/RunState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/Application/RunState.d" -MT"Source/Application/RunState.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Application/StateManager.o: ../Source/Application/StateManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/Application/StateManager.d" -MT"Source/Application/StateManager.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Application/main.o: ../Source/Application/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/Application/main.d" -MT"Source/Application/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


