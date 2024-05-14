#pragma once

// Most configuration will be found in info.json

// ┌─────────────────────────────────────────────────┐
// │ o l e d s                                       │
// └─────────────────────────────────────────────────┘

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H  "./lib/glcdfont.c"
#endif

// ┌─────────────────────────────────────────────────┐
// │ a u d i o                                       │
// └─────────────────────────────────────────────────┘ 

#define AUDIO_DAC_SAMPLE_MAX 4095U
#define AUDIO_VOICE_DEFAULT butts_fader

#ifdef AUDIO_ENABLE     
#    define KLOR_SOUND W__NOTE(_DS0), W__NOTE(_DS1), H__NOTE(_DS2), H__NOTE(_DS3), Q__NOTE(_DS4), Q__NOTE(_DS5), E__NOTE(_DS6), E__NOTE(_DS7), S__NOTE(_DS8), Q__NOTE(_GS0)
#    define STARTUP_SONG SONG(KLOR_SOUND)
#    define BYE_SOUND H__NOTE(_DS4), H__NOTE(_DS3), W__NOTE(_DS1)
#    define GOODBYE_SONG SONG(BYE_SOUND)
#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif 

// ┌─────────────────────────────────────────────────┐
// │ h a p t i c   f e e d b a c k                   │
// └─────────────────────────────────────────────────┘ 

#ifdef HAPTIC_ENABLE
#    define FB_ERM_LRA 1
#    define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 
#    define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3 
#    define RATED_VOLTAGE 2
#    define V_PEAK 2.8
#    define V_RMS 2.0 
#    define F_LRA 150 // resonance freq 
#    define DRV_GREETING       alert_750ms
#endif

// ┌─────────────────────────────────────────────────┐
// │ t r a c k b a l l                               │
// └─────────────────────────────────────────────────┘ 

#ifdef POINTING_DEVICE_ENABLE
#    define PAW3204_SCLK_PIN D0
#    define PAW3204_SDIO_PIN D1
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define AUTO_MOUSE_DELAY 300
#endif