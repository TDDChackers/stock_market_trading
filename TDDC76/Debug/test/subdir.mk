################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../test/Database.cc \
../test/Decision.cc \
../test/Evaluation.cc \
../test/Master_Evaluation.cc \
../test/Model.cc \
../test/Trader.cc \
../test/main.cc 

OBJS += \
./test/Database.o \
./test/Decision.o \
./test/Evaluation.o \
./test/Master_Evaluation.o \
./test/Model.o \
./test/Trader.o \
./test/main.o 

CC_DEPS += \
./test/Database.d \
./test/Decision.d \
./test/Evaluation.d \
./test/Master_Evaluation.d \
./test/Model.d \
./test/Trader.d \
./test/main.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -pedantic -Wall -Wextra -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


