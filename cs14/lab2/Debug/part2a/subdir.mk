################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../part2a/list.cc \
../part2a/main.cc 

OBJS += \
./part2a/list.o \
./part2a/main.o 

CC_DEPS += \
./part2a/list.d \
./part2a/main.d 


# Each subdirectory must supply rules for building sources it contributes
part2a/%.o: ../part2a/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


