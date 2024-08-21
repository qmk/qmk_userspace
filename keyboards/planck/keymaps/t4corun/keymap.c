#include "t4corun.h"

#define LAYOUT_planck_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#define LAYOUT_3x5_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09,                             \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,                             \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29,                             \
	          k32, k33, k34, k35, k36, k37,                                       \
                      e01, e02                                                  \
)                                                                               \
LAYOUT_planck_wrapper (                                                         \
	k00,   k01,   k02,   k03, k04, KC_NO, KC_NO, k05, k06,   k07,   k08,   k09,   \
	k10,   k11,   k12,   k13, k14, KC_NO, KC_NO, k15, k16,   k17,   k18,   k19,   \
	k20,   k21,   k22,   k23, k24, KC_NO, KC_NO, k25, k26,   k27,   k28,   k29,   \
	KC_NO, KC_NO, KC_NO, k32, k33, k34,   k35,   k36, k37,   KC_NO, KC_NO, KC_ESC \
)

#define PLANCK(...) LAYOUT_3x5_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]     = PLANCK(LAYER_QWERTY),
  [_COLEMAK_DH] = PLANCK(LAYER_COLEMAK_DH),
  [_GAME]       = PLANCK(LAYER_GAME),
  [_NAVIGATION] = PLANCK(LAYER_NAVIGATION),
  [_NUMBER]     = PLANCK(LAYER_NUMBER),
  [_SYMBOL]     = PLANCK(LAYER_SYMBOL),
  [_MOUSE_FUNC] = PLANCK(LAYER_MOUSE_FUNC)
};