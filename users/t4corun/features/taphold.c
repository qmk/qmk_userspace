#include "taphold.h"

void single_tap(uint16_t key, uint16_t altkey, bool isHold) {
  isHold ? tap_code16(altkey) : tap_code16(key);
}

void double_tap(uint16_t key, uint16_t altkey, uint32_t ms) {
  tap_code16(key);
  wait_ms(ms);
  tap_code16(altkey);
}

void insert_brackets(uint16_t left, uint16_t right, uint32_t ms) {
  tap_code16(left);
  wait_ms(ms);
  tap_code16(right);
  wait_ms(ms);
  tap_code16(KC_LEFT);
}

//here we can have the holds be more complex, like sending "" when you hold "
bool process_tap_hold_key(keyrecord_t* record, uint16_t keycode) {

  //tap is record->tap.count && record->event.pressed
  //hold is record->event.pressed

  //just saving this to handle mods
  //bool isShift = ( (get_mods() & MOD_BIT(KC_LSFT)) || (get_oneshot_mods() & MOD_BIT(KC_LSFT)) );
  //isShift ? insert_brackets(LSFT(key), LSFT(altkey)) : insert_brackets(key, altkey);

  bool isHold = false;

  if (record->tap.count && record->event.pressed) {

    switch(keycode) {

      case TR_LCBR:
        single_tap(TAPHOLD_LCBR, isHold);
        break;
      case TR_LABK:
        single_tap(TAPHOLD_LABK, isHold);
        break;
      case TR_LBRC:
        single_tap(TAPHOLD_LBRC, isHold);
        break;
      case TR_LPRN:
        single_tap(TAPHOLD_LPRN, isHold);
        break;
      case TR_SQUO:
        single_tap(TAPHOLD_SQUO, isHold);
        break;
      case TR_DQUO:
        single_tap(TAPHOLD_DQUO, isHold);
        break;
      case TR_EQL:
        single_tap(TAPHOLD_LPRN, isHold);
        break;
      case TR_PLUS:
        single_tap(TAPHOLD_PLUS, isHold);
        break;
      case TR_PIPE:
        single_tap(TAPHOLD_PIPE, isHold);
        break;
      case TR_COMM:
        single_tap(TAPHOLD_COMM, isHold);
        break;
      case TR_DOT:
        single_tap(TAPHOLD_DOT, isHold);
        break;
      case TR_PERC:
        single_tap(TAPHOLD_PERC, isHold);
        break;
      case TR_EXLM:
        single_tap(TAPHOLD_EXLM, isHold);
        break;
      case TR_MINS:
        single_tap(TAPHOLD_MINS, isHold);
        break;
      case TR_GRV:
        single_tap(TAPHOLD_GRV, isHold);
        break;
      case TAPHOLD_SCLN:
        single_tap(TAPHOLD_SCLN, isHold);
        break;
      case TR_QUOT:
        single_tap(TAPHOLD_QUOT, isHold);
        break;
      
      //tap numlock twice to toggle ploopy nano drag scroll
      case PN_DRGS:
        double_tap(TAPHOLD_NUM, WAIT_DELAY);
        break;

      //tap capslock twice to cycle ploopy nano pointer DPI
      case PN_PDPI:
        double_tap(TAPHOLD_CAPS, WAIT_DELAY);
        break;
    }

    return false;

  } else if (record->tap.count == 0 && record->event.pressed) {

    isHold = true;

    switch(keycode) {

      //Brackets
      case TR_LCBR:
        insert_brackets(TAPHOLD_LCBR);
        break;
      case TR_LABK:
        insert_brackets(TAPHOLD_LABK);
        break;
      case TR_LBRC:
        insert_brackets(TAPHOLD_LBRC);
        break;
      case TR_SQUO:
        insert_brackets(TAPHOLD_SQUO);
        break;
      case TR_DQUO:
        insert_brackets(TAPHOLD_DQUO);
        break;
      case TR_LPRN:
        insert_brackets(TAPHOLD_LPRN);
        break;

      //double tap
      case TR_EQL:
        double_tap(TAPHOLD_LPRN);
        break;
      case TR_PLUS:
        double_tap(TAPHOLD_PLUS);
        break;
      case TR_PIPE:
        double_tap(TAPHOLD_PIPE);
        break;

      //custom action
      case TR_COMM:
        single_tap(TAPHOLD_COMM, isHold);
        break;
      case TR_DOT:
        single_tap(TAPHOLD_DOT, isHold);
        break;
      case TR_PERC:
        single_tap(TAPHOLD_PERC, isHold);
        break;
      case TR_EXLM:
        double_tap(TAPHOLD_NEQL);
        break;

      //simulates auto-shift
      case TR_MINS:
        single_tap(TAPHOLD_MINS, isHold);
        break;
      case TR_GRV:
        single_tap(TAPHOLD_GRV, isHold);
        break;
      case TAPHOLD_SCLN:
        single_tap(TAPHOLD_SCLN, isHold);
        break;
      case TR_QUOT:
        single_tap(TAPHOLD_QUOT, isHold);
        break;
    }

    return false;

  }

  return true;  // Continue default handling.
}