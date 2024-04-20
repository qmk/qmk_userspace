#include "combo.h"

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

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  
  switch (index) {

#if defined(MOUSEKEY_ENABLE)
    case MOUSE_BUTTON3:
    case MOUSE_BUTTON4:
    case MOUSE_BUTTON5:
    case MOUSE_DRGTOG:
#endif //MOUSEKEY_ENABLE

    case KEY_ESC:
    case KEY_ENT:
    case KEY_TAB:
      return true;

    default:
      return false;
  }
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {

    case LYR_CONFIG:
    case LYR_FUNCTION:
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

    default:
      return false;
  }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {

  // disable all combos on config layer
  if ( get_highest_layer(layer_state) == _CONFIG ) {
    return false;
  }

  switch (combo_index) {

    case KEY_ESC:
    case KEY_ENT:
    case KEY_TAB:
      if (  get_highest_layer(layer_state) == _NAVIGATION ||
            get_highest_layer(layer_state) == _SYMBOL ) {
        return false;
      }
      break;

    case MOUSE_BUTTON1:
    case MOUSE_BUTTON2:
    case MOUSE_BUTTON3:
    case MOUSE_BUTTON4:
    case MOUSE_BUTTON5:
    case MOUSE_DRGTOG:
      if (  get_highest_layer(layer_state) == _NAVIGATION || 
            get_highest_layer(layer_state) == _NUMBER || 
            get_highest_layer(layer_state) == _SYMBOL ) {
        return false;
      }
      break;
  }

  return true;
}