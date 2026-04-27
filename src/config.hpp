/*
    File:    config.hpp
    Created: 2026.04.06.
    Author:  Daniel Szilagyi
*/

#ifndef CONFIG_H_
#define CONFIG_H_

// LED
#define LED_PIN (15) // MCU built-in LED pin

// Touch sensor
#define TOUCH_PIN (19)        // Touch sensor I/O pin
#define TOUCH_TIME_MIN (1000) // Touch sensor minimum detection time

// DFPlayer
#define MP3PLAYER_UART_PIN_RX (4)  // MCU UART RX -> DFPlayer UART TX
#define MP3PLAYER_UART_PIN_TX (5)  // MCU UART TX -> DFPlayer UART RX
#define MP3PLAYER_UART_BAUD (9600) // DFPlayer UART baud rate
#define MP3PLAYER_SOUND_COUNT (10) // Sound count

#endif // CONFIG_H_
