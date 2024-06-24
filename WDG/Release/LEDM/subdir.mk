################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LEDM/LEDM.c 

OBJS += \
./LEDM/LEDM.o 

C_DEPS += \
./LEDM/LEDM.d 


# Each subdirectory must supply rules for building sources it contributes
LEDM/%.o: ../LEDM/%.c LEDM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\DIO" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\WDGDRV" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\WDGM" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\LEDM" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\Lib" -Wall -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


