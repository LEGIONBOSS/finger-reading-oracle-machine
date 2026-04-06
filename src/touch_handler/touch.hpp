/*
    File:    touch.hpp
    Created: 2026.04.06.
    Author:  Daniel Szilagyi
*/

#ifndef TOUCH_H_
#define TOUCH_H_

#include <stdint.h>

uint8_t touch_init(uint8_t pin, void (*touch_cb)(void), uint32_t touch_time_min = 1000);
uint8_t touch_update(uint32_t time_ms);
uint8_t touch_get_state(uint8_t* state);

#endif // TOUCH_H_
