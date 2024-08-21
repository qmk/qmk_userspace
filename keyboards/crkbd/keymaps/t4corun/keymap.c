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

#define LAYOUT_crkbd_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

#define LAYOUT_3x5_3_keymap( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09,               \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,               \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29,               \
	          k32, k33, k34, k35, k36, k37,                         \
                      e01, e02                                    \
)                                                                 \
LAYOUT_crkbd_wrapper (                                            \
	KC_NO, k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, KC_NO, \
	KC_NO, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, KC_NO, \
	KC_NO, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, KC_NO, \
	                 k32, k33, k34, k35, k36, k37                   \
)

#define CRKBD(...) LAYOUT_3x5_3_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY]     = CRKBD(LAYER_QWERTY),
  [_COLEMAK_DH] = CRKBD(LAYER_COLEMAK_DH),
  [_GAME]       = CRKBD(LAYER_GAME),
  [_NAVIGATION] = CRKBD(LAYER_NAVIGATION),
  [_NUMBER]     = CRKBD(LAYER_NUMBER),
  [_SYMBOL]     = CRKBD(LAYER_SYMBOL),
  [_MOUSE]      = CRKBD(LAYER_MOUSE),
  [_FUNCTION]   = CRKBD(LAYER_FUNCTION),
  [_CONFIG]     = CRKBD(LAYER_CONFIG)
};
