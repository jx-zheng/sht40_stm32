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
#define SHT40_200mW_1S_HEAT    0x39
#define SHT40_200mW_100MS_HEAT 0x32
#define SHT40_110mW_1S_HEAT    0x2F
#define SHT40_110mW_100MS_HEAT 0x24
#define SHT40_20mW_1S_HEAT     0x1E
#define SHT40_20mW_100MS_HEAT  0x15

/*
 * Sensor Handle
 */
typedef struct {

    /* I2C handle */
    I2C_HandleTypeDef *i2cHandle;

    /* Whether to calculate checksums */
    bool checksums;

} SHT40;

#endif /* INC_SHT40_H_ */
