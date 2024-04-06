#include "encoder.h"


/* may have to swap the hands in this array since we do right side master*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_DEFAULT_LAYER_1 ] = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, //wheel up, wheel down, vol up and down
  [_DEFAULT_LAYER_2 ] = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, //wheel up, wheel down, vol up and down
  [_DEFAULT_LAYER_3 ] = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, //wheel up, wheel down, xx,xx
  [_NAVIGATION]       = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(___x___, ___x___)  }, //wheel up, wheel down, xx,xx
  [_NUMBER]           = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  }, //xx,xx left and right
  [_SYMBOL]           = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  }, //xx,xx xx,xx
  [_FUNCTION]         = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_UP,   KC_DOWN)  }, //xx,xx up and down
  [_MOUSE]            = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(___x___, ___x___)  }, //wheel up, wheel down, ??,??
  [_GAME_NUM]         = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, //wheel up, wheel down, xx,xx
  [_CONFIG]           = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(___x___, ___x___)  }, //maybe rgb functionality?
};