################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../AreaNode.cc \
../NumberList.cc \
../PhoneBook.cc \
../main.cc 

OBJS += \
./AreaNode.o \
./NumberList.o \
./PhoneBook.o \
./main.o 

CC_DEPS += \
./AreaNode.d \
./NumberList.d \
./PhoneBook.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


