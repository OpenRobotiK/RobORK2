################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC.c \
../src/EEPROM.c \
../src/PWM.c \
../src/UART.c \
../src/cr_startup_lpc176x.c \
../src/main.c \
../src/watchdog.c 

OBJS += \
./src/ADC.o \
./src/EEPROM.o \
./src/PWM.o \
./src/UART.o \
./src/cr_startup_lpc176x.o \
./src/main.o \
./src/watchdog.o 

C_DEPS += \
./src/ADC.d \
./src/EEPROM.d \
./src/PWM.d \
./src/UART.d \
./src/cr_startup_lpc176x.d \
./src/main.d \
./src/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -D__USE_CMSIS_DSPLIB=CMSISv2p00_DSPLIB_CM3 -I"C:\Users\Florent\Documents\GitHub\RobORK\Programme\CMSISv2p00_LPC17xx\inc" -I"C:\Users\Florent\Documents\GitHub\RobORK\Programme\CMSISv2p00_DSPLIB_CM3\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cr_startup_lpc176x.o: ../src/cr_startup_lpc176x.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -D__USE_CMSIS_DSPLIB=CMSISv2p00_DSPLIB_CM3 -I"C:\Users\Florent\Documents\GitHub\RobORK\Programme\CMSISv2p00_LPC17xx\inc" -I"C:\Users\Florent\Documents\GitHub\RobORK\Programme\CMSISv2p00_DSPLIB_CM3\inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cr_startup_lpc176x.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


