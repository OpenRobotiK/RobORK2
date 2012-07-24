################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: test_project.axf

# Tool invocations
test_project.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Florent\Documents\GitHub\RobORK\Programme\CMSISv2p00_LPC17xx\Debug" -L"C:\Users\Florent\Documents\GitHub\RobORK\Programme\CMSISv2p00_DSPLIB_CM3\lib" -Xlinker -Map="test_project.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "test_project_Debug.ld" -o"test_project.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) test_project.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "test_project.axf"; # arm-none-eabi-objcopy -O binary "test_project.axf" "test_project.bin" ; checksum -p LPC1769 -d "test_project.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
