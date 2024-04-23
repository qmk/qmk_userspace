// Copyright 2024 Jose Gisbert, aka lejouson <email@gont.es>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define MASTER_RIGHT
#define ONESHOT_TAP_TOGGLE 2
#define TAPPING_TOGGLE 1

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_BREATHING 2
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

#ifdef ENCODER_ENABLE
  #define ENCODER_RESOLUTION 2
#endif
