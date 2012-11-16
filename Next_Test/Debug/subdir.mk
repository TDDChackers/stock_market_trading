################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../communicator.cpp \
../communicator_test.cpp 

CC_SRCS += \
../main.cc 

OBJS += \
./communicator.o \
./communicator_test.o \
./main.o 

CC_DEPS += \
./main.d 

CPP_DEPS += \
./communicator.d \
./communicator_test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/victorbirath/Documents/TDDC76/CPP_downloads/chilkat-9.3.2-macosx/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/victorbirath/Documents/TDDC76/CPP_downloads/chilkat-9.3.2-macosx/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


