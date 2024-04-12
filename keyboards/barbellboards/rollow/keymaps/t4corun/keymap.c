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
	          k32, k33, k34, k35, k36, K37            \
)

#define ROLLOW(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT_LAYER_1 ] = ROLLOW(LAYER_QWERTY),
  [_DEFAULT_LAYER_2 ] = ROLLOW(LAYER_COLEMAK_DH),
  [_DEFAULT_LAYER_3 ] = ROLLOW(LAYER_GAME),
  [_NAVIGATION]       = ROLLOW(LAYER_NAVIGATION),
  [_NUMBER]           = ROLLOW(LAYER_NUMBER),
  [_SYMBOL]           = ROLLOW(LAYER_SYMBOL),
  [_FUNCTION]         = ROLLOW(LAYER_FUNCTION),
  [_MOUSE]            = ROLLOW(LAYER_MOUSE),
  [_GAME_NUM]         = ROLLOW(LAYER_GAME_NUM),
  [_CONFIG]           = ROLLOW(LAYER_CONFIG)

};


#if defined(ENCODER_MAP_ENABLE)

/* may have to swap the hands in this array since we do right side master*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_DEFAULT_LAYER_1] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, //wheel up, wheel down, vol up and down
  [_DEFAULT_LAYER_2] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, //wheel up, wheel down, vol up and down
  [_DEFAULT_LAYER_3] = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, //wheel up, wheel down, xx,xx
  [_NAVIGATION]      = { ENCODER_CCW_CW(ZOOMIN,  ZOOMOUT), ENCODER_CCW_CW(___x___, ___x___)  }, //wheel up, wheel down, xx,xx
  [_NUMBER]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  }, //xx,xx left and right
  [_SYMBOL]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  }, //xx,xx xx,xx
  [_FUNCTION]        = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_DOWN, KC_UP  )  }, //xx,xx up and down
  [_MOUSE]           = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(___x___, ___x___)  }, //wheel up, wheel down, ??,??
  [_GAME_NUM]        = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }, //wheel up, wheel down, xx,xx
  [_CONFIG]          = { ENCODER_CCW_CW(TR_MWHD, TR_MWHU), ENCODER_CCW_CW(___x___, ___x___)  }, //maybe rgb functionality?
};
#endif