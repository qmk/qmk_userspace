#pragma once
#include "t4corun.h"

enum combos {

#if defined(MOUSEKEY_ENABLE)
  MOUSE_BUTTON1,
  MOUSE_BUTTON2,
  MOUSE_BUTTON3,
  MOUSE_BUTTON4,
  MOUSE_BUTTON5,
  MOUSE_DRGTOG,
#endif //MOUSEKEY_ENABLE

  COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;


#if defined(MOUSEKEY_ENABLE)
const uint16_t PROGMEM mou_btn1_combo[] = { KC_D,    KC_F,    COMBO_END };
const uint16_t PROGMEM mou_btn2_combo[] = { KC_S,    KC_D,    COMBO_END };
const uint16_t PROGMEM mou_btn3_combo[] = { KC_G,    KC_B,    COMBO_END };
const uint16_t PROGMEM mou_btn4_combo[] = { KC_F,    KC_R,    COMBO_END };
const uint16_t PROGMEM mou_btn5_combo[] = { KC_T,    KC_G,    COMBO_END };
const uint16_t PROGMEM mou_drg_combo[]  = { KC_X,    KC_C,    COMBO_END };
#endif //MOUSEKEY_ENABLE



combo_t key_combos[COMBO_LENGTH] = {

#if defined(MOUSEKEY_ENABLE)
  [MOUSE_BUTTON1] = COMBO(mou_btn1_combo, TR_BTN1),
  [MOUSE_BUTTON2] = COMBO(mou_btn2_combo, TR_BTN2),
  [MOUSE_BUTTON3] = COMBO(mou_btn3_combo, TR_BTN3),
  [MOUSE_BUTTON4] = COMBO(mou_btn4_combo, TR_BTN4),
  [MOUSE_BUTTON5] = COMBO(mou_btn5_combo, TR_BTN5),
  [MOUSE_DRGTOG]  = COMBO(mou_drg_combo,  TR_DRGS),
#endif //MOUSEKEY_ENABLE

};

