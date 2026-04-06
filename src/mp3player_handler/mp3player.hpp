#ifndef MP3PLAYER_H_
#define MP3PLAYER_H_

#include <stdint.h>
#include <Arduino.h>

uint8_t mp3player_init(HardwareSerial* serial, uint8_t volume = 24, uint8_t scan_voice_folder = 1, uint8_t scan_voice_count = 3, uint8_t scan_sound_folder = 2, uint8_t scan_sound_count = 1, uint8_t result_voice_folder = 3, uint8_t result_voice_count = 20);
uint8_t mp3player_play_program(void);
uint8_t mp3player_stop(void);
uint8_t mp3player_get_playing(uint8_t* playing);

#endif // MP3PLAYER_H_
