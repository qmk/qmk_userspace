#pragma once
#include "t4corun.h"


const uint16_t PROGMEM mou_btn1_combo[] = { KC_C,    KC_V,    COMBO_END };
const uint16_t PROGMEM mou_drg_combo[]  = { KC_X,    KC_V,    COMBO_END };

const uint16_t PROGMEM key_ent_combo[]  = { KC_D,    KC_F,    COMBO_END };
const uint16_t PROGMEM key_bspc_combo[] = { KC_M,    TR_COMM, COMBO_END };
const uint16_t PROGMEM key_tab_combo[]  = { KC_J,    KC_K,    COMBO_END };


enum combos {
  MOUSE_BUTTON1,
  MOUSE_DRGTOG,
  KEY_ENT,
  KEY_BSPC,
  KEY_TAB,
  COMBO_LENGTH
};

//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[COMBO_LENGTH] = {
  [MOUSE_BUTTON1] = COMBO(mou_btn1_combo, KC_BTN1),
  [MOUSE_DRGTOG]  = COMBO(mou_drg_combo,  TR_DRGS),
  [KEY_ENT]      = COMBO(key_ent_combo,  KC_ENT),
  [KEY_BSPC]     = COMBO(key_bspc_combo, KC_BSPC),
  [KEY_TAB]      = COMBO(key_tab_combo,  KC_TAB)
};