#include QMK_KEYBOARD_H

extern uint8_t is_master;

bool is_mouse_jiggle_active = false;
bool mouse_jiggle_direction = false; // used to alternate direction
uint16_t mouse_jiggle_frequency = 3000; // how often to move the mouse (15 seconds)
uint16_t mouse_jiggle_timer = 0;

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable();
    rgb_matrix_set_speed(RGB_MATRIX_DEFAULT_SPD);
    //rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
    rgb_matrix_sethsv(HSV_PURPLE);
#endif
}

enum custom_keycodes {
    DEFAULT = SAFE_RANGE,
    LOWER,
    RAISE,
    FUNC,
    MOUSE,
    SHORTCUT,
    LOCKWIN,
    M_JIGL,
    CTL_ATL_DEL,
    SNAP_LFT,
    SNAP_RT,
    SNAP_TOP,
    SNAP_BTM,
    KVM_SW
};

enum combos {
  JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOCKWIN:
            if (record->event.pressed) {
                // when keycode LOCKWIN is pressed
                register_code(KC_LGUI);  // press the Windows key
                register_code(KC_L); // press the L key
            } else {
                // when keycode LOCKWIN is released
                unregister_code(KC_LGUI); // release the Windows key
                unregister_code(KC_L);  // release the L key
            }
            break;
        case M_JIGL:
            if (record->event.pressed) {
                is_mouse_jiggle_active = !is_mouse_jiggle_active;
            }
          break;
        case CTL_ATL_DEL:
            if(record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_DEL);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_DEL);
            }
            break;
        case KVM_SW:
            if(record->event.pressed) {
                register_code(KC_NUM);
                register_code(KC_NUM);
            } else {
                unregister_code(KC_NUM);
                unregister_code(KC_NUM);
            }
        break;
        case SNAP_LFT:
            if(record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LEFT);
            }
        break;
        case SNAP_RT:
            if(record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_RIGHT);
            }
        break;
        case SNAP_TOP:
            if(record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_UP);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_UP);
            }
        break;
        case SNAP_BTM:
            if(record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_DOWN);
            }
        break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_keyboard_master()) {
        // initialize timer on master half only, remove if statement above for non-split
        if (mouse_jiggle_timer == 0) mouse_jiggle_timer = timer_read();
    }

    if (is_mouse_jiggle_active) {
        if (timer_elapsed(mouse_jiggle_timer) > mouse_jiggle_frequency) {
            mouse_jiggle_timer = timer_read();
            tap_code(KC_NUM);
            if (mouse_jiggle_direction) {
                tap_code(KC_MS_L);
            } else {
                tap_code(KC_MS_R);
            }
            tap_code(KC_NUM);
            mouse_jiggle_direction = !mouse_jiggle_direction;
        } 
    }
}

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _FUNC   3
#define _MOUSE  4
#define _SHORTCUT  5

// For _QWERTY layer
#define OSL_FUN  OSL(_FUNC)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define MOU_GUI  LT(_MOUSE, KC_LGUI)
#define SHR_SFT  LT(_SHORTCUT, KC_LSFT)
#define OSM_SFT  OSM(MOD_LSFT)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_CTL  OSM(MOD_LCTL)

// For _LOWER layer
#define ALT_TAB LALT(KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     OSM_ALT,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P  ,  KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSM_SFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H    ,KC_J    ,KC_K    ,KC_L   , KC_SCLN, KC_QUOT,\
  //|---- ----+--------+--------+--------+--------+-------|                    |--------+--------+--------+--------+--------+--------|
     OSM_CTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,OSL_FUN,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MOU_GUI,LOW_TAB, KC_SPC,      KC_ENT, RSE_BSP, SHR_SFT \
                                      //`--------------------------'  `--------------------------'
  ),

[_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_EQL, KC_LBRC, KC_LCBR,                       KC_RCBR, KC_RBRC, KC_MINS, XXXXXXX, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
  ),
  
[_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, KC_DEL , KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_INS,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

[_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,                     QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_NUM,                     LOCKWIN, QK_RBT,  QK_BOOT, EE_CLR,  KC_SLEP, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),

[_MOUSE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  ),
  
[_SHORTCUT] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    CTL_ATL_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                     KVM_SW, XXXXXXX, SNAP_TOP, XXXXXXX, M_JIGL, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,SNAP_LFT, SNAP_BTM, SNAP_RT,XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS\
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
      case LT(_MOUSE, KC_LGUI):
            return TAPPING_TERM_THUMB;
      case LT(_SHORTCUT, OSM_SFT):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_FUNC] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),              ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)  },
    [_RAISE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),             ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),             ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MOUSE] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),              ENCODER_CCW_CW(KC_WH_R, KC_WH_L) },
    [_SHORTCUT] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),             ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status

    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _FUNC:
                oled_write_P(PSTR("FN\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("Mouse\n"), false);
                break;
            case _SHORTCUT:
                oled_write_P(PSTR("Shortcuts\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
    } else {
        oled_write_raw(logo, sizeof(logo));
    }
    return false;
}
#endif