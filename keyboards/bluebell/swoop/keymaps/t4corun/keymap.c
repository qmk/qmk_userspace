#include "t4corun.h"

#define LAYOUT_swoop_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
) \
LAYOUT_swoop_wrapper ( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37            \
)

#define SWOOP(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT_LAYER_1] = SWOOP(LAYER_QWERTY),
  [_DEFAULT_LAYER_2] = SWOOP(LAYER_COLEMAK_DH),
  [_DEFAULT_LAYER_3] = SWOOP(LAYER_GAME),
  [_NAVIGATION]      = SWOOP(LAYER_NAVIGATION),
  [_NUMBER]          = SWOOP(LAYER_NUMBER),
  [_SYMBOL]          = SWOOP(LAYER_SYMBOL),
  //[_FUNCTION]        = SWOOP(LAYER_FUNCTION),
  [_CONFIG]          = SWOOP(LAYER_CONFIG)

};


#if defined(ENCODER_MAP_ENABLE)

/* The encoder presses are handled in the keymap */

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_DEFAULT_LAYER_1] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_DEFAULT_LAYER_2] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_DEFAULT_LAYER_3] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
  [_NAVIGATION]      = { ENCODER_CCW_CW(ZOOMIN,  ZOOMOUT), ENCODER_CCW_CW(___x___, ___x___)  },
  [_NUMBER]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
  [_SYMBOL]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  },
  //[_FUNCTION]        = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_DOWN, KC_UP  )  },
  [_CONFIG]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  },
};

#endif