################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Manager.cpp \
../Map.cpp \
../Robot.cpp \
../Utils.cpp \
../main.cpp 

OBJS += \
./Manager.o \
./Map.o \
./Robot.o \
./Utils.o \
./main.o 

CPP_DEPS += \
./Manager.d \
./Map.d \
./Robot.d \
./Utils.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


