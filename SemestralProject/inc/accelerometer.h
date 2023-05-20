#ifndef __ACCELEROMETER_H
#define __ACCELEROMETER_H

#include "stm32_eval_spi_accel.h"

struct accelerometer {
    uint16_t current_vibration;
    uint16_t min;
    uint16_t max;
    uint8_t sample_flag;
};

extern struct accelerometer accelerometer_state;

void init_accelerometer();

uint16_t read_accelerotmeter_Y();

uint16_t read_accelerotmeter_X();

uint8_t sample_accelerometer();





#endif