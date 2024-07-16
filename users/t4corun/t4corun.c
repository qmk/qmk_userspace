#include "t4corun.h"


// Keeps track of base layer so only one key is needed 
// to cycle through them vs making three individual ones
static uint8_t current_base_layer = FIRST_DEFAULT_LAYER;

// keep track of current mods to override existing keys
static uint8_t current_mods;

// enables encoder to handle alt/ctrl tab and ctrl scroll wheel
static bool hold_forward_active = false;
static bool hold_reverse_active = false;
static uint16_t hold_mod_timer = 0;

#if defined(WPM_ENABLE)
// Luna Pet Variables
static bool isJumping = false;
static bool showedJump = true;

// Allows the OLED code to see when space bar is pressed
bool isLunaJumping(void) { return isJumping; }
bool isJumpShown(void) { return showedJump; }

// Allows the OLED code to clear the space bar status when render is complete
void setLunaJumped(void) { showedJump = true;}
#endif // WPM_ENABLE


// Hold Navigation and Number to get Symbol
layer_state_t layer_state_set_user(layer_state_t state) { 
  return update_tri_layer_state(state, _NAVIGATION, _NUMBER, _SYMBOL); 
}


// Customize behavior for existing keycodes or create new ones
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  current_mods = get_mods() | get_oneshot_mods();
  
  switch (keycode) {

    // use the host state status to boot the Ploopy Nano
    // will effectively turn on num lock/caps lock/scroll lock then back off
    case PN_BOOT:
      if (record->event.pressed) {
        if(!host_keyboard_led_state().num_lock) { tap_code(KC_NUM); }
        if(!host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
        if(!host_keyboard_led_state().scroll_lock) { tap_code(KC_SCRL); }
      } else {
        if(host_keyboard_led_state().num_lock) { tap_code(KC_NUM); }
        if(host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
        if(host_keyboard_led_state().scroll_lock) { tap_code(KC_SCRL); }
      }
      return false;

    // makes scroll lock a hold instead of toggle
    // enables momentary drag scroll on ploopy nano
    case KC_SCRL:
      if (record->event.pressed) {
        tap_code(KC_SCRL);
      } else {
        tap_code(KC_SCRL);
      }
      return false;


    // makes num lock a hold instead of toggle
    // prevents accidental ploopy nano going into bootloader
    case KC_NUM:
      if (record->event.pressed) {
        tap_code(KC_NUM);
      } else {
        tap_code(KC_NUM);
      }
      return false;

#if defined(WPM_ENABLE)
    case KC_SPC:
      if (record->event.pressed) {
        isJumping = true;
        showedJump = false;
      }
      else {
        isJumping = false;
      }
      break;
#endif // WPM_ENABLE

    case BASELYR:
      if (record->event.pressed) {
        current_base_layer = (current_base_layer + 1) % NUM_DEFAULT_LAYERS; 
        set_single_persistent_default_layer(current_base_layer);
      }
      return false;

    case RBSELYR:
      if (record->event.pressed) { 
        current_base_layer = (current_base_layer - 1) % NUM_DEFAULT_LAYERS; 
        set_single_persistent_default_layer(current_base_layer);
      }
      return false;

    case FWD_TAB:
    case REV_TAB:
      if (record->event.pressed) {
        if (keycode == FWD_TAB && !hold_forward_active) {
          hold_forward_active = true;
          hold_reverse_active = false;
          unregister_code(KC_LSFT);
        }
        if (keycode == REV_TAB && !hold_reverse_active) {
          hold_forward_active = false;
          hold_reverse_active = true;
          register_code(KC_LSFT);
        }
        hold_mod_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    case ZOOMIN:
    case ZOOMOUT:
      if (record->event.pressed) {
        if (!hold_forward_active) {
          hold_forward_active = true;
          register_code(KC_LCTL);
        }
        hold_mod_timer = timer_read();
        if (keycode == ZOOMIN) {
          register_code(KC_WH_U);
        } else {
          register_code(KC_WH_D);
        }
      } else {
        if (keycode == ZOOMIN) {
          unregister_code(KC_WH_U);
        } else {
          unregister_code(KC_WH_D);
        }
      }
      return false;

#if defined(RGB_MATRIX_ENABLE)
    case FWD_RGB:
    case REV_RGB:
      if (record->event.pressed) {
        switch (current_mods) {
          case MOD_BIT(KC_LSFT):
            keycode == FWD_RGB ? rgb_matrix_increase_hue() : rgb_matrix_decrease_hue();
            break;

          case MOD_BIT(KC_LCTL):
            keycode == FWD_RGB ? rgb_matrix_increase_sat() : rgb_matrix_decrease_sat();
            break;

          case MOD_BIT(KC_LALT):
            keycode == FWD_RGB ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
            break;
          
          case MOD_BIT(KC_LGUI):
            keycode == FWD_RGB ? rgb_matrix_increase_speed() : rgb_matrix_decrease_speed();
            break;

          default:
            keycode == FWD_RGB ? rgb_matrix_step() : rgb_matrix_step_reverse();
            break;    
        }
      }
      return false;
#endif


#if defined(HAPTIC_ENABLE)
    case TR_HNXT:
      if (record->event.pressed) {
        if( current_mods & MOD_MASK_SHIFT ) {
          haptic_mode_decrease();
        } else {
          haptic_mode_increase();
        }
      }
      return false;
#endif

#if defined(AUDIO_ENABLE)
    case TR_CKUP:
      if (record->event.pressed) {
        if( current_mods & MOD_MASK_SHIFT ) {
          clicky_freq_down();
        } else {
          clicky_freq_up();
        }
      }
      return false;
#endif


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

void matrix_scan_user(void) {
  // timer for the hold mods
  if (hold_forward_active || hold_reverse_active) {
    if (timer_elapsed(hold_mod_timer) > HOLD_MOD_TIMEOUT) {
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      hold_forward_active = false;
      hold_reverse_active = false;
    }
  }
}