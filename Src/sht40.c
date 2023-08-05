/*
 * sht40.c
 * Author: Kevin Zheng
 */

#include "sht40.h"

static bool verify_checksum(uint16_t data, uint8_t checksum) {
    // TODO
    return false;
}

static float hardware_to_celsius(uint8_t reading) {
    // TODO
    return 0.0;
}

static float hardware_to_humidity_percentage(uint8_t reading) {
    // TODO
    return 0.0;
}
