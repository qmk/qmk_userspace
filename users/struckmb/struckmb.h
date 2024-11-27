#pragma once
#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"

#ifndef QWERTY_ENABLE
#    ifndef BONE_ENABLE
#        ifndef COLEMAK_DH_ENABLE
#            fail // at least one base layer has to be enabled!
#        endif    // !COLEMAK_DH_ENABLE
#    endif        // !BONE_ENABLE
#endif            // !QWERTY_ENABLE

// one shot shortcuts
#define OSM_ALT OSM(MOD_LALT)
#define OSM_AGR OSM(MOD_RALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_SFT OSM(MOD_LSFT)

// layer switching shortcuts
#define LOW_TAB LT(LAYER_LOWER, KC_TAB)
#define RSE_BSP LT(LAYER_RAISE, KC_BSPC)
#define ATT(kc) LT(LAYER_ATTIC, kc)
#define SY(kc) LT(LAYER_SYMBOL, kc)
#ifdef MOUSEKEY_ENABLE
#    define MS(kc) LT(LAYER_POINTER, kc)
#else
#    define MS(kc) kc
#endif

// // first and last column for 6 column keyboards:
#define SFT_ENT LSFT_T(KC_ENT)
#define SFT_SPC RSFT_T(KC_SPC)
#define ALT_BSP LALT_T(KC_BSPC)
#define CTL_ESC LCTL_T(KC_ESC)

/// Enumeration of layers
enum userspace_layers {
// base layers
#ifdef QWERTY_ENABLE
    LAYER_QWERTY,
#endif // QWERTY_ENABLE
#ifdef BONE_ENABLE
    LAYER_BONE,
#endif /* ifdef BONE_ENABLE */
#ifdef COLEMAK_DH_ENABLE
    LAYER_COLEMAK_DH,
#endif /* ifdef COLEMAK_DH_ENABLE */
#ifdef GAME_ENABLE
    LAYER_GAME,
#endif /* ifdef GAME_ENABLE */
    LAYER_SYMBOL,
#ifdef ASETNIOP_ENABLE
    LAYER_ASETNIOP,
#endif /* ifdef ASETNIOP_ENABLE */
#ifdef ARTSENIO_ENABLE
    // ARTSENIO layers
    LAYER_ARTSENIO,
    L_ARTS_NUM,
    L_ARTS_SYM,
    L_ARTS_PAR,
    L_ARTS_NAV,
    L_ARTS_MSE,
#endif /* ifdef ARTSENIO_ENABLE */
    // standard layers
    LAYER_LOWER,
    LAYER_RAISE,
#ifdef MOUSEKEY_ENABLE
    LAYER_POINTER,
#endif // MOUSEKEY_ENABLE
    LAYER_ATTIC
};

// Custom macro keycode ranges
enum userspace_custom_keycodes {
    // Safe stuff
    BS_SAFE = SAFE_RANGE,
#ifdef QWERTY_ENABLE
    DL_QWER,
#endif // ifdef QWERTY_ENABLE
#ifdef BONE_ENABLE
    DL_BONE,
#endif // ifdef BONE_ENABLE
#ifdef COLEMAK_DH_ENABLE
    DL_CODH,
#endif // ifdef COLEMAK_DH_ENABLE
    DL_PREV,
    DL_NEXT,
    NO_MODS,
#ifdef ARTSENIO_ENABLE
    /* AR_START, AR_END, // Dummy key codes for combo definitions */
    AR_A,
    AR_S,
    AR_E,
    AR_O,
#endif // ARTSENIO_ENABLE
#ifdef ASETNIOP_ENABLE
/* AS_START, AS_END, // Dummy key codes for combo definitions */
#endif // ASETNIOP_ENABLE
    DE_RSQU,
// Encoder button
#ifdef ENCODER_ENABLE
    BS_ENC0,
    BS_ENC1,
#endif // ENCODER_ENABLE
       // use for keymap specific codes
    KEYMAP_SAFE_RANGE
};

// Fallbacks to first base layer
#ifndef QWERTY_ENABLE
#    define DL_QWER DF(0)
#endif // ifndef QWERTY_ENABLE
#ifndef BONE_ENABLE
#    define DL_BONE DF(0)
#endif // ifndef BONE_ENABLE
#ifndef COLEMAK_DH_ENABLE
#    define DL_CODH DF(0)
#endif // ifndef COLEMAK_DH_ENABLE
// non-sticky layers (return after reset):
#ifdef GAME_ENABLE
#    define DL_GAME DF(LAYER_GAME)
#else
#    define DL_GAME DF(0)
#endif /* ifndef GAME_ENABLE */
#ifdef ARTSENIO_ENABLE
#    define DL_ARTS DF(LAYER_ARTSENIO)
#    define AR_A LT(L_ARTS_PAR, DE_A)
#    define AR_E LT(L_ARTS_SYM, DE_E)
#    define AR_S LT(L_ARTS_NUM, DE_S)
#    define AR_O DE_O
#else
#    define DL_ARTS DF(0)
#endif /* ifndef ARTSENIO_ENABLE */
#ifdef ASETNIOP_ENABLE
#    define DL_ASET DF(LAYER_ASETNIOP)
#else
#    define DL_ASET DF(0)
#endif /* ifndef ASETNIOP_ENABLE */

// KEYMAS
// first and last column keys for base layer
#define _0L1_1_ ALT_BSP
#define _0L2_1_ CTL_ESC
#define _0L3_1_ LGUI_T(KC_NUBS)
// R1 and R2 depend on layout
#define _0R1_1_(kc) LALT_T(kc)
#define _0R2_1_(kc) RCTL_T(kc)
#define _0R3_1_(kc) RGUI_T(kc)
// thumbs
#define _0L4_2_ KC_ESC, LOW_TAB
#define _0L4_3_ KC_ESC, SFT_ENT, LOW_TAB
#define _0R4_2_ RSE_BSP, SFT_SPC
#define _0R4_3_ _0R4_2_, KC_APP

/* THUMBS for base layers
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │Esc│Ent│Tab│ │Bsp│Spc│App│
 *          └───┴───┴LOW┘ └RSE┴───┴───┘
 *                *                 *
 */
#define _THUMBS_3_2_ _0L4_3_, _0R4_2_
#define _THUMBS_3_3_ _0L4_3_, _0R4_3_

#ifdef QWERTY_ENABLE
/* QWERTY layout
 *  q │ w │ e │ r │ t         z │ u │ i │ o │ p │(ü)
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 *  a │ s │ d │ f │ g         h │ j │ k │ l │ ö │(ä)
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 *  y │ x │ c │ v │ b         n │ m │ , │ . │ ß │(Ent)
 */
#    define _QL1_5_ DE_Q, DE_W, DE_E, DE_R, DE_T
#    define _QL2_5_ SY(DE_A), DE_S, DE_D, DE_F, DE_G
#    define _QL3_5_ MS(DE_Y), DE_X, DE_C, DE_V, DE_B
#    define _QR1_5_ DE_Z, DE_U, DE_I, DE_O, DE_P
#    define _QR2_5_ DE_H, DE_J, DE_K, DE_L, SY(DE_ODIA)
#    define _QR3_5_ DE_N, DE_M, DE_COMM, DE_DOT, MS(DE_SS)
//
#    define _QL1_6_ _0L1_1_, _QL1_5_
#    define _QL2_6_ _0L2_1_, _QL2_5_
#    define _QL3_6_ _0L3_1_, _QL3_5_
#    define _QR1_6_ _QR1_5_, _0R1_1_(DE_UDIA)
#    define _QR2_6_ _QR2_5_, _0R2_1_(DE_ADIA)
#    define _QR3_6_ _QR3_5_, _0R3_1_(KC_ENT)
//
#    define _QWERTY_3x5_ _QL1_5_, _QR1_5_, _QL2_5_, _QR2_5_, _QL3_5_, _QR3_5_
#    define _QWERTY_3x6_ _QL1_6_, _QR1_6_, _QL2_6_, _QR2_6_, _QL3_6_, _QR3_6_
#endif // QWERTY_ENABLE

#ifdef BONE_ENABLE
/* BONE layout
 *  j │ d │ u │ a │ x         p │ h │ l │ m │ w │(ß)
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 *  c │ t │ i │ e │ o         b │ n │ r │ s │ g │(q)
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 *  f │ v │ ü │ ä │ ö         y │ z │ , │ . │ k │(Ent)
 */
#    define _BL1_5_ DE_J, DE_D, DE_U, DE_A, DE_X
#    define _BL2_5_ SY(DE_C), DE_T, DE_I, DE_E, DE_O
#    define _BL3_5_ MS(DE_F), DE_V, DE_UDIA, DE_ADIA, DE_ODIA
#    define _BR1_5_ DE_P, DE_H, DE_L, DE_M, DE_W
#    define _BR2_5_ DE_B, DE_N, DE_R, DE_S, SY(DE_G)
#    define _BR3_5_ DE_Y, DE_Z, DE_COMM, DE_DOT, MS(DE_K)
//
#    define _BL1_6_ _0L1_1_, _BL1_5_
#    define _BL2_6_ _0L2_1_, _BL2_5_
#    define _BL3_6_ _0L3_1_, _BL3_5_
#    define _BR1_6_ _BR1_5_, _0R1_1_(DE_SS)
#    define _BR2_6_ _BR2_5_, _0R2_1_(DE_Q)
#    define _BR3_6_ _BR3_5_, _0R3_1_(KC_ENT)
//
#    define _BONE_3x5_ _BL1_5_, _BR1_5_, _BL2_5_, _BR2_5_, _BL3_5_, _BR3_5_
#    define _BONE_3x6_ _BL1_6_, _BR1_6_, _BL2_6_, _BR2_6_, _BL3_6_, _BR3_6_
#endif // BONE_ENABLE

#ifdef COLEMAK_DH_ENABLE
/* Colemak Mod-DH layout (german adaption)
 *  q │ w │ f │ p │ b         j │ l │ u │ y │ õ │(ü)
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 *  a │ r │ s │ t │ g         m │ n │ e │ i │ o │(ä)
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 *  z │ x │ c │ d │ v         k │ h │ , │ . │ ß │(Ent)
 */
#    define _CL1_5_ DE_Q, DE_W, DE_F, DE_P, DE_B
#    define _CL2_5_ SY(DE_A), DE_R, DE_S, DE_T, DE_G
#    define _CL3_5_ MS(DE_Z), DE_X, DE_C, DE_D, DE_V
#    define _CR1_5_ DE_J, DE_L, DE_U, DE_Y, DE_ODIA
#    define _CR2_5_ DE_M, DE_N, DE_E, DE_I, SY(DE_O)
#    define _CR3_5_ DE_K, DE_H, DE_COMM, DE_DOT, MS(DE_SS)
//
#    define _CL1_6_ _0L1_1_, _CL1_5_
#    define _CL2_6_ _0L2_1_, _CL2_5_
#    define _CL3_6_ _0L3_1_, _CL3_5_
#    define _CR1_6_ _BR1_5_, _0R1_1_(DE_SS)
#    define _CR2_6_ _BR2_5_, _0R2_1_(DE_Q)
#    define _CR3_6_ _BR3_5_, _0R3_1_(KC_ENT)
//
#    define _COLEMAK_DH_3x5_ _CL1_5_, _CR1_5_, _CL2_5_, _CR2_5_, _CL3_5_, _CR3_5_
#    define _COLEMAK_DH_3x6_ _CL1_6_, _CR1_6_, _CL2_6_, _CR2_6_, _CL3_6_, _CR3_6_
#endif // COLEMAK_DH_ENABLE

#ifdef GAME_ENABLE
/* GAME layout
 *  q │ w │ e │ r │ t         6 │ 7 │ 8 │ 9 │ 0
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 *  a │ s │ d │ f │ g         ← │ ↓ │ ↑ │ → │Tab
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 *  y │ x │ c │ v │ b         1 │ 2 │ 3 │ 4 │ 5
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │Esc│Sft│Ctl│ │Spc│Ent│Alt│
 *          └───┴───┴───┘ └───┴───┴───┘
 *            *                     *
 */
#    define _GL1_5_ _QL1_5_
#    define _GL2_5_ _QL2_5_
#    define _GL3_5_ _QL3_5_
#    define _GR1_5_ KC_6, KC_7, KC_8, KC_9, KC_0
#    define _GR2_5_ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TAB
#    define _GR3_5_ KC_1, KC_2, KC_3, KC_4, KC_5
//
#    define _GL1_6_ KC_NO, _GL1_5_
#    define _GL2_6_ KC_NO, _GL2_5_
#    define _GL3_6_ KC_NO, _GL3_5_
#    define _GR1_6_ _GR1_5_, KC_NO
#    define _GR2_6_ _GR2_5_, KC_NO
#    define _GR3_6_ _GR3_5_, KC_NO
//
#    define _GL4_2_ KC_LSFT, KC_LCTL
#    define _GL4_3_ KC_ESC, _GL4_2_
#    define _GR4_2_ KC_SPC, KC_ENT
#    define _GR4_3_ _GR4_2_, KC_LALT
#endif // GAME_ENABLE

/* Symbols layer
 *  @ │ _ │ [ │ ] │ ^         ! │ < │ > │ = │ &
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 *  \ │ / │ { │ } │ *         ? │ ( │ ) │ - │ :
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 *  # │ $ │ | │ ~ │ ´         + │ % │ " │ ' │ ;
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │ ° │Sft│ ` │ │AGr│Sft│CWT│
 *          └───┴───┴───┘ └───┴───┴───┘
 *            *                     *
 */
#define _SL1_5_ DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define _SL2_5_ DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define _SL3_5_ DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT
#define _SR1_5_ DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define _SR2_5_ DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN
#define _SR3_5_ DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN
//
#define _SL1_6_ KC_LALT, _SL1_5_
#define _SL2_6_ KC_LCTL, _SL2_5_
#define _SL3_6_ KC_LGUI, _SL3_5_
#define _SR1_6_ _SR1_5_, KC_LALT
#define _SR2_6_ _SR2_5_, KC_RCTL
#define _SR3_6_ _SR3_5_, KC_RGUI
//
#define _SL4_2_ KC_LSFT, DE_GRV
#define _SL4_3_ DE_DEG, _SL4_2_
#define _SR4_2_ KC_RALT, KC_LSFT
#define _SR4_3_ _SR4_2_, CW_TOGG
//
#define _SYMBOLS_3x5_ _SL1_5_, _SR1_5_, _SL2_5_, _SR2_5_, _SL3_5_, _SR3_5_
#define _SYMBOLS_3x6_ _SL1_6_, _SR1_6_, _SL2_6_, _SR2_6_, _SL3_6_, _SR3_6_

/* Lower: Numbers and function keys
 * F1 │F2 │F3 │F4 │ §         / │ 7 │ 8 │ 9 │ -
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * F5 │F6 │F7 │F8 │ €         + │ 4 │ 5 │ 6 │ .
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * F9 │F10│F11│F12│ ¢         0 │ 1 │ 2 │ 3 │ ,
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │Bsp│Sft│(v)│ │Del│Sft│XXX│
 *          └───┴───┴───┘ └ATT┴───┴───┘
 *            *                     *
 */
#define _LL1_5_ KC_F1, KC_F2, KC_F3, KC_F4, DE_SECT
#define _LL2_5_ KC_F5, KC_F6, KC_F7, KC_F8, DE_EURO
#define _LL3_5_ KC_F9, KC_F10, KC_F11, KC_F12, DE_CENT
#define _LR1_5_ DE_SLSH, DE_7, DE_8, DE_9, DE_MINS
#define _LR2_5_ DE_PLUS, DE_4, DE_5, DE_6, DE_DOT
#define _LR3_5_ DE_0, DE_1, DE_2, DE_3, DE_COMM
//
#define _LL1_6_ KC_LALT, _LL1_5_
#define _LL2_6_ KC_LCTL, _LL2_5_
#define _LL3_6_ KC_LGUI, _LL3_5_
#define _LR1_6_ _LR1_5_, KC_LALT
#define _LR2_6_ _LR2_5_, KC_RCTL
#define _LR3_6_ _LR3_5_, KC_RGUI
//
#define _LL4_2_ KC_LSFT, KC_TRNS
#define _LL4_3_ KC_BSPC, _LL4_2_
#define _LR4_2_ ATT(KC_DEL), KC_LSFT
#define _LR4_3_ _LR4_2_, KC_NO
//
#define _LOWER_3x5_ _LL1_5_, _LR1_5_, _LL2_5_, _LR2_5_, _LL3_5_, _LR3_5_
#define _LOWER_3x6_ _LL1_6_, _LR1_6_, _LL2_6_, _LR2_6_, _LL3_6_, _LR3_6_

/* Raise: Control + Navigation layer
 * PUp│BSp│ ↑ │Del│Ins       Prv│Stp│Ply│Nxt│Ejt
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * Hme│ ← │ ↓ │ → │End       Meh│Sft│Ctl│Alt│Gui
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * App│Cut│Cpy│Pst│PDn       PSc│CWT│Pse│AGr│SLk
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │V ×│V -│Bsp│ │(v)│V +│V ×│
 *          └───┴───┴ATT┘ └───┴───┴───┘
 *            *                     *
 */
#define _RL1_5_ KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_INS
#define _RL2_5_ KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _RL3_5_ KC_APP, KC_CUT, KC_COPY, KC_PSTE, KC_PGDN
#define _RR1_5_ KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_EJCT
#define _RR2_5_ OSM_MEH, OSM_SFT, OSM_CTL, OSM_ALT, OSM_GUI
#define _RR3_5_ KC_PSCR, CW_TOGG, KC_PAUS, OSM_AGR, KC_SCRL
//
#define _RL1_6_ KC_LALT, _LR1_5_
#define _RL2_6_ KC_LCTL, _LR2_5_
#define _RL3_6_ KC_LGUI, _LR3_5_
#define _RR1_6_ _RR1_5_, KC_LALT
#define _RR2_6_ _RR2_5_, KC_RCTL
#define _RR3_6_ _RR3_5_, KC_RGUI
//
#define _RL4_2_ KC_VOLD, ATT(KC_BSPC)
#define _RL4_3_ KC_MUTE, _RL4_2_
#define _RR4_2_ KC_TRNS, KC_VOLU
#define _RR4_3_ _LR4_2_, KC_MUTE
//
#define _RAISE_3x5_ _RL1_5_, _RR1_5_, _RL2_5_, _RR2_5_, _RL3_5_, _RR3_5_
#define _RAISE_3x6_ _RL1_6_, _RR1_6_, _RL2_6_, _RR2_6_, _RL3_6_, _RR3_6_

#ifdef MOUSEKEY_ENABLE
#    define MS_GSB1 S(G(KC_BTN1))
#    define MS_CSB1 S(C(KC_BTN1))
/* Pointer layer
 * vMv│<M<│Ms↑│>M>│             │GSC│CSC│   │
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * Bt4│Ms←│Ms↓│Ms→│Bt5     * Meh│Sft│Ctl│Alt│Gui *
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * Tb←│Cut│Cpy│Pst│^M^       Slo│Med│Fst│AGr│Tb→
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │GSC│Bt1│Bt2│ │Gui│Bt3│CSC│
 *          └───┴───┴───┘ └───┴───┴───┘
 *            *                     *
 */
#    define _PL1_5_ KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX
#    define _PL2_5_ KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5
#    define _PL3_5_ S(C(KC_TAB)), KC_CUT, KC_COPY, KC_PSTE, KC_WH_U
#    define _PR1_5_ XXXXXXX, MS_GSB1, MS_CSB1, XXXXXXX, XXXXXXX
#    define _PR2_5_ OSM_MEH, OSM_SFT, OSM_CTL, OSM_ALT, OSM_GUI
#    define _PR3_5_ KC_ACL0, KC_ACL1, KC_ACL2, KC_RALT, C(KC_TAB)
//
#    define _PL1_6_ KC_LALT, _PL1_5_
#    define _PL2_6_ KC_LCTL, _PL2_5_
#    define _PL3_6_ KC_LGUI, _PL3_5_
#    define _PR1_6_ _PR1_5_, KC_LALT
#    define _PR2_6_ _PR2_5_, KC_RCTL
#    define _PR3_6_ _PR3_5_, KC_RGUI
//
#    define _PL4_2_ KC_BTN1, KC_BTN2
#    define _PL4_3_ MS_GSB1, _PL4_2_
#    define _PR4_2_ KC_LGUI, KC_BTN3
#    define _PR4_3_ _PR4_2_, MS_CSB1
//
#    define _POINTER_3x5_ _PL1_5_, _PR1_5_, _PL2_5_, _PR2_5_, _PL3_5_, _PR3_5_
#    define _POINTER_3x6_ _PL1_6_, _PR1_6_, _PL2_6_, _PR2_6_, _PL3_6_, _PR3_6_
#endif

/* Attic: Adjustments and missing stuff
 * QBt│ECl│LAs│LAr│ •         ¡ │ ‹ │ « │ » │ ›
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * LyG│Ly←│Ly→│BsL│MDX        ¿ │ … │ ‚ │ ‘ │ ’
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 * R_T│R_M│R_M│R_M│R_M       n-–│m-—│ „ │ “ │ ”
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │LSf│Br-│(v)│ │(v)│Br+│RSf│
 *          └───┴───┴───┘ └───┴───┴───┘
 *            *                     *
 */
#define _AL1_5_ QK_BOOT, EE_CLR, DL_ASET, DL_ARTS, DE_MDDT
#define _AL2_5_ DL_GAME, DL_PREV, DL_NEXT, DL_QWER, NO_MODS
#define _AL3_5_ RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD
#define _AR1_5_ DE_IEXL, DE_LSAQ, DE_LDAQ, DE_RDAQ, DE_RSAQ
#define _AR2_5_ DE_IQUE, DE_ELLP, DE_SLQU, DE_LSQU, DE_RSQU
#define _AR3_5_ DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU
//
#define _AL1_6_ KC_NO, _AL1_5_
#define _AL2_6_ KC_NO, _AL2_5_
#define _AL3_6_ KC_NO, _AL3_5_
#define _AR1_6_ _AR1_5_, KC_NO
#define _AR2_6_ _AR2_5_, KC_NO
#define _AR3_6_ _AR3_5_, KC_NO
//
#define _AL4_2_ KC_BRID, KC_TRNS
#define _AL4_3_ KC_LSFT, _AL4_2_
#define _AR4_2_ KC_TRNS, KC_BRIU
#define _AR4_3_ _AR4_2_, KC_RSFT
//
#define _ATTIC_3x5_ _AL1_5_, _AR1_5_, _AL2_5_, _AR2_5_, _AL3_5_, _AR3_5_
#define _ATTIC_3x6_ _AL1_6_, _AR1_6_, _AL2_6_, _AR2_6_, _AL3_6_, _AR3_6_
