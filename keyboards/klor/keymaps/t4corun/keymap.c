#include "t4corun.h"

#define LAYOUT_klor_wrapper(...) KLOR_LAYOUT(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
LAYOUT_klor_wrapper ( \
	k00, k01, k02,     k03, k04,           k05, k06, k07,    k08, k09, \
	k10, k11, k12,     k13, k14,           k15, k16, k17,    k18, k19, \
	k20, k21, k22,     k23, k24, k32, k37, k25, k26, k27,    k28, k29, \
	          KC_BTN1, k33, k34,           k35, k36, KC_BTN4           \
)

#define KLOR(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY]     = KLOR(LAYER_QWERTY),
  [_COLEMAK_DH] = KLOR(LAYER_COLEMAK_DH),
  [_GAME]       = KLOR(LAYER_GAME),
  [_NAVIGATION] = KLOR(LAYER_NAVIGATION),
  [_NUMBER]     = KLOR(LAYER_NUMBER),
  [_SYMBOL]     = KLOR(LAYER_SYMBOL),
  [_CONFIG]     = KLOR(LAYER_CONFIG)

};


#if defined(ENCODER_MAP_ENABLE)

/* These are horizontal encoders. Found I have to make it opposite the rotary encoders for it to feel intuitive*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

  [_QWERTY]     = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_COLEMAK_DH] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_GAME]       = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_NAVIGATION] = { ENCODER_CCW_CW(ZOOMIN,  ZOOMOUT), ENCODER_CCW_CW(___x___, ___x___)  },
  [_NUMBER]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_SYMBOL]     = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  },
  [_CONFIG]     = { ENCODER_CCW_CW(BASELYR, RBSELYR), ENCODER_CCW_CW(TR_RMOD, TR_RRMD)  }

};

#endif