################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/zComm.cpp \
../src/zDetect.cpp \
../src/zMovement.cpp \
../src/zVision.cpp 

OBJS += \
./src/zComm.o \
./src/zDetect.o \
./src/zMovement.o \
./src/zVision.o 

CPP_DEPS += \
./src/zComm.d \
./src/zDetect.d \
./src/zMovement.d \
./src/zVision.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


