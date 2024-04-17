#include "combo.h"


//only need to make it for the qwerty layer
//const uint16_t PROGMEM dragtog_combo[]     = {TR_COMM, TR_DOT,     COMBO_END};
//const uint16_t PROGMEM sniptog_combo[]     = {KC_M,    TR_DOT,     COMBO_END};
//const uint16_t PROGMEM moubtn4_combo[]     = {KC_SPC,  NAV,        COMBO_END};

/*
mouse buttons to map
- mb1 left    1 df 
- mb2 right   3 dg
- mb3 middle
- mb4 back    2 cv
- mb5 forward

bigrams that may work for mouse
- cv
- cb
- xc
- cv
*/


bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {

    case LYR_CONFIG:
    case LYR_FUNCTION:
      return true;

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

    case MOUSE_BUTTON1:
    case MOUSE_BUTTON2:
    case MOUSE_BUTTON4:
    case MOUSE_DRGTOG:

    default:
      return false;
  }
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
  switch (combo_index) {
    /* List combos here that you want to only activate if their keys
    * are pressed in the same order as they are defined in the combo's key
    * array. 
    * 
    * return false means they do not have to be pressed in order
    * 
    * */

    default:
      return true; 
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