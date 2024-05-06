#include "combo.h"

bool get_combo_must_tap(uint16_t index, combo_t *combo) {

  switch (index) {

#if defined(MOUSEKEY_ENABLE)
    case MOUSE_BUTTON3:
    case MOUSE_BUTTON4:
    case MOUSE_BUTTON5:
    case MOUSE_DRGTOG:
      return true;
#endif //MOUSEKEY_ENABLEdf

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

    case MOUSE_BUTTON1:
    case MOUSE_BUTTON2:
    case MOUSE_BUTTON3:
    case MOUSE_BUTTON4:
    case MOUSE_BUTTON5:
    case MOUSE_DRGTOG:
      if (  get_highest_layer(layer_state) > _DEFAULT_LAYER_1 ) {
        return false;
      }
      break;

  }

  return true;
}