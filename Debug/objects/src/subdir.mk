################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../objects/src/Card.cpp \
../objects/src/Dealer.cpp \
../objects/src/Deck.cpp \
../objects/src/Player.cpp 

OBJS += \
./objects/src/Card.o \
./objects/src/Dealer.o \
./objects/src/Deck.o \
./objects/src/Player.o 

CPP_DEPS += \
./objects/src/Card.d \
./objects/src/Dealer.d \
./objects/src/Deck.d \
./objects/src/Player.d 


# Each subdirectory must supply rules for building sources it contributes
objects/src/%.o: ../objects/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


