// vim: tabstop=2:softtabstop=2:shiftwidth=2

/**
 * Feature libraries
 */
#include "features/layer_lock.h"

/**
 * Layers
 */
enum custom_layers {
  _BASE,
  _NAV,
  _SYM,
  _FUN,
};

/**
 * Custom keys
 */
enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  SELLINE,
  UPDIR,
  USRNAME,
  LITERAL,
  ARROW,
  ARROW_RE,
};

/**
 * Key aliases to improve readability
 */

#define CTL_ESC LCTL_T(KC_ESC)   // 'Escape' when tapped, 'Control' when held
#define CTL_ENT LCTL_T(KC_ENT)   // 'Enter' when tapped, 'Control' when held
#define ENT_SFT LSFT_T(KC_ENT)   // 'Space' when tapped, 'Shift' when held
#define BS_NAV LT(_NAV, KC_BSPC) // 'Backspace' when tapped, 'MO(_NAV)' when held

#define MO_SYM MO(_SYM)

#define REDO C(S(KC_Z))

// One Shot Modifiers
#define OSM_LS OSM(MOD_LSFT)
#define OSM_RS OSM(MOD_RSFT)
#define OSM_A OSM(MOD_LALT)
#define OSM_G OSM(MOD_LGUI)
#define OSM_C OSM(MOD_LCTL)
#define OSM_CS OSM(MOD_LCTL | MOD_LSFT)

// Selecting/extending words
#define WORD_PR C(KC_LEFT)
#define WORD_NX C(KC_RGHT)
#define SELALL C(KC_A)

// Navigating browser tabs
#define TAB_PR C(KC_PGUP)
#define TAB_NX C(KC_PGDN)
#define TAB_CL C(KC_W)
#define TAB_RE C(S(KC_T))

/**
 * Caps Word (https://docs.qmk.fm/features/caps_word)
 */
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;

      // Keycodes that continue Caps Word, without shifting
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word
  }
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

  // Macros
  if (record->event.pressed) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
      case UPDIR:
        SEND_STRING("../");
        return false;

      case USRNAME:
        SEND_STRING("chzerv");
        return false;

      case LITERAL:
        SEND_STRING("\"${}\""SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false;

      case SELLINE:
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
        return false;

      case ARROW:
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          del_oneshot_mods(MOD_MASK_SHIFT);
          unregister_mods(MOD_MASK_SHIFT);
          SEND_STRING("=>");
          register_mods(mods);
        } else {
          SEND_STRING("->");
        }
        return false;

      case ARROW_RE:
        SEND_STRING("<-");
        return false;
    }
  }

  return true;
}
