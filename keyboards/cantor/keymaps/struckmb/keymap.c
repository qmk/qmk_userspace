// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "struckmb.h"
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //
    [LAYER_QWERTY] =                                           //
    LAYOUT_split_3x6_3_wrapper(_QWERTY_3x6_, _THUMBS_3_3_),
    [LAYER_SYMBOL]  = LAYOUT_split_3x6_3_wrapper(_SYMBOLS_3x6_, _SL4_3_, _SR4_3_),
    [LAYER_LOWER]   = LAYOUT_split_3x6_3_wrapper(_LOWER_3x6_, _LL4_3_, _LR4_3_),
    [LAYER_RAISE]   = LAYOUT_split_3x6_3_wrapper(_RAISE_3x6_, _RL4_3_, _RR4_3_),
    [LAYER_POINTER] = LAYOUT_split_3x6_3_wrapper(_POINTER_3x6_, _PL4_3_, _PR4_3_),
    [LAYER_ATTIC]   = LAYOUT_split_3x6_3_wrapper(_ATTIC_3x6_, _AL4_3_, _AR4_3_)};
