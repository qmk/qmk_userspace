#include "t4corun.h"

#define LAYOUT_crkbd_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
LAYOUT_crkbd_wrapper ( \
	KC_NO, k00, k01, k02,     k03, k04, k05, k06, k07,    k08, k09, KC_NO, \
	KC_NO, k10, k11, k12,     k13, k14, k15, k16, k17,    k18, k19, KC_NO, \
	KC_NO, k20, k21, k22,     k23, k24, k25, k26, k27,    k28, k29, KC_NO, \
	                 TR_BTN1, k33, k34, k35, k36, TR_BTN4                  \
)

#define CRKBD(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT_LAYER_1 ] = CRKBD(LAYER_QWERTY),
  [_DEFAULT_LAYER_2 ] = CRKBD(LAYER_COLEMAK_DH),
  [_DEFAULT_LAYER_3 ] = CRKBD(LAYER_GAME),
  [_NAVIGATION] = CRKBD(LAYER_NAVIGATION),
  [_NUMBER] = CRKBD(LAYER_NUMBER),
  [_SYMBOL] = CRKBD(LAYER_SYMBOL),
  [_FUNCTION] = CRKBD(LAYER_FUNCTION),
  [_MOUSE] = CRKBD(LAYER_MOUSE),
  [_GAME_NUM] = CRKBD(LAYER_GAME_NUM),
  [_CONFIG] = CRKBD(LAYER_CONFIG)

};