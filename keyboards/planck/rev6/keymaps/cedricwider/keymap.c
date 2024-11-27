/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _HALMAK,
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _NAVIGATION,
  _NUMSYM,
  _ADJUST
};

enum planck_keycodes {
  HALMAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  BACKLIT,
  EXT_PLV
};

/* Layer aliases
 * CK stands for CedKey and is equivalent to KC.
 */
#define CK_LWR TT(_LOWER)
#define CK_RSE TT(_RAISE)
#define FNCTN TT(_NUMSYM)

/* Tap Dance Declarations */
#define CLESC LCTL_T(KC_ESC)
#define CLENT LCTL_T(KC_ENT)
#define GUI_S LGUI_T(KC_S)
#define ALT_H LALT_T(KC_H)
#define CTL_N LCTL_T(KC_N)
#define SHFTT LSFT_T(KC_T)
#define SHFTA RSFT_T(KC_A)
#define CTL_E RCTL_T(KC_E)
#define ALT_O LALT_T(KC_O)
#define GUI_I RGUI_T(KC_I)
#define LSPAC LT(_NAVIGATION, KC_ENT)
#define RSPAC KC_SPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Halmak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   w  |   l  |   r  |   b  |   z  |   ;  |   q  |   u  |   d  |   j  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | clesc|   s  |   h  |   n  |   t  |   ,  |   .  |   a  |   e  |   o  |   i  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CW_TG|   f  |   m  |   v  |   c  |   /  |   g  |   p  |   x  |   k  |   y  |clent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_HALMAK] = LAYOUT_planck_grid(
    KC_TAB , KC_W,    KC_L,    KC_R,    KC_B,    KC_Z,    KC_SCLN, KC_Q,    KC_U,    KC_D,    KC_J,    KC_BSPC,
    CLESC  , GUI_S,   ALT_H,   CTL_N,   SHFTT,   KC_COMM, KC_DOT,  SHFTA,   CTL_E,   ALT_O,   GUI_I,   KC_QUOT,
    CW_TOGG, KC_F,    KC_M,    KC_V,    KC_C,    KC_SLSH, KC_G,    KC_P,    KC_X,    KC_K,    KC_Y,    CLENT,
    FNCTN  , KC_LCTL, KC_LALT, KC_LGUI, CK_LWR,   LSPAC,   RSPAC,   CK_RSE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
    KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
    KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TRNS,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
    KC_TRNS,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS,
    KC_TRNS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH,    KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,      KC_F4,    KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,      KC_F10,   KC_F11,  KC_F12,  KC_PIPE, KC_TILD, KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, TO(_HALMAK), _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,       KC_4,     KC_5,    KC_6,    KC_7,           KC_8,       KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,      KC_F4,    KC_F5,   KC_F6,   KC_MINS,        KC_EQL,     KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,      KC_F10,   KC_F11,  KC_F12,  KC_NUHS,        KC_NUBS,    KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, TO(_HALMAK), _______, _______, TG(_NUMSYM),    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Navigation (Lower + Raise) */
[_NAVIGATION] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______,     _______, LSFT(KC_TAB), KC_TAB, LALT(KC_BSPC),  KC_BSPC,  KC_DEL,  _______,
    _______, _______, _______, _______, _______,     _______,   KC_LEFT,   KC_DOWN,    KC_UP,       KC_RIGHT, KC_ESC,  _______,
    _______, _______, _______, _______, _______,     _______,   KC_HOME,   KC_PGDN,    KC_PGUP,     KC_END,   _______, _______,
    _______, _______, _______, _______, TO(_HALMAK), _______,   _______,   _______,    _______,     _______,  _______, _______
),


/* NUMSYM (Lower + Raise) */
[_NUMSYM] = LAYOUT_planck_grid(
    _______, _______, _______, KC_LCBR, KC_RCBR,     _______, KC_ASTR, KC_7,    KC_8,  KC_9,   KC_SLSH, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN,     _______, KC_COLN, KC_4,    KC_5,  KC_6,   KC_MINS, _______,
    _______, _______, _______, KC_LBRC, KC_RBRC,     _______, KC_COMM, KC_1,    KC_2,  KC_3,   KC_PLUS, _______,
    _______, _______, _______, _______, TO(_HALMAK), _______, _______, _______, KC_0,  KC_DOT, _______, _______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Halmak|Qwerty|Colemk|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    DT_PRNT, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, KC_DEL ,
    DT_DOWN, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, HALMAK,  QWERTY,  COLEMAK, _______,  DT_UP,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HALMAK:
      if (record->event.pressed) {
        print("mode just switched to halmak\n");
        set_single_persistent_default_layer(_HALMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to colemak\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          gpio_write_pin_low(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          gpio_write_pin_high(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            #ifdef AUDIO_ENABLE
                static bool play_sound = false;
            #endif

            if (active) {
                #ifdef AUDIO_ENABLE
                    if (play_sound) {
                        PLAY_SONG(plover_song);
                    }
                #endif
                layer_on(_ADJUST);
            } else {
                #ifdef AUDIO_ENABLE
                    if (play_sound) {
                        PLAY_SONG(plover_gb_song);
                    }
                #endif
                layer_off(_ADJUST);
            }

            #ifdef AUDIO_ENABLE
                play_sound = true;
            #endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case CK_RSE:
    case CK_LWR:
      return false;
    default:
      return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHFTT:
        case SHFTA:
        case LSPAC:
        case RSPAC:
            return g_tapping_term - 50;
        default:
            return g_tapping_term;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHFTT:
        case SHFTA:
            return 150;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LWR:
        case CK_RSE:
        case SHFTT:
        case SHFTA:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LWR:
        case CK_RSE:
        case LSPAC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
