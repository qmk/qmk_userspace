#include "taphold.h"


void double_tap( uint16_t key, uint32_t ms) {
  tap_code16(key);
  wait_ms(ms);
  tap_code16(key);
}

void insert_brackets (uint16_t left, uint16_t right, uint32_t ms) {
  tap_code16(left);
  wait_ms(ms);
  tap_code16(right);
  wait_ms(ms);
  tap_code16(KC_LEFT);
}

bool process_tap_hold_key (keyrecord_t* record, uint16_t tap_keycode, uint16_t hold_keycode, int mode) {
  if (record->tap.count > 0) { // Key is being tapped
    // register on press, unregister on release
    record->event.pressed ? register_code16(tap_keycode) : unregister_code16(tap_keycode);
  } else { // Key is being hel
    switch (mode) {
      case HOLD_BRACKETS:
        record->event.pressed ? insert_brackets(tap_keycode, hold_keycode, TAP_CODE_DELAY) : 0;
        break;

      case HOLD_DOUBLETP:
        record->event.pressed ? double_tap(tap_keycode, TAP_CODE_DELAY) : 0;
        break;

      default:
        record->event.pressed ? register_code16(hold_keycode) : unregister_code16(hold_keycode);
        break;
    }
  }
  return false;
}

