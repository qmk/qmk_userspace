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

//Brackets: open and close brackets and put the cursor inside
#define TH_LCBR KC_LCBR, KC_RCBR
#define TH_LABK KC_LABK, KC_RABK
#define TH_LBRC KC_LBRC, KC_RBRC
#define TH_SQUO KC_QUOT, KC_QUOT
#define TH_DQUO KC_DQUO, KC_DQUO
#define TH_LPRN KC_LPRN, KC_RPRN

//double tap
#define TH_EQL  KC_EQL,  KC_EQL 
#define TH_PLUS KC_PLUS, KC_PLUS
#define TH_PIPE KC_PIPE, KC_PIPE
#define TH_NUM  KC_NUM,  KC_NUM //For ploopy nano
#define TH_CAPS KC_CAPS, KC_CAPS

//Custom: things like overriding default shifted key
#define TH_COMM KC_COMM, KC_LPRN
#define TH_DOT  KC_DOT,  KC_RPRN
#define TH_PERC KC_PERC, KC_CIRC
#define TH_EXLM KC_EXLM, KC_EXLM
#define TH_NEQL KC_EXLM, KC_EQL

//auto shift
#define TH_MINS KC_MINS, KC_UNDS
#define TH_GRV  KC_GRV,  KC_TILD
#define TH_SCLN KC_SCLN, KC_COLN
#define TH_QUOT KC_QUOT, KC_DQUO


