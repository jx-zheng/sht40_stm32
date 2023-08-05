/*
 * sht40.h
 * Author: Kevin Zheng
 */

#ifndef INC_SHT40_H_
#define INC_SHT40_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"

/*
 * I2C Address
 */
#define SHT40_I2C_ADDR (0x44 << 1)

/*
 * Commands
 */
#define SHT40_HI_PREC_MEASURE  0xFD
#define SHT40_MED_PREC_MEASURE 0xF6
#define SHT40_LOW_PREC_MEASURE 0xE0
#define SHT40_READ_SERIAL      0x89
#define SHT40_SOFT_RESET       0x94
#define SHT40_200mW_1s_HEAT    0x39
#define SHT40_200mW_100ms_HEAT 0x32
#define SHT40_110mW_1s_HEAT    0x2F
#define SHT40_110mW_100ms_HEAT 0x24
#define SHT40_20mW_1s_HEAT     0x1E
#define SHT40_20mW_100ms_HEAT  0x15

/*
 * Result/Measurement Struct
 */
typedef struct {

    /* Temperature in Celsius */
    float temperature;

    /* Percentage relative humidity */
    float rel_humidity;

} SHT40_Measurement;

/*
 * Measurement Precision Levels
 */
typedef enum {
    HIGH_PRECISION, /* Low repeatability */
    MED_PRECISION, /* Medium repeatability */
    LOW_PRECISION /* High repeatability */
} SHT40_Precision;

/*
 * Heater Duration and Power Options
 */
typedef enum {
    HIGH_POWER_1s      = SHT40_200mW_1s_HEAT,
    HIGH_POWER_100ms   = SHT40_200mW_100ms_HEAT,
    MEDIUM_POWER_1s    = SHT40_110mW_1s_HEAT,
    MEDIUM_POWER_100ms = SHT40_110mW_100ms_HEAT,
    LOW_POWER_1s       = SHT40_20mW_1s_HEAT,
    LOW_POWER_100ms    = SHT40_20mW_100ms_HEAT
} SHT40_HeaterOption;

/*
 * Initialization
 * Determines whether a successful I2C connection has been made by reading
 * the serial number of the device and calculating the CRC8 checksum
 */
HAL_StatusTypeDef SHT40_Initialize(const I2C_HandleTypeDef* i2cHandle);

/*
 * Measurement-Taking
 */
HAL_StatusTypeDef SHT40_Measure(const I2C_HandleTypeDef* i2cHandle, SHT40_Measurement* result, SHT40_Precision precision);

/*
 * Heater Control
 * SHT40_Measurement is optional (may be provided as NULL)
 */
HAL_StatusTypeDef SHT40_Heat(const I2C_HandleTypeDef* i2cHandle, SHT40_Measurement* result, SHT40_HeaterOption option);

/*
 * Reset/Serial
 */
HAL_StatusTypeDef SHT40_SoftReset(const I2C_HandleTypeDef* i2cHandle);
uint8_t SHT40_ReadSerial(const I2C_HandleTypeDef* i2cHandle);

#endif /* INC_SHT40_H_ */
