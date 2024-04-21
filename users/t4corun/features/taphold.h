#pragma once
#include "t4corun.h"

void insert_brackets(uint16_t left, uint16_t right);
void double_tap(uint16_t keycode, uint32_t ms);
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode);

/* the first element is the key
 * the second is altkey
 * for the most part it will be tap for key, hold for alt key
 * 
 * I was doing a switch statement to assign these each time, but this is faster
 *    and easier to maintain
*/ 
/*
//Brackets: open and close brackets and put the cursor inside
static const uint16_t TR_LCBR_taphold[] = { KC_LCBR, KC_RCBR };
static const uint16_t TR_LABK_taphold[] = { KC_LABK, KC_RABK };
static const uint16_t TR_LBRC_taphold[] = { KC_LBRC, KC_RBRC };
static const uint16_t TR_SQUO_taphold[] = { KC_QUOT, KC_QUOT };
static const uint16_t TR_DQUO_taphold[] = { KC_DQUO, KC_DQUO };

//double tap
static const uint16_t TR_EQL_taphold[]  = { KC_EQL,  KC_EQL };
static const uint16_t TR_PLUS_taphold[] = { KC_PLUS, KC_PLUS };
static const uint16_t TR_PIPE_taphold[] = { KC_PIPE, KC_PIPE };

//Custom: things like overriding default shifted key
static const uint16_t TR_LPRN_taphold[] = { KC_LPRN, KC_LPRN };
static const uint16_t TR_COMM_taphold[] = { KC_COMM, KC_LPRN };
static const uint16_t TR_DOT_taphold[]  = { KC_DOT,  KC_RPRN };
static const uint16_t TR_PERC_taphold[] = { KC_PERC, KC_CIRC };

//Faux auto shift
static const uint16_t TR_MINS_taphold[] = { KC_MINS, KC_UNDS };
static const uint16_t TR_GRV_taphold[] = { KC_GRV, KC_TILDE };
static const uint16_t TR_SCLN_taphold[] = { KC_SCLN, KC_COLN };
static const uint16_t TR_QUOT_taphold[] = { KC_QUOT, KC_DQUO };
*/