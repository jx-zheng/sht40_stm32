/*
 * sht40.c
 * Author: Kevin Zheng
 */

#include "sht40.h"

static bool verify_checksum(uint16_t data, uint8_t checksum);
static float hardware_to_celsius(uint8_t reading);
static float hardware_to_humidity_percentage(uint8_t reading);

static bool verify_checksum(uint16_t data, uint8_t checksum) {
    static const uint8_t POLYNOMIAL = 0x31;
    uint8_t crc = 0xFF;

    for (uint8_t i = 0; i < 16; i++) {
        uint8_t bit = (data & 0x8000) >> 15;
        data <<= 1;
        crc ^= bit;

        if (crc & 0x80) {
            crc = (crc << 1) ^ POLYNOMIAL;
        } else {
            crc <<= 1;
        }
    }

    return crc == checksum;
}

static float hardware_to_celsius(uint16_t reading) {
    return -45.0 + 175.0 * (reading / 65535.0);
}

static float hardware_to_humidity_percentage(uint16_t reading) {
    return -6.0 + 125.0 * (reading / 65535.0);
}
