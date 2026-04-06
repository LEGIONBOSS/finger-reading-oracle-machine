/*
    File:    config.hpp
    Created: 2026.04.06.
    Author:  Daniel Szilagyi
*/

#ifndef CONFIG_H_
#define CONFIG_H_

// LED
#define LED_PIN (13)                      // MCU built-in LED pin

// Touch sensor
#define TOUCH_PIN (19)                    // Touch sensor I/O pin
#define TOUCH_TIME_MIN (1000)             // Touch sensor minimum detection time

// DFPlayer
#define MP3PLAYER_UART_PIN_RX (17)        // MCU UART RX -> DFPlayer UART TX
#define MP3PLAYER_UART_PIN_TX (16)		  // MCU UART TX -> DFPlayer UART RX
#define MP3PLAYER_SCAN_VOICE_FOLDER (1)   // Scan voice mp3 files folder number
#define MP3PLAYER_SCAN_VOICE_COUNT (3)    // Scan voice mp3 files count
#define MP3PLAYER_SCAN_SOUND_FOLDER (2)   // Scan sound mp3 files folder number
#define MP3PLAYER_SCAN_SOUND_COUNT (1)	  // Scan sound mp3 files count
#define MP3PLAYER_RESULT_VOICE_FOLDER (3) // Result voice mp3 files folder number
#define MP3PLAYER_RESULT_VOICE_COUNT (20) // Result voice mp3 files count

#endif // CONFIG_H_
