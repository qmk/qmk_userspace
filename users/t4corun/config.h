/*
* Set build options for
* - consistent configuration across all keyboards
* - enable features specific to certain board (e.g. encoders, rgb, oled)
* - a way to save memory on MCU
*
* Pattern
* - This will hold config for features we force to be on
* - bring in additional configuration for features that can be enabled/disabled
*/

#pragma once

//Turn off settings we won't use to save memory
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

//Set common configuration for all keyboards
#define USB_POLLING_INTERVAL_MS 1



/* Tapping, Oneshot
*  https://docs.qmk.fm/tap_hold
*  https://docs.qmk.fm/one_shot_keys
*/
#undef TAP_CODE_DELAY
#undef TAPPING_TERM
#undef QUICK_TAP_TERM

#undef ONESHOT_TAP_TOGGLE
#undef ONESHOT_TIMEOUT


#define TAP_CODE_DELAY 5
#define TAPPING_TERM 175
#define QUICK_TAP_TERM 120

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2000



/* Caps Word
*  https://docs.qmk.fm/features/caps_word
*
*  Explore these
*  #undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
*  #undef CAPS_WORD_INVERT_ON_SHIFT
*/
#if defined(CAPS_WORD_ENABLE)
#  undef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  undef CAPS_WORD_IDLE_TIMEOUT

#  define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#  define CAPS_WORD_IDLE_TIMEOUT 2000
#endif //CAPS_WORD_ENABLE



/* Combos
*  https://docs.qmk.fm/features/combo
*/
#if defined(COMBO_ENABLE)
#  undef COMBO_ONLY_FROM_LAYER
#  undef EXTRA_SHORT_COMBOS
#  undef COMBO_TERM
#  undef COMBO_TERM_PER_COMBO
#  undef COMBO_MUST_HOLD_PER_COMBO
#  undef COMBO_SHOULD_TRIGGER

#  define COMBO_ONLY_FROM_LAYER 0 //this will always setup combos based off of QWERTY layout
#  define EXTRA_SHORT_COMBOS
#  define COMBO_TERM 35
#  define COMBO_TERM_PER_COMBO
#  define COMBO_MUST_HOLD_PER_COMBO
#  define COMBO_SHOULD_TRIGGER
#endif //COMBO_ENABLE



/* Split keyboard
*  https://docs.qmk.fm/features/split_keyboard
*/
#if defined(SPLIT_KEYBOARD)
#  undef SPLIT_TRANSPORT_MIRROR
#  undef SPLIT_LAYER_STATE_ENABLE
#  undef SPLIT_LED_STATE_ENABLE
#  undef SPLIT_MODS_ENABLE
#  undef SPLIT_OLED_ENABLE
#  undef SPLIT_ACTIVITY_ENABLE
#  undef SPLIT_WPM_ENABLE
#  undef MASTER_RIGHT

#  define SPLIT_TRANSPORT_MIRROR
#  define SPLIT_LAYER_STATE_ENABLE
#  define SPLIT_LED_STATE_ENABLE
#  define SPLIT_MODS_ENABLE
#  define SPLIT_OLED_ENABLE
#  define SPLIT_ACTIVITY_ENABLE
#  define SPLIT_WPM_ENABLE
#  define MASTER_RIGHT
#endif //SPLIT_KEYBOARD



/* OLED
*  https://docs.qmk.fm/features/oled_driver
*/
#if defined(OLED_ENABLE)
#  undef OLED_TIMEOUT
#  undef OLED_FONT_H

#  define OLED_TIMEOUT 60000 //1 min
#  define OLED_FONT_H "./lib/font.c"
#endif //OLED_ENABLE



/* Haptic Feedback
*  https://docs.qmk.fm/features/haptic_feedback
*/
#if defined(HAPTIC_ENABLE)
#  if defined(HAPTIC_DRV2605L)
#    undef DRV2605L_GREETING
#    undef DRV2605L_DEFAULT_MODE

#    define DRV2605L_GREETING DRV2605L_EFFECT_750_MS_ALERT_100
#    define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_STRONG_CLICK_1_100
#  endif //HAPTIC_DRV2605L
#endif //HAPTIC_ENABLE



/* Audio
*  https://docs.qmk.fm/features/audio
*  https://docs.qmk.fm/squeezing_avr#audio-settings
*/
#if defined(AUDIO_ENABLE)
#  undef KLOR_SOUND
#  undef BYE_SOUND
#  undef NO_MUSIC_MODE
#  undef AUDIO_CLICKY
#  undef STARTUP_SONG
#  undef GOODBYE_SONG
#  undef DEFAULT_LAYER_SONGS

#  define KLOR_SOUND W__NOTE(_DS0), W__NOTE(_DS1), H__NOTE(_DS2), H__NOTE(_DS3), Q__NOTE(_DS4), Q__NOTE(_DS5), E__NOTE(_DS6), E__NOTE(_DS7), S__NOTE(_DS8), Q__NOTE(_GS0)
#  define BYE_SOUND H__NOTE(_DS4), H__NOTE(_DS3), W__NOTE(_DS1)
#  define NO_MUSIC_MODE
#  define AUDIO_CLICKY
#  define STARTUP_SONG SONG(KLOR_SOUND)
#  define GOODBYE_SONG SONG(BYE_SOUND)
#  define DEFAULT_LAYER_SONGS \
    { SONG(QWERTY_SOUND)      \
      ,SONG(COLEMAK_SOUND)    \
      ,SONG(GUITAR_SOUND)     \
    }
#endif //AUDIO_ENABLE



/* RGB Matrix
*  https://docs.qmk.fm/features/rgb_matrix
*/
#if defined(RGB_MATRIX_ENABLE)
#  undef RGB_MATRIX_SLEEP
#  undef RGB_MATRIX_TIMEOUT

#  undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#  undef RGB_MATRIX_DEFAULT_HUE
#  undef RGB_MATRIX_DEFAULT_SAT
#  undef RGB_MATRIX_DEFAULT_VAL
#  undef RGB_MATRIX_DEFAULT_SPD

#  undef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#  undef RGB_MATRIX_TYPING_HEATMAP_SPREAD
#  undef RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT
#  undef RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP


#  define RGB_MATRIX_SLEEP
#  define RGB_MATRIX_TIMEOUT 60000 //1 min

#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#  define RGB_MATRIX_DEFAULT_HUE 4
#  define RGB_MATRIX_DEFAULT_SAT 79
#  define RGB_MATRIX_DEFAULT_VAL 59
#  define RGB_MATRIX_DEFAULT_SPD 32

#  if defined(KEYBOARD_bastardkb_charybdis_3x5) \
   || defined(KEYBOARD_dztech_dz60rgb_v2_1)    \
   || defined(KEYBOARD_bluebell_swoop)         \
   || defined(KEYBOARD_klor_2040)

#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

   //enable minimal effects to save memory
#  else
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#  endif //KEYBOARD_bastardkb_charybdis_3x5...

   //heatmap specific settings
#  if defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
#    define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 9     //default 25
#    define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40               //40
#    define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16           //16
#    define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 20        //32
#  endif //ENABLE_RGB_MATRIX_TYPING_HEATMAP
#endif //RGB_MATRIX_ENABLE
