// Copyright 2025 Jose Gisbert, aka lejouson <contacto@email.gont.es>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define MASTER_RIGHT

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_BREATHING 2
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #ifndef RGBLIGHT_LIMIT_VAL
    #define RGBLIGHT_LIMIT_VAL 150
  #endif
#endif

#ifdef ENCODER_ENABLE
  #define ENCODER_RESOLUTION 2
#endif

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.