#include QMK_KEYBOARD_H

// Tap Dance declarations

enum {
    TD_A,
    TD_O,
    TD_U,
    TD_S
};

// LEDs

layer_state_t layer_state_set_user(layer_state_t state) {
    // interestingly had to set the one I wanted on to 0 and the rest to 1 (for off)
    switch (get_highest_layer(state)) {
      case 1:
          // For Layer 1 set calculator led on
          writePin(LED_COMPOSE_PIN, 0);
          writePin(LED_SCROLL_LOCK_PIN, 1);
          break;
      case 2:
          // For Layer 2 set scroll lock led on
          writePin(LED_COMPOSE_PIN, 1);
          writePin(LED_SCROLL_LOCK_PIN, 0);
          break;
      default:
          // set off
          writePin(LED_COMPOSE_PIN, 1);
          writePin(LED_SCROLL_LOCK_PIN, 1);
    }
  return state;
}

bool led_update_user(led_t led_state) {
    // we want caps and num lock to keep working as is:
    writePin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);
    writePin(LED_NUM_LOCK_PIN, !led_state.num_lock);

    return false;
}

// Tap Dance functions
void dance_key_a (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("a");
        reset_tap_dance(state);
    } else if (state->count == 2) {
        if (!(keyboard_report->mods & MOD_MASK_SHIFT)) {
            send_unicode_string("ä");
        } else {
            send_unicode_string("Ä");
        }

        reset_tap_dance(state);
    }
}

void dance_key_s (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("s");
        reset_tap_dance(state);
    } else if (state->count == 2) {
        send_unicode_string("ß");

        reset_tap_dance(state);
    }
}

void dance_key_o (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("o");
        reset_tap_dance(state);
    } else if (state->count == 2) {
        if (!(keyboard_report->mods & MOD_MASK_SHIFT)) {
            send_unicode_string("ö");
        } else {
            send_unicode_string("Ö");
        }

        reset_tap_dance(state);
    }
}

void dance_key_u (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("u");
        reset_tap_dance(state);
    }  else if (state->count == 2) {
        if (!(keyboard_report->mods & MOD_MASK_SHIFT)) {
            send_unicode_string("ü");
        } else {
            send_unicode_string("Ü");
        }

        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_A] = ACTION_TAP_DANCE_FN(dance_key_a),
    [TD_O] = ACTION_TAP_DANCE_FN(dance_key_o),
    [TD_U] = ACTION_TAP_DANCE_FN(dance_key_u),
    [TD_S] = ACTION_TAP_DANCE_FN(dance_key_s),
};

// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, MO(2), TG(1), QK_BOOT, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, TD(TD_U), KC_I, TD(TD_O), KC_P, KC_BSLS, KC_CAPS, TD(TD_A), TD(TD_S), KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_GRV, KC_INS, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_LCTL, KC_LALT, KC_RGUI, KC_RCTL, KC_HOME, KC_PGUP, KC_BSPC, KC_DEL, KC_END, KC_PGDN, KC_ENT, KC_SPC),
        [1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NUM, KC_PEQL, KC_PSLS, KC_PAST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_0, KC_DOT, KC_PENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
        [2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_MRWD, KC_MPLY, KC_MFFD, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


//const key_override_t alt_a_key_override = ko_make_basic(MOD_MASK_ALT, TD(TD_A), UP(AE_LOWER, AE_UPPER));
//const key_override_t alt_o_key_override = ko_make_basic(MOD_MASK_ALT, TD(TD_O), UP(OE_LOWER, OE_UPPER));
//const key_override_t alt_u_key_override = ko_make_basic(MOD_MASK_ALT, TD(TD_U), UP(UE_LOWER, UE_UPPER));
//const key_override_t alt_s_key_override = ko_make_basic(MOD_MASK_ALT, TD(TD_S), UC(SS_LOWER));
//
//const key_override_t **key_overrides = (const key_override_t *[]){
//    &alt_a_key_override,
//	&alt_o_key_override,
//	&alt_u_key_override,
//	&alt_s_key_override,
//    NULL
//};
