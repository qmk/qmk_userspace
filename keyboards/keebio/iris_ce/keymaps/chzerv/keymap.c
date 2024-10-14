#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/autocorrection.h"
#include "features/achordion.h"

// Select word (https://getreuer.info/posts/keyboards/select-word/index.html)
enum custom_keycodes {
    SELWORD = SAFE_RANGE,
    UPDIR,
    LITERAL,
};

// Layers
enum custom_layers {
    _BASE,
    _SYM,
    _NAV,
    _FUN
};

// Aliases for mappings
#define MO_SYM MO(_SYM)
#define MO_NAV MO(_NAV)
#define FUN_ENT LT(_FUN, KC_ENT)

// `Escape` when tapped, `Control` when held
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

// One shot modifiers, used in the navigation layer (_NAV)
#define OSM_G OSM(MOD_LGUI)
#define OSM_A OSM(MOD_LALT)
#define OSM_S OSM(MOD_LSFT)
#define OSM_C OSM(MOD_LCTL)

#define TAB_NXT C(KC_PGDN)
#define TAB_PRV C(KC_PGUP)
#define TAB_NEW C(KC_T)
#define TAB_EXT C(KC_W)
#define WORD_N C(KC_RIGHT)
#define WORD_P C(KC_LEFT)
#define TMUX_ C(KC_SPC) // TMUX prefix key (Ctrl+Spc)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
// KEYMAP //
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_S,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TMUX_,            KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_S,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, MO_NAV,  FUN_ENT,                   KC_SPC,  MO_SYM,  OSM_A
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    // The number row stays so we can do `Mod+Number` for navigating DE/WM workspaces
    [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, TAB_EXT, TAB_NXT, TAB_PRV, TAB_NEW,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, OSM_G,   OSM_A,   OSM_S,   OSM_C,   _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,SELWORD, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _______, _______,          _______, WORD_P,  _______, _______, WORD_N, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TMUX_,   KC_QUOT, KC_LT,   KC_GT,   KC_DQUO, KC_TILD,                            LITERAL, KC_LBRC, KC_RBRC, KC_RBRC, KC_AT,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_EQL,  KC_UNDS, KC_DLR,  KC_ASTR,                            KC_SLSH, KC_LPRN, KC_RPRN, KC_SCLN, KC_QUES, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PIPE, KC_AMPR, KC_MINS, KC_PLUS, KC_PERC, _______,          UPDIR,   KC_TILD, KC_LCBR, KC_RCBR, KC_RCBR, KC_SLSH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),


    [_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, MS_BTN1, MS_UP,   MS_BTN2, MS_BTN3, XXXXXXX,                            UG_TOGG, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MS_LEFT, MS_DOWN, MS_RGHT, DT_UP,   DT_DOWN,                            UG_NEXT, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, EE_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,XXXXXXX, XXXXXXX,          _______, XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX, QK_BOOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, CW_TOGG, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

// Replaces a mod-tap key's hold function with its one-shot counterpart.
static bool oneshot_mod_tap(uint16_t keycode, keyrecord_t* record) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      const uint8_t mods = (keycode >> 8) & 0x1f;
      add_oneshot_mods(((mods & 0x10) == 0) ? mods : (mods << 4));
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Start achordion
    if (!process_achordion(keycode, record)) { return false; }

    // Macros
    if (record->event.pressed) {
        switch (keycode) {
            case UPDIR:
                SEND_STRING("../");
                return false;
            case LITERAL:
                SEND_STRING("\"${}\""SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                return false;
        }
    }

    // One shot modifiers when HRMs are held
    // https://getreuer.info/posts/keyboards/achordion/index.html#one-shot-mod-tap-key
    switch (keycode) {
        case HOME_D:
        case HOME_S:
        case HOME_F:
        case HOME_K:
        case HOME_J:
        case HOME_L:
            return oneshot_mod_tap(keycode, record);
    }

    // Other macros...

    // Select word
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

    if (!process_autocorrection(keycode, record)) { return false; }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();

    select_word_task();
  // Other tasks...
}

//
// Achordion configuration
// https://getreuer.info/posts/keyboards/achordion/index.html
//
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    default:
      return 800;
  }
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  // Disable streak detection on LT keys.
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;
  }

  // Disable streak detection on shortcuts such as Ctrl-C, Ctrl-V
  // e.g., Ctrl-C
  switch (tap_hold_keycode) {
    case HOME_F:
    case HOME_J:
      if (next_keycode == KC_C || next_keycode == KC_V) {
        return 0;
      }
      break;
  }

  return 200;
}


uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing.
  switch (keycode) {
    case HOME_J:
    case HOME_K:
    case HOME_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

bool achordion_chord(uint16_t tap_hold_keycode,
        keyrecord_t* tap_hold_record,
        uint16_t other_keycode,
        keyrecord_t* other_record) {

    return true;
}

//
// Caps Word configuration
// https://docs.qmk.fm/features/caps_word
//
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Configure keycodes that continue caps word
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false; // Deactivate Caps Word
    }
}
