#include "tyosa.h"
#include "encoder.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
        XXXXXXX,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                                           KC_J,     KC_L,     KC_U,     KC_Y,  KC_SCLN, XXXXXXX,
        XXXXXXX,    HR_GA,    HR_AR,    HR_CS,    HR_ST,     KC_G,                                           KC_M,    HR_SN,    HR_CE,    HR_AI,    HR_GO, XXXXXXX,
        XXXXXXX,     KC_Z,     KC_X,     KC_C,     KC_D,     KC_V, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,     KC_K,     KC_H,  KC_COMM,   KC_DOT,  KC_SLSH, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,  MEH_SPC, OS_LSFT, OS_LCTL,      SYM, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT(
        XXXXXXX,  KC_PERC,    KC_AT,  KC_HASH,   KC_DLR,   KC_ESC,                                        KC_BSPC,  KC_AMPR,  KC_ASTR,   KC_GRV, KC_CIRC, XXXXXXX,
        XXXXXXX,  QC_AGRV,  QC_EGRV,  QC_EAIG, XXXXXXX,   KC_TAB,                                         KC_ENT,  KC_LBRC,  KC_LPRN,  KC_RPRN, KC_RBRC, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  QC_CCED, XXXXXXX,  QC_UGRV, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,  QC_QUOT,  KC_BSLS,  KC_LCBR,  KC_RCBR,     NAV, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,  COLEMAK, OS_LSFT, KC_RALT,      NUM, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_ESC,                                        KC_BSPC,  QC_BACK,  QC_PTAB,  QC_NTAB,  QC_NEXT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_TAB,                                         KC_ENT,    HR_SL,    HR_CD,    KC_UP,  KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_DEL, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,  COLEMAK, OS_LSFT, KC_RCTL,      SYM, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_ESC,                                        KC_BSPC,     KC_7,     KC_8,     KC_9,  KC_MINS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_TAB,                                         KC_ENT,     KC_4,     KC_5,     KC_6,  KC_EQL, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PAST,  KC_PDOT, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,     KC_0,     KC_1,     KC_2,     KC_3,      NAV, XXXXXXX,
                                       XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, OS_LSFT, OS_LCTL,      SYM, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case QC_EAIG:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_QUOTE));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_EGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_AGRV:
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                set_mods(mod_state);
                SEND_STRING("a");
            }
            return true;
        case QC_CCED:
            if (record->event.pressed) {
                register_code(KC_RALT);
                SEND_STRING(",");
                unregister_code(KC_RALT);
            }
            return true;
        case KC_LENC:
            if (record->tap.count && record->event.pressed) {
                left_encoder_click();
            } else if (record->event.pressed) {
                left_encoder_hold();
            }
            return false;
        case KC_RENC:
            if (record->tap.count && record->event.pressed) {
                right_encoder_click();
            } else if (record->event.pressed) {
                right_encoder_hold();
            }
            return false;
        case QC_QUOT: //TODO double press the quote and put cursor between them ?
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_QUOTE));
                SEND_STRING(SS_TAP(X_SPC));
            }
            return false;
    }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
