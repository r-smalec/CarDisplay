################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD/Src/disp_conf.c \
../LCD/Src/disp_gui.c \
../LCD/Src/fonts.c \
../LCD/Src/samurai_logo_q1.c \
../LCD/Src/samurai_logo_q2.c \
../LCD/Src/samurai_logo_q3.c \
../LCD/Src/samurai_logo_q4.c \
../LCD/Src/test.c 

OBJS += \
./LCD/Src/disp_conf.o \
./LCD/Src/disp_gui.o \
./LCD/Src/fonts.o \
./LCD/Src/samurai_logo_q1.o \
./LCD/Src/samurai_logo_q2.o \
./LCD/Src/samurai_logo_q3.o \
./LCD/Src/samurai_logo_q4.o \
./LCD/Src/test.o 

C_DEPS += \
./LCD/Src/disp_conf.d \
./LCD/Src/disp_gui.d \
./LCD/Src/fonts.d \
./LCD/Src/samurai_logo_q1.d \
./LCD/Src/samurai_logo_q2.d \
./LCD/Src/samurai_logo_q3.d \
./LCD/Src/samurai_logo_q4.d \
./LCD/Src/test.d 


# Each subdirectory must supply rules for building sources it contributes
LCD/Src/disp_conf.o: ../LCD/Src/disp_conf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/disp_conf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/disp_gui.o: ../LCD/Src/disp_gui.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/disp_gui.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/fonts.o: ../LCD/Src/fonts.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/fonts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/samurai_logo_q1.o: ../LCD/Src/samurai_logo_q1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/samurai_logo_q1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/samurai_logo_q2.o: ../LCD/Src/samurai_logo_q2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/samurai_logo_q2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/samurai_logo_q3.o: ../LCD/Src/samurai_logo_q3.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/samurai_logo_q3.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/samurai_logo_q4.o: ../LCD/Src/samurai_logo_q4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/samurai_logo_q4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
LCD/Src/test.o: ../LCD/Src/test.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32L432xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/rsmal/OneDrive/Dokumenty/STM32/CarDisplay/firmware/CarDisplay/LCD/Inc" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/test.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

