#pragma once

// Many settings are taken from https://github.com/getreuer/qmk-keymap/

#define TAPPING_TOGGLE 2
#define SELECT_WORD_TIMEOUT 2000  // When idle, clear state after 2 seconds.

// Slow down the rate at which macros are sent
#define TAP_CODE_DELAY 5

//
// Tap/hold configuration for home row mods
//
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

// Enable streak detection for Achorion
#define ACHORDION_STREAK

//
// RGB
//

// Turn RGB off when PC goes on sleep
#define RGBLIGHT_SLEEP

// the modes we do use for lights
#define RGBLIGHT_EFFECT_BREATHING
