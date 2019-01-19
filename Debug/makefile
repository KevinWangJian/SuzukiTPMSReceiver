################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 27
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/APL/subdir.mk
-include src/DDL/subdir.mk
-include src/HAL/subdir.mk
-include src/MDL/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SuzukiTPMSReceiverDisplayer.elf \

EXECUTABLES_QUOTED += \
"SuzukiTPMSReceiverDisplayer.elf" \

EXECUTABLES_OS_FORMAT += \
SuzukiTPMSReceiverDisplayer.elf \

SECONDARY_FLASH += \
SuzukiTPMSReceiverDisplayer.hex \

SECONDARY_FLASH_QUOTED += \
"SuzukiTPMSReceiverDisplayer.hex" \

SECONDARY_FLASH_OS_FORMAT += \
SuzukiTPMSReceiverDisplayer.hex \

SECONDARY_SIZE += \
SuzukiTPMSReceiverDisplayer.siz \

SECONDARY_SIZE_QUOTED += \
"SuzukiTPMSReceiverDisplayer.siz" \

SECONDARY_SIZE_OS_FORMAT += \
SuzukiTPMSReceiverDisplayer.siz \


# All Target
all: warning-messages explicit-dependencies SuzukiTPMSReceiverDisplayer.elf secondary-outputs

# Tool invocations
SuzukiTPMSReceiverDisplayer.elf: $(OBJS) E:/wangjian/project/Suzuki(ChangAn)TPMSReceiver/firmware/SuzukiTPMSReceiverDisplayer/Project_Settings/Linker_Files/SKEAZ_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #28 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "SuzukiTPMSReceiverDisplayer.elf" "@SuzukiTPMSReceiverDisplayer.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

SuzukiTPMSReceiverDisplayer.hex: $(EXECUTABLES)
	@echo 'Executing target #29 $@'
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O ihex $(EXECUTABLES)  "SuzukiTPMSReceiverDisplayer.hex"
	@echo 'Finished building: $@'
	@echo ' '

SuzukiTPMSReceiverDisplayer.siz: $(EXECUTABLES)
	@echo 'Executing target #30 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH_QUOTED) ./*/*.d ./*/*/*.d  ./*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

