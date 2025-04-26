// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _SYM,
    _NAV,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Hands Down Promethium (Inverted)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   V  |   W  |   G  |   M  |   J  |                    |   ;  |   .  |   '  |   =  |   /  |  Z   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   S  |   N  |   T  |   H  |   K  |-------.    ,-------|   ,  |   A  |   E  |   I  |   C  |  Q   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   F  |   P  |   D  |   L  |   X  |-------|    |-------|   -  |   U  |   O  |   Y  |   B  |ENTER |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | LAlt |   R  |  SPC | / LOWER /      \ RAISE \  |BKSPC | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /        \       \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_TAB,   KC_V,   KC_W,    KC_G,    KC_M,    KC_J,                             KC_SCLN, KC_DOT,  KC_QUOT, KC_EQL,  KC_SLSH,  KC_Z,
  KC_ESC,   KC_S,   KC_N,    KC_T,    KC_H,    KC_K,                             KC_COMM, KC_A,    KC_E,    KC_I,    KC_C,     KC_Q,
  KC_LSFT,  KC_F,   KC_P,    KC_D,    KC_L,    KC_X,   KC_MUTE,      XXXXXXX,    KC_MINS, KC_U,    KC_O,    KC_Y,    KC_B,     KC_ENT,
                 KC_LGUI,    KC_LALT, KC_R,    KC_SPC, KC_ESC,       TO(_SYM), KC_BSPC, KC_ENT,  KC_RCTL, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   '  |   <  |   >  |   "  |   .  |                    |   &  |   :: |   [  |   ]  |   %  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   -  |   +  |   =  |   #  |-------.    ,-------|   |  |   :  |   (  |   )  |   ?  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  ^   |  /   |  *   |   \  | ../  |-------|    |-------|   ~  |   $  |   {  |   }  |   @  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt |   R  |  SPC | / LOWER /      \ RAISE \  |BKSPC | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  _______, KC_QUOT, KC_LT,   KC_GT,   KC_DQT,  KC_DOT,                             KC_AMPR, KC_COLN, KC_LBRC, KC_RBRC, KC_PERC, _______,
  _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH,                            KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
  _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, _______, _______,       _______,    KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   _______,
                    _______, _______, _______, _______, TO(_BASE),     TO(_NAV), _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt |   R  |  SPC | / LOWER /      \ RAISE \  |BKSPC | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______,  _______, _______,  _______,    _______,
  _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                         KC_PGUP, KC_PRVWD, KC_UP,   KC_NXTWD, C(KC_BSPC), KC_BSPC,
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                         KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_DEL,     KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,       _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,  XXXXXXX,    _______,
                    _______, _______, _______, _______, TO(_BASE),     TO(_SYM), _______, _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

void my_print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("HDPi"), false);

    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("HSSN"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        my_print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
