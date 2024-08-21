#pragma once
#include QMK_KEYBOARD_H
#include "features/taphold.h"

void set_default_layer(bool forward);
void reset_ploopynano(void);

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
  _MOUSE,
  _FUNCTION,
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

  FWD_TAB,  // turn encoder for tab and shift tab
  REV_TAB,  // hold alt or ctrl while turning for window / tab switching

  ZOOMIN,   // turn encoder for mouse wheel zoom
  ZOOMOUT,

  FWD_CFG,  // turn encoder while holding mod combinations to adjust features
  REV_CFG,  // e.g. RGB settings, haptic frequency, click frequency, base layer

  TOG_CFG   // press key while holding mod combinations to toggle features or enter bootloader

};

#define ___x___ KC_NO

// layer changes
#define NAV     MO(_NAVIGATION)
#define NUM     MO(_NUMBER)
#define MOU_A   LT(_MOUSE, KC_A)
#define MOU_TOG TG(_MOUSE)
#define FUNC    MO(_FUNCTION)
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
- If the feature is disabled then the key is just the normal key
- Any keycodes with prefix TR has behavior dependent on if the feature is enabled.
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
  MOU_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TR_QUOT, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_COLEMAK_DH                                                                    \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TR_QUOT, \
  MOU_A,   KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    TR_COMM, TR_DOT,  TR_MINS, \
                    _BASE_L4_________________, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_GAME                                                                          \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,    KC_8,    KC_9,    KC_ESC,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_4,    KC_5,    KC_6,    KC_GRV,  \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT, KC_1,    KC_2,    KC_3,    ___x___, \
                    KC_ENT,  KC_SPC,  KC_LSFT, _BASE_R4_________________,                   \
                                      SCR_TOP, KC_MUTE


#define LAYER_NAVIGATION                                                                    \
  KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, ___x___, KC_APP,  ___x___, ___x___, ___x___, \
  ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSPC, _SCAG_MODS________________________, \
  _UCCPR_L___________________________________, KC_DEL,  KC_TAB,  ___x___, ___x___, ___x___, \
                    ___x___, NUM,     KC_ENT,  _LAYER_TRANS_____________,                   \
                                      SCR_TOP, TOG_CFG


#define LAYER_NUMBER                                                                        \
  KC_ESC,  SC_SNIP, SC_FILE, ___x___, ___x___, KC_TAB,  KC_7,    KC_8,    KC_9,    KC_COMM, \
  _GACS_MODS________________________, ___x___, KC_BSPC, KC_4,    KC_5,    KC_6,    KC_DOT,  \
  _UCCPR_L___________________________________, KC_DEL,  KC_1,    KC_2,    KC_3,    KC_MINS, \
                    _LAYER_TRANS_____________, KC_0,    NAV,     ___x___,                   \
                                      ___x___, SC_WIN


#define LAYER_SYMBOL                                                                        \
  ___x___, ___x___, KC_AT,   KC_DLR,  TR_GRV,  TR_EQL,  KC_HASH, KC_ASTR, ___x___, TR_DQUO, \
  KC_AMPR, TR_LCBR, KC_RCBR, TR_PIPE, TR_SCLN, KC_BSPC, KC_QUES, TR_LBRC, KC_RBRC, TR_SQUO, \
  TR_PERC, TR_LABK, KC_RABK, TR_BSLS, KC_EXLM, KC_DEL,  TR_SLSH, TR_LPRN, KC_RPRN, TR_MINS, \
                    _LAYER_TRANS_____________, _LAYER_TRANS_____________,                   \
                                      ___x___, ___x___


#define LAYER_MOUSE                                                                         \
  _NONE_5____________________________________, TR_PDPI, TR_SDPI, ___x___, ___x___, MOU_TOG, \
  _______, TR_LALT, TR_LCTL, TR_LSFT, TR_DRGS, ___x___, ___x___, ___x___, ___x___, ___x___, \
  ___x___, KC_BTN1, KC_BTN5, KC_BTN4, TR_SNIP, ___x___, ___x___, ___x___, ___x___, ___x___, \
                    KC_BTN1, KC_BTN3, KC_BTN2, ___x___, ___x___, ___x___,                   \
                                      SCR_TOP, ZOOMRST


#define LAYER_FUNCTION                                                                      \
  ___x___, ___x___, ___x___, ___x___, KC_NUM,  KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
  _GACS_MODS________________________, KC_CAPS, KC_BRK,  KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
  ___x___, ___x___, ___x___, ___x___, KC_SCRL, KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  \
                    _NONE_3__________________, DM_PLY1, DM_REC1, ___x___,                   \
                                      ___x___, ___x___


#define LAYER_CONFIG                                                                        \
  _NONE_5____________________________________, ___x___, KC_VOLD, KC_VOLU, KC_MUTE, QK_BOOT, \
  ___x___, FWD_CFG, REV_CFG, TOG_CFG, ___x___, ___x___, _SCAG_MODS________________________, \
  _NONE_5____________________________________, _NONE_5____________________________________, \
                    _NONE_3__________________, _NONE_3__________________,                   \
                                      TOG_CFG, TOG_CFG
