/*
    File:    touch.cpp
    Created: 2026.04.06.
    Author:  Daniel Szilagyi
*/

#include <Arduino.h>
#include "touch.hpp"

static uint8_t _pin = 0;
static void (*_touch_cb)(void);
static uint32_t _touch_time_min = 0;
static uint8_t _init = 0;

static uint32_t _touch_start_time = 0;
static uint8_t _last_state = 0;
static uint8_t _cb_flag = 1;

uint8_t touch_init(uint8_t pin, void (*touch_cb)(void), uint32_t touch_time_min)
{
    // Check arguments
    if (!touch_cb) return 0;

    // Set locals
    _pin = pin;
    _touch_cb = touch_cb;
    _touch_time_min = touch_time_min;
    _init = 1;

    // Setup HW
    pinMode(_pin, INPUT);

    return 1;
}

uint8_t touch_update(uint32_t time_ms)
{
    if (!_init)
    {
        return 0;
    }

    uint8_t current_state = digitalRead(_pin);
    if (_last_state == 0 && current_state == 1)      // Touch down
    {
        _touch_start_time = time_ms;
    }
    else if (_last_state == 1 && current_state == 1) // Touch held
    {
        uint32_t touch_time = time_ms - _touch_start_time;
        if (touch_time >= _touch_time_min && _cb_flag)
        {
            _touch_cb();
            _cb_flag = 0; // Block further CB calls
        }
    }
    else if (_last_state == 1 && current_state == 0) // Touch release
    {
        _cb_flag = 1; // Enable CB again
    }
    _last_state = current_state;

    return 1;
}

uint8_t touch_get_state(uint8_t* state)
{
    // Check arguments
    if (!_init || !state)
    {
        return 0;
    }

    // Return state
    *state = digitalRead(_pin);

    return 1;
}
