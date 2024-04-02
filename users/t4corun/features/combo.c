#include "combo.h"


//only need to make it for the qwerty layer
//const uint16_t PROGMEM dragtog_combo[]     = {TR_COMM, TR_DOT,     COMBO_END};
//const uint16_t PROGMEM sniptog_combo[]     = {KC_M,    TR_DOT,     COMBO_END};
//const uint16_t PROGMEM moubtn4_combo[]     = {KC_SPC,  NAV,        COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {

/*
#if defined(POINTING_DEVICE_ENABLE)
  [DRAGTOGGLE]      = COMBO(dragtog_combo, DRG_TOG),
  [SNIPERTOGGLE]    = COMBO(sniptog_combo, SNP_TOG),
#else
  [DRAGTOGGLE]      = COMBO(dragtog_combo, ___x___),
  [SNIPERTOGGLE]    = COMBO(sniptog_combo, ___x___),  
#endif //POINTING_DEVICE_ENABLE

#if defined(MOUSELAYER_ENABLE)
  [MOUSEBUTTON4]    = COMBO(moubtn4_combo, KC_BTN4)
#else
  [MOUSEBUTTON4]    = COMBO(moubtn4_combo, ___x___)
#endif //MOUSELAYER_ENABLE
*/
};


bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    default:
      return false;
  }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  
  switch (index) {

    /* 
    case DRAGTOGGLE:
    case SNIPERTOGGLE:
    case MOUSEBUTTON4:
      return true;
    */

    default:
      return false;
  }
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
  switch (combo_index) {
    /* List combos here that you want to only activate if their keys
    * are pressed in the same order as they are defined in the combo's key
    * array. */

    default:
      return false;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  // or with combo index, i.e. its name from enum.
  switch (index) {
    /*
    case CONFIGLAYER:
      return COMBO_HOLD_TERM + 150;
    */
   
    default:
      return COMBO_TERM;

  }   
}