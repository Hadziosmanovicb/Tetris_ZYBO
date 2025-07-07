################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/blocks.c \
../src/color.c \
../src/define.c \
../src/display_demo.c \
../src/falling.c \
../src/grid.c \
../src/hardware_init.c \
../src/interrupts.c \
../src/sd.c 

OBJS += \
./src/blocks.o \
./src/color.o \
./src/define.o \
./src/display_demo.o \
./src/falling.o \
./src/grid.o \
./src/hardware_init.o \
./src/interrupts.o \
./src/sd.o 

C_DEPS += \
./src/blocks.d \
./src/color.d \
./src/define.d \
./src/display_demo.d \
./src/falling.d \
./src/grid.d \
./src/hardware_init.d \
./src/interrupts.d \
./src/sd.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../Tetris_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


