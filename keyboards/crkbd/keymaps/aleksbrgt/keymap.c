#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_layers {
    BSE, // Base
    NUM, // Numbers and symbols
    NAV, // Navigation
    MED, // Media keys
    FUN, // Function keys
    OTH,  // "Other", caps, menu context, rctrl (rctrl is supposed to be used as the compose key https://en.wikipedia.org/wiki/Compose_key),
    PRN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BSE] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |   Q  MED  W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   0   |   P   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // | A GUI | S ALT | D CTL | F SFT |   G   |                    |   H   | J SFT | K CTL | L ALT | ' GUI |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |   Z   |   X   |   C   |   V   |   B   |                    |   N   |   M   |   ,   |   .   |   /   |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |ESC OTH|SPC NUM|TAB NAV|    |ENT FUN|  BSP  |  DEL  |
        //                          -------+-------+-------      -------+-------+-------
        KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,
        LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),      LCTL_T(KC_K),      RALT_T(KC_L),      RGUI_T(KC_QUOT),
        KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,
                                              LT(OTH, KC_ESC),   LT(NUM, KC_SPC),   LT(NAV, KC_TAB),   LT(FUN, KC_ENT),   KC_BSPC,           KC_DEL
    ),
    [NUM] = LAYOUT_split_3x5_3(
        //   ---------------------------------------                      ---------------------------------------
        //  |       |       |   (   |   )   |       |                    |  [ {  |  7 &  |  8 *  |  9 (  |  ] }  |
        //  |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        //  |  GUI  |  CTL  |  ALT  |  SFT  |   -   |                    |  = +  |  4 $  |  5 %  |  6 ^  |   ;   |
        //  |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        //  |       |       |       |       |   _   |                    |  \ |  |  1 !  |  2 @  |  3 #  |   `   |
        //   -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                          |  ESC  |  SPC  |  TAB  |    |       |  0 )  |       |
        //                           -------+-------+-------      -------+-------+-------
        XXXXXXX,           XXXXXXX,           KC_LPRN,           KC_RPRN,           XXXXXXX,           KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_MINS,           KC_EQL,            KC_4,              KC_5,              KC_6,              KC_SCLN,
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_UNDS,           KC_BSLS,           KC_1,              KC_2,              KC_3,              KC_GRV,
                                              KC_ESC,            KC_SPC,            KC_TAB,            XXXXXXX,           KC_0,              XXXXXXX
    ),
    [NAV] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |   ←   |   ↓   |   ↑   |   →   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |  ins  | home  | pgdn  | pgup  |  end  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |  ENT  |  BSPC |  DEL  |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         KC_INS,           KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,
                                              KC_ESC,            KC_SPC,               KC_TAB,          KC_ENT,           KC_BSPC,           KC_DEL
    ),
    [MED] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |  PREV | VOL - | VOL + |  NEXT |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |       |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       | PLAY  |  MUTE |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,
                                              KC_ESC,            KC_SPC,               KC_TAB,          XXXXXXX,          KC_MPLY,           KC_MUTE
    ),
    [FUN] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |  F 7  |  F 8  |  F 9  |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |  F 4  |  F 5  |  F 6  |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |  F 1  |  F 2  |  F 3  |       |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_F7,             KC_F8,             KC_F9,             KC_F10,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           XXXXXXX,           XXXXXXX,           KC_F4,             KC_F5,             KC_F6,             KC_F11,
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_F1,             KC_F2,             KC_F3,             KC_F12,
                                              KC_ESC,            KC_SPC,            KC_TAB,            XXXXXXX,           XXXXXXX,           XXXXXXX
    ),
    [OTH] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  CAPS |       |       |       |       |                    |       |       |       |       | R CTL |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |  APP  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,            XXXXXXX,          XXXXXXX,
        KC_CAPS,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,            XXXXXXX,          KC_RCTL,
        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,            XXXXXXX,          KC_APP,
                                              KC_ESC,            KC_SPC,            KC_TAB,            XXXXXXX,           XXXXXXX,           XXXXXXX
    ),
    [PRN] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  CAPS |       |       |       |       |                    |       |       |       |       | R CTL |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |  APP  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        KC_Q,              XXXXXXX,           KC_E,              XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,            XXXXXXX,          XXXXXXX,
        KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           XXXXXXX,           XXXXXXX,           KC_LEFT,           KC_DOWN,            KC_UP,            KC_RGHT,
        XXXXXXX,           XXXXXXX,           KC_F,              XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,            XXXXXXX,          XXXXXXX,
                                              KC_ESC,            KC_SPC,            XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX
    ),
};

const uint16_t PROGMEM combo_media[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_prn[] = {KC_Q, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_media, MO(MED)),
    COMBO(combo_prn, TG(PRN)),
};
