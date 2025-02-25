// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include "rpw.c"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWR 0
#define _DEF_ALT 1
#define _SYM 2
#define _NUM 3
#define _NAV 4
#define _L1 5
#define _ADJ 6

#define KC_QWR DF(_QWR)
#define KC_QWR2 DF(_DEF_ALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWR] = LAYOUT( /* qwerty */
    KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS ,
    KC_TRNS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS ,
    KC_TRNS,  CTL_A,   ALT_S,   SFT_D,   GUI_F,   KC_G,                        KC_H,    GUI_J,   SFT_K,   ALT_L,   CTL_QUOT,KC_TRNS ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC ,
    MO(_ADJ),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, SYM_ENT, KC_TAB,    KC_BSPC, NUM_SPC, NAV_ESC, KC_MINS, KC_QUOT, KC_ENT,  KC_RGUI
  ),

  [_DEF_ALT] = LAYOUT(
    KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS ,
    KC_TRNS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS ,
    KC_TRNS,  CTL_A,   ALT_S,   SFT_D,   GUI_F,   KC_G,                        KC_H,    GUI_J,   SFT_K,   ALT_L,   CTL_QUOT,KC_TRNS ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC ,
    MO(_ADJ),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, SYM_ENT, KC_TAB,    KC_BSPC, NUM_SPC, TO(_L1), KC_MINS, KC_QUOT, KC_ENT,  KC_RGUI
  ),

  [_SYM] = LAYOUT(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TILD,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_MINS, GUI_EQL, SFT_LBRC, ALT_RBRC, CTL_BSLS, KC_GRV ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD,  KC_TRNS,  KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NUM] = LAYOUT(
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS ,
    KC_TRNS,      KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,                     KC_TRNS, KC_RGUI, KC_RSFT, KC_RALT, CTL_SCLN,KC_TRNS ,
    KC_TRNS,      KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_F12,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_L1] = LAYOUT(
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS ,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS ,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, TO(_DEF_ALT),KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

  ),

  [_ADJ] = LAYOUT(
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , DF(_QWR)   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , DF(_DEF_ALT)   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , QK_BOOT
  )

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};
