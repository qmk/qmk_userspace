#include "tapping.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    default:
      //uprintf("tapping term: %d \n", TAPPING_TERM);
      return TAPPING_TERM;
  }
}