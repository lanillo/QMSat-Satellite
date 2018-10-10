################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/EFM32/EFM32_GPIO.cpp \
../Source/EFM32/EFM32_I2C.cpp \
../Source/EFM32/EFM32_PWM.cpp \
../Source/EFM32/EFM32_SPI.cpp \
../Source/EFM32/EFM32_Timer0.cpp \
../Source/EFM32/EFM32_USART1.cpp 

OBJS += \
./Source/EFM32/EFM32_GPIO.o \
./Source/EFM32/EFM32_I2C.o \
./Source/EFM32/EFM32_PWM.o \
./Source/EFM32/EFM32_SPI.o \
./Source/EFM32/EFM32_Timer0.o \
./Source/EFM32/EFM32_USART1.o 

CPP_DEPS += \
./Source/EFM32/EFM32_GPIO.d \
./Source/EFM32/EFM32_I2C.d \
./Source/EFM32/EFM32_PWM.d \
./Source/EFM32/EFM32_SPI.d \
./Source/EFM32/EFM32_Timer0.d \
./Source/EFM32/EFM32_USART1.d 


# Each subdirectory must supply rules for building sources it contributes
Source/EFM32/EFM32_GPIO.o: ../Source/EFM32/EFM32_GPIO.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_GPIO.d" -MT"Source/EFM32/EFM32_GPIO.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/EFM32/EFM32_I2C.o: ../Source/EFM32/EFM32_I2C.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_I2C.d" -MT"Source/EFM32/EFM32_I2C.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/EFM32/EFM32_PWM.o: ../Source/EFM32/EFM32_PWM.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_PWM.d" -MT"Source/EFM32/EFM32_PWM.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/EFM32/EFM32_SPI.o: ../Source/EFM32/EFM32_SPI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_SPI.d" -MT"Source/EFM32/EFM32_SPI.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/EFM32/EFM32_Timer0.o: ../Source/EFM32/EFM32_Timer0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_Timer0.d" -MT"Source/EFM32/EFM32_Timer0.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/EFM32/EFM32_USART1.o: ../Source/EFM32/EFM32_USART1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/CMSIS/Include" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Factory" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Interface" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Application" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\EFM32" -I"C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Include\Peripherals" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Source/EFM32/EFM32_USART1.d" -MT"Source/EFM32/EFM32_USART1.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


