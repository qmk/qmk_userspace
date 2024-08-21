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
void setLunaJumped(void) { showedJump = true; }
#endif // WPM_ENABLE


// Hold Navigation and Number to get Symbol
layer_state_t layer_state_set_user(layer_state_t state) { 
  return update_tri_layer_state(state, _NAVIGATION, _NUMBER, _SYMBOL);
}

// helper function to adjust default layer
void set_default_layer(bool forward) {
  current_base_layer = forward ? 
    (current_base_layer + 1) % NUM_DEFAULT_LAYERS : 
    (current_base_layer - 1) % NUM_DEFAULT_LAYERS;
  set_single_persistent_default_layer(current_base_layer);
}

// helper function to put ploopy nano into bootloader
// my ploopy nano will reset when num/caps/scroll lock is enabled
void reset_ploopynano(void) {
  // turn on all three host states
  if(!host_keyboard_led_state().num_lock) { tap_code(KC_NUM); }
  if(!host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
  if(!host_keyboard_led_state().scroll_lock) { tap_code(KC_SCRL); }

  // then turn them off
  tap_code(KC_NUM);
  tap_code(KC_CAPS);
  tap_code(KC_SCRL);
}

// Customize behavior for existing keycodes or create new ones
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  current_mods = get_mods() | get_oneshot_mods();
  
  switch (keycode) {

    // makes scroll lock a hold instead of toggle
    // enables momentary drag scroll on ploopy nano
    case KC_SCRL:
      record->event.pressed ? tap_code(KC_SCRL) : tap_code(KC_SCRL);
      return false;

    // makes num lock a hold instead of toggle
    // prevents accidental ploopy nano going into bootloader
    case KC_NUM:
      record->event.pressed ? tap_code(KC_NUM) : tap_code(KC_NUM);
      return false;

    // controls luna pet OLED animation
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

    // turn encoder for tab and shift tab
    // hold alt or ctrl while turning for window / tab switching
    case FWD_TAB:
    case REV_TAB:
      if (record->event.pressed) {
        if (keycode == FWD_TAB && !hold_forward_active) {
          hold_forward_active = true;
          hold_reverse_active = false;
          unregister_mods(MOD_MASK_SHIFT);
        }
        if (keycode == REV_TAB && !hold_reverse_active) {
          hold_forward_active = false;
          hold_reverse_active = true;
          register_mods(MOD_MASK_SHIFT);
        }
        hold_mod_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    // turn encoder for mouse wheel zoom
    case ZOOMIN:
    case ZOOMOUT:
      if (record->event.pressed) {
        if (!hold_forward_active) {
          hold_forward_active = true;
          register_mods(MOD_MASK_CTRL);
        }
        hold_mod_timer = timer_read();
        keycode == ZOOMIN ? register_code(KC_WH_U) : register_code(KC_WH_D);
      } else {
        keycode == ZOOMIN ? unregister_code(KC_WH_U) : unregister_code(KC_WH_D);
      }
      return false;

    // turn encoder while holding mod combinations to adjust features
    // e.g. RGB settings, haptic frequency, click frequency, base layer
    case FWD_CFG:
    case REV_CFG:
      if (record->event.pressed) {
        if (!hold_forward_active) {
          hold_forward_active = true;
        }
        hold_mod_timer = timer_read();
        switch (current_mods) {
#if defined(RGB_MATRIX_ENABLE)
          case MOD_BIT(KC_LSFT):
            keycode == FWD_CFG ? rgb_matrix_increase_hue() : rgb_matrix_decrease_hue();
            break;
          case MOD_BIT(KC_LCTL):
            keycode == FWD_CFG ? rgb_matrix_increase_sat() : rgb_matrix_decrease_sat();
            break;
          case MOD_BIT(KC_LALT):
            keycode == FWD_CFG ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
            break;        
          case MOD_BIT(KC_LGUI):
            keycode == FWD_CFG ? rgb_matrix_increase_speed() : rgb_matrix_decrease_speed();
            break;
          case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL):
            keycode == FWD_CFG ? rgb_matrix_step() : rgb_matrix_step_reverse();
            break;
#endif //RGB_MATRIX_ENABLE
#if defined(HAPTIC_ENABLE)
          case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
            keycode == FWD_CFG ? haptic_mode_increase() : haptic_mode_decrease();
            break;
#endif //HAPTIC_ENABLE
#if defined(AUDIO_ENABLE)
          case MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI):
            keycode == FWD_CFG ? clicky_freq_up() : clicky_freq_down();
            break;
#endif //AUDIO_ENABLE
          default:
            keycode == FWD_CFG ? set_default_layer(true) : set_default_layer(false);
            break;
        }
      }
      return false;

    // press key while holding mod combinations to toggle features or enter bootloader
    case TOG_CFG:
      if (record->event.pressed) {
        switch (current_mods) {
          case MOD_BIT(KC_LSFT):
            reset_keyboard();
            break;
          case MOD_BIT(KC_LCTL):
            reset_ploopynano();
            break;
#if defined(RGB_MATRIX_ENABLE)
          case MOD_BIT(KC_LALT):
            rgb_matrix_toggle();
            break;
#endif //RGB_MATRIX_ENABLE
#if defined(COMBO_ENABLE)
          case MOD_BIT(KC_LGUI):
            combo_toggle();
            break;
#endif //COMBO_ENABLE
#if defined(HAPTIC_ENABLE)
          case MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL):
            haptic_toggle();
            break;
#endif //HAPTIC_ENABLE
#if defined(AUDIO_ENABLE)
          case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT):
            is_audio_on() ? audio_off(): audio_on();
            break;
          
          case MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI):
            clicky_toggle();
            break;
#endif //AUDIO_ENABLE
          default:
            set_default_layer(true);
            break;
        }
      }
      unregister_mods(MOD_MASK_CSAG);
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

void matrix_scan_user(void) {
  // timer for the hold mods
  if (hold_forward_active || hold_reverse_active) {
    if (timer_elapsed(hold_mod_timer) > HOLD_MOD_TIMEOUT) {
      unregister_mods(MOD_MASK_CSAG);
      hold_forward_active = false;
      hold_reverse_active = false;
    }
  }
}