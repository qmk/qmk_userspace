#include "tapping.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case NAV_0:
      return TAPPING_TERM + 60;

    default:
      return TAPPING_TERM;

  }

}