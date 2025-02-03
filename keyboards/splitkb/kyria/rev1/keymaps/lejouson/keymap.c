// Copyright 2025 Jose Gisbert, aka lejouson <contacto@email.gont.es>
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include <keymap_spanish.h>

enum layers {
    _DEFAULT = 0,
    _NAVI,
    _FUNCTION,
    _SYMBOLS,
    _NUMERIC,
    _CONFIG
};

enum keycodes {
    KC_EMQM = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Default
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Ç     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  º  ª  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ñ  |  ´  ¨  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  ¿  ¡  |   Z  |   X  |   C  |   V  |   B  |SH/Del| Alt  |  | Tab  |LShift|   N  |   M  | ,  ; | . :  | -  _ |  ?  !  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |W+Sh+S| Caps | Lower| Bksp | Ctrl |  | Enter| Space| Raise| GUI  |  ≡   |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DEFAULT] = LAYOUT(
        KC_ESC,  ES_Q, ES_W, ES_E,      ES_R,    ES_T,                                                ES_Y,         ES_U,    ES_I,    ES_O,   ES_P,    ES_CCED,
        ES_MORD, ES_A, ES_S, ES_D,      ES_F,    ES_G,                                                ES_H,         ES_J,    ES_K,    ES_L,   ES_NTIL, ES_ACUT,
        ES_IEXL, ES_Z, ES_X, ES_C,      ES_V,    ES_B,      SFT_T(KC_DEL), KC_LALT, KC_TAB,  KC_LSFT, ES_N,         ES_M,    ES_COMM, ES_DOT, ES_MINS, KC_EMQM,
                             LSG(ES_S), KC_CAPS, MO(_NAVI), KC_BSPC,       KC_LCTL, KC_ENT,  KC_SPC,  MO(_SYMBOLS), KC_LGUI, KC_APP
    ),
/*
 * Navi
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | Ct+Y | Ct+Z | Ct+V | Ct+C | Ct+V |                              | PageUp| Home |  Up  | End  | C+Hom|        |
 * |--------+------+------+------+------+------|                              |-------+------+------+------+------+--------|
 * |        | GUI  | Alt  | Ctrl |LShift|      |                              | PDown | Left | Down | Right| C+End|Lay Lock|
 * |--------+------+------+------+------+------+-------------.  ,-------------+-------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |       |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+-------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |       |      |Ctrl+C|
 *                        `----------------------------------'  `-----------------------------------'
 */
    [_NAVI] = LAYOUT(
      _______, C(KC_Y),       C(KC_Z), C(KC_V), C(KC_C), C(KC_X),                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  C(KC_HOME), XXXXXXX,
      XXXXXXX, KC_LGUI,       KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, C(KC_END),  QK_LLCK,
      XXXXXXX, MO(_FUNCTION), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, C(KC_C)
    ),
/*
 * Function
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  F5  |  F11 |  F12 |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |  F1  |  F2  |  F3  |Alt+F4|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_F5,   KC_F11,  KC_F12,  XXXXXXX,  XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, XXXXXXX,                                     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   A(KC_F4), _______,
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Symbols
 *
 * ,-------------------------------------------.                              ,------------------------------------------.
 * |        |  |   |  &   |  {   |  }   |  "   |                              |  $   |  [   |  ]   |  %   |  @   |       |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+-------|
 * |   -    |  *   |  +   |  (   |  )   |  =   |                              |  ;   |  <   |  >   |  /   |  \   |       |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
 * |        |      |      |  ~   |  `   |  '   |      |      |  |      |      |  #   |  ^   |  €   |      |      |       |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
        _______, ES_PIPE, ES_AMPR, ES_LCBR, ES_RCBR, ES_DQUO,                                     ES_DLR,  ES_LBRC, ES_RBRC, ES_PERC, ES_AT,        XXXXXXX,
        ES_MINS, ES_ASTR, ES_PLUS, ES_LPRN, ES_RPRN, ES_EQL,                                      ES_SCLN, ES_LABK, ES_RABK, ES_SLSH, ES_BSLS,      _______,
        XXXXXXX, XXXXXXX, XXXXXXX, ES_TILD, ES_GRV,  ES_QUOT, _______, _______, _______, _______, ES_HASH, ES_CIRC, ES_EURO, XXXXXXX, MO(_NUMERIC), XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Numeric
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   6  |   7  |   8  |   9  |   0  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   /  |   :  |   ,  |   .  |   -  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMERIC] = LAYOUT(
      _______, ES_6,    ES_7,    ES_8,    ES_9,    ES_0,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, ES_1,    ES_2,    ES_3,    ES_4,    ES_5,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      XXXXXXX, KC_PSLS, ES_COLN, KC_COMM, KC_PDOT, KC_PMNS, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Config
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | VAI  | SAI  | HUI  | MOD  |                              |      | Next | Vol+ |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | VAD  | SAD  | HUD  | TOG  |                              |      | Play | Mute |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | RMOD |      |      |  |      |      |      | Prev | Vol- |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CONFIG]= LAYOUT(
      _______, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_M_B,                                     XXXXXXX, KC_MNXT, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,                                     XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P, _______, _______, _______, _______, XXXXXXX, KC_MPRV, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAVI, _SYMBOLS, _CONFIG);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_EMQM:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(ES_QUES);
                    set_mods(mod_state);
                } else {
                    register_code16(ES_EXLM);
                }
            } else {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code16(ES_QUES);
                } else {
                    unregister_code16(ES_EXLM);
                }
            }
            return false;
        default:
            return true;
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _DEFAULT:
                oled_write_P(PSTR("Alfa\n"), false);
                break;
            case _NAVI:
                oled_write_P(PSTR("Navi\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _SYMBOLS:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _NUMERIC:
                oled_write_P(PSTR("Numeric\n"), false);
                break;
            case _CONFIG:
                oled_write_P(PSTR("Config\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT ] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_TAB,     S(KC_TAB) ) },
    [  _NAVI  ] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(C(KC_RGHT), C(KC_LEFT)) },
    [_FUNCTION] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(_______,    _______   ) },
    [_SYMBOLS ] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(_______,    _______   ) },
    [_NUMERIC ] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(_______,    _______   ) },
    [ _CONFIG ] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(_______,    _______   ) },
};
#endif
