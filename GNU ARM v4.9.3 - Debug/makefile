################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include obj/Debug/QMSat_embeded/Tests/Steps/Peripherals/subdir.mk
-include obj/Debug/QMSat_embeded/Tests/subdir.mk
-include obj/Debug/QMSat_embeded/Source/Peripherals/subdir.mk
-include obj/Debug/QMSat_embeded/Source/Application/subdir.mk
-include obj/Debug/QMSat-Satellite/Tests/Steps/Peripherals/subdir.mk
-include obj/Debug/QMSat-Satellite/Tests/Steps/Mocks/subdir.mk
-include obj/Debug/QMSat-Satellite/Tests/subdir.mk
-include obj/Debug/QMSat-Satellite/Source/Peripherals/subdir.mk
-include obj/Debug/QMSat-Satellite/Source/EFM32/subdir.mk
-include obj/Debug/QMSat-Satellite/Source/Application/subdir.mk
-include obj/Debug/BDD/fw-cxxtest/cxxtest/subdir.mk
-include emlib/subdir.mk
-include Source/Peripherals/subdir.mk
-include Source/EFM32/subdir.mk
-include Source/Application/subdir.mk
-include Factory/subdir.mk
-include CMSIS/EFM32GG/subdir.mk
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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: QMSat_Embeded.axf

# Tool invocations
QMSat_Embeded.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C++ Linker'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "QMSat_Embeded.ld" --specs=nosys.specs -Xlinker --gc-sections -Xlinker -Map="QMSat_Embeded.map" --specs=nano.specs -o QMSat_Embeded.axf "./CMSIS/EFM32GG/startup_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./Factory/Factory.o" "./Source/Application/InitState.o" "./Source/Application/RunState.o" "./Source/Application/StateManager.o" "./Source/Application/main.o" "./Source/EFM32/EFM32_GPIO.o" "./Source/EFM32/EFM32_I2C.o" "./Source/EFM32/EFM32_Timer0.o" "./Source/Peripherals/LED.o" "./emlib/em_cmu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_system.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: QMSat_Embeded.hex'
	arm-none-eabi-objcopy -O ihex "QMSat_Embeded.axf" "QMSat_Embeded.hex"
	@echo ' '

	@echo 'Building bin file: QMSat_Embeded.bin'
	arm-none-eabi-objcopy -O binary "QMSat_Embeded.axf" "QMSat_Embeded.bin"
	@echo ' '

	@echo 'Building s37 file: QMSat_Embeded.s37'
	arm-none-eabi-objcopy -O srec "QMSat_Embeded.axf" "QMSat_Embeded.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "QMSat_Embeded.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) QMSat_Embeded.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
