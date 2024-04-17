#pragma once
#include "t4corun.h"

enum combos {

  // left hand combos
#if defined(MOUSEKEY_ENABLE)
  MOUSE_BUTTON1,
  MOUSE_BUTTON2,
  MOUSE_BUTTON3,
  MOUSE_BUTTON4,
  MOUSE_BUTTON5,
  MOUSE_DRGTOG,
#endif //MOUSEKEY_ENABLE

  KEY_ESC,
  KEY_TAB,
  KEY_ENT,
  LYR_FUNCTION,

  // right hand combos
  KEY_DEL,
  KEY_BSPC,
  LYR_CONFIG,

  COMBO_LENGTH
};


// left hand combos
#if defined(MOUSEKEY_ENABLE)
const uint16_t PROGMEM mou_btn1_combo[] = { KC_D,    KC_F,    COMBO_END };
const uint16_t PROGMEM mou_btn2_combo[] = { KC_S,    KC_D,    COMBO_END };
const uint16_t PROGMEM mou_btn3_combo[] = { KC_S,    KC_F,    COMBO_END };
const uint16_t PROGMEM mou_btn4_combo[] = { KC_E,    KC_R,    COMBO_END };
const uint16_t PROGMEM mou_btn5_combo[] = { KC_W,    KC_E,    COMBO_END };
const uint16_t PROGMEM mou_drg_combo[]  = { KC_Z,    KC_X,    COMBO_END };
#endif //MOUSEKEY_ENABLE

const uint16_t PROGMEM key_esc_combo[] = { KC_Q,    KC_W,    COMBO_END };
const uint16_t PROGMEM key_tab_combo[] = { KC_C,    KC_V,    COMBO_END };
const uint16_t PROGMEM key_ent_combo[] = { KC_X,    KC_V,    COMBO_END };
const uint16_t PROGMEM lyr_fun_combo[] = { NUM,     TR_LSFT, COMBO_END };

// right hand combos
const uint16_t PROGMEM key_del_combo[]  = { KC_M,    TR_DOT,  COMBO_END };
const uint16_t PROGMEM key_bspc_combo[] = { KC_M,    TR_COMM, COMBO_END };
const uint16_t PROGMEM lyr_cfg_combo[]  = { KC_SPC,  NAV,     COMBO_END };


combo_t key_combos[COMBO_LENGTH] = {

  // left hand combos
#if defined(MOUSEKEY_ENABLE)
  [MOUSE_BUTTON1] = COMBO(mou_btn1_combo, TR_BTN1),
  [MOUSE_BUTTON2] = COMBO(mou_btn2_combo, TR_BTN2),
  [MOUSE_BUTTON3] = COMBO(mou_btn3_combo, TR_BTN3),
  [MOUSE_BUTTON4] = COMBO(mou_btn4_combo, TR_BTN4),
  [MOUSE_BUTTON5] = COMBO(mou_btn5_combo, TR_BTN5),
  [MOUSE_DRGTOG]  = COMBO(mou_drg_combo,  TR_DRGS),
#endif //MOUSEKEY_ENABLE

  [KEY_ESC]      = COMBO(key_esc_combo,  KC_ESC),
  [KEY_TAB]      = COMBO(key_tab_combo,  KC_TAB),
  [KEY_ENT]      = COMBO(key_ent_combo,  KC_ENT),
  [LYR_FUNCTION] = COMBO(lyr_fun_combo,  FUNC),

  // right hand combos
  [KEY_DEL]      = COMBO(key_del_combo,  KC_DEL),
  [KEY_BSPC]     = COMBO(key_bspc_combo, KC_BSPC),
  [LYR_CONFIG]   = COMBO(lyr_cfg_combo,  CONFIG)

};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;
