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
  [_CONFIG]          = SWOOP(LAYER_CONFIG)

};


#if defined(ENCODER_MAP_ENABLE)

/* The encoder presses are handled in the keymap */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_DEFAULT_LAYER_1] = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_DEFAULT_LAYER_2] = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_DEFAULT_LAYER_3] = { ENCODER_CCW_CW(TR_MWHU, TR_MWHD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_NAVIGATION]      = { ENCODER_CCW_CW(ZOOMOUT, ZOOMIN),  ENCODER_CCW_CW(___x___, ___x___)  },
  [_NUMBER]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
  [_SYMBOL]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(___x___, ___x___)  },
  [_CONFIG]          = { ENCODER_CCW_CW(___x___, ___x___), ENCODER_CCW_CW(LSFT(TR_RMOD), TR_RMOD) },
};

#endif //ENCODER_MAP_ENABLE


#if defined(RGB_MATRIX_ENABLE)

/*
 * Center: 133 
 * 20  41  61  81  102 122 143 163 183 204 224 244
 *                                                   Center: 54
 * 16  11  10  04  03          21  22  28  29  34    21
 * 15  12  09  05  02          20  23  27  30  33    43
 * 14  13  08  06  01          19  24  26  31  32    64
 *             17  07  00  18  25  35                85
 */

/*
led_config_t g_led_config = { 
  {
    // Key matrix to LED index
    // I still don't understand but make it match the split layout?
    // Left 1-18
    {16,     11,     10,     4,      3},
    {15,     12,      9,     5,      2},
    {14,     13,      8,     6,      1},
    {NO_LED, NO_LED, 17,     7,      0},
    // Right 1-18
    {21,     22,     28,     29,     34},
    {20,     23,     27,     30,     33},
    {19,     24,     26,     31,     32},
    {18,     25,     35,     NO_LED, NO_LED}
  }
  , {
    // LED index to physical position
    // Start from 0 and go to the end
    // Left 1-18
    {122,85},  {102,64},  {102,43},  {102,21},  {81,21},   {81,43},
    {81,64},   {102,85},  {61,64},   {61,43},   {61,21},   {41,21},
    {41,43},   {41,64},   {20,64},   {20,43},   {20,21},   {81,85},
    // Right 1-18
    {143,85},  {163,64},  {163,43},  {163,21},  {183,21},  {183,43},
    {183,64},  {163,85},  {204,64},  {204,43},  {204,21},  {224,21},
    {224,43},  {224,64},  {244,64},  {244,43},  {244,21},  {183,85}
  } 
  , {
    // LED index to flag
    // Start from 0 and go to the end
    // Left 1-18
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, 
    // Right 1-18
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
  }
};
*/

led_config_t g_led_config = { 
  {
    // Key matrix to LED index
    // I still don't understand but make it match the split layout?
    // Left 1-18
    {16,     11,     10,     4,      3},
    {15,     12,      9,     5,      2},
    {14,     13,      8,     6,      1},
    {NO_LED, NO_LED, 17,     7,      0},
    // Right 1-18
    {21,     22,     28,     29,     34},
    {20,     23,     27,     30,     33},
    {19,     24,     26,     31,     32},
    {18,     25,     35,     NO_LED, NO_LED}
  }
  , {
    // LED index to physical position
    // Start from 0 and go to the end
    // Left 1-18
    {102,64},                       //0 inner thumb key
    {81,43},   {81,21},   {81,0},   //1: inner column
    {61,0},    {61,21},   {61,43},  //4
    {81,64},                        //7 middle thumb
    {41,43},   {41,21},   {41,0},   //8
    {20,0},    {20,21},   {20,13},  //11
    {0,43},    {0,21},    {0,0},    //14
    {81,85},                        //17
    // Right 1-18
    {122,64},                       //18
    {143,43},  {143,21},  {143,0},  //19
    {163,0} ,  {163,21},  {163,43}, //22
    {143,64},                       //25
    {183,43},  {183,21},  {183,28}, //26
    {204,0},   {204,21},  {204,43}, //29
    {224,43},  {224,21},  {224,0},  //32
    {163,64}                        //35
  } 
  , {
    // LED index to flag
    // Start from 0 and go to the end
    // Left 1-18
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, 
    // Right 1-18
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
  }
};

#endif //RGB_MATRIX_ENABLE