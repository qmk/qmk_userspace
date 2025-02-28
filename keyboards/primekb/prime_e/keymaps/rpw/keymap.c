/* Copyright 2018 Holten Campbell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "rpw.c"

enum prime_e_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAME,
    _NAV,
    _SYM,
    _NUM,
    _NUMPAD,
    _FUNC,
    _PROG,
    _APPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      _______,  KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,                     KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,     _______, _______,
      _______,  CTL_A,  ALT_S,   SFT_D,  GUI_F,   KC_G,                     KC_H,   GUI_J,    SFT_K,    ALT_L,   CTL_SCLN, _______,
      _______,  KC_Z,   KC_X,    KC_C,   KC_V,    KC_B,          MO(_PROG), KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  _______,
      KC_TRNS,  KC_TRNS,         MO(_NAV),     MO(_SYM),         NUM_SPC,           MO(_NAV),                    KC_TRNS,  KC_TRNS
    ),

    [_GAME] = LAYOUT(
      KC_TAB,   KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,                     KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,     KC_BSLS, KC_BSPC,
      CTL_ESC,  KC_A,   KC_S,    KC_D,   KC_F,    KC_G,                     KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
      KC_LSFT,  KC_Z,   KC_X,    KC_C,   KC_V,    KC_B,          MO(_PROG), KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  MO(_APPS),
      KC_LCTL,  KC_LOPT,         KC_LGUI,         KC_SPC,        NUM_SPC,           MO(_NAV),                    KC_TRNS,  KC_TRNS
    ),

    // Navigation
    [_NAV] = LAYOUT(
      KC_TAB,    KC_1,     KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,      KC_8,     KC_9,    KC_0,     KC_DEL, KC_BSPC,
      QK_GESC,   _______,  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_LEFT,   KC_DOWN,  KC_UP,   KC_RIGHT, KC_ENT,
      KC_TRNS,   _______,  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_HOME,   KC_PGDN,  KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
      BL_TOGG,   BL_STEP,                        KC_TRNS,    KC_TRNS,	         MO(_FUNC), KC_TRNS,                                KC_TRNS, KC_TRNS
    ),

    // Symbol layer
    [_SYM] = LAYOUT(
      KC_TILD,  KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS, KC_BSPC,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_MINS,   KC_EQL,    KC_LBRC,   KC_RBRC,   KC_BSLS,    KC_GRV,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,    KC_PIPE, KC_TRNS,
      KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	       MO(_FUNC),   KC_PDOT,                                       KC_TRNS, KC_TRNS
    ),

    // Numbers
    [_NUM] = LAYOUT(
      KC_TRNS,   KC_1,      KC_2,      KC_3,      KC_4,       KC_5,                 KC_6,      KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS, KC_BSPC,
      KC_CAPS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,              KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
      BL_TOGG,   BL_STEP,                         KC_TRNS,    MO(_FUNC),	   KC_TRNS, KC_TRNS,                                KC_TRNS,  KC_TRNS
    ),

    // Numpad
    [_NUMPAD] = LAYOUT(
      KC_TRNS,   KC_1,      KC_2,      KC_3,      KC_4,       KC_5,                   KC_7,      KC_8,     KC_9,     KC_9,    KC_0,     KC_MINS, KC_BSPC,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                KC_4,      KC_5,     KC_6,     KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,       KC_TRNS, KC_1,      KC_2,     KC_3,     KC_TRNS, KC_DOT,   KC_TRNS,
      BL_TOGG,   BL_STEP,                         KC_TRNS,    MO(_FUNC),	            KC_0,                KC_TRNS,           KC_TRNS,  KC_TRNS
    ),

    [_FUNC] = LAYOUT(
      QK_BOOT,    KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_F6,     KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	       KC_TRNS,   KC_TRNS,                               KC_TRNS, KC_TRNS
    ),

    [_PROG] = LAYOUT(
      QK_BOOT,   KC_1,      DF(_QWERTY), KC_3,      KC_4,       KC_5,                   KC_7,      KC_8,     KC_9,     KC_9,    DT_PRNT,  DT_UP, DT_DOWN,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    DF(_GAME),              KC_4,      KC_5,     KC_6,     KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,       KC_TRNS, KC_1,      KC_2,     KC_3,     KC_TRNS, KC_DOT,   KC_TRNS,
      BL_TOGG,   BL_STEP,                         KC_TRNS,    MO(_FUNC),	            KC_0,                KC_TRNS,           KC_TRNS,  KC_TRNS
    ),

    [_APPS] = LAYOUT(
      QK_BOOT,   KC_1,      KC_2,      KC_3,      KC_4,       KC_5,                   KC_7,      KC_8,     KC_9,     KC_9,    DT_PRNT,  DT_UP, DT_DOWN,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                KC_4,      KC_5,     KC_6,     KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,       KC_TRNS, KC_1,      KC_2,     LCAG(KC_S), LCAG(KC_C), KC_DOT,   KC_TRNS,
      BL_TOGG,   BL_STEP,                         KC_TRNS,    MO(_FUNC),	            KC_0,                KC_TRNS,           KC_TRNS,  KC_TRNS
    ),

};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
/*
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }
*/
}

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) == 1) {
        writePinHigh(B1);
    } else {
	writePinLow(B1);
    }

    if (get_highest_layer(state) == 2) {
        writePinHigh(B2);
    } else {
	writePinLow(B2);
    }
    return state;
}

/*
bool led_update_keymap(led_t led_state) {
    writePin(TOP_LED, LED_ON(IS_LAYER_ON(_FN1))); // Use for Layer 1
    writePin(MIDDLE_LED, LED_ON(IS_LAYER_ON(_FN2))); // Use for Layer 2
    writePin(BOTTOM_LED, LED_ON(led_state.caps_lock)); // Use for Caps Lock
    return false; // Override default set by KB
}
*/
