#include "ncsibra.h"

#define LAYOUT_wrapper(...)            LAYOUT_ortho_5x12(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_wrapper(COLEMAK_LAYER),

[_QWERTY] = LAYOUT_wrapper(QWERTY_LAYER),

[_LOWER] = LAYOUT_wrapper(LOWER_LAYER),

[_RAISE] = LAYOUT_wrapper(RAISE_LAYER),

[_NUM] = LAYOUT_wrapper(NUM_LAYER),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void matrix_scan_keymap(void) {}
