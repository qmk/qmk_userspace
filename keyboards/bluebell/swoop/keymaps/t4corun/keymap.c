/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "t4corun.h"

#define LAYOUT_swoop_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, k37,           \
                      e01, e02                      \
)                                                   \
LAYOUT_swoop_wrapper (                              \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
	          k32, k33, k34, k35, k36, e02            \
)

#define SWOOP(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY]     = SWOOP(LAYER_QWERTY),
  [_COLEMAK_DH] = SWOOP(LAYER_COLEMAK_DH),
  [_GAME]       = SWOOP(LAYER_GAME),
  [_NAVIGATION] = SWOOP(LAYER_NAVIGATION),
  [_NUMBER]     = SWOOP(LAYER_NUMBER),
  [_SYMBOL]     = SWOOP(LAYER_SYMBOL),
  [_MOUSE_FUNC] = SWOOP(LAYER_MOUSE_FUNC),
  [_CONFIG]     = SWOOP(LAYER_CONFIG)

};


#if defined(ENCODER_MAP_ENABLE)

/* The encoder presses are handled in the keymap */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

  [_QWERTY]     = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_COLEMAK_DH] = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_GAME]       = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_NAVIGATION] = { ENCODER_CCW_CW(KC_LEFT,  KC_RGHT), ENCODER_CCW_CW(___x___, ___x___) },
  [_NUMBER]     = { ENCODER_CCW_CW(___x___,  ___x___), ENCODER_CCW_CW(REV_TAB, FWD_TAB) },
  [_SYMBOL]     = { ENCODER_CCW_CW(___x___,  ___x___), ENCODER_CCW_CW(___x___, ___x___) },
  [_MOUSE_FUNC] = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D), ENCODER_CCW_CW(ZOOMOUT, ZOOMIN)  },
  [_CONFIG]     = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RBSELYR, BASELYR) }

};

#endif //ENCODER_MAP_ENABLE


#if defined(RGB_MATRIX_ENABLE)

/*
 * Center: 112
 * 0   20  41  61  81  102 122 143 163 183 204 224
 *                                                   Center: 32
 * 16  11  10  04  03          21  22  28  29  34    0
 * 15  12  09  05  02          20  23  27  30  33    21
 * 14  13  08  06  01          19  24  26  31  32    43
 *             17  07  00  18  25  35                64
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
    {34,     29,     28,     22,     21},
    {33,     30,     27,     23,     20},
    {32,     31,     26,     24,     19},
    {NO_LED, NO_LED, 35,     25,     18}
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
    {0,43},    {0,21},    {0,0},    //14 outer column
    {81,85},                        //17 outer thumb
    // Right 1-18
    {122,64},                       //18 inner thumb
    {143,43},  {143,21},  {143,0},  //19 inner column
    {163,0} ,  {163,21},  {163,43}, //22
    {143,64},                       //25 middle thumb
    {183,43},  {183,21},  {183,0},  //26
    {204,0},   {204,21},  {204,43}, //29
    {224,43},  {224,21},  {224,0},  //32 outer column
    {163,64}                        //35 outer thumb
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