#include "combo.h"

bool combo_should_trigger (uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  switch (combo_index) {
    case MOUSE_BUTTON2:
      if ( get_highest_layer(layer_state | default_layer_state) > FIRST_DEFAULT_LAYER ) {
        return false;
      }

    case MOUSE_DRGTOG:
      if (( get_highest_layer(layer_state | default_layer_state) != FIRST_DEFAULT_LAYER )
       && ( get_highest_layer(layer_state | default_layer_state) != _MOUSE_FUNC )) {
          return false;
      }

    default:
      return true;
  }
}