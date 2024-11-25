/* Copyright 2021 Gabriel Bustamante Toledo
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

enum layers { BASE2, MEDIA, NAV, TILNAV, SYM, NUM, FUN };

enum {
    TD_ALFRED_PASTE, TD_SCREEN, TD_WINDOW_RIGHT, TD_WINDOW_LEFT, TD_CURLIES, TD_BRACKS, TD_BRACKS_NORMAL
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_WINDOW_LEFT] = ACTION_TAP_DANCE_DOUBLE( A(G(KC_LEFT)) , G(A(C(KC_LEFT))) ),
    [TD_WINDOW_RIGHT] = ACTION_TAP_DANCE_DOUBLE( A(G(KC_RIGHT)) , G(A(C(KC_RIGHT))) ),
    [TD_CURLIES] = ACTION_TAP_DANCE_DOUBLE( KC_LCBR , KC_RCBR ),
    [TD_BRACKS] = ACTION_TAP_DANCE_DOUBLE( KC_LBRC , KC_RBRC ),
    [TD_BRACKS_NORMAL] = ACTION_TAP_DANCE_DOUBLE( KC_LPRN , KC_RPRN ),
    [TD_ALFRED_PASTE] = ACTION_TAP_DANCE_DOUBLE( G(KC_V) , G(A(KC_V)) ),
    [TD_SCREEN] = ACTION_TAP_DANCE_DOUBLE( S(G(KC_4)) , S(G(C(KC_4))) ),
};

void set_color(int r, int g, int b){
	rgb_matrix_set_color(5,  r, g, b);
	rgb_matrix_set_color(6,  r, g, b);
	rgb_matrix_set_color(17, r, g, b);
	rgb_matrix_set_color(18, r, g, b);
	rgb_matrix_set_color(29, r, g, b);
	rgb_matrix_set_color(30, r, g, b);
	rgb_matrix_set_color(41, r, g, b);
}

// void rgb_matrix_indicators_user(void) {

// 	switch (get_highest_layer(layer_state)) {
// 		case BASE2:
// 			set_color(128, 64, 0);
// 			break;
// 		case MEDIA:
// 			set_color(50, 10, 20);
// 			break;
// 		case NAV:
// 			set_color(0, 40, 50);
// 			break;
// 		case TILNAV:
// 			set_color(0, 0, 50);
// 			break;
// 		case SYM:
// 			set_color(0, 50, 1.9);
// 			break;
// 		case NUM:
// 			set_color(10, 0, 50);
// 			break;
// 		case FUN:
// 			set_color(50, 0, 0);
// 			break;
// 	}
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE2] = LAYOUT_planck_mit(
		KC_Q,           KC_W,          KC_E,               KC_R,             KC_T,               TG(BASE2),  KC_NO,  KC_Y,             KC_U,              KC_I,             KC_O,            KC_P,
		LCTL_T(KC_A),   LALT_T(KC_S),  LGUI_T(KC_D),       LSFT_T(KC_F),     KC_G,               KC_NO,      KC_NO,  KC_H,             RSFT_T(KC_J),      LGUI_T(KC_K),     LALT_T(KC_L),    LCTL_T(KC_QUOT),
		KC_Z,           KC_X,          KC_C,               KC_V,             KC_B,               KC_NO,      KC_NO,  KC_N,             KC_M,              KC_COMM,          KC_DOT,          KC_SLSH,
		TD(TD_SCREEN),  KC_NO,  LT(MEDIA, KC_ESC),  LT(NAV, KC_SPC),  LT(TILNAV, KC_TAB),        A(KC_SPC),        LT(SYM, KC_ENT),  LT(NUM, KC_BSPC),  LT(FUN, KC_DEL),  TD(TD_WINDOW_LEFT),           TD(TD_WINDOW_RIGHT)
	),

	[MEDIA] = LAYOUT_planck_mit(
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
		KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,
		KC_NO,    KC_ALGR,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BRMD,    KC_BRMU,    KC_NO,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,         KC_MSTP,  KC_MPLY,  KC_MUTE,  KC_NO,    KC_NO
	),

	[NAV] = LAYOUT_planck_mit(
		G(KC_S),  TD(TD_ALFRED_PASTE),  G(KC_C),  G(KC_X),  G(KC_Z),   KC_NO,    KC_NO,    G(KC_S),  TD(TD_ALFRED_PASTE),  G(KC_C),  G(KC_X),  G(KC_Z),
		KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_NO,   KC_NO,    KC_NO,    KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
		KC_NO,    KC_ALGR,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,         KC_ENT,   KC_BSPC,  KC_DEL,   KC_NO,    KC_NO
	),

	[TILNAV] = LAYOUT_planck_mit(
		G(KC_S),  TD(TD_ALFRED_PASTE),  G(KC_C),  G(KC_X),  G(KC_Z),KC_NO,   KC_NO,    KC_NO,  KC_NO,  A(KC_F19),  A(KC_F18),  A(KC_F17),
		KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    A(KC_F16),  A(KC_F15),  A(KC_F14),  A(KC_F13),
		KC_NO,    KC_ALGR,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,         KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_NO,    KC_NO
	),

	[SYM] = LAYOUT_planck_mit(
		KC_PIPE,  KC_AMPR,  KC_ASTR,  KC_BSLS,  TD(TD_BRACKS),   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
		KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  TD(TD_BRACKS_NORMAL),   KC_NO,    KC_NO,    KC_NO,    KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,
		KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  TD(TD_CURLIES),   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_ALGR,  KC_NO,
		KC_NO,    KC_NO,    KC_SCLN,  KC_PMNS,  KC_UNDS,        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
	),

	[NUM] = LAYOUT_planck_mit(
		KC_EQL,  KC_7,   KC_8,    KC_9,  KC_PAST,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
		KC_COLN,  KC_4,   KC_5,    KC_6,  KC_PMNS,    KC_NO,    KC_NO,    KC_NO,    KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,
		KC_SLSH,   KC_1,   KC_2,    KC_3,  KC_PPLS,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_ALGR,  KC_NO,
		KC_NO,    KC_NO,  KC_DOT,  KC_0,  KC_COMM,        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
	),

	[FUN] = LAYOUT_planck_mit(
		KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    QK_BOOT,
		KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,
		KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_ALGR,  KC_NO,
		KC_NO,   KC_NO,   KC_APP,  KC_SPC,  KC_TAB,         KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
	)

};

