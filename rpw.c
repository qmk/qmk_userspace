#ifdef PERMISSIVE_HOLD_PER_KEY
// true: Immediately select the hold action when another key is tapped.
// false: Do not select the hold action when another key is tapped.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_D:
            return true;
        case SFT_K:
            return true;
        default:
            return false;
    }
}
#endif

#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_BSPC,
    COMBO_NUMBAK,
    COMBO_TAB,
    COMBO_ESC,
    COMBO_DEL,
};

const uint16_t PROGMEM combo_bspc[]   = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[]    = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[]    = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[] = {
    [COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC),
    [COMBO_NUMBAK] = COMBO(combo_numbak, KC_BSPC),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_DEL] = COMBO(combo_del, KC_DEL)
};
#endif

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(FN1, KC_NO):
        if (record->tap.count && record->event.pressed) {
          layer_invert(FN3);
          return false;
        }
    }
    return true;
  }
*/
