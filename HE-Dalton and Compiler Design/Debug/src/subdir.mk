################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HE-Dalton\ and\ Compiler\ Design.cpp 

OBJS += \
./src/HE-Dalton\ and\ Compiler\ Design.o 

CPP_DEPS += \
./src/HE-Dalton\ and\ Compiler\ Design.d 


# Each subdirectory must supply rules for building sources it contributes
src/HE-Dalton\ and\ Compiler\ Design.o: ../src/HE-Dalton\ and\ Compiler\ Design.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/HE-Dalton and Compiler Design.d" -MT"src/HE-Dalton\ and\ Compiler\ Design.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


