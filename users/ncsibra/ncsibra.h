#pragma once

#include QMK_KEYBOARD_H

#define MOD_ACTIVE(mod) ((keyboard_report->mods & MOD_BIT(mod)) || ((get_oneshot_mods() & MOD_BIT(mod)) && !has_oneshot_mods_timed_out()))
#define OSK_ACTIVE()    ((get_oneshot_mods()) || is_oneshot_layer_active())

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define REPEAT_DELAY 500
#define REPEAT_RATE 30

enum layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM,
  _WOW,
  _MOD,
};

enum keycodes {
  // layer keys
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,

  // tap-hold keys
  TH_ESC,
  TH_1,
  TH_2,
  TH_3,
  TH_4,
  TH_5,
  TH_6,
  TH_7,
  TH_8,
  TH_9,
  TH_0,
  TH_BSPC,

  // Custom oneshot layer implementation.
  OSL_MOD_LAYER,

  // Custom oneshot mods implementation.
  OSM_SHFT,
  OSM_CTRL,
  OSM_ALT,
  OSM_GUI,

  NEW_SAFE_RANGE
};

#define COLEMAK_LAYER \
  KC_ESC,         TH_1,     TH_2,           TH_3,           TH_4,         TH_5,    TH_6,     TH_7,        TH_8,           TH_9,     TH_0,            KC_BSPC, \
  KC_TAB,         KC_Q,     KC_W,           KC_F,           KC_P,         KC_B,    KC_J,     KC_L,        KC_U,           KC_Y,     KC_SCLN,         KC_QUOT, \
  KC_ESC,         KC_A,     KC_R,           KC_S,           KC_T,         KC_G,    KC_M,     KC_N,        KC_E,           KC_I,     KC_O,            KC_ENT, \
  KC_LSFT,        KC_Z,     KC_X,           KC_C,           KC_D,         KC_V,    KC_K,     KC_H,        KC_COMM,        KC_DOT,   KC_SLSH,         KC_RSFT, \
  TT(_NUM),       KC_LGUI,  KC_LALT,        KC_LCTL,        MO(_LOWER),   KC_SPC,  KC_BSPC,  TT(_RAISE),  KC_DEL,         KC_RALT,  OSL_MOD_LAYER,   TO(_WOW)

#define QWERTY_LAYER \
  KC_ESC,         TH_1,     TH_2,           TH_3,           TH_4,         TH_5,    TH_6,     TH_7,        TH_8,           TH_9,           TH_0,            KC_BSPC, \
  KC_TAB,         KC_Q,     KC_W,           KC_E,           KC_R,         KC_T,    KC_Y,     KC_U,        KC_I,           KC_O,           KC_P,            KC_QUOT, \
  KC_ESC,         KC_A,     KC_S,           KC_D,           KC_F,         KC_G,    KC_H,     KC_J,        KC_K,           KC_L,           KC_SCLN,         KC_ENT, \
  KC_LSFT,        KC_Z,     KC_X,           KC_C,           KC_V,         KC_B,    KC_N,     KC_M,        KC_COMM,        KC_DOT,         KC_SLSH,         KC_RSFT, \
  TT(_NUM),       KC_LGUI,  KC_LALT,       KC_LCTL,         MO(_LOWER),   KC_SPC,  KC_BSPC,  TT(_RAISE),  KC_DEL,         KC_RALT,        OSL_MOD_LAYER,   KC_DEL

/* Lower
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |   !  |   [  |   ]  |   *  |   &  |   |  |      |   '  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   @  |   #  |   `  |   :  |   (  |   )  |   =  |   +  |   "  |      |   "  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   ^  |   $  |   %  |   ~  |   {  |   }  |   -  |   _  |   \  |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      | Lower|      |      |Raise |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
#define LOWER_LAYER \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,         KC_F6,    KC_F7,     KC_F8,           KC_F9,    KC_F10,   KC_F11,   KC_F12, \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_EXLM,       KC_LBRC,  KC_RBRC,  KC_ASTR,         KC_AMPR,  KC_PIPE,  XXXXXXX,  KC_QUOT, \
  _______,  KC_AT,    KC_HASH,  KC_GRV,   KC_COLN,       KC_LPRN,  KC_RPRN,  KC_EQL,          KC_PLUS,  KC_DQUO,  XXXXXXX,  KC_DQUO, \
  KC_LSFT,  KC_CIRC,  KC_DLR,   KC_PERC,  KC_TILD,       KC_LCBR,  KC_RCBR,  KC_MINS,         KC_UNDS,  KC_BSLS,  XXXXXXX,  _______, \
  _______,  _______,  _______,  _______,  _______,       _______,  _______,  KC_LCTL,         KC_LCTL,  _______,  _______,  XXXXXXX

#define RAISE_LAYER \
  QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DF(_QWERTY), XXXXXXX,       XXXXXXX,     DF(_COLEMAK), XXXXXXX,  XXXXXXX,    XXXXXXX, TO(_WOW), \
  DB_TOGG,  XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,     XXXXXXX,       XXXXXXX,     KC_HOME,      KC_UP,    KC_END,     XXXXXXX,  KC_DEL, \
  _______,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,     XXXXXXX,       XXXXXXX,     KC_LEFT,      KC_DOWN,  KC_RIGHT,   XXXXXXX,  _______, \
  KC_CAPS,  _______,  _______,  _______,  _______,     _______,       XXXXXXX,     KC_PGUP,      XXXXXXX,  KC_PGDN,    XXXXXXX,  _______, \
  _______,  _______,  _______,  _______,  _______,     LCTL(KC_SPC),  _______,     _______,      _______,  TG(_RAISE), _______,  _______


#define NUM_LAYER \
  XXXXXXX,       XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     KC_VOLU,       XXXXXXX,  KC_NUM_LOCK, XXXXXXX,      XXXXXXX,      KC_KP_SLASH,      KC_BSPC, \
  XXXXXXX,       XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     KC_VOLD,       XXXXXXX,  KC_KP_7,     KC_KP_8,      KC_KP_9,      KC_KP_ASTERISK,   XXXXXXX, \
  KC_VOLU,       XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,  KC_KP_4,     KC_KP_5,      KC_KP_6,      KC_KP_MINUS,      KC_KP_ENTER, \
  KC_VOLD,       XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     LSFT(KC_INS),  XXXXXXX,  KC_KP_1,     KC_KP_2,      KC_KP_3,      KC_KP_PLUS,       XXXXXXX, \
  _______,       _______,     _______,     XXXXXXX,       XXXXXXX,     XXXXXXX,       KC_BSPC,  KC_KP_0,     KC_KP_DOT,    KC_KP_DOT,    KC_KP_EQUAL,      XXXXXXX


#define WOW_LAYER \
  KC_ESC,         TH_1,     TH_2,     TH_3,     TH_4,     TH_5,    TH_6,     TH_7,    TH_8,     TH_9,     TH_0,        KC_BSPC, \
  KC_TAB,         KC_H,     KC_Q,     KC_W,     KC_E,     KC_R,    KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,        KC_QUOT, \
  KC_TAB,         KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,    KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,     KC_ENT, \
  KC_LSFT,        KC_Z,     KC_X,     KC_N,     KC_C,     KC_V,    KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,     KC_RSFT, \
  KC_M,           KC_Y,     KC_LALT,  KC_LCTL,  KC_SPC,   KC_P,    KC_BSPC,  KC_DEL,  KC_DEL,   KC_LGUI,  KC_PSCR,     TO(_COLEMAK)


#define MOD_LAYER \
  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  OSM_SHFT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  OSM_GUI,  OSM_ALT,  OSM_SHFT,  OSM_CTRL, _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  OSL_MOD_LAYER
