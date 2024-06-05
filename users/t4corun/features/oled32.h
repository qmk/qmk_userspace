#pragma once

#include "t4corun.h"

#define OLED_RENDER_KEYLOCK_NAME      "Lock"
#define OLED_RENDER_MODS_NAME         "Mods"
#define OLED_RENDER_FEATURE_NAME      "Feat"
#define OLED_RENDER_WPM_NAME          "Wpm"

#define OLED_RENDER_LAYOUT_QWERTY     "QWRTY"
#define OLED_RENDER_LAYOUT_COLEMAK_DH "CLMAK"
#define OLED_RENDER_LAYOUT_GAME       "GAME"

#define OLED_RENDER_LAYER_BASE        " Def"
#define OLED_RENDER_LAYER_NAVIGATION  " Nav"
#define OLED_RENDER_LAYER_NUMBER      " Num"
#define OLED_RENDER_LAYER_SYMBOL      " Sym"
#define OLED_RENDER_LAYER_CONFIG      " Cfg"

// LUNA PET Variables
#if defined(WPM_ENABLE)
#   define OLED_LUNA_X                   0
#   define OLED_LUNA_Y                   13
#   define OLED_LUNA_MIN_WALK_SPEED      10
#   define OLED_LUNA_MIN_RUN_SPEED       40
#   define OLED_LUNA_ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#   define OLED_LUNA_ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024
#endif //WPM_ENABLE



void render_default_layer_state(void);
void render_layer_state(void);
void render_keylock_status(void);
void render_mod_status(void);
void render_feature_status(void);


static const char PROGMEM scroll_off[]  = {0x8D, 0};
static const char PROGMEM scroll_on[]   = {0x8E, 0};

static const char PROGMEM num_off[]     = {0xAD, 0};
static const char PROGMEM num_on[]      = {0xAE, 0};

static const char PROGMEM caps_off[]    = {0xCD, 0};
static const char PROGMEM caps_on[]     = {0xCE, 0};

static const char PROGMEM shift_off[]   = {0x85, 0x86, 0};
static const char PROGMEM shift_on[]    = {0x87, 0x88, 0};

static const char PROGMEM ctrl_off[]    = {0xA9, 0xAA, 0};
static const char PROGMEM ctrl_on[]     = {0xAB, 0xAC, 0};

static const char PROGMEM alt_off[]     = {0xA5, 0xA6, 0};
static const char PROGMEM alt_on[]      = {0xA7, 0xA8, 0};

static const char PROGMEM gui_off[]     = {0x89, 0x8A, 0};
static const char PROGMEM gui_on[]      = {0x8B, 0x8C, 0};

static const char PROGMEM rgb_off[]     = {0xC5, 0xC6, 0};
static const char PROGMEM rgb_on[]      = {0xC7, 0xC8, 0};

static const char PROGMEM dragscr_off[] = {0xC9, 0xCA, 0};
static const char PROGMEM dragscr_on[]  = {0xCB, 0xCC, 0};

static const char PROGMEM sound_off[]   = {0x8F, 0x90, 0};
static const char PROGMEM sound_on[]    = {0xAF, 0xB0, 0};

static const char PROGMEM haptic_off[]  = {0x91, 0x92, 0};
static const char PROGMEM haptic_on[]   = {0xB1, 0xB2, 0};

static const char PROGMEM lyr_cfg[] = {
  0xE1, 0xD1, 0xD2, 0xD3, 0xE1,
  0xE1, 0xBA, 0xBB, 0xBC, 0xE1,
  0xE1, 0xB7, 0xB8, 0xB9, 0xE1,
  0xE1, 0xD7, 0xD8, 0xD9, 0xE1, 0x00
};

static const char PROGMEM lyr_sym[] = {
  0xE1, 0x97, 0x98, 0x99, 0xE1,
  0xE1, 0xDA, 0xDB, 0xDC, 0xE1,
  0xE1, 0xB7, 0xB8, 0xB9, 0xE1,
  0xE1, 0xD7, 0xD8, 0xD9, 0xE1, 0x00
};

static const char PROGMEM lyr_num[] = {
  0xE1, 0x97, 0x98, 0x99, 0xE1,
  0xE1, 0x9A, 0x9B, 0x9C, 0xE1,
  0xE1, 0xBA, 0xBB, 0xBC, 0xE1,
  0xE1, 0xD7, 0xD8, 0xD9, 0xE1, 0x00
};

static const char PROGMEM lyr_nav[] = {
  0xE1, 0x97, 0x98, 0x99, 0xE1,
  0xE1, 0xB7, 0xB8, 0xB9, 0xE1,
  0xE1, 0xDA, 0xDB, 0xDC, 0xE1,
  0xE1, 0xD7, 0xD8, 0xD9, 0xE1, 0x00
};

static const char PROGMEM lyr_def[] = {
  0xE1, 0x97, 0x98, 0x99, 0xE1,
  0xE1, 0xB7, 0xB8, 0xB9, 0xE1,
  0xE1, 0x9A, 0x9B, 0x9C, 0xE1,
  0xE1, 0xD4, 0xD5, 0xD6, 0xE1, 0x00
};

static const char PROGMEM qmk_logo_small[] = {
  0xE1, 0x9D, 0x9E, 0x9F, 0xE1,
  0xE1, 0xBD, 0xBE, 0xBF, 0xE1,
  0xE1, 0xDD, 0xDE, 0xDF, 0xE1, 0x00
};