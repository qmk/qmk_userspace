#pragma once
#include "t4corun.h"


//const uint16_t PROGMEM mou_btn1_combo[] = { KC_D,    KC_F,    COMBO_END };
//const uint16_t PROGMEM mou_btn2_combo[] = { KC_S,    KC_D,    COMBO_END };
//const uint16_t PROGMEM mou_btn3_combo[] = { KC_F,    KC_G,    COMBO_END };
//const uint16_t PROGMEM mou_btn4_combo[] = { KC_F,    KC_R,    COMBO_END };
//const uint16_t PROGMEM mou_btn5_combo[] = { KC_T,    KC_G,    COMBO_END };
const uint16_t PROGMEM mou_drg_combo[]  = { KC_X,    KC_C,    COMBO_END };


//const uint16_t PROGMEM key_ent_combo[]  = { KC_C,    KC_V,    COMBO_END };
//const uint16_t PROGMEM key_tab_combo[]  = { KC_U,    KC_I,    COMBO_END };
//const uint16_t PROGMEM key_bspc_combo[] = { KC_M,    TR_COMM, COMBO_END };



enum combos {
//  MOUSE_BUTTON1,
//  MOUSE_BUTTON2,
//  MOUSE_BUTTON3,
//  MOUSE_BUTTON4,
//  MOUSE_BUTTON5,
  MOUSE_DRGTOG,

//  KEY_ENT,
//  KEY_TAB,
//  KEY_BSPC,
  COMBO_LENGTH
};


//their documentation is so confusing because you don't use COMBO_LEN defining the actions
uint16_t COMBO_LEN = COMBO_LENGTH;


combo_t key_combos[COMBO_LENGTH] = {
//  [MOUSE_BUTTON1] = COMBO(mou_btn1_combo, KC_BTN1),
//  [MOUSE_BUTTON2] = COMBO(mou_btn2_combo, KC_BTN2),
//  [MOUSE_BUTTON3] = COMBO(mou_btn3_combo, KC_BTN3),
//  [MOUSE_BUTTON4] = COMBO(mou_btn4_combo, KC_BTN4),
//  [MOUSE_BUTTON5] = COMBO(mou_btn5_combo, KC_BTN5),
  [MOUSE_DRGTOG]  = COMBO(mou_drg_combo,  TR_DRGS)

//  [KEY_ENT]      = COMBO(key_ent_combo,  KC_ENT),
//  [KEY_TAB]      = COMBO(key_tab_combo,  KC_TAB),
//  [KEY_BSPC]     = COMBO(key_bspc_combo, KC_BSPC)

};