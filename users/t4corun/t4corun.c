#include "t4corun.h"

// Keeps track of base layer so we can make one key to cycle through them
// instead of making a key for each one */
static uint8_t current_base_layer  = _DEFAULT_LAYER_1;

// Should keep track of the Ploopy Nano drag scroll mode
// There is a possibility of this being out of sync
static bool drag_scroll_enabled = false;

// Luna Pet Variables
static bool isJumping = false;
static bool showedJump = true;



// Allows the OLED code to get the drag scroll mode
bool drag_scroll_is_enabled(void) { return drag_scroll_enabled; }

// Allows the OLED code to see when space bar is pressed
bool isLunaJumping(void) { return isJumping; }
bool isJumpShown(void) { return showedJump; }

// Allows the OLED code to clear the space bar status when render is complete
void setLunaJumped(void) { showedJump = true;}

// Hold Navigation and Number to get Symbol
layer_state_t layer_state_set_user(layer_state_t  state) { return update_tri_layer_state(state, _NAVIGATION, _NUMBER, _SYMBOL); }

// Customize behavior for existing keycodes or create new ones
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case KC_SPC:
      if (record->event.pressed) {
        isJumping = true;
        showedJump = false;
      }
      else {
        isJumping = false;
      }
      break;

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
        // double_tap(KC_NUM, KC_NUM, WAIT_DELAY);
        double_tap(KC_NUM, WAIT_DELAY);

        //I realize this may not work for the Charybdis nano
        drag_scroll_enabled = !drag_scroll_enabled;
        
      }
      return false;

    case PN_PDPI:
      if (record->event.pressed) {

        //tap capslock twice to cycle ploopy nano pointer DPI
        //double_tap(KC_CAPS, KC_CAPS, WAIT_DELAY);
        double_tap(KC_CAPS, WAIT_DELAY);

      }
      return false;

    //https://docs.qmk.fm/#/mod_tap?id=changing-both-tasp-and-hold
    //https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
    //https://www.jonashietala.se/series/t-34/ he focuses on a keymap for programming/VIM
    // Brackets: open and close brackets and put the cursor inside
    case TR_LCBR:
      return process_tap_hold_key(record, KC_LCBR, KC_RCBR, HOLD_BRACKETS);
    case TR_LABK:
      return process_tap_hold_key(record, KC_LABK, KC_RABK, HOLD_BRACKETS);
    case TR_LBRC:
      return process_tap_hold_key(record, KC_LBRC, KC_RBRC, HOLD_BRACKETS);
    case TR_LPRN:
      return process_tap_hold_key(record, KC_LPRN, KC_RPRN, HOLD_BRACKETS);
    case TR_DQUO:
      return process_tap_hold_key(record, KC_DQUO, KC_DQUO, HOLD_BRACKETS);
    case TR_SQUO:
      return process_tap_hold_key(record, KC_QUOT, KC_QUOT, HOLD_BRACKETS);

    // double tap
    case TR_BSLS:
      return process_tap_hold_key(record, KC_BSLS, KC_BSLS, HOLD_DOUBLETP);
    case TR_SLSH:
      return process_tap_hold_key(record, KC_SLSH, KC_SLSH, HOLD_DOUBLETP);
    case TR_PIPE:
      return process_tap_hold_key(record, KC_PIPE, KC_PIPE, HOLD_DOUBLETP);

    // Custom override without holding shift
    case TR_COMM:
      return process_tap_hold_key(record, KC_COMM, KC_LPRN, HOLD_SINGLETP);
    case TR_DOT:
      return process_tap_hold_key(record, KC_DOT,  KC_RPRN, HOLD_SINGLETP);
    case TR_PERC:
      return process_tap_hold_key(record, KC_PERC, KC_CIRC, HOLD_SINGLETP);

    // auto shift
    case TR_EQL:
      return process_tap_hold_key(record, KC_EQL,  KC_PLUS, HOLD_SINGLETP);
    case TR_MINS:
      return process_tap_hold_key(record, KC_MINS, KC_UNDS, HOLD_SINGLETP);
    case TR_GRV:
      return process_tap_hold_key(record, KC_GRV,  KC_TILD, HOLD_SINGLETP);
    case TR_SCLN:
      return process_tap_hold_key(record, KC_SCLN, KC_COLN, HOLD_SINGLETP);
    case TR_QUOT:
      return process_tap_hold_key(record, KC_QUOT, KC_DQUO, HOLD_SINGLETP);

  }

  // let QMK process the normal behavior if not handled above
  return true;
}