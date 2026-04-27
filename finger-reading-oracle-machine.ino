/*
    File:    finger-reading-oracle-machine.ino
    Created: 2026.04.21.
    Author:  Daniel Szilagyi
*/

#include "src/config.hpp"
#include "src/touch_handler/touch.hpp"
#include "src/DFRobotDFPlayerMini/DFRobotDFPlayerMini.h"

static uint8_t _track_num = 0;
static uint8_t _playing = 0;
DFRobotDFPlayerMini player;

void touch_cb(void);

void setup(void)
{
    // Init LED
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    // Init touch sensor
    touch_init(TOUCH_PIN, &touch_cb, TOUCH_TIME_MIN);

    // Init player
    Serial2.begin(MP3PLAYER_UART_BAUD, SERIAL_8N1, MP3PLAYER_UART_PIN_RX, MP3PLAYER_UART_PIN_TX);
    while (!player.begin(Serial2))
    {
        delay(0);
    }
    player.volume(30);

    // Init random track number
    randomSeed(analogRead(6));
    _track_num = random(1, MP3PLAYER_SOUND_COUNT + 1); // 1-10

    // Indicate ready state on LED
    digitalWrite(LED_PIN, HIGH);
}

void loop(void)
{
    touch_update(millis());

    if (player.available() > 0
        && player.readType() == DFPlayerPlayFinished)
    {
        // Clear playing flag
        _playing = 0;

        // Indicate ready state on LED
        digitalWrite(LED_PIN, HIGH);

        // Increment track number + wrap around
        if (++_track_num > MP3PLAYER_SOUND_COUNT)
        {
            _track_num = 1;
        }
    }
}

void touch_cb(void)
{
    if (!_playing)
    {
        player.play(_track_num);
        _playing = 1;
        digitalWrite(LED_PIN, LOW);
    }
}
