################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Factory/Constants.cpp \
../Factory/Factory.cpp 

OBJS += \
./Factory/Constants.o \
./Factory/Factory.o 

CPP_DEPS += \
./Factory/Constants.d \
./Factory/Factory.d 


# Each subdirectory must supply rules for building sources it contributes
Factory/Constants.o: ../Factory/Constants.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Factory/Constants.d" -MT"Factory/Constants.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Factory/Factory.o: ../Factory/Factory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Factory/Factory.d" -MT"Factory/Factory.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


