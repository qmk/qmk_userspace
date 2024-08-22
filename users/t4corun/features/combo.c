#include "combo.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  // or with combo index, i.e. its name from enum.
  switch (index) {
    case LYR_FUNCTION:
      return COMBO_TERM + 100;

    default:
      return COMBO_TERM;
  }
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    case LYR_FUNCTION:
      return true;

    default:
      return false;
  }
}

bool combo_should_trigger (uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  switch (combo_index) {
    case MOUSE_BUTTON2:
      if ( get_highest_layer(layer_state | default_layer_state) > FIRST_DEFAULT_LAYER ) {
        return false;
      }

    case MOUSE_DRGTOG:
      if (( get_highest_layer(layer_state | default_layer_state) != FIRST_DEFAULT_LAYER )
       && ( get_highest_layer(layer_state | default_layer_state) != _MOUSE )) {
          return false;
      }

    case LYR_FUNCTION:
      if ( get_highest_layer(layer_state | default_layer_state) > FIRST_DEFAULT_LAYER ) {
        return false;
      }

    default:
      return true;
  }
}
