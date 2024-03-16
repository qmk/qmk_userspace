/*
Copyright 2021 vnz

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "vnz.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names { _BASE, _LOWER, _RAISE, _ADJUST };

enum atlas_keycodes { BASE = SAFE_RANGE, LOWER, RAISE, ADJUST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | PgUp | PgDn | Alt  |Space |Lower |Raise |Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_PGUP, KC_PGDN, KC_LALT, KC_SPC,  LOWER,   RAISE,   KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |PrtScr|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | APPS |   â  |   ê  |   é  |   |  |   {  |   }  |   û  |   î  |   ô  |   œ  | NAPP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LGUI |   à  |   ù  |   è  |   (  |   [  |   ]  |   )  |   ï  |   ü  |      |   €  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   ç  |      |      |      |      |      |      |   \  |ALTENT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Home | VDDW | VDUP |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
  KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PLUS,
  LX_APPS, FR_AA2,  FR_EA3,  FR_EA1,  KC_PIPE, KC_LCBR, KC_RCBR, FR_UA1,  FR_IA1,  FR_OA1,  FR_OA2,  LX_NAPP,
  KC_LGUI, FR_AA1,  FR_UA2,  FR_EA2,  KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, FR_IA2,  FR_UA3,  _______, EURO,
  _______, _______, _______, FR_CA1,  _______, _______, _______, _______, _______, _______, KC_BSLS, ALTENT,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, LX_VDDW, LX_VDUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   :  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TBLT | TBRT |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  KC_DEL,  S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
  _______, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN, KC_DQUO,
  _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), KC_LABK, KC_RABK, KC_QUES, KC_BTN2,
  _______, ST_TBLT, ST_TBRT, _______, _______, _______, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Static|  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Â  |   Ê  |   É  |      |      |      |   Û  |   Î  |   Ô  |   Œ  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Boot |   À  |   Ù  |   È  |      |      |      |      |   Ï  |   Ü  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Mod+ | Hue+ |      |UC_MAC|UC_WIN| NKRO |UC_LNX|      | Bri+ | Sat+ |RGBtog|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Mod- | Hue- |      |      |      |      |      |      | Bri- | Sat- |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
  RGB_M_P, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_EQL,
  _______, FR_AM2,  FR_EM3,  FR_EM1,  _______, _______, _______, FR_UM1,  FR_IM1,  FR_OM1,  FR_OM2,  _______,
  QK_BOOT, FR_AM1,  FR_UM2,  FR_EM2,  _______, _______, _______, _______, FR_IM2,  FR_UM3,  _______, _______,
  _______, RGB_MOD, RGB_HUI, _______, UC_MAC,  UC_WINC, NK_TOGG, UC_LINX, _______, RGB_VAI, RGB_SAI, RGB_TOG,
  _______, RGB_RMOD,RGB_HUD, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_SAD, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
    }
    return true;
};
