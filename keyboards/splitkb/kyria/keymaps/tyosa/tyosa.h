#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FUN,
    _MEDIA,
    _NUM
};

enum custom_keycodes {
    QC_EGRV = SAFE_RANGE,       // è
    QC_EAIG,                    // é
    QC_AGRV,                    // à
    QC_CCED,                    // ç
    QC_UGRV,                    // ù
    QC_ICRC,                    // î
    QC_OCRC,                    // ù
    KC_LEFT_ENC_MODE,           // left encoder mode
    KC_RIGHT_ENC_MODE,          // right encoder mode
    ALT_TAB,                    // alt-tab
    QC_QUOT                     // non-dead quotes
};

typedef struct _master_to_slave_t {
    bool is_sneaking;
    bool is_barking;
} master_to_slave_t;

#define  CTL_ESC    MT(MOD_LCTL, KC_ESC)
#define LALT_ENT    MT(MOD_LALT, KC_ENT)
#define RALT_ENT    MT(MOD_RALT, KC_ENT)
#define  KC_LENC    LT(0, KC_LEFT_ENC_MODE)
#define  KC_RENC    LT(0, KC_RIGHT_ENC_MODE)

// Custom actions
#define     COPY    LCTL(KC_C)
#define    PASTE    LCTL(KC_V)
#define      CUT    LCTL(KC_X)
#define  KC_REDO    LCTL(KC_Y)
#define  KC_UNDO    LCTL(KC_Z)

// Home row mods
#define    HR_GA    LGUI_T(KC_A)
#define    HR_AR    LALT_T(KC_R)
#define    HR_CS    LCTL_T(KC_S)
#define    HR_ST    LSFT_T(KC_T)
#define    HR_SN    LSFT_T(KC_N)
#define    HR_CE    LCTL_T(KC_E)
#define    HR_AI    LALT_T(KC_I)
#define    HR_GO    LGUI_T(KC_O)

// Thumb tap/hold
#define  MEH_GUI    MEH_T(KC_LGUI)
#define  MED_ESC    LT(_MEDIA, KC_ESC)
#define  NAV_SPC    LT(_NAV, KC_SPC)
#define  SYM_ENT    LT(_SYM, KC_ENT)
#define  NUM_BSP    LT(_NUM, KC_BSPC)
#define  FUN_DEL    LT(_FUN, KC_DEL)

// Layer toggle
#define   QC_NAV    TG(_NAV)

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;
