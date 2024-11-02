#pragma once

typedef enum {
    TAPPED,
    HELD,
} taphold_state;

void matrix_scan_tap_hold(taphold_state state);
bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record);