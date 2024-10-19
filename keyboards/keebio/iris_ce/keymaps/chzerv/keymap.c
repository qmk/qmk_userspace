#include QMK_KEYBOARD_H
#include "features/select_word.h"

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
    _FUN,
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
// KEYMAP //
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
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
     _______, _______, TAB_EXT, TAB_PRV, TAB_NXT, TAB_NEW,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_BSPC,
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
     _______, KC_QUOT, KC_LT,   KC_GT,   KC_DQUO, KC_GRV,                             LITERAL, KC_LBRC, KC_RBRC, KC_COLN,  KC_AT,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_EQL,  KC_UNDS, KC_DLR,  KC_ASTR,                            KC_SLSH, KC_LPRN, KC_RPRN, KC_SCLN, KC_QUES, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PIPE, KC_AMPR, KC_MINS, KC_PLUS, KC_PERC, UPDIR,            _______, KC_TILD, KC_LCBR, KC_RCBR, KC_RCBR, KC_SLSH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, MS_UP,   MS_WHLD, MS_WHLU, MS_BTN3,                            UG_TOGG, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN1, MS_BTN2,                            UG_NEXT, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, EE_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,XXXXXXX, XXXXXXX,          _______, XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX, QK_BOOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, CW_TOGG, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Macros
    if (record->event.pressed) {
        switch (keycode) {
            case UPDIR:
                SEND_STRING("../");
                return false;
            case LITERAL:
                SEND_STRING("\"${}\"" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return false;
        }
    }

    // Select word
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

    return true;
}

void matrix_scan_user(void) {
    select_word_task();
}

//
// Caps Word configuration
// https://docs.qmk.fm/features/caps_word
//
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Configure keycodes that continue caps word
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to alphas.
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false; // Deactivate Caps Word
    }
}
