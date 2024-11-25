/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Arda Kilicdagi <GH: @ardakilic, TW: @ardadev>

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

#include QMK_KEYBOARD_H
// animation vars

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 60 //Switch to fast animation when over words per minute

//custom codes

#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CMD_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

#define CTL_QUOTE RCTL_T(KC_QUOT)
#define ALT_L RALT_T(KC_L)
#define CMD_K RGUI_T(KC_K)
#define SFT_J RSFT_T(KC_J)

#define XXX KC_NO

#define HMRW S(G(KC_SPACE))
#define ALF A(KC_SPACE)
#define MEDI_ESC LT(_MEDIA, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define TIL_TAB LT(_TILNAV, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)
#define SAVE G(KC_S)
#define PASTE TD(TD_ALFRED_PASTE)
#define COPY G(KC_C)
#define CUT G(KC_X)
#define UNDO G(KC_Z)


#define MOV_WES A(KC_F16)
#define MOV_SOU A(KC_F15)
#define MOV_NOR A(KC_F14)
#define MOV_EAS A(KC_F13)
#define FUL_FLO TD(TD_FULL_FLOAT)
#define MVW_1 S(A(KC_1))
#define MVW_2 S(A(KC_2))
#define MVW_3 S(A(KC_3))
#define MVW_4 S(A(KC_4))
#define MVW_5 S(A(KC_5))
#define MVW_6 S(A(KC_6))
#define MVW_7 S(A(KC_7))
#define MVW_8 S(A(KC_8))
#define MVW_9 S(A(KC_9))

#define FCW_1 C(KC_1)
#define FCW_2 C(KC_2)
#define FCW_3 C(KC_3)
#define FCW_4 C(KC_4)
#define FCW_5 C(KC_5)
#define FCW_6 C(KC_6)
#define FCW_7 C(KC_7)
#define FCW_8 C(KC_8)
#define FCW_9 C(KC_9)

#define MVW_LEF G(A(KC_F16))
#define MVW_RIG G(A(KC_F13))
#define FCS_MV1 TD(TD_MVW_1)
#define FCS_MV2 TD(TD_MVW_2)
#define FCS_MV3 TD(TD_MVW_3)
#define FCS_MV4 TD(TD_MVW_4)
#define FCS_MV5 TD(TD_MVW_5)
#define FCS_MV6 TD(TD_MVW_6)
#define FCS_MV7 TD(TD_MVW_7)
#define FCS_MV8 TD(TD_MVW_8)
#define FCS_MV9 TD(TD_MVW_9)

// Layers
enum {
  _QWERTY,
  _MEDIA,
  _NAV,
  _TILNAV,
  _SYM,
  _NUM,
  _FUN
};

enum {
    TD_ALFRED_PASTE, TD_SCREEN, TD_FULL_FLOAT, TD_MVW_1, TD_MVW_2, TD_MVW_3, TD_MVW_4, TD_MVW_5, TD_MVW_6, TD_MVW_7, TD_MVW_8, TD_MVW_9
};

enum custom_keycodes {
    CURLIES = SAFE_RANGE,
    SQUARES,
    BRACKETS

};

enum combos {
    IO_DASH,
    KL_COLON,
    SD_ALF,
    WE_HMRW
};

const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RGUI_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
[IO_DASH] = COMBO(io_combo, KC_MINUS),
[KL_COLON] = COMBO(kl_combo, KC_SEMICOLON),
[SD_ALF] = COMBO(sd_combo, ALF),
[WE_HMRW] = COMBO(we_combo, HMRW)

};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ALFRED_PASTE] = ACTION_TAP_DANCE_DOUBLE( G(KC_V) , C(G(A(KC_V))) ),
    [TD_SCREEN] = ACTION_TAP_DANCE_DOUBLE( S(G(KC_4)) , S(G(C(KC_4))) ),
    [TD_FULL_FLOAT] = ACTION_TAP_DANCE_DOUBLE( A(KC_F18), C(A(KC_F18))),
    [TD_MVW_1] = ACTION_TAP_DANCE_DOUBLE(FCW_1, MVW_1),
    [TD_MVW_2] = ACTION_TAP_DANCE_DOUBLE(FCW_2, MVW_2),
    [TD_MVW_3] = ACTION_TAP_DANCE_DOUBLE(FCW_3, MVW_3),
    [TD_MVW_4] = ACTION_TAP_DANCE_DOUBLE(FCW_4, MVW_4),
    [TD_MVW_5] = ACTION_TAP_DANCE_DOUBLE(FCW_5, MVW_5),
    [TD_MVW_6] = ACTION_TAP_DANCE_DOUBLE(FCW_6, MVW_6),
    [TD_MVW_7] = ACTION_TAP_DANCE_DOUBLE(FCW_7, MVW_7),
    [TD_MVW_8] = ACTION_TAP_DANCE_DOUBLE(FCW_8, MVW_8),
    [TD_MVW_9] = ACTION_TAP_DANCE_DOUBLE(FCW_9, MVW_9),

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE LAYER
  [_QWERTY] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |  hmrw  |   Q    |   W    |   E    |   R    |   T    |      |    Y   |   U    |   I    |   O    |   P    |  Alfr |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |   A    |   S    |   D    |   F    |   G    |      |    H   |   J    |   K    |   L    |   '    |  ;    |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | SftCaps|   Z    |   X    |   C    |   V    |   B    |      |    N   |   M    |   ,    |   .    |   /    | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |Med/Esc|Nav/Spc|Til/Tab|  |Sym/Ent|Num/Bsp|Fun/Del|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_QWERTY] = LAYOUT_split_3x6_3(
    XXX,          KC_Q,    KC_W,   KC_E,   KC_R,      KC_T,           KC_Y,    KC_U,       KC_I,      KC_O,     KC_P,      XXX,
    _______,       CTL_A,   ALT_S,  CMD_D,  SFT_F,     KC_G,           KC_H,    SFT_J,      CMD_K,     ALT_L,    CTL_QUOTE, XXX,
    TD(TD_SCREEN), KC_Z,    KC_X,   KC_C,   KC_V,      KC_B,           KC_N,    KC_M,       KC_COMM,   KC_DOT,   KC_SLSH,   _______, /*KC_ENT*/
                                  MEDI_ESC,  NAV_SPC,  TIL_TAB,        SYM_ENT,  NUM_BSP,  FUN_DEL

  ),

/*
 * Media LAYER
  [_MEDIA] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,-----------------------------------------------------.
    |  BOOT  | ------ | ------ | ------ | ------ | ------ |      | ------ | RGBTOG | RGBMOD | RGBHUI | RGBSAI | RGBVAI |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+------- |
    | ------ |KC_LCTL |KC_LALT |KC_LGUI |KC_LSFT | ------ |      | ------ |KC_MPRV |KC_VOLD |KC_VOLU |KC_MNXT | ------ |
  //|------yy--+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
    | ------ |KC_ALGR | ------ | ------ | ------ | ------ |      | ------ | ------ | ------ |KC_BRMD |KC_BRMU | ------ |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       |       |  |KC_MSTP|KC_MPLY|KC_MUTE|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_MEDIA] = LAYOUT_split_3x6_3(
    QK_BOOT,  _______,  _______,  _______,  _______,   _______,          _______,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,   _______,          _______,    KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  _______,
    _______,  KC_ALGR,  _______,  _______,  _______,   _______,          _______,    _______,  _______,  KC_BRMD,  KC_BRMU,  _______,
                                  _______,  _______,   _______,          KC_MSTP,  KC_MPLY,  KC_MUTE
  ),

/*
 * NAVIGATION LAYER
  [_TPL] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    | ------ |  Save  |AlfPaste|  Copy  |  Cut   |  Undo  |      |  Save  |AlfPaste|  Copy  |  Cut   |  Undo  | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |KC_LCTL |KC_LALT |KC_LGUI |KC_LSFT | ------ |      |KC_CAPS |KC_LEFT |KC_DOWN |  KC_UP |KC_RGHT | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |KC_ALGR | ------ | ------ | ------ | ------ |      | KC_INS |KC_HOME |KC_PGDN |KC_PGUP | KC_END | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       |       |  | KC_ENT|KC_BSPC| KC_DEL|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_NAV] = LAYOUT_split_3x6_3(
    _______,  SAVE,     PASTE,   COPY,     CUT,      UNDO,               SAVE,     PASTE,    COPY,     CUT,      UNDO,  _______,
    _______,  KC_LCTL,  KC_LALT, KC_LGUI,  KC_LSFT,  _______,            KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,
    _______,  _______,  _______, _______,  _______,  _______,            KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,
                                _______,    _______, _______,            KC_ENT,   KC_BSPC, KC_DEL
  ),

/*
 * TILLING LAYER
    Set to custom skhd shortcuts via yabai
  [_TILNAV] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    | ------ |  Save  |AlfPaste|  Copy  |  Cut   |  Undo  |      | ------ | ------ | YA_BLN | YA_FUL | YA_ROT | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |KC_LCTL |KC_LALT |KC_LGUI |KC_LSFT | ------ |      | ------ |YA_LEFT |YA_DOWN |  YA_UP |YA_RGHT | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |KC_ALGR | ------ | ------ | ------ | ------ |      | ------ | ------ | ------ | ------ | ------ | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       |       |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_TILNAV] = LAYOUT_split_3x6_3(
    _______, KC_NO,    FCS_MV7,  FCS_MV8,  FCS_MV9,  KC_NO,                   _______, _______,    A(KC_F19),  FUL_FLO,  A(KC_F17), _______,
    _______, MVW_LEF,  FCS_MV4,  FCS_MV5,  FCS_MV6,  MVW_RIG,                _______, MOV_WES,  MOV_SOU,  MOV_NOR,  MOV_EAS, _______,
    _______, KC_NO,    FCS_MV1,  FCS_MV2,  FCS_MV3,  XXX,                _______,  _______,   _______,    _______,    _______,   _______,
                                             _______,  _______,  _______,                KC_LCTL, KC_LSFT, _______
  ),

/*
 * SYMBOL LAYER
 *
  [_SYM] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |  PIPE  |   &    |   *    |   \    |   []   |      |        |        |        |        |        |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |    :   |   $    |   %    |   ^    |   ()   |      |        |  SHIFT |   CMD  |   ALT  |  CTRL  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   ~    |    !   |   @    |   #    |   {}   |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |   ;   |   -   |   _   |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_SYM] = LAYOUT_split_3x6_3(
    _______,  KC_PIPE,  KC_AMPR,  KC_ASTR,  KC_BSLS,  SQUARES,         _______, _______, _______, _______, _______, KC_BSPC,
    _______,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  BRACKETS,        _______, KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL, _______,
    _______,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  CURLIES,         _______, _______, _______, _______, _______, _______,
                                  KC_SCLN,  KC_PMNS,  KC_UNDS,               _______, _______, _______
  ),


  /*
 * NUMBER LAYER
  [_TPL] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |   =    |   7    |   8    |   9    |   *    |      |        |        |        |        |        |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   :    |   4    |   5    |   6    |   -    |      |        |  SHIFT |   CMD  |   ALT  |  CTRL  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   /    |   1    |   2    |   3    |   +    |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |   .   |   0   |   ,   |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_NUM] = LAYOUT_split_3x6_3(
    _______,  KC_EQL,  KC_7,   KC_8,    KC_9,  KC_PAST,      _______, _______, _______, _______, KC_BSPC, KC_BSPC,
    _______,  KC_COLN, KC_4,   KC_5,    KC_6,  KC_PMNS,      _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______,
    _______,  KC_SLSH, KC_1,   KC_2,    KC_3,  KC_PPLS,      _______, _______, _______, _______, _______, _______,
                               KC_DOT,  KC_0,  KC_COMM,      _______, _______, _______
  ),



/*
 * FUN LAYER
  [_TPL] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |   F12  |   F7   |   F8   |   F9   |PRNTSCRN|      |        |        |        |        |        |QK_BOOT|
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   F11  |   F4   |   F5   |   F6   |        |      |        |  SHIFT |   CMD  |   ALT  |  CTRL  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   F10  |   F1   |   F2   |   F3   | PAUSE  |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |  ESC  | SPACE |  TAB  |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_FUN] = LAYOUT_split_3x6_3(
    _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                      _______, _______, _______, _______, _______, QK_BOOT,
    _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                     _______, KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL, _______,
    _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                    _______, _______, _______, _______, _______, _______,
                                         KC_ESC,  KC_SPC,  KC_TAB,     _______, _______, _______
  )
};


#ifdef OLED_ENABLE

#include "mario.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _TILNAV:
            oled_write_ln_P(PSTR("Tilnav"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case _FUN:
        // case _ADJUST|_LOWER:
        // case _ADJUST|_RAISE:
        // case _ADJUST|_LOWER|_RAISE:
        // case _ADJUST|_LOWER|_RAISE|_SPACE:
        // case _ADJUST|_LOWER|_RAISE|_SPACE|_NUMPAD|_SODA:
            oled_write_ln_P(PSTR("Fun"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}



bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_anim();

    }
    return false;
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {
        case CURLIES:
              if (record->event.pressed) {
                SEND_STRING("{}");
                tap_code(KC_LEFT);
              }
              return false;
        case BRACKETS:
              if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
              }
              return false;
        case SQUARES:
              if (record->event.pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
              }
              return false;
    }

  return true;
}
