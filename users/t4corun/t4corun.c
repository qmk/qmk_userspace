#include "t4corun.h"

static uint8_t current_base_layer = _DEFAULT_LAYER_1;

layer_state_t layer_state_set_user(layer_state_t  state) {

  state = update_tri_layer_state(state, _NAVIGATION, _NUMBER, _SYMBOL);
  return state;

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    
    case BASELYR:
      if (record->event.pressed) { 
        current_base_layer = (current_base_layer + 1) % NUM_BASE_LAYER; 
        set_single_persistent_default_layer(current_base_layer);
      }
      return false;

    //https://docs.qmk.fm/#/mod_tap?id=changing-both-tasp-and-hold
    //https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
    //https://www.jonashietala.se/series/t-34/ he focuses on a keymap for programming/VIM
    case TR_LCBR:
    case TR_LABK:
    case TR_LBRC:
    case TR_LPRN:
    case TR_SQUO:
    case TR_DQUO:
    case TR_EQL:
    case TR_PLUS:
    case TR_PIPE:
    case TR_COMM:
    case TR_DOT:
    case TR_PERC:
    case TR_EXLM:
    case TR_MINS:
    case TR_GRV:
    case TR_SCLN:
    case TR_QUOT:
    case PN_DRGS:
    case PN_PDPI:
      return process_tap_hold_key(record, keycode);

  }
  return true;
}