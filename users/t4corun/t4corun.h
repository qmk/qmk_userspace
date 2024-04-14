#pragma once
#include QMK_KEYBOARD_H
#include "features/taphold.h"


enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,
  _COLEMAK_DH,
  _GAME,
  _NAVIGATION,
  _NUMBER,
  _SYMBOL,
  _FUNCTION,
  _MOUSE,
  _GAME_NUM,
  _CONFIG
};

enum keycodes {
  //These are only here to make the case statements unique in taphold.c
  TH_LCBR = QK_USER,
  TH_LABK,
  TH_LBRC,
  TH_SQUO,
  TH_DQUO,
  TH_LPRN,
  TH_COMM,
  TH_DOT,
  TH_PERC,
  TH_EQL,
  TH_MINS,
  TH_GRV,
  TH_SCLN,
  TH_QUOT,

  PN_DRGS,
  PN_PDPI,

  BASELYR
};

#define ___x___ KC_NO

// momentary layer
#define NAV        MO(_NAVIGATION)
#define NAV_0      LT(_NAVIGATION, KC_0)
#define NUM        MO(_NUMBER)
#define CONFIG     MO(_CONFIG)
#define FUNC       MO(_FUNCTION)
#define GAMENUM    MO(_GAME_NUM)

// Windows Shortcuts
#define SC_COPY    LCTL(KC_C)
#define SC_CUT     LCTL(KC_X)
#define SC_UNDO    LCTL(KC_Z)
#define SC_PAST    LCTL(KC_V)
#define SC_REDO    LCTL(KC_Y)
#define SC_SNIP    LGUI(LSFT(KC_S))
#define SC_FILE    LGUI(KC_E)

// Zoom
#define ZOOMIN     LCTL(LSFT(KC_EQL))
#define ZOOMOUT    LCTL(KC_MINS)
#define ZOOMRST    LCTL(KC_0)

/*
- Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
- If the feature is disabled then the key is just the normal key
- We will only define things that are used across different layers. Entire layers are turned off in the keymap
*/


// one shot mods
#define TR_LSFT OSM(MOD_LSFT)
#define TR_LCTL OSM(MOD_LCTL)
#define TR_LALT OSM(MOD_LALT)
#define TR_LGUI OSM(MOD_LGUI)


//tap hoLd
#define TR_LCBR  LT(_DEFAULT_LAYER_1, TH_LCBR) // bracket behvavior
#define TR_LABK  LT(_DEFAULT_LAYER_1, TH_LABK)
#define TR_LBRC  LT(_DEFAULT_LAYER_1, TH_LBRC) 
#define TR_SQUO  LT(_DEFAULT_LAYER_1, TH_SQUO)
#define TR_DQUO  LT(_DEFAULT_LAYER_1, TH_DQUO)

#define TR_LPRN  LT(_DEFAULT_LAYER_1, TH_LPRN) // custom behavior
#define TR_COMM  LT(_DEFAULT_LAYER_1, TH_COMM)
#define TR_DOT   LT(_DEFAULT_LAYER_1, TH_DOT)
#define TR_PERC  LT(_DEFAULT_LAYER_1, TH_PERC)

#define TR_EQL   LT(_DEFAULT_LAYER_1, TH_EQL)  // basically auto shift
#define TR_MINS  LT(_DEFAULT_LAYER_1, TH_MINS)
#define TR_GRV   LT(_DEFAULT_LAYER_1, TH_GRV)
#define TR_SCLN  LT(_DEFAULT_LAYER_1, TH_SCLN)
#define TR_QUOT  LT(_DEFAULT_LAYER_1, TH_QUOT)


#if defined(MOUSEKEY_ENABLE)
#   define TR_MOUZ LT(_MOUSE, KC_Z)

#   define TR_MOUU KC_MS_U
#   define TR_MOUD KC_MS_D
#   define TR_MOUL KC_MS_L
#   define TR_MOUR KC_MS_R

#   define TR_MWHU KC_WH_U //Mouse wheel keys are not needed unless the board has no encoders
#   define TR_MWHD KC_WH_D

#   define TR_BTN1 KC_BTN1
#   define TR_BTN2 KC_BTN2
#   define TR_BTN3 KC_BTN3
#   define TR_BTN4 KC_BTN4
#   define TR_BTN5 KC_BTN5

#   define TR_NUM1 LT(_NUMBER, KC_BTN1)

# if defined(KEYBOARD_bastardkb_charybdis_3x5)
//these codes are defined in charybdis.h
#   define TR_SNIP SNIPING  
#   define TR_DRGS DRGSCRL
#   define TR_SDPI S_D_MOD  //sniping dpi
#   define TR_PDPI DPI_MOD  //pointer dpi
# else
#   define TR_SNIP ___x___
#   define TR_DRGS PN_DRGS  //use host status for ploopy nano drag scroll
#   define TR_SDPI ___x___
#   define TR_PDPI PN_PDPI  //use host status for ploopy nano dpi switch
# endif //KEYBOARD_bastardkb_charybdis_3x5

#else
#   define TR_MOUZ KC_A

#   define TR_MOUU ___x___
#   define TR_MOUD ___x___
#   define TR_MOUL ___x___
#   define TR_MOUR ___x___

#   define TR_MWHU ___x___
#   define TR_MWHD ___x___

#   define TR_BTN1 ___x___
#   define TR_BTN2 ___x___
#   define TR_BTN3 ___x___
#   define TR_BTN4 ___x___
#   define TR_BTN5 ___x___

#   define TR_SNIP ___x___
#   define TR_DRGS ___x___
#   define TR_SDPI ___x___
#   define TR_PDPI ___x___

#   define TR_NUM1 MO(_NUMBER)

#endif //MOUSEKEY_ENABLE


#if defined(DYNAMIC_MACRO_ENABLE)
#   define TR_DMR1 DM_REC1
#   define TR_DMP1 DM_PLY1
#   define TR_DMR2 DM_REC2
#   define TR_DMP2 DM_PLY2
#else
#   define TR_DMR1 ___x___
#   define TR_DMP1 ___x___
#   define TR_DMR2 ___x___
#   define TR_DMP2 ___x___
#endif //DYNAMIC_MACRO_ENABLE

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#   define TR_RHUI RGB_HUI
#   define TR_RSAI RGB_SAI
#   define TR_RVAI RGB_VAI
#   define TR_RSPI RGB_SPI
#   define TR_RTOG RGB_TOG
#   define TR_RMOD RGB_MOD
#else
#   define TR_RHUI ___x___
#   define TR_RSAI ___x___
#   define TR_RVAI ___x___
#   define TR_RSPI ___x___
#   define TR_RTOG ___x___
#   define TR_RMOD ___x___
#endif //RGB_MATRIX_ENABLE || RGBLIGHT_ENABLE



#define _DEFAULT_LAYER_1 FIRST_DEFAULT_LAYER
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#define _DEFAULT_LAYER_3 (FIRST_DEFAULT_LAYER + 2)
#define NUM_BASE_LAYER 3

#define _NONE_3__________________                   ___x___, ___x___, ___x___
#define _NONE_5____________________________________ ___x___, ___x___, ___x___, ___x___, ___x___
#define _GACS_MODS________________________          TR_LGUI, TR_LALT, TR_LCTL, TR_LSFT
#define _GACS_MOUSE_MODS_________                   TR_LALT, TR_LCTL, TR_LSFT
#define _SCAG_MODS________________________          TR_LSFT, TR_LCTL, TR_LALT, TR_LGUI
#define _UCCPR_L___________________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define _BASE_L4_________________                   ___x___, TR_NUM1, TR_LSFT
#define _BASE_R4_________________                   KC_SPC,  NAV,     KC_MUTE
#define _LAYER_TRANS_____________                   ___x___, _______, ___x___


  //___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,

#define BASETEST \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    KC_TAB,  KC_ESC,  KC_LSFT, KC_SPC,  KC_ENT,  KC_MUTE


#define LAYER_QWERTY \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TR_QUOT, \
  TR_MOUZ, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________


#define LAYER_COLEMAK_DH \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TR_QUOT, \
  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
  TR_MOUZ, KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________


#define LAYER_GAME \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    _NONE_5____________________________________, \
  GAMENUM, KC_A,    KC_S,    KC_D,    KC_F,    _NONE_5____________________________________, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _NONE_5____________________________________, \
                    ___x___, KC_LSFT, KC_SPC,  _BASE_R4_________________


#define LAYER_NAVIGATION \
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,  ___x___, KC_APP,  ___x___, CONFIG,  \
  ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _SCAG_MODS________________________, \
  _UCCPR_L___________________________________, KC_DEL,  KC_TAB,  KC_VOLD, KC_VOLU, KC_MUTE, \
                    ZOOMRST, NUM,     KC_ENT,  _LAYER_TRANS_____________


#define LAYER_NUMBER \
  KC_ESC,  SC_SNIP, SC_FILE, FUNC,    TR_GRV,  KC_ENT,  KC_7,    KC_8,    KC_9,    KC_TAB,  \
  _GACS_MODS________________________, TR_SCLN, KC_BSPC, KC_4,    KC_5,    KC_6,    KC_DOT,  \
  _UCCPR_L___________________________________, KC_DEL,  KC_1,    KC_2,    KC_3,    TR_MINS, \
                    _LAYER_TRANS_____________, KC_SPC,  NAV_0,   ___x___


#define LAYER_SYMBOL \
  KC_ESC,  ___x___, KC_AT,   KC_DLR,  TR_GRV,  TR_EQL,  KC_HASH, KC_ASTR, ___x___, TR_DQUO, \
  KC_AMPR, TR_LCBR, KC_RCBR, KC_PIPE, TR_SCLN, KC_BSPC, KC_QUES, TR_LBRC, KC_RBRC, TR_SQUO, \
  TR_PERC, TR_LABK, KC_RABK, KC_BSLS, KC_EXLM, KC_DEL,  KC_SLSH, TR_LPRN, TR_DOT,  TR_MINS, \
                    _LAYER_TRANS_____________, _LAYER_TRANS_____________


#define LAYER_FUNCTION \
  TR_DMP2, TR_DMR2, ___x___, _______, KC_SCRL, KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  _NONE_5____________________________________, KC_CAPS, KC_F4,   KC_F5,   KC_F6,   KC_F11, \
  _NONE_5____________________________________, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F12, \
                    _LAYER_TRANS_____________, TR_DMP1, TR_DMR1, ___x___


#define LAYER_MOUSE \
  ___x___, TR_BTN5, TR_BTN4, TR_BTN3, ___x___, TR_MWHU, ___x___, TR_MOUU, ___x___, ___x___, \
  _______, _GACS_MOUSE_MODS_________, ___x___, TR_MWHD, TR_MOUL, TR_MOUD, TR_MOUR, ___x___, \
  _NONE_3__________________, TR_DRGS, TR_SNIP, TR_SDPI, TR_PDPI, ___x___, ___x___, ___x___, \
                    ___x___, TR_BTN1, TR_BTN2, _NONE_3__________________


#define LAYER_GAME_NUM \
  ___x___, KC_ESC,  KC_TILD, KC_G,    KC_T,    _NONE_5____________________________________, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    _NONE_5____________________________________, \
  ___x___, KC_5,    KC_6,    KC_7,    KC_8,    _NONE_5____________________________________, \
                    ___x___, KC_LALT, KC_LCTL, _LAYER_TRANS_____________


#define LAYER_CONFIG \
  _NONE_5____________________________________, EE_CLR,  QK_RBT,  QK_BOOT, ___x___, _______, \
  TR_RTOG, TR_RMOD, _NONE_3__________________, BASELYR, _SCAG_MODS________________________, \
  TR_RHUI, TR_RSAI, TR_RVAI, TR_RSPI, ___x___, _NONE_5____________________________________, \
                    _NONE_3__________________, _LAYER_TRANS_____________
