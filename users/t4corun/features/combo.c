#include "combo.h"

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

#if defined(MOUSEKEY_ENABLE)
    case MOUSE_BUTTON3:
    case MOUSE_BUTTON4:
    case MOUSE_BUTTON5:
    case MOUSE_DRGTOG:
#endif //MOUSEKEY_ENABLE

    case KEY_TAB:
    case KEY_BWRD:
      return true;

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
    * */

#if defined(MOUSEKEY_ENABLE2222)
    case MOUSE_BUTTON1:
    case MOUSE_BUTTON2:
    case MOUSE_BUTTON4:
      return true;
#endif //MOUSEKEY_ENABLE

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