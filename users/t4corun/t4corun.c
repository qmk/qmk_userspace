#include "t4corun.h"

static uint8_t current_base_layer = _DEFAULT_LAYER_1;

layer_state_t layer_state_set_user(layer_state_t  state) {

  state = update_tri_layer_state(state, _NAVIGATION, _SYMBOL, _NUMBER);
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

    case RBSELYR:
      if (record->event.pressed) { 
        current_base_layer = (current_base_layer - 1) % NUM_BASE_LAYER; 
        set_single_persistent_default_layer(current_base_layer);
      }
      return false;

    case PN_DRGS:
      if (record->event.pressed) {
        //tap numlock twice to toggle ploopy nano drag scroll
        double_tap(KC_NUM, KC_NUM, WAIT_DELAY);
      }
      return false;

    case PN_PDPI:
      if (record->event.pressed) {
        //tap capslock twice to cycle ploopy nano pointer DPI
        double_tap(KC_CAPS, KC_CAPS, WAIT_DELAY);
      }
      return false;

/*
    case KC_BSPC: {
      //https://docs.qmk.fm/#/feature_advanced_keycodes?id=shift-backspace-for-delete

      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered = false;

      if (record->event.pressed) {

        uint8_t current_mod = get_mods();
        uint8_t current_osm = get_oneshot_mods();

        // Detect the activation of either shift keys
        if ((current_mod | current_osm) & MOD_MASK_SHIFT) {

          // First temporarily canceling both shifts so that
          // shift isn't applied to the KC_DEL keycode
          del_mods(MOD_MASK_SHIFT);
          del_oneshot_mods(MOD_MASK_SHIFT);

          // Press delete and keep track that key press
          register_code(KC_DEL);
          delkey_registered = true;

          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key
          set_mods(current_mod);
          set_oneshot_mods(current_osm);

          return false;

        }

      } else { // on release of KC_BSPC

        if(delkey_registered) {

          unregister_code(KC_DEL);
          delkey_registered = false;
          return false;

        }

      }

      // QMK will process Backspace instead
      // if the shift modifier is not detected
      return true;
    }
*/

    //https://docs.qmk.fm/#/mod_tap?id=changing-both-tasp-and-hold
    //https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
    //https://www.jonashietala.se/series/t-34/ he focuses on a keymap for programming/VIM
    case TR_LCBR:
    case TR_LABK:
    case TR_LBRC:
    case TR_LPRN:
    case TR_SQUO:
    case TR_EQL:
    case TR_BSLS:
    case TR_SLSH:
    case TR_COMM:
    case TR_DOT:
    case TR_PERC:
    case TR_EXLM:
    case TR_AT: 
    case TR_QUES:
    case TR_MINS:
    case TR_GRV:
    case TR_SCLN:
    case TR_QUOT:
      return process_tap_hold_key(record, keycode);

  }
  return true;
}