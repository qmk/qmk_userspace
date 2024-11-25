/*
Copyright 2024 Brian Grant <@btgrant-76>

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

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum layer_names {
  _BASE,
  _NRM,
  _SYM,
  _NUM,
  _NAV,
  _FUN,
  _MSE,
  _ADD
};

#define _MED _SYM

enum custom_keycodes {
  SCRN2CLP = SAFE_RANGE, // macOS take screenshot to the clip board
  SCRN2FL,               // macOS take screenshot to a file
  QUO_INST,
  UP_DIR,//:../
  LOG_OUT,
  CAPWD_TG,
  NEW_SAFE_RANGE
};

// Tap Dance declarations
enum {
  TD_F1,
  TD_F2,
  TD_F6,
  TD_F9,
  TD_F12,
  TD_DOT,
  TD_ZERO,
  TD_TWO,
  TD_THREE,
  TD_QUOT,
  TD_DASH,
  TD_GRV
};

/* Aliases */
#define HOLD XXXXXXX //:(hold)

/** Layer Keys **/
#define TAB_FUN LT(_FUN, KC_TAB) //:Tab/FUN
#define TAB_MSE LT(_MSE, KC_TAB) //:Tab/MSE
#define BS_NUM LT(_NUM, KC_BSPC) //:BS/NUM
#define ESC_SYM LT(_SYM, KC_ESC) //:Esc/SYM
#define ESC_MSE LT(_MSE, KC_ESC) //:Esc/MSE
#define ESC_FUN LT(_FUN, KC_ESC) //:Esc/FUN
#define ENT_MSE LT(_MSE, KC_ENT) //:Ent/MSE
#define ENT_SYM LT(_SYM, KC_ENT) //:Ent/SYM
#define SPC_NAV LT(_NAV, KC_SPC) //:Spc/NAV
#define DEL_MED LT(_MED, KC_DEL) //:Del/MED
#define DEL_MSE LT(_MSE, KC_DEL) //:Del/MSE

#define LPRN_MSE LT(_MSE, KC_LPRN)

/** Mod Tap Aliases **/
/*** Home Row Mods ***/
#define A_CTL LCTL_T(KC_A) //:A/Ctl
#define A_WIN LGUI_T(KC_A) //:A/WIN
#define S_ALT LALT_T(KC_S) //:S/Alt
#define D_GUI LGUI_T(KC_D) //:D/Cmd
#define D_CTL LCTL_T(KC_D) //:D/CTL
#define F_SFT LSFT_T(KC_F) //:F/Sft
#define J_SFT RSFT_T(KC_J) //:J/Sft
#define K_GUI RGUI_T(KC_K) //:K/Cmd
#define K_CTL RCTL_T(KC_K) //:K/CTL
#define L_ALT RALT_T(KC_L) //:L/Alt
#define SCLN_CTL RCTL_T(KC_SCLN) //:;_:/Ctl
#define SCLN_WIN RGUI_T(KC_SCLN) //:;_:/WIN
#define HRM_L KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT //:Ctl||Opt||GUI||Sft
#define HRM_R KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL //:Sft||GUI||Opt||Ctl
#define HRM_LWIN KC_LGUI, KC_LALT,KC_LCTL, KC_LSFT //:WIN||Opt||Ctl||Sft
#define HRM_RWIN KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI  //:Sft||Ctl||Opt||WIN

/*** Others ***/
#define ENT_SFT RSFT_T(KC_ENT) //:Ent/Sft
#define SLS_HYPR HYPR_T(KC_SLSH) //:/_?/Hypr
#define Z_HYPR HYPR_T(KC_Z) //:Z/Hypr
#define B_MEH MEH_T(KC_B) //:B/Meh
#define N_MEH MEH_T(KC_N) //:N/Meh

/*** Thumb keys ***/
#define DEL_GUI LGUI_T(KC_DEL) //:Del/Cmd
#define SPC_MEH MEH_T(KC_SPC)

/*** Shortcuts ***/
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)
#define CLIPBOARD_R REDO, PASTE, COPY, CUT, UNDO //:Redo||Paste||Copy||Cut||Undo
#define CLIPBOARD_L UNDO, CUT, COPY, PASTE, REDO //:Undo||Cut||Copy||Paste||Redo

/*** macOS navigation ***/
#define MISS_CTL LCTL(KC_UP)
#define LEFT_SPC LCTL(KC_LEFT)
#define RGHT_SPC LCTL(KC_RIGHT)

/*** Other shortcuts ***/
#define BACK LCMD(KC_LBRC) //:Back
#define FWD LCMD(KC_RBRC) //:Forward
#define TAB_LFT LSG(KC_LBRC) //:Tab_Lft
#define TAB_RGT LSG(KC_RBRC) //:Tab_Rght
#define Z_MUTE HYPR(KC_SPC) //:Zoom_Mute

#ifdef TAP_DANCE_ENABLE
// Tap Dances
#define F1_TD TD(TD_F1) //:F1
#define F2_TD TD(TD_F2) //:F2
#define F6_TD TD(TD_F6) //:F6
#define F9_TD TD(TD_F9) //:F9
#define F12_TD TD(TD_F12) //:F12
#define DOT_TD TD(TD_DOT) //:.
#define ZERO_TD TD(TD_ZERO) //:0
#define TWO_TD TD(TD_TWO) //:2
#define THREE_TD TD(TD_THREE) //:3
#define QUOT_TD TD(TD_QUOT) //:'_"
#define DASH_TD TD(TD_DASH) //:-__
#define GRV_TD TD(TD_GRV) //:`_~
#else
#define F1_TD KC_F1
#define F2_TD KC_F2
#define F6_TD KC_F6
#define F9_TD KC_F9
#define F12_TD KC_F12
#define DOT_TD KC_DOT
#define ZERO_TD KC_0
#define TWO_TD KC_2
#define THREE_TD KC_3
#define QUOT_TD KC_QUOT
#define DASH_TD KC_MINS
#define GRV_TD KC_GRV
#endif // TAP_DANCE_ENABLE

/* portable keymaps */
/** 10u **/
/*** base ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Q     │  W     │  E     │  R     │  T     │ */
#define ___5BASE_1_L___     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  A/Ctl │  S/Alt │  D/Cmd │  F/Sft │  G     │ */
#define ___5BASE_2_L___     A_CTL,   S_ALT,   D_GUI,   F_SFT,   KC_G
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Z/Hypr │  X     │  C     │  V     │  B/Meh │ */
#define ___5BASE_3_L___     Z_HYPR,   KC_X,    KC_C,    KC_V,   B_MEH
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Tab/FUN│ BS/NUM │ Esc/MSE│ */
#define ___BASE_THUMB_L___                    TAB_FUN, BS_NUM,  ESC_MSE
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Y     │  U     │  I     │  O     │  P     │ */
#define ___5BASE_1_R___     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  H     │  J/Sft │  K/Cmd │  L/Alt │ ; :/Ctl│ */
#define ___5BASE_2_R___     KC_H,    J_SFT,   K_GUI,   L_ALT,   SCLN_CTL
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  N/Meh │  M     │  , <   │  . >   │/ ?/Hypr│ */
#define ___5BASE_3_R___     N_MEH,   KC_M,    KC_COMM, KC_DOT,  SLS_HYPR
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │Ent/MSE │Spc/NAV │ Del/MED│ */
#define ___BASE_THUMB_R___  ENT_MSE, SPC_NAV, DEL_MED
                        /* ╰────────┴────────┴────────╯ */

/*** number ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5NUM_1_L___      CLIPBOARD_L
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  S/Alt │  Cmd   │  Shift │Capwd TG│ */
#define ___5NUM_2_L___      KC_LCTL, S_ALT,   KC_LGUI, KC_LSFT, CAPWD_TG
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Esc   │  ---   │ Leader │ Space  │  BS    │ */
#define ___5NUM_3_L___      KC_ESC,  XXXXXXX, QK_LEAD, KC_SPC,  KC_BSPC
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  Del   │ (hold) │  BS    │ */
#define ___NUM_THUMB_L___                     KC_DEL,  HOLD, KC_BSPC
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  [ {   │  7     │  8     │  9     │  ] }   │ */
#define ___5NUM_1_R___      KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  = +   │  4     │  5     │  6     │  ' "   │ */
                            // TODO maybe try moving the quote hold to a different key?
#define ___5NUM_2_R___      KC_EQL,  KC_4,    KC_5,    KC_6,    QUOT_TD
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  \ |   │  1     │  2     │  3     │  ` ~   │ */
#define ___5NUM_3_R___      KC_BSLS, KC_1,    TWO_TD,  THREE_TD, GRV_TD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  - _   │  0     │  .     │ */
#define ___NUM_THUMB_R___   KC_MINS, ZERO_TD, DOT_TD
                        /* ╰────────┴────────┴────────╯ */

/*** symbol ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5SYM_1_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Med <==│ Vol Dn │ Vol Up │ Med==> │RGB Spd+│ */
#define ___5SYM_2_L___      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_SPI
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ RGB tog│RGB mod+│RGB hue+│RGB sat+│RGB brt+│ */
#define ___5SYM_3_L___      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  Mute  │Ply/Paus│  Stop  │ */
#define ___SYM_THUMB_L___                     KC_MUTE, KC_MPLY, KC_MSTP
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  {     │  &     │  *     │  )     │  }     │ */
#define ___5SYM_1_R___      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  +     │  $     │  %     │  ^     │  "     │ */
#define ___5SYM_2_R___      KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  |     │  !     │  @     │  #     │  ~     │ */
#define ___5SYM_3_R___      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  _     │  (     │ (hold) │ */
#define ___SYM_THUMB_R___   KC_UNDS, LPRN_MSE, HOLD
                        /* ╰────────┴────────┴────────╯ */

/*** navigation ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Tab Lft│  Back  │ Forward│Tab Rght│  ../   │ */
#define ___5NAV_1_L___      TAB_LFT, BACK,    FWD,     TAB_RGT, UP_DIR
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │  ---   │ */
#define ___5NAV_2_L___      HRM_L,                        XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5NAV_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Del/Cmd│  Bs    │  Ent   │ */
#define ___NAV_THUMB_L___                     DEL_GUI, KC_BSPC, KC_ENT
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │ */
#define ___5NAV_1_R___      CLIPBOARD_R
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Left  │  Down  │  Up    │  Right │  Caps  │ */
#define ___5NAV_2_R___      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_CAPS
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Home  │  PgDn  │  PgUp  │  End   │ Ent    │ */
#define ___5NAV_3_R___      KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_ENT
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │ (hold) │  ---   │ */
#define ___NAV_THUMB_R___   XXXXXXX, HOLD, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** function ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Log Out│  ---   │Scrn2Clp│ Scrn2Fl│  ---   │ */
#define ___5FUN_1_L___      LOG_OUT, XXXXXXX, SCRN2CLP, SCRN2FL, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │ScrnBrt+│ */
#define ___5FUN_2_L___      HRM_L,                        KC_BRIU
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │ScrnBrt-│ */
#define ___5FUN_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ (hold) │  MSE   │  Tab   │ */
#define ___FUN_THUMB_L___                     HOLD, MO(_MSE), XXXXXXX
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  F7    │  F8    │  F9    │  F12   │ */
#define ___5FUN_1_R___      XXXXXXX, KC_F7,   KC_F8,   F9_TD,   F12_TD
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F4    │  F5    │  F6    │  F11   │ */
#define ___5FUN_2_R___      XXXXXXX, KC_F4,   KC_F5,   F6_TD,   KC_F11
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F1    │  F2    │  F3    │  F10   │ */
#define ___5FUN_3_R___      XXXXXXX, F1_TD,   F2_TD,   KC_F3,   KC_F10
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │  ADD   │  ---   │ */
#define ___FUN_THUMB_R___   XXXXXXX, MO(_ADD), XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** mouse ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5MSE_1_L___      CLIPBOARD_L
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │Button 5│Button 3│Button 1│Button 2│ Wheel D│ */
#define ___5MSE_2_L___      KC_BTN5, KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX // KC_WH_D
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Esc   │  Ctl   │  Alt   │  Cmd   │ Shft   │ */
#define ___5MSE_3_L___      KC_ESC,  HRM_L                         // KC_WH_U // TODO how much am I using wheel up/down? If I shifted HRM over to the right, I could put Esc on Z like the default layer
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │ (hold) │ (hold) │ */
#define ___MSE_THUMB_L___                     XXXXXXX, HOLD, HOLD
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │MseSpd 0│MseSpd 1│MseSpd 2│  ---   │ */
#define ___5MSE_1_R___      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Mouse L│ Mouse D│ Mouse U│ Mouse R│  ---   │ */
#define ___5MSE_2_R___      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Wheel L│ Wheel U│ Wheel D│ Wheel R│  ---   │ */
// wheel up/down are swapped intentionally so the actual directions are synced
// relative to "natural scrolling"
#define ___5MSE_3_R___      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │ (hold) │ (hold) │  ---   │ */
#define ___MSE_THUMB_R___   HOLD, HOLD, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** additional features ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Bootldr│  ---   │  ---   │DF: BASE│DF: NRM │ */
#define ___5ADD_1_L___      QK_BOOT, XXXXXXX, XXXXXXX, DF(_BASE), DF(_NRM)
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │DynTpRpt│ DynTpDn│ DynTpUp│  ---   │ */
#define ___5ADD_2_L___      XXXXXXX, DT_PRNT, DT_DOWN, DT_UP,   XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │ ASftRpt│ ASft Dn│ ASft Up│  ---   │ */
#define ___5ADD_3_L___      XXXXXXX, AS_RPT,  AS_DOWN, AS_UP,   XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │  ---   │  ---   │ */
#define ___ADD_THUMB_L___                     XXXXXXX, XXXXXXX, XXXXXXX
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │ */
#define ___5ADD_1_R___      CLIPBOARD_R
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5ADD_2_R___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5ADD_3_R___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │ (hold) │  ---   │ */
#define ___ADD_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */
