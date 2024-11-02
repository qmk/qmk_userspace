#include "ncsibra.h"

#define LAYOUT_wrapper(...)            LAYOUT_preonic_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_wrapper(COLEMAK_LAYER),

[_QWERTY] = LAYOUT_wrapper(QWERTY_LAYER),

[_LOWER] = LAYOUT_wrapper(LOWER_LAYER),

[_RAISE] = LAYOUT_wrapper(RAISE_LAYER),

[_NUM] = LAYOUT_wrapper(NUM_LAYER),

[_WOW] = LAYOUT_wrapper(WOW_LAYER),

[_MOD] = LAYOUT_wrapper(MOD_LAYER),
};
