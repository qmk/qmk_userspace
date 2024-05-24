#include tapping.h

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NAV:
      return TAPPING_TERM - 40;

    default:
      return TAPPING_TERM;
  }
}