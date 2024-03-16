#pragma once

#include QMK_KEYBOARD_H

#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
    #include "vnz_unicode.h"
#endif

#define ALTENT A(KC_ENT)

// Standard copy and paste
#define ST_COPY C(KC_C)
#define ST_PSTE C(KC_V)

// Linux copy and paste
#define LX_COPY S(C(KC_C))
#define LX_PSTE S(C(KC_V))

// Linux switch between applications
#define LX_APPS A(KC_ESC)
#define LX_NAPP S(A(KC_ESC))

// Linux switch between virtual desktop
#define LX_VDUP C(A(KC_UP))
#define LX_VDDW C(A(KC_DOWN))

// Switch between tabs
#define ST_TBLT C(KC_PGUP)
#define ST_TBRT C(KC_PGDN)
