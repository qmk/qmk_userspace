// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "rpw.c"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWR,
    _SYM,
    _NUM,
    _NAV,
    _BORK,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_RHLSC0  // right-hand layer shift/cycle
};

#define KC_RHLSC0 LT(_NAV, 1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWR] = LAYOUT(
        _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
        _______,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
        _______,  CTL_A,  ALT_S,   SFT_D,   GUI_F,   KC_G,                      KC_H,    GUI_J,   SFT_K,   ALT_L,  CTL_QUOT,  KC_QUOT,
        _______,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,    _______, KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                        KC_LGUI,KC_LALT,KC_LCTL, LT(_NAV, 1), MO(_SYM),        NUM_SPC,  KC_RHLSC0, KC_RCTL, KC_RALT, KC_RGUI
    ),

    [_SYM] = LAYOUT(
        _______,  _______ , _______ , _______ , _______ , _______,                     _______ , _______ , _______ , _______ , _______,  _______,
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     _______,
        _______, _______ , _______ , _______ , _______ , _______,                      KC_MINS, GUI_EQL, SFT_LBRC, ALT_RBRC, CTL_BSLS, _______,
        _______,  KC_EQL, KC_MINS, KC_PLUS, KC_TILD, KC_RCBR, _______,       _______,  KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,
                            _______, _______, _______, _______, _______,    TO(_QWR), _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
        _______, _______,  _______,  _______,  _______, _______,                       KC_TRNS, KC_RGUI, KC_RSFT, KC_RALT, CTL_SCLN, _______,
        _______, C(KC_Z), C(KC_X), C(KC_C), KC_TILD, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                                _______, _______, _______, KC_TILD, KC_DEL,       _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                       _______,  _______  , _______,  _______ ,  _______ ,_______,
        _______, KC_TAB  , KC_TILD,  _______,  _______,  _______,                            KC_6,    KC_7,    KC_8,    KC_DEL,   KC_BSPC,  _______,
        _______, KC_ESC  , _______,  _______,  _______,  _______,                        KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_ENT,  KC_TRNS,
        _______, C(KC_Z), C(KC_X), C(KC_C), KC_TILD, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   _______, _______,
                                _______, _______, _______, KC_TILD, KC_DEL,       _______, _______, _______, _______, _______
    ),

    [_BORK] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
        _______, KC_TAB,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_DEL,  KC_BSPC,  _______,
        _______, QK_GESC,   KC_B,    KC_O,    KC_R,    KC_K,                       KC_Z, KC_B, KC_O, KC_R, KC_K,  KC_TRNS,
        _______, C(KC_Z), C(KC_X), C(KC_C), KC_TILD, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                                _______, _______, _______, KC_TILD, TO(_QWR),       _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RHLSC0:
            if (record->tap.count && record->event.pressed) {
                layer_on(_SYM);      // When held switch the Symbol layer
                return false;        // Return false to ignore further processing of key
            }
            break;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
