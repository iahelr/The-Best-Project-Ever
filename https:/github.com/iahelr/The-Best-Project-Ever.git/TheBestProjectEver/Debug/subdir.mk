################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Consts.cpp \
../IntMatrix.cpp \
../LocationMatrix.cpp \
../Manager.cpp \
../Map.cpp \
../PathFinder.cpp \
../Robot.cpp \
../Utils.cpp \
../WayPointManager.cpp \
../main.cpp 

OBJS += \
./Consts.o \
./IntMatrix.o \
./LocationMatrix.o \
./Manager.o \
./Map.o \
./PathFinder.o \
./Robot.o \
./Utils.o \
./WayPointManager.o \
./main.o 

CPP_DEPS += \
./Consts.d \
./IntMatrix.d \
./LocationMatrix.d \
./Manager.d \
./Map.d \
./PathFinder.d \
./Robot.d \
./Utils.d \
./WayPointManager.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


