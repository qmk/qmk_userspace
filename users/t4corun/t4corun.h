#pragma once
#include QMK_KEYBOARD_H
#include "features/taphold.h"

#if defined(WPM_ENABLE)
bool isLunaJumping(void);
bool isJumpShown(void);
void setLunaJumped(void);
#endif // WPM_ENABLE

#define HOLD_MOD_TIMEOUT 1000

// put the default base layers first
enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,
  _COLEMAK_DH,
  _GAME,
  _NAVIGATION,
  _NUMBER,
  _SYMBOL,
  _MOUSE_FUNC,
  _CONFIG
};

// start at the second layer
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#define _DEFAULT_LAYER_3 (FIRST_DEFAULT_LAYER + 2)
#define NUM_DEFAULT_LAYERS 3

enum keycodes {
  //These are only here to make the taphold/defines unique
  TH_LCBR = QK_USER,
  TH_LABK,
  TH_LBRC,
  TH_LPRN,
  TH_DQUO,
  TH_SQUO,

  TH_BSLS,
  TH_SLSH,
  TH_PIPE,

  TH_COMM,
  TH_DOT,
  TH_PERC,

  TH_EQL,
  TH_MINS,
  TH_GRV,
  TH_SCLN,
  TH_QUOT,

  PN_BOOT,  // Press to enter Ploopy Nano Bootloader

  TR_HNXT,  // HF_NEXT or HF_PREV when shift is held
  TR_CKUP,  // CK_UP or CK_DOWN when shift is held

  FWD_TAB,
  REV_TAB,

  FWD_RGB,
  REV_RGB,

  ZOOMIN,
  ZOOMOUT,

  BASELYR,
  RBSELYR
};

#define ___x___ KC_NO

// layer changes
#define NAV     MO(_NAVIGATION)
#define NUM     MO(_NUMBER)
#define MF_Z    LT(_MOUSE_FUNC, KC_Z)
#define MOU_FUN TG(_MOUSE_FUNC)
#define CONFIG  MO(_CONFIG)

// Windows Shortcuts
#define SC_COPY LCTL(KC_C)
#define SC_CUT  LCTL(KC_X)
#define SC_UNDO LCTL(KC_Z)
#define SC_PAST LCTL(KC_V)
#define SC_REDO LCTL(KC_Y)
#define SC_SNIP LGUI(LSFT(KC_S))
#define SC_FILE LGUI(KC_E)
#define SC_WIN  LGUI(KC_TAB)

// Encoders
#define ZOOMRST LCTL(KC_0)
#define SCR_TOP LCTL(KC_HOME)

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


// tap hoLd. These will be intercepted and overridden. The LT will be ignored
// Brackets: open and close brackets and put the cursor inside
#define TR_LCBR LT(FIRST_DEFAULT_LAYER, TH_LCBR)
#define TR_LABK LT(FIRST_DEFAULT_LAYER, TH_LABK)
#define TR_LBRC LT(FIRST_DEFAULT_LAYER, TH_LBRC)
#define TR_LPRN LT(FIRST_DEFAULT_LAYER, TH_LPRN)
#define TR_DQUO LT(FIRST_DEFAULT_LAYER, TH_DQUO)
#define TR_SQUO LT(FIRST_DEFAULT_LAYER, TH_SQUO)

// double tap
#define TR_BSLS LT(FIRST_DEFAULT_LAYER, TH_BSLS)
#define TR_SLSH LT(FIRST_DEFAULT_LAYER, TH_SLSH)
#define TR_PIPE LT(FIRST_DEFAULT_LAYER, TH_PIPE)

// Custom override without holding shift
#define TR_COMM LT(FIRST_DEFAULT_LAYER, TH_COMM)
#define TR_DOT  LT(FIRST_DEFAULT_LAYER, TH_DOT)
#define TR_PERC LT(FIRST_DEFAULT_LAYER, TH_PERC)

// auto shift
#define TR_EQL  LT(FIRST_DEFAULT_LAYER, TH_EQL)
#define TR_MINS LT(FIRST_DEFAULT_LAYER, TH_MINS)
#define TR_GRV  LT(FIRST_DEFAULT_LAYER, TH_GRV)
#define TR_SCLN LT(FIRST_DEFAULT_LAYER, TH_SCLN)
#define TR_QUOT LT(FIRST_DEFAULT_LAYER, TH_QUOT)


#if defined(KEYBOARD_bastardkb_charybdis_3x5)
//these mouse codes are defined in charybdis.h
#  define TR_SNIP SNIPING  
#  define TR_DRGS DRG_TOG
#  define TR_SDPI S_D_MOD  //sniping dpi
#  define TR_PDPI DPI_MOD  //pointer dpi
#else
#  define TR_SNIP ___x___
#  define TR_DRGS KC_SCRL  //use host status for ploopy nano drag scroll
#  define TR_SDPI ___x___
#  define TR_PDPI KC_NUM   //use host status for ploopy nano dpi switch
#endif //KEYBOARD_bastardkb_charybdis_3x5


#define _NONE_3__________________                   ___x___, ___x___, ___x___
#define _NONE_5____________________________________ ___x___, ___x___, ___x___, ___x___, ___x___
#define _GACS_MODS________________________          TR_LGUI, TR_LALT, TR_LCTL, TR_LSFT
#define _SCAG_MODS________________________          TR_LSFT, TR_LCTL, TR_LALT, TR_LGUI
#define _UCCPR_L___________________________________ SC_UNDO, SC_CUT,  SC_COPY, SC_PAST, SC_REDO

#define _BASE_L4_________________                   KC_BTN1, NUM,     TR_LSFT
#define _BASE_R4_________________                   KC_SPC,  NAV,     ___x___
#define _LAYER_TRANS_____________                   ___x___, _______, ___x___


//___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,

#define LAYER_QWERTY                                                                        \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TR_QUOT, \
  MF_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_COLEMAK_DH                                                                    \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TR_QUOT, \
  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
  MF_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_GAME                                                                          \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_4,    KC_5,    KC_6,    KC_GRV,  \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_1,    KC_2,    KC_3,    CM_TOGG, \
                    KC_ENT,  KC_SPC,  KC_LSFT, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_NAVIGATION                                                                    \
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, ___x___, KC_APP,  ___x___, DM_REC1, DM_PLY1, \
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _SCAG_MODS________________________, \
  _UCCPR_L___________________________________, KC_DEL,  KC_TAB,  KC_VOLD, KC_VOLU, KC_MUTE, \
                    ___x___, NUM,     KC_ENT,  _LAYER_TRANS_____________,                   \
                                      SCR_TOP, ___x___


#define LAYER_NUMBER                                                                        \
  KC_ESC,  SC_SNIP, SC_FILE, MOU_FUN, KC_ENT,  ___x___, KC_7,    KC_8,    KC_9,    KC_COMM, \
  _GACS_MODS________________________, KC_TAB,  ___x___, KC_4,    KC_5,    KC_6,    KC_DOT,  \
  _UCCPR_L___________________________________, ___x___, KC_1,    KC_2,    KC_3,    KC_MINS, \
                    _LAYER_TRANS_____________, KC_0,    NAV,     ___x___,                   \
                                      ___x___, SC_WIN


#define LAYER_SYMBOL                                                                        \
  QK_BOOT, ___x___, KC_AT,   KC_DLR,  TR_GRV,  TR_EQL,  KC_HASH, KC_ASTR, ___x___, ___x___, \
  PN_BOOT, TR_LCBR, KC_RCBR, TR_PIPE, TR_SCLN, KC_AMPR, KC_QUES, TR_LBRC, KC_RBRC, ___x___, \
  BASELYR, TR_LABK, KC_RABK, TR_BSLS, KC_EXLM, TR_PERC, TR_SLSH, TR_LPRN, KC_RPRN, ___x___, \
                    _LAYER_TRANS_____________, _LAYER_TRANS_____________,                   \
                                      ___x___, ___x___


#define LAYER_MOUSE_FUNC                                                                    \
  MOU_FUN, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, HF_TOGG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
  _GACS_MODS________________________, TR_DRGS, AU_TOGG, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
  _______, RGB_MOD, KC_BTN5, KC_BTN4, TR_SNIP, RGB_TOG, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
                    KC_BTN1, KC_BTN3, KC_BTN2, TR_PDPI, TR_SDPI, ___x___,                   \
                                      SCR_TOP, ZOOMRST

/*

#define LAYER_CONFIG                                                                        \
  ___x___, HF_RST,  TR_HNXT, HF_FDBK, HF_TOGG, BASELYR, PN_BOOT, EE_CLR,  QK_BOOT, _______, \
  RGB_MOD, CK_RST,  TR_CKUP, CK_TOGG, AU_TOGG, ___x___, TR_LSFT, ___x___, ___x___, ___x___, \
  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_TOG, ___x___, ___x___, ___x___, ___x___, ___x___, \
                    ___x___, DM_REC1, DM_PLY1, ___x___, ___x___, ___x___,                   \
                                      ___x___, ___x___
*/





/*
#define LAYER_QWERTY                                                                        \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TR_QUOT, \
  MF_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_COLEMAK_DH                                                                    \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TR_QUOT, \
  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
  MF_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_GAME                                                                          \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_4,    KC_5,    KC_6,    KC_GRV,  \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_1,    KC_2,    KC_3,    CM_TOGG, \
                    KC_ENT,  KC_SPC,  KC_LSFT, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_NAVIGATION                                                                    \
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, ___x___, KC_APP,  ___x___, ___x___, CONFIG,  \
  ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _SCAG_MODS________________________, \
  _UCCPR_L___________________________________, KC_DEL,  KC_TAB,  KC_VOLD, KC_VOLU, KC_MUTE, \
                    ___x___, NUM,     KC_ENT,  _LAYER_TRANS_____________,                   \
                                      SCR_TOP, ___x___


#define LAYER_NUMBER                                                                        \
  KC_ESC,  SC_SNIP, SC_FILE, MOU_FUN, KC_ENT,  ___x___, KC_7,    KC_8,    KC_9,    KC_COMM, \
  _GACS_MODS________________________, KC_TAB,  KC_BSPC, KC_4,    KC_5,    KC_6,    KC_DOT,  \
  _UCCPR_L___________________________________, KC_DEL,  KC_1,    KC_2,    KC_3,    KC_MINS, \
                    _LAYER_TRANS_____________, KC_0,    NAV,     ___x___,                   \
                                      ___x___, SC_WIN


#define LAYER_SYMBOL                                                                        \
  KC_ESC,  ___x___, KC_AT,   KC_DLR,  TR_GRV,  TR_EQL,  KC_HASH, KC_ASTR, ___x___, TR_DQUO, \
  KC_AMPR, TR_LCBR, KC_RCBR, TR_PIPE, TR_SCLN, KC_BSPC, KC_QUES, TR_LBRC, KC_RBRC, TR_SQUO, \
  TR_PERC, TR_LABK, KC_RABK, TR_BSLS, KC_EXLM, KC_DEL,  TR_SLSH, TR_LPRN, KC_RPRN, TR_MINS, \
                    _LAYER_TRANS_____________, _LAYER_TRANS_____________,                   \
                                      ___x___, ___x___


#define LAYER_MOUSE_FUNC                                                                    \
  MOU_FUN, KC_MPRV, KC_MNXT, KC_MPLY, ___x___, ___x___, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
  _GACS_MODS________________________, TR_DRGS, KC_CAPS, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
  _______, ___x___, KC_BTN5, KC_BTN4, TR_SNIP, ___x___, KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
                    KC_BTN1, KC_BTN3, KC_BTN2, TR_PDPI, TR_SDPI, ___x___,                   \
                                      SCR_TOP, ZOOMRST


#define LAYER_CONFIG                                                                        \
  ___x___, HF_RST,  TR_HNXT, HF_FDBK, HF_TOGG, BASELYR, PN_BOOT, EE_CLR,  QK_BOOT, _______, \
  RGB_MOD, CK_RST,  TR_CKUP, CK_TOGG, AU_TOGG, ___x___, TR_LSFT, ___x___, ___x___, ___x___, \
  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_TOG, ___x___, ___x___, ___x___, ___x___, ___x___, \
                    ___x___, DM_REC1, DM_PLY1, ___x___, ___x___, ___x___,                   \
                                      ___x___, ___x___


*/