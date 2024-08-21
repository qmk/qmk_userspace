#pragma once
#include "t4corun.h"

const uint16_t PROGMEM mou_btn2_combo[] = { KC_C,    KC_V,    COMBO_END };
const uint16_t PROGMEM mou_drg_combo[]  = { KC_X,    KC_V,    COMBO_END };

enum combos {
  MOUSE_BUTTON2,
  MOUSE_DRGTOG,
  COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[COMBO_LENGTH] = {
  [MOUSE_BUTTON2] = COMBO(mou_btn2_combo, KC_BTN2),
  [MOUSE_DRGTOG]  = COMBO(mou_drg_combo,  TR_DRGS)
};