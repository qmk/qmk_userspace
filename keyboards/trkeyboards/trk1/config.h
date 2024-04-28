/*
Copyright 2022 Tvrd Rad Keyboards

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

#pragma once

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* Key matrix pins */
#define MATRIX_ROW_PINS { F5, F4, F1, F0, B7 }
#define MATRIX_COL_PINS { B3, B2, D2, D3, C6, C7, D5, F6, F7, B6, B5, B4, D7, D6, D4 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* EEPROM Driver Configuration */
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

/* Encoder Configuration */
#define ENCODERS_PAD_A { B0 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

#define OLED_TIMEOUT 0
