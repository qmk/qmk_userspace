#include "t4corun.h"

#define LAYOUT_cnano_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
LAYOUT_cnano_wrapper ( \
	k00, k01, k02,     k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12,     k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22,     k23, k24, k25, k26, k27, k28, k29, \
	          TR_BTN1, k33, k34, k35, k36                 \
)

#define CNANO(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT_LAYER_1] = CNANO(LAYER_QWERTY),
  [_DEFAULT_LAYER_2] = CNANO(LAYER_COLEMAK_DH),
  [_DEFAULT_LAYER_3] = CNANO(LAYER_GAME),
  [_NAVIGATION]      = CNANO(LAYER_NAVIGATION),
  [_NUMBER]          = CNANO(LAYER_NUMBER),
  [_SYMBOL]          = CNANO(LAYER_SYMBOL),
  [_CONFIG]          = CNANO(LAYER_CONFIG)

};