#include QMK_KEYBOARD_H

#include "rpw.c"

enum layer_number {
    _QWR = 0,
    _SYM,
    _NUM,
    _NAV
};

enum custom_keycodes {
    KC_RHLSC0  // right-hand layer shift/cycle
};

#define KC_RHLSC0 LT(_NAV, 1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWR] = LAYOUT(
        _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
        _______,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
        _______,  CTL_A,  ALT_S,   SFT_D,   GUI_F,   KC_G,                      KC_H,    GUI_J,   SFT_K,   ALT_L,  CTL_QUOT,  KC_QUOT,
        _______,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,    _______, KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                        KC_LALT,KC_LCTL, LT(_NAV, 1), MO(_SYM),        NUM_SPC,  KC_RHLSC0, KC_RCTL, KC_RALT
    ),

    [_SYM] = LAYOUT(
        _______,  _______ , _______ , _______ , _______ , _______,                     _______ , _______ , _______ , _______ , _______,  _______,
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     _______,
        _______, _______ , _______ , _______ , _______ , _______,                      KC_MINS, GUI_EQL, SFT_LBRC, ALT_RBRC, CTL_BSLS, _______,
        _______,  KC_EQL, KC_MINS, KC_PLUS, KC_TILD, KC_RCBR, _______,       _______,  KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,
                            _______, _______, _______, _______,    TO(_QWR), _______, _______, _______
    ),

    [_NUM] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
        _______, _______,  _______,  _______,  _______, _______,                       KC_TRNS, KC_RGUI, KC_RSFT, KC_RALT, CTL_SCLN, _______,
        _______, C(KC_Z), C(KC_X), C(KC_C), KC_TILD, XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   XXXXXXX, _______,
                                _______, _______, KC_TILD, KC_DEL,       _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                       _______,  _______  , _______,  _______ ,  _______ ,_______,
        _______, KC_TAB  , KC_TILD,  _______,  _______,  _______,                            KC_6,    KC_7,    KC_8,    KC_DEL,   KC_BSPC,  _______,
        _______, KC_ESC  , _______,  _______,  _______,  _______,                        KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, KC_ENT,  KC_TRNS,
        _______, C(KC_Z), C(KC_X), C(KC_C), KC_TILD, XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   _______, _______,
                                _______, _______, KC_TILD, KC_DEL,       _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NUM, _NAV);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
