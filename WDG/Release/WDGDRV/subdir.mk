################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../WDGDRV/WDGDRV.c 

OBJS += \
./WDGDRV/WDGDRV.o 

C_DEPS += \
./WDGDRV/WDGDRV.d 


# Each subdirectory must supply rules for building sources it contributes
WDGDRV/%.o: ../WDGDRV/%.c WDGDRV/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\DIO" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\WDGDRV" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\WDGM" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\LEDM" -I"C:\Users\ELAZHAR\eclipse-workspace\new_wwdg\Lib" -Wall -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


