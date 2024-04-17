#pragma once
#include "t4corun.h"

enum combos {
  //DRAGTOGGLE,
  //SNIPERTOGGLE,c
  //MOUSEBUTTON4,

#if defined(MOUSELAYER_ENABLE)
  MOUSE_BUTTON1,
  MOUSE_BUTTON2,
  MOUSE_BUTTON4,
  MOUSE_DRGTOG,
#endif //MOUSELAYER_ENABLE

  KB_TAB,
  KB_BSPC,
  LYR_CONFIG,
  LYR_FUNCTION,
  COMBO_LENGTH
};

#if defined(MOUSELAYER_ENABLE)
const uint16_t PROGMEM mou_btn1_combo[] = { KC_D,    KC_F,    COMBO_END };
const uint16_t PROGMEM mou_btn2_combo[] = { KC_D,    KC_G,    COMBO_END };
const uint16_t PROGMEM mou_btn4_combo[] = { KC_C,    KC_V,    COMBO_END };
const uint16_t PROGMEM mou_drg_combo[]  = { TR_COMM, TR_DOT,  COMBO_END };
#endif //MOUSELAYER_ENABLE

const uint16_t PROGMEM kb_tab_combo[]  = { KC_S,    KC_F,    COMBO_END };
const uint16_t PROGMEM kb_bspc_combo[] = { KC_J,    KC_L,    COMBO_END };
const uint16_t PROGMEM lyr_cfg_combo[] = { KC_SPC,  NAV,     COMBO_END };
const uint16_t PROGMEM lyr_fun_combo[] = { NUM,     TR_LSFT, COMBO_END };

combo_t key_combos[COMBO_LENGTH] = {

#if defined(MOUSELAYER_ENABLE)
  [MOUSE_BUTTON1] = COMBO(mou_btn1_combo, TR_BTN1),
  [MOUSE_BUTTON2] = COMBO(mou_btn2_combo, TR_BTN2),
  [MOUSE_BUTTON4] = COMBO(mou_btn4_combo, TR_BTN4),
  [MOUSE_BUTTON4] = COMBO(mou_drg_combo,  TR_DRGS),
#endif //MOUSELAYER_ENABLE

  [KB_TAB]       = COMBO(kb_tab_combo,   KC_TAB),
  [KB_BSPC]      = COMBO(kb_bspc_combo,  KC_BSPC),
  [LYR_CONFIG]   = COMBO(lyr_cfg_combo,  CONFIG),
  [LYR_FUNCTION] = COMBO(lyr_fun_combo,  FUNC)
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;