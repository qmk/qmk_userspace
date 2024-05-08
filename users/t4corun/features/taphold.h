#pragma once
#include "t4corun.h"

void single_tap(uint16_t key, uint16_t altkey, bool isHold);
void double_tap(uint16_t key, uint16_t altkey, uint32_t ms);
void insert_brackets(uint16_t left, uint16_t right, uint32_t ms);
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode);

/* the first element is the alt key (tap action)
 * the second is altkey (hold action usually)
 * 
 * I was doing a switch statement to assign these each time, but this is faster
 *    and easier to maintain
*/ 

// Brackets: open and close brackets and put the cursor inside
#define TAPHOLD_LCBR KC_LCBR, KC_RCBR
#define TAPHOLD_LABK KC_LABK, KC_RABK
#define TAPHOLD_LBRC KC_LBRC, KC_RBRC
#define TAPHOLD_LPRN KC_LPRN, KC_RPRN
#define TAPHOLD_SQUO KC_QUOT, KC_QUOT

// double tap
#define TAPHOLD_EQL  KC_EQL,  KC_EQL
#define TAPHOLD_BSLS KC_BSLS, KC_BSLS
#define TAPHOLD_SLSH KC_SLSH, KC_SLSH

// Custom override without holding shift
#define TAPHOLD_COMM KC_COMM, KC_LPRN
#define TAPHOLD_DOT  KC_DOT,  KC_RPRN
#define TAPHOLD_PERC KC_PERC, KC_CIRC
#define TAPHOLD_EXLM KC_EXLM, KC_DLR
#define TAPHOLD_AT   KC_AT,   KC_AMPR
#define TAPHOLD_ASTR KC_ASTR, KC_QUES

// auto shift
#define TAPHOLD_MINS KC_MINS, KC_UNDS
#define TAPHOLD_GRV  KC_GRV,  KC_TILD
#define TAPHOLD_SCLN KC_SCLN, KC_COLN
#define TAPHOLD_QUOT KC_QUOT, KC_DQUO


