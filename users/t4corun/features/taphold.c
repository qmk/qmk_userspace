#include "taphold.h"

void insert_brackets(uint16_t left, uint16_t right) {
  tap_code16(left);
  tap_code16(right);
  tap_code16(KC_LEFT);
}

void double_tap(uint16_t keycode, uint32_t ms) {
  tap_code16(keycode);
  wait_ms(ms);
  tap_code16(keycode);
}


//here we can have the holds be more complex, like sending "" when you hold "
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode) {

  //tap is record->tap.count && record->event.pressed
  //hold is record->event.pressed

  //bool isShift = ( (get_mods() & MOD_BIT(KC_LSFT)) || (get_oneshot_mods() & MOD_BIT(KC_LSFT)) );
  uint16_t key = KC_NO;
  uint16_t altkey = KC_NO;

  switch(keycode) {

    //Brackets
    //open and close brackets and put the cursor inside
    case TR_LCBR:
      key = KC_LCBR;
      altkey = KC_RCBR;
      break;
    case TR_LABK:
      key = KC_LABK;
      altkey = KC_RABK;
      break;
    case TR_LBRC:
      key = KC_LBRC;
      altkey = KC_RBRC;
      break;
    case TR_SQUO:
      key = KC_QUOT;
      altkey = KC_QUOT;
      break;
    case TR_DQUO:
      key = KC_DQUO;
      altkey = KC_DQUO; 
      break;

    //Custom
    case TR_LPRN: //tap for comma, hold for bracket parenthesis
    case TR_COMM: //tap for comma, hold for left parenthesis
      key = KC_COMM; 
      altkey = KC_LPRN;
      break;
    case TR_DOT:  //tap for dot, hold for right parenthesis
      key = KC_DOT;
      altkey = KC_RPRN;
      break;
    case TR_PERC: //tap for percent, hold for carat. for saving room on symbols layer
      key = KC_PERC; 
      altkey = KC_CIRC;
      break;

    //faux auto-shift
    case TR_EQL:  //tap for equal, hold for plus
      key = KC_EQL; 
      altkey = KC_PLUS;
      break;
    case TR_MINS: //tap for minus, hold for underscore
      key = KC_MINS;
      altkey = KC_UNDS;
      break;
    case TR_GRV: //tap for grave, hold for tilde
      key = KC_GRV; 
      altkey = KC_TILDE;
      break;
    case TH_SCLN: //tap for semicolon, hold for colon
      key = KC_SCLN;
      altkey = KC_COLN;
      break;
    case TR_QUOT: //tap for single quote, hold for double quote
      key = KC_QUOT; 
      altkey = KC_DQUO;
      break;
  }


  if (record->tap.count && record->event.pressed) {

    tap_code16(key);
    return false;

  } else if (record->tap.count == 0 && record->event.pressed) {

    switch(keycode) {

      //Brackets
      case TR_LCBR:
      case TR_LABK:
      case TR_LBRC:
      case TR_SQUO:
      case TR_DQUO:
        //isShift ? insert_brackets(LSFT(key), LSFT(altkey)) : insert_brackets(key, altkey);
        insert_brackets(key, altkey);
        break;
      
      //custom and faux auto-shift
      case TR_LPRN:
        insert_brackets(KC_LPRN, KC_RPRN);
        break;
      case TR_COMM:
      case TR_DOT:
      case TR_PERC:  
      case TR_EQL:
      case TR_MINS:
      case TR_GRV:
      case TH_SCLN:
      case TR_QUOT:
        tap_code16(altkey);
        break;
    }

    return false;
  }

  return true;  // Continue default handling.
}