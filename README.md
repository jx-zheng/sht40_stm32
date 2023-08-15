# sht40_stm32
SHT40 Temperature and Humidity Sensor IC driver for STM32

![A diagram showing an example application circuit with the SHT40](https://github.com/jx-zheng/sht40_stm32/assets/43159579/753bfefc-55b3-4816-8ce6-06e1e11c377e)

## Introduction

This repository contains a driver for the SHT40 temperature and humidity sensor by Sensirion, written in C. From the SHT40 [datasheet](https://sensirion.com/media/documents/33FD6951/64D3B030/Sensirion_Datasheet_SHT4x.pdf):

> SHT4x is a digital sensor platform for measuring relative humidity and temperature at different accuracy classes. Its I2C interface provides several preconfigured I2C addresses while maintaining an ultra-low power budget (0.4 μW). The power-trimmed internal heater can be used at three heating levels thus enabling sensor operation in demanding environments. 

The driver implements allows for easy use of all SHT40 functions, including retrieval of measurements at the 3 precision levels, heating, and CRC8 checksum verification.

## Compatibility

This driver works with any STM32F4 (Arm Cortex M4) out-of-the-box, and was tested on an STM32 Black Pill board (STM32F401CDU6). Making this driver compatible with other STM32Fx-series MCUs can be achieved by simply changing the included HAL support header in Inc/ds1307.h.

## Files and Usage

Add Inc/sht40.h and Src/sht40.c to your STM32 project in the corresponding folders. main.c provides a usage example of the driver on an STM32F4xx MCU,
where UART serial output is set up to initialize the driver, set a time and date, and write the time and date to the serial port every 5 seconds. Note that main.c will not build on its own; it depends on MCU-specific code generated via STM32CubeMX.
