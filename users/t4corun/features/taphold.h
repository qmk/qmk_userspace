#pragma once
#include "t4corun.h"

void single_tap(uint16_t key);
void double_tap(uint16_t key, uint32_t ms);
void insert_brackets(uint16_t left, uint16_t right, uint32_t ms);
bool process_tap_hold_key(keyrecord_t* record, uint16_t tap_keycode, uint16_t hold_keycode, int mode);