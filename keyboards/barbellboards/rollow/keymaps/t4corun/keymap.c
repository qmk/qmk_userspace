#include "t4corun.h"

#define LAYOUT_rollow_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37,           \
                      e01, e02                      \
)                                                   \
LAYOUT_rollow_wrapper (                             \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          e01, k33, k34, k35, k36, e02            \
)

#define ROLLOW(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]     = ROLLOW(LAYER_QWERTY),
  [_COLEMAK_DH] = ROLLOW(LAYER_COLEMAK_DH),
  [_GAME]       = ROLLOW(LAYER_GAME),
  [_NAVIGATION] = ROLLOW(LAYER_NAVIGATION),
  [_NUMBER]     = ROLLOW(LAYER_NUMBER),
  [_SYMBOL]     = ROLLOW(LAYER_SYMBOL),
  [_MOUSE]      = ROLLOW(LAYER_MOUSE),
  [_FUNCTION]   = ROLLOW(LAYER_FUNCTION),
  [_CONFIG]     = ROLLOW(LAYER_CONFIG)
};


#if defined(ENCODER_MAP_ENABLE)

/* These are horizontal encoders. Found I have to make it opposite the rotary encoders for it to feel intuitive*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY]     = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
  [_COLEMAK_DH] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
  [_GAME]       = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
  [_NAVIGATION] = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT), ENCODER_CCW_CW(___x___, ___x___) },
  [_NUMBER]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(FWD_TAB, REV_TAB) },
  [_SYMBOL]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___) },
  [_MOUSE]      = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(ZOOMIN,  ZOOMOUT) },
  [_FUNCTION]   = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___) },
  [_CONFIG]     = { ENCODER_CCW_CW(FWD_CFG, REV_CFG), ENCODER_CCW_CW(FWD_CFG, REV_CFG) }
};

#endif
