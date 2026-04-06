/*
    File:    finger-reading-oracle-machine.ino
    Created: 2026.04.06.
    Author:  Daniel Szilagyi
*/

#include "src/config.hpp"
#include "src/touch_handler/touch.hpp"

void touch_cb(void);

void setup(void)
{
    Serial.begin(115200);
    touch_init(TOUCH_PIN, &touch_cb, TOUCH_TIME_MIN);
}

void loop(void)
{
    uint32_t time_now = millis();
    touch_update(time_now);
}

void touch_cb(void)
{
    Serial.println("TOUCH DETECTED");
}
