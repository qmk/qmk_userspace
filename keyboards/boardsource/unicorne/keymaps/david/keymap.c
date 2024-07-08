#include QMK_KEYBOARD_H


// ------------------ Tap-Dance ----------------- //
enum {
    TD_SHFT_CAPS = 0
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_SHFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};
// if caps lock is on && is pressed: toggle/turn off caps lock

// ------------------- Layers ------------------- //
enum layers {  // Layers
    _DVRK,
    _QWRT,
    _GAME,
    _SYMB,
    _NAV,
    _FUNC,
    _SYS
};

/* Layer Blueprint:
    [_{NAME}] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //'--------------------------'  '--------------------------'
    ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVRK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_TAB, KC_SCLN, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,	KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SHFT_CAPS), KC_QUOT, KC_Q, KC_J, KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            KC_LGUI, KC_BSPC, MO(_NAV), MO(_SYMB),  KC_SPC, KC_RALT
                                        //'--------------------------'  '--------------------------'
    ),
    [_QWRT] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SHFT_CAPS), KC_Z, KC_X, KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            KC_LGUI, KC_BSPC, MO(_NAV), MO(_SYMB),  KC_SPC, KC_RALT
                                        //'--------------------------'  '--------------------------'
    ),
    [_GAME] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_TAB,    KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_G, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_B, KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                           KC_LALT, KC_SPC, MO(_SYMB),   MO(_NAV),  KC_SPC, KC_LGUI
                                        //'--------------------------'  '--------------------------'
    ),
    [_SYMB] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_ESC, _______, _______, _______, KC_ASTR, KC_CIRC,                      KC_PLUS,    KC_1,    KC_2,  KC_3, KC_PERC, TO(_FUNC),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_HASH, KC_LPRN, KC_RPRN, KC_SLSH, KC_BSLS,                       KC_EQL,    KC_4,    KC_5,    KC_6,    KC_0,   KC_AT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_LBRC, KC_RBRC, KC_EXLM,  KC_GRV,                      KC_MINS,    KC_7,    KC_8,    KC_9,  KC_DLR, _______,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            _______, _______, XXXXXXX,  _______, _______, _______
                                        //'--------------------------'  '--------------------------'
    ),
    [_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
      TO(_FUNC), XXXXXXX, KC_FIND, KC_UNDO, KC_AGIN, XXXXXXX,                      XXXXXXX,  KC_END, KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX,  KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            KC_LGUI, XXXXXXX, _______,    XXXXXXX, _______, _______
                                        //'--------------------------'  '--------------------------'
    ),
    [_FUNC] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
          KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                         TO(_SYS), TO(_DVRK), XXXXXXX,    XXXXXXX, TO(_DVRK), TO(_SYS)
                                        //'--------------------------'  '--------------------------'
    ),
    [_SYS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_MOD, RGB_VAI, RGB_SPI, BL_BRTG,   BL_UP,  QK_RBT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_VAD, RGB_SPD, BL_TOGG, BL_DOWN, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                      TO(_QWRT), TO(_DVRK), TO(_GAME),  TO(_GAME), TO(_DVRK), TO(_QWRT)
                                        //'--------------------------'  '--------------------------'
    )
};


// don't touch.. idk what this does at the moment
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif

// Layer Timeout
void matrix_scan_user(void) {
    if (  // any 'toggled' layer is active
        (get_highest_layer(layer_state) == _FUNC
        || get_highest_layer(layer_state) == _SYS)
        && last_input_activity_elapsed() > 10000  // 10 seconds
    ) {
        layer_move(_DVRK);
        oled_off();  // not working... now try
    }
}

// ------------------- Macros ------------------- //
// https://docs.qmk.fm/feature_advanced_keycodes#shift-backspace-for-delete
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();  // Store the current modifier state
    switch (keycode) {
        case KC_BSPC: {
            // Track delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // Temporarily canceling both shifts
                    // so 'shift' isn't applied to KC_DEL
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }
    return true;
};

// ---------------- OLED Screens ---------------- //
#ifdef OLED_ENABLE

// Rotate Screens
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    bool vertical_text = false;
    if (vertical_text) {  // vertical
        if (!is_keyboard_left()) { return OLED_ROTATION_180; }
        return rotation;
    } else {  // horizontal
        return OLED_ROTATION_270;
    }
}

// Layer Status
void render_current_layer(void) {
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state)) {
        case _DVRK:
            oled_write_P(PSTR(" DVRK\n"), false); break;
        case _QWRT:
            oled_write_P(PSTR(" QWRT\n"), false); break;
        case _GAME:
            oled_write_P(PSTR(" GAME\n"), false); break;
        case _SYMB:
            oled_write_P(PSTR(" SYMB\n"), false); break;
        case _NAV:
            oled_write_P(PSTR(" NAV\n"), false); break;
        case _FUNC:
            oled_write_P(PSTR(" FUNC\n"), false); break;
        case _SYS:
            oled_write_P(PSTR(" SYS\n"), false); break;
        default:
            oled_write_P(PSTR("ERROR\n"), false); break;
    }
}

// Logos
static void render_apple_logo(void) {
    static const char PROGMEM raw_logo_apple[] = {  // `const unsigned char`
          0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,  0,  0,  0,
        112,124, 62, 62,159,135,128,128,128,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,224,248,252,254,255,255,255,255,255,255,255,255,254,
        254,254,255,255,255,255,255,255,255, 31, 15,  6,  0,  0,  0,  0,
          0,  0,  0, 31,255,255,255,255,255,255,255,255,255,255,255,255,
        255,255,255,255,255,255,255,255,255,248,224,192,192,  0,  0,  0,
          0,  0,  0,  0,  0,  3,  7, 15, 31, 63,127,127,127, 63, 63, 31,
         31, 31, 31, 63, 63,127,127, 63, 63, 31, 15,  3,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo_apple, sizeof(raw_logo_apple));
}
static void render_arch_logo(void) {
    static const char PROGMEM raw_arch_logo[] = {
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,
        240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,248,242,247,239,
        255,255,255,252,240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,192,240,252,254,255,255,127,  7,  3,  1,
          1,  3,  7,127,255,255,255,252,184,160,128,  0,  0,  0,  0,  0,
          0,  0,  0,  8, 12,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7, 14,  8,  0,  0,  0,
    };
    oled_write_raw_P(raw_arch_logo, sizeof(raw_arch_logo));
}
static void render_windows_logo(void) {
    static const char PROGMEM raw_windows_logo[] = {
          0,  0,  0,128,128,128,128,192,192,192,192,192,192,224,  0,224,
        224,224,224,224,240,240,240,240,240,240,248,248,248,  0,  0,  0,
          0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,  0,255,
        255,255,255,255,255,255,255,255,255,255,255,255,255,  0,  0,  0,
          0,  0,  0,254,254,254,254,254,254,254,254,254,254,254,  0,254,
        254,254,254,254,254,254,254,254,254,254,254,254,254,  0,  0,  0,
          0,  0,  0,  3,  3,  3,  3,  3,  3,  7,  7,  7,  7,  7,  0,  7,
         15, 15, 15, 15, 15, 15, 15, 15, 31, 31, 31, 31, 31,  0,  0,  0,
    };
    oled_write_raw_P(raw_windows_logo, sizeof(raw_windows_logo));
}
// Display Current OS on start-up
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_set_cursor(0, 5);
        switch (detected_os) {
            case OS_MACOS:
            case OS_IOS:
                render_apple_logo();
                break;
            case OS_WINDOWS:
                render_windows_logo();
                break;
            case OS_LINUX:
                render_arch_logo();  // this would be awkward if it's not Arch..
                                     // I'm not drawing the penguin for this
                break;
            case OS_UNSURE:
                oled_write(PSTR("OS: ?"), false);
                // display some symbol to represent unfamiliar OS
                break;
        }
    }
    return true;
}

// Mod Key Icons (Paired)
static const char PROGMEM mod_icons[4][4][64] = {  // 1 = pressed
    {  // ctl_shft
/*0 0*/ {  0,240,248,  4,  2,130,194, 98, 50, 98,194,130,  2,  4,248,  0,  0,240,248,  4,  2, 66, 98,242,250,242, 98, 66,  2,  4,248,  0,  0, 31, 63,112, 96, 97, 96, 96, 96, 96, 96, 97, 32, 16, 15,  0,  0, 31, 63,112, 96, 96, 96,111,111,111, 96, 96, 32, 16, 15,  0},
/*0 1*/ {  0,240,248,  4,  2,130,194, 98, 50, 98,194,130,  2,  4,248,  0,  0,240,248,252,124, 60, 28, 12, 28, 60,124,252,248,240,  0,  0,  0, 31, 63,112, 96, 97, 96, 96, 96, 96, 96, 97, 32, 16, 15,  0,  0, 31, 63,127,127,127, 96, 96, 96,127,127,127, 63, 31,  0,  0},
/*1 0*/ {  0,240,248,252,252,124, 60,156, 60,124,252,252,248,240,  0,  0,  0,240,248,  4,  2, 66, 98,242,250,242, 98, 66,  2,  4,248,  0,  0, 31, 63,127,124,126,127,127,127,126,124,127, 63, 31,  0,  0,  0, 31, 63,112, 96, 96, 96,111,111,111, 96, 96, 32, 16, 15,  0},
/*1 1*/ {  0,240,248,252,252,124, 60,156, 60,124,252,252,248,240,  0,  0,  0,240,248,252,124, 60, 28, 12, 28, 60,124,252,248,240,  0,  0,  0, 31, 63,127,124,126,127,127,127,126,124,127, 63, 31,  0,  0,  0, 31, 63,127,127,127, 96, 96, 96,127,127,127, 63, 31,  0,  0},
    }, {  // gui_alt (linux/unknown)
/*0 0*/ {  0,240,248,  4,114,250,154,154,154,154,154,186, 50,  4,248,  0,  0,240,248,  4,  2,194,226, 50, 50, 50,226,194,  2,  4,248,  0,  0, 31, 63,112,102,110,108,108,108,108,108,111, 39, 16, 15,  0,  0, 31, 63,112, 96,103,103, 97, 97, 97,103,103, 32, 16, 15,  0},
/*0 1*/ {  0,240,248,  4,114,250,154,154,154,154,154,186, 50,  4,248,  0,  0,240,248,252,124, 60,156,156,156, 60,124,252,248,240,  0,  0,  0, 31, 63,112,102,110,108,108,108,108,108,111, 39, 16, 15,  0,  0, 31, 63,127,112,112,125,125,125,112,112,127, 63, 31,  0,  0},
/*1 0*/ {  0,240,248, 28, 12,204,204,204,204,204,140,156,248,240,  0,  0,  0,240,248,  4,  2,194,226, 50, 50, 50,226,194,  2,  4,248,  0,  0, 31, 63,115, 98,102,102,102,102,102, 96,113, 63, 31,  0,  0,  0, 31, 63,112, 96,103,103, 97, 97, 97,103,103, 32, 16, 15,  0},
/*1 1*/ {  0,240,248, 28, 12,204,204,204,204,204,140,156,248,240,  0,  0,  0,240,248,252,124, 60,156,156,156, 60,124,252,248,240,  0,  0,  0, 31, 63,115, 98,102,102,102,102,102, 96,113, 63, 31,  0,  0,  0, 31, 63,127,112,112,125,125,125,112,112,127, 63, 31,  0,  0},
    }, {  // gui_alt (mac/ios)
/*0 0*/ {  0,240,248,  4, 18, 42,242, 34, 34, 34,242, 42, 18,  4,248,  0,  0,240,248,  4,  2, 18, 18, 34,194,  2, 18, 18,  2,  4,248,  0,  0, 31, 63,112,100,106,103, 98, 98, 98,103,106, 36, 16, 15,  0,  0, 31, 63,112, 96, 96, 96, 96, 97, 98,100,100, 32, 16, 15,  0},
/*0 1*/ {  0,240,248,  4, 18, 42,242, 34, 34, 34,242, 42, 18,  4,248,  0,  0,240,248,252,220,220,188,124,252,220,220,252,248,240,  0,  0,  0, 31, 63,112,100,106,103, 98, 98, 98,103,106, 36, 16, 15,  0,  0, 31, 63,127,127,127,127,124,123,119,119,127, 63, 31,  0,  0},
/*1 0*/ {  0,240,248,220,172, 28,188,188,188, 28,172,220,248,240,  0,  0,  0,240,248,  4,  2, 18, 18, 34,194,  2, 18, 18,  2,  4,248,  0,  0, 31, 63,119,107,112,123,123,123,112,107,119, 63, 31,  0,  0,  0, 31, 63,112, 96, 96, 96, 96, 97, 98,100,100, 32, 16, 15,  0},
/*1 1*/ {  0,240,248,220,172, 28,188,188,188, 28,172,220,248,240,  0,  0,  0,240,248,252,220,220,188,124,252,220,220,252,248,240,  0,  0,  0, 31, 63,119,107,112,123,123,123,112,107,119, 63, 31,  0,  0,  0, 31, 63,127,127,127,127,124,123,119,119,127, 63, 31,  0,  0},
    }, {  // gui_alt (windows)
/*0 0*/ {  0,240,248,  4,  2,114,114,114,  2,114,114,114,  2,  4,248,  0,  0,240,248,  4,  2,194,226, 50, 50, 50,226,194,  2,  4,248,  0,  0, 31, 63,112, 96,103,103,103, 96,103,103,103, 32, 16, 15,  0,  0, 31, 63,112, 96,103,103, 97, 97, 97,103,103, 32, 16, 15,  0},
/*0 1*/ {  0,240,248,  4,  2,114,114,114,  2,114,114,114,  2,  4,248,  0,  0,240,248,252,124, 60,156,156,156, 60,124,252,248,240,  0,  0,  0, 31, 63,112, 96,103,103,103, 96,103,103,103, 32, 16, 15,  0,  0, 31, 63,127,112,112,125,125,125,112,112,127, 63, 31,  0,  0},
/*1 0*/ {  0,240,248,252, 28, 28, 28,252, 28, 28, 28,252,248,240,  0,  0,  0,240,248,  4,  2,194,226, 50, 50, 50,226,194,  2,  4,248,  0,  0, 31, 63,127,113,113,113,127,113,113,113,127, 63, 31,  0,  0,  0, 31, 63,112, 96,103,103, 97, 97, 97,103,103, 32, 16, 15,  0},
/*1 1*/ {  0,240,248,252, 28, 28, 28,252, 28, 28, 28,252,248,240,  0,  0,  0,240,248,252,124, 60,156,156,156, 60,124,252,248,240,  0,  0,  0, 31, 63,127,113,113,113,127,113,113,113,127, 63, 31,  0,  0,  0, 31, 63,127,112,112,125,125,125,112,112,127, 63, 31,  0,  0},
    }
};


static void render_ctl_shift(int ctl, int shft) {
    oled_write_raw_P(
        mod_icons[0][2*ctl + shft],
        sizeof(mod_icons[0][2*ctl + shft])
    );
}


static void render_gui_alt(int gui, int alt) {
    int os_num;
    os_variant_t detected_os = detected_host_os();
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            os_num = 1;
            break;
        case OS_WINDOWS:
            os_num = 2;
            break;
        default:
            os_num = 0;
    }

    oled_write_raw_P(
        mod_icons[1 + os_num][2*gui + alt],
        sizeof(mod_icons[1 + os_num][2*gui + alt])
    );
}


void render_mod_status(uint8_t mod_status) {
    bool is_caps = host_keyboard_led_state().caps_lock;
    #ifdef CAPS_WORD_ENABLE
    is_caps |= is_caps_word_on();
    #endif

    oled_set_cursor(0, 5);
    render_ctl_shift(
        (mod_status & MOD_MASK_CTRL) ? 1 : 0,
        (mod_status & MOD_MASK_SHIFT || is_caps) ? 1 : 0
    );

    oled_set_cursor(0, 7); 
    render_gui_alt(
        (mod_status & MOD_MASK_GUI) ? 1 : 0,
        (mod_status & MOD_MASK_ALT) ? 1 : 0
    );
}

// Display Words-per-minute
int peak_wpm, curr_wpm;
void render_wpm(void) {
    curr_wpm = get_current_wpm();

    // get WPM Peak | reset if wpm is 0
    oled_set_cursor(1, 12);
    if (curr_wpm == 0) { peak_wpm = 0; }
    if (curr_wpm > peak_wpm || last_input_activity_elapsed() > 3500) {
        peak_wpm = curr_wpm;
    }
    oled_write(get_u8_str(peak_wpm, '0'), false);

    oled_set_cursor(0, 13);
    oled_write(PSTR("-----"), false);
    oled_set_cursor(1, 14);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
    oled_set_cursor(1, 15);
    oled_write(PSTR("WPM"), false);
}


void render_caps_lock(void) {
    oled_set_cursor(1, 10);
    oled_write_P(
        host_keyboard_led_state().caps_lock ? PSTR("CAPS") : PSTR("\n"),
        false
    );
}


void master_oled(void) {  // Left Side
    render_current_layer();
    // render_caps_lock();  // don't need if I have mod key status active
}


void slave_oled(void) {  // Right Side
    render_current_layer();
    render_mod_status(get_mods() | get_oneshot_mods());
    render_wpm();
}


bool oled_task_user() {
    if(is_keyboard_master()) master_oled();
    else slave_oled();

    return false;
}

#endif