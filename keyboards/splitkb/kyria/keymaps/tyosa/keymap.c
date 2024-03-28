#include QMK_KEYBOARD_H
#include "tyosa.h"
#include "luna.h"
#include "encoder.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: Colemak DH
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : | Insert |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |  - / _ |GUI/A |R/ALT |S/CTRL|T/SHFT|   G  |                              |   M  |N/SHFT|E/CTRL|I/ALT |O/GUI | ' / "  |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |   Z  |   X  |   C  |   D  |   V  |      | LENC |  | RENC |      |   K  |   H  | ,  < | . >  | /  ? |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      | LGui |  Esc | Space| Tab  |  | Enter| Bspc |Delete| Nav  |      |
     *                        |      |      | Media| Nav  |      |  |  Sym | Num  | Func | Togl |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_COLEMAK_DH] = LAYOUT(
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_INS,
      KC_MINS,   HR_GA,   HR_AR,   HR_CS,   HR_ST,    KC_G,                                        KC_M,   HR_SN,   HR_CE,   HR_AI,   HR_GO, QC_QUOT,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, KC_LENC, KC_RENC, XXXXXXX,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 XXXXXXX, KC_LGUI, MED_ESC, NAV_SPC,  KC_TAB, SYM_ENT, NUM_BSP, FUN_DEL,  QC_NAV, XXXXXXX
    ),

    /*
     * Nav Layer: Navigation, editing
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              | Redo | Paste| Copy | Cut  | Undo |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | LGui |  Alt | Ctrl | Shift|      |                              |CapsLk|  ←   |   ↓  | ↑    | →    |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      |Insert| Home |PageUp|PageDn|  End |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      | LGui |  Esc | Space| Tab  |  | Enter| Bspc |Delete|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_REDO,   PASTE,    COPY,     CUT, KC_UNDO, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX,    COPY, XXXXXXX,   PASTE, XXXXXXX, _______, _______, XXXXXXX,  KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
                                 _______, _______,  KC_ESC,  KC_SPC,  KC_TAB,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    ),

    /*
     * Num layer : Numerals and symbols
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        | [ / {| 7 / &| 8 / *| 9 / (| ] / }|                              |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | ; / :| 4 / $| 5 / %| 6 / ^| + / =|                              |      | Shift| Ctrl |  Alt | LGui |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        | ~ / `| 1 / !| 2 / @| 3 / #| \ / ||      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      | . / >| 0 / )| - / _|  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_NUM ] = LAYOUT(
      XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
      XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT, XXXXXXX, XXXXXXX,
                                 _______, _______,  KC_DOT,    KC_0, KC_MINS, _______, _______, _______, _______, _______
    ),

    /*
     * Sym Layer: Numbers and symbols
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              |      |      |  ù   |      |      |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |   à  |      |      | Shift|      |                              |      |  é   |  è   |  î   | ô    |'/" grv |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |  ç   |      |      |      |      |  |      |      |      |      |  ^   |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      | Esc  | Space| Tab  |  | Enter| Bspc | Del  |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_SYM] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, QC_UGRV, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, QC_AGRV, XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX,                                     XXXXXXX, QC_EAIG, QC_EGRV, QC_ICRC, QC_OCRC, KC_QUOT,
      XXXXXXX, XXXXXXX, XXXXXXX, QC_CCED, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______,  KC_ESC,  KC_SPC,  KC_TAB,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    ),

    [_FUN] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case QC_EAIG:
            if (record->event.pressed) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the X_QUOTE keycode
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_QUOTE));
                // Reapplying modifier state so that the held shift key(s)
                // still work
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_EGRV:
            if (record->event.pressed) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the X_QUOTE keycode
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                // Reapplying modifier state so that the held shift key(s)
                // still work
                set_mods(mod_state);
                SEND_STRING("e");
            }
            return true;
        case QC_AGRV:
            if (record->event.pressed) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the X_QUOTE keycode
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                // Reapplying modifier state so that the held shift key(s)
                // still work
                set_mods(mod_state);
                SEND_STRING("a");
            }
            return true;
        case QC_ICRC:
            if (record->event.pressed) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the X_QUOTE keycode
                add_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_6));
                del_mods(MOD_MASK_SHIFT);
                // Reapplying modifier state so that the held shift key(s)
                // still work
                set_mods(mod_state);
                SEND_STRING("i");
            }
            return true;
        case QC_OCRC:
            if (record->event.pressed) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the X_QUOTE keycode
                add_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_6));
                del_mods(MOD_MASK_SHIFT);
                // Reapplying modifier state so that the held shift key(s)
                // still work
                set_mods(mod_state);
                SEND_STRING("o");
            }
            return true;
        case QC_UGRV:
            if (record->event.pressed) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the X_QUOTE keycode
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_GRV));
                // Reapplying modifier state so that the held shift key(s)
                // still work
                set_mods(mod_state);
                SEND_STRING("u");
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
        case QC_QUOT:
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


/**************** Oled *****************/

// Used to draw on to the oled screen
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK_DH:
                oled_write_P(PSTR("Base\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUN:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Num\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }


        oled_write_P(PSTR("Left: "), false);
        left_encoder_oled();

        oled_write_P(PSTR("Right: "), false);
        right_encoder_oled();

    } else {
        render_luna(0,1);
        oled_set_cursor(0,6);
        oled_write_P(PSTR("       WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}

