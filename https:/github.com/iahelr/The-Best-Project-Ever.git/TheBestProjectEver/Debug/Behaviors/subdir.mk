################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Behaviors/A.cpp \
../Behaviors/ActionResult.cpp \
../Behaviors/B.cpp \
../Behaviors/Behavior.cpp \
../Behaviors/C.cpp \
../Behaviors/GoForward.cpp \
../Behaviors/TurnInPlace.cpp \
../Behaviors/TurnLeft.cpp \
../Behaviors/TurnRight.cpp 

OBJS += \
./Behaviors/A.o \
./Behaviors/ActionResult.o \
./Behaviors/B.o \
./Behaviors/Behavior.o \
./Behaviors/C.o \
./Behaviors/GoForward.o \
./Behaviors/TurnInPlace.o \
./Behaviors/TurnLeft.o \
./Behaviors/TurnRight.o 

CPP_DEPS += \
./Behaviors/A.d \
./Behaviors/ActionResult.d \
./Behaviors/B.d \
./Behaviors/Behavior.d \
./Behaviors/C.d \
./Behaviors/GoForward.d \
./Behaviors/TurnInPlace.d \
./Behaviors/TurnLeft.d \
./Behaviors/TurnRight.d 


# Each subdirectory must supply rules for building sources it contributes
Behaviors/%.o: ../Behaviors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


