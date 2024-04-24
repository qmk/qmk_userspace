#include "t4corun.h"

#define LAYOUT_rollow_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
LAYOUT_rollow_wrapper ( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
)

#define ROLLOW(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT_LAYER_1] = ROLLOW(LAYER_QWERTY),
  [_DEFAULT_LAYER_2] = ROLLOW(LAYER_COLEMAK_DH),
  [_DEFAULT_LAYER_3] = ROLLOW(LAYER_GAME),
  [_NAVIGATION]      = ROLLOW(LAYER_NAVIGATION),
  [_NUMBER]          = ROLLOW(LAYER_NUMBER),
  [_SYMBOL]          = ROLLOW(LAYER_SYMBOL),
  [_CONFIG]          = ROLLOW(LAYER_CONFIG)

};


#if defined(ENCODER_MAP_ENABLE)

/* These are horizontal encoders. Found I have to make it opposite the rotary encoders for it to feel intuitive*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_DEFAULT_LAYER_1] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_DEFAULT_LAYER_2] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_DEFAULT_LAYER_3] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_NAVIGATION]      = { ENCODER_CCW_CW(ZOOMIN,  ZOOMOUT), ENCODER_CCW_CW(___x___, ___x___)  },
  [_NUMBER]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_SYMBOL]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  },
  [_CONFIG]          = { ENCODER_CCW_CW(BASELYR, RBSELYR), ENCODER_CCW_CW(TR_RMOD, TR_RRMD)  }
};

#endif