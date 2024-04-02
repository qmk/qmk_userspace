#include "t4corun.h"

layer_state_t layer_state_set_user(layer_state_t  state) {

  state = update_tri_layer_state(state, _NAVIGATION, _NUMBER, _SYMBOL);
  return state;

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

  case QWERTY:
    if (record->event.pressed) { set_single_persistent_default_layer(_QWERTY); } //default_layer_set(1UL<<_QWERTY); }
    return false;

  case CLMAKDH:
    if (record->event.pressed) { set_single_persistent_default_layer(_COLEMAK_DH); } //default_layer_set(1UL<<_COLEMAK_DH); }
    return false;

  case GAME:
    if (record->event.pressed) { set_single_persistent_default_layer(_GAME); } //default_layer_set(1UL<<_COLEMAK_DH); }
    return false;

  case PN_DRGS:
    if (record->event.pressed) { 
      double_tap(KC_NUM, WAIT_DELAY);
    }
    return false;
  
  case PN_PDPI:
    if (record->event.pressed) { 
      double_tap(KC_CAPS, WAIT_DELAY);
    }
    return false;

  //https://docs.qmk.fm/#/mod_tap?id=changing-both-tasp-and-hold
  //https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
  //https://www.jonashietala.se/series/t-34/ he focuses on a keymap for programming/VIM
  case TR_LCBR:
  case TR_LABK:
  case TR_LBRC:
  case TR_SQUO:
  case TR_DQUO:
  case TR_LPRN:
  case TR_COMM:
  case TR_DOT:
  case TR_PERC:
  case TR_EQL:
  case TR_MINS:
  case TR_GRV:
  case TR_SCLN:
  case TR_QUOT:
    return process_tap_hold_key(record, keycode);


  }
  return true;
}