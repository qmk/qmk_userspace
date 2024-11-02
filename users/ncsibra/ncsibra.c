#include "ncsibra.h"

// Tap hold keys
static taphold_t th_events[] = {
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_ESC,  .kc_hold = KC_F11 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_1,    .kc_hold = KC_F1 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_2,    .kc_hold = KC_F2 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_3,    .kc_hold = KC_F3 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_4,    .kc_hold = KC_F4 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_5,    .kc_hold = KC_F5 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_6,    .kc_hold = KC_F6 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_7,    .kc_hold = KC_F7 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_8,    .kc_hold = KC_F8 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_9,    .kc_hold = KC_F9 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_0,    .kc_hold = KC_F10 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_BSPC, .kc_hold = KC_F12 },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if keycode is ESC or at least contains ESC(in case of Mod Tap etc) and one shot modifier or one shot layer is active, then cancel
  if (record->event.pressed && OSK_ACTIVE() && ((keycode & 0xFF) == KC_ESC)) {
    layer_off(get_oneshot_layer());
    reset_oneshot_layer();
    clear_oneshot_mods();
    return false;
  }

  return process_record_user_taphold(keycode, record);
};

static uint16_t prev_th_key = KC_NO;
static uint16_t prev_th_time = 0;

bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      matrix_scan_tap_hold(TAPPED);
  }

  if (keycode < TH_FIRST || keycode > TH_LAST) { return true; }

  taphold_t *th_event = &th_events[keycode - TH_FIRST];

  // if pressed twice fast, hold KC_TAP instead of usual logic, Mod Tap functionality works similarly
  if (record->event.pressed) {
    if (keycode == prev_th_key && timer_elapsed(prev_th_time) < TH_DELAY) {
      register_code16(th_event->kc_tap);
      th_event->is_double = true;
      return false;
    } else {
      prev_th_key = keycode;
      prev_th_time = timer_read();
    }
  }

  if (record->event.pressed) {
      th_event->timer = timer_read();
      th_event->is_pressed = true;
  } else if (th_event->is_pressed) {
      register_code16(th_event->kc_tap);
      unregister_code16(th_event->kc_tap);
      th_event->is_pressed = false;
  } else if (th_event->is_double) {
      unregister_code16(th_event->kc_tap);
      th_event->is_double = false;
  }

  return false;
}

void matrix_scan_tap_hold(taphold_state state) {
  for (uint8_t index = 0 ; index < TH_EVENTS_COUNT ; ++index ) {
      taphold_t *th_event = &th_events[index];
      if (!th_event->is_pressed) { continue; }
      if (state == TAPPED || timer_elapsed(th_event->timer) > TH_DELAY) {
          uint16_t code = state == HELD ? th_event->kc_hold : th_event->kc_tap;
          register_code16(code);
          unregister_code16(code);
          th_event->is_pressed = false;
      }
  }
}


void matrix_scan_user(void) {
    matrix_scan_tap_hold(HELD);
}
