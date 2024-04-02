#pragma once
#include "t4corun.h"

void insert_brackets(uint16_t left, uint16_t right);
void double_tap(uint16_t keycode, uint32_t ms);
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode);