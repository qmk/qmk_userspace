/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

// Because of the shift and space key being shared, this stops a space being registered when I do a space, then quickly shift a key.
// It also means that I cannot double tap and hold to send lots of space characters.
#define QUICK_TAP_TERM 100 // This can also be set on a per key basis
#define TAPPING_TERM 200
// #define CHORDAL_HOLD
// #define PERMISSIVE_HOLD // This can generate more accidental mod triggers.
// Experimental stuff here:
// This sends the modifier key code, until the mod-tap behaviour is settled. Helps with shift click etc
// #define SPECULATIVE_HOLD
// Suppresses the hold tap modifiers if pressed within FLOW_TAP_TERM
// #define FLOW_TAP_TERM 150

// Get words per min on both keyboards so my little screens know how to animate.
#define SPLIT_WPM_ENABLE

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif


#define SPLIT_HAND_PIN B6 // The promicro (ATmega) pin definition. On the rp2040 its GP21.
#define	SPLIT_HAND_PIN_LOW_IS_LEFT

#define COMBO_ONLY_FROM_LAYER 0 // Layer independant combos. Allows the combos to work on all layers. This also means layer dependant combos will not work.
