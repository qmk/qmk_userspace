#include "tapping.h"

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  //This is effective for all dual role keys (e.g. Mod-Taps, Layer-Taps, etc)
  switch(keycode) {
    default:
      //Disable HOLD_ON_OTHER_KEY_PRESS aka enable IGNORE_MOD_TAP_INTERRUPT 
      return false;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    default:
      return QUICK_TAP_TERM;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    default:
      //uprintf("tapping term: %d \n", TAPPING_TERM);
      return TAPPING_TERM;
  }
}