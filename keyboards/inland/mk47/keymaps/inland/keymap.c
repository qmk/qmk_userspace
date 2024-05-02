#include QMK_KEYBOARD_H

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
    LOCKWIN,
    M_JIGL,
    C_ALT_D,
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
        case C_ALT_D:
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _FUNC   3

// For _QWERTY layer
#define OSL_FUN  OSL(_FUNC)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define OSM_SFT  OSM(MOD_LSFT)
#define OSM_RSFT  OSM(MOD_RSFT)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_CTL  OSM(MOD_RCTL)
#define OSM_GUI  OSM(MOD_LGUI)

// For _LOWER layer
#define ALT_TAB LALT(KC_TAB)



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_mit(\
        OSM_ALT,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,      KC_BSLS,\
        OSM_SFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,   KC_QUOT,\
        OSM_CTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,   OSL_FUN,\
        XXXXXXX,    XXXXXXX,    XXXXXXX,    OSM_GUI,    LOW_TAB,    KC_SPC,     RSE_BSP,    KC_ENT,     OSM_RSFT,   XXXXXXX,    XXXXXXX\
    ),

    [_LOWER] = LAYOUT_planck_mit(\
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,    KC_F12,\
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,      XXXXXXX,\
        _______,    XXXXXXX,    XXXXXXX,    KC_EQL,     KC_LBRC,    KC_LCBR,    KC_RCBR,    KC_RBRC,    KC_MINS,    XXXXXXX,    XXXXXXX,   XXXXXXX,\
        _______,    XXXXXXX,    XXXXXXX,    KC_TRNS,    KC_TRNS,    KC_SPC,     KC_TRNS,    KC_TRNS,    KC_TRNS,    XXXXXXX,    XXXXXXX\
    ),
 
    [_RAISE] = LAYOUT_planck_mit(\
        _______,    KC_DEL,     KC_HOME,    KC_PGUP,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UP,      XXXXXXX,    XXXXXXX,    _______,\
        _______,    KC_INS,     KC_END,     KC_PGDN,    XXXXXXX,    XXXXXXX,    KC_MUTE,    KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,    _______,\
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,    _______,\
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    XXXXXXX,    XXXXXXX\
    ),

    [_FUNC] = LAYOUT_planck_mit(\
        _______,    C_ALT_D,    KC_NUM,     XXXXXXX,    XXXXXXX,    XXXXXXX,    KVM_SW,     XXXXXXX,    SNAP_TOP,   XXXXXXX,    RGB_TOG,    _______,\
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    SNAP_LFT,   SNAP_BTM,   SNAP_RT,    KC_CALC,    _______,\
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LOCKWIN,    QK_RBT,     QK_BOOT,    EE_CLR,     KC_SLEP,    _______,\
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    XXXXXXX,    XXXXXXX\
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {	   
	    case _QWERTY:
            rgb_matrix_set_color(i, RGB_PURPLE);
            break;

        case _LOWER:
            rgb_matrix_set_color(i, RGB_BLUE);
            break;

	    case _RAISE:
            rgb_matrix_set_color(i, RGB_GREEN);
            break;

	    case _FUNC:
            rgb_matrix_set_color(i, RGB_RED);
            break;

        }
    }
    return false;
}
// clang-format on
