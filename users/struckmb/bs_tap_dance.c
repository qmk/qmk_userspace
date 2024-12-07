#ifdef TAP_DANCE_ENABLE
// Create a global instance of the tapdance state type
static td_state_t td_state;

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    }

    if (state->count == 2)
        return TD_DOUBLE_SINGLE_TAP;
    else
        return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void symL_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    if (td_state == TD_SINGLE_HOLD) {
        layer_on(LAYER_SYMBOL);
        return;
    }
    uint8_t current_layer = get_highest_layer(default_layer_state);
    switch (td_state) {
        case TD_SINGLE_TAP:
#    ifdef QWERTY_ENABLE
            if (LAYER_QWERTY == current_layer) register_code(DE_A);
#    endif // QWERTY_ENABLE
#    ifdef BONE_ENABLE
            if (LAYER_BONE == current_layer) register_code(DE_C);
#    endif // BONE_ENABLE
#    ifdef COLEMAK_DH_ENABLE
            if (LAYER_COLEMAK_DH == current_layer) register_code(DE_A);
#    endif // COLEMAK_DH_ENABLE
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
#    ifdef QWERTY_ENABLE
            if (LAYER_QWERTY == current_layer) {
                tap_code(DE_A);
                register_code(DE_A);
            }
#    endif // QWERTY_ENABLE
#    ifdef BONE_ENABLE
            if (LAYER_BONE == current_layer) {
                tap_code(DE_C);
                register_code(DE_C);
            }
#    endif // BONE_ENABLE
#    ifdef COLEMAK_DH_ENABLE
            if (LAYER_COLEMAK_DH == current_layer) {
                tap_code(DE_A);
                register_code(DE_A);
            }
#    endif // COLEMAK_DH_ENABLE
            break;
        default:
            break;
    }
}

void symL_reset(tap_dance_state_t *state, void *user_data) {
    if (td_state == TD_SINGLE_HOLD) {
        layer_off(LAYER_SYMBOL);
        return;
    }
    uint8_t current_layer = get_highest_layer(default_layer_state);
    switch (td_state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
#    ifdef QWERTY_ENABLE
            if (LAYER_QWERTY == current_layer) unregister_code(DE_A);
#    endif // QWERTY_ENABLE
#    ifdef BONE_ENABLE
            if (LAYER_BONE == current_layer) unregister_code(DE_C);
#    endif // BONE_ENABLE
#    ifdef COLEMAK_DH_ENABLE
            if (LAYER_COLEMAK_DH == current_layer) unregister_code(DE_A);
#    endif // COLEMAK_DH_ENABLE
            break;
        default:
            break;
    }
}

void symR_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    if (td_state == TD_SINGLE_HOLD) {
        layer_on(LAYER_SYMBOL);
        return;
    }
    uint8_t current_layer = get_highest_layer(default_layer_state);
    switch (td_state) {
        case TD_SINGLE_TAP:
#    ifdef QWERTY_ENABLE
            if (LAYER_QWERTY == current_layer) register_code(DE_ODIA);
#    endif // QWERTY_ENABLE
#    ifdef BONE_ENABLE
            if (LAYER_BONE == current_layer) register_code(DE_G);
#    endif // BONE_ENABLE
#    ifdef COLEMAK_DH_ENABLE
            if (LAYER_COLEMAK_DH == current_layer) register_code(DE_O);
#    endif // COLEMAK_DH_ENABLE
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 key presses within tapping term
#    ifdef QWERTY_ENABLE
            if (LAYER_QWERTY == current_layer) {
                tap_code(DE_ODIA);
                register_code(DE_ODIA);
            }
#    endif // QWERTY_ENABLE
#    ifdef BONE_ENABLE
            if (LAYER_BONE == current_layer) {
                tap_code(DE_G);
                register_code(DE_G);
            }
#    endif // BONE_ENABLE
#    ifdef COLEMAK_DH_ENABLE
            if (LAYER_COLEMAK_DH == current_layer) {
                tap_code(DE_O);
                register_code(DE_O);
            }
#    endif // COLEMAK_DH_ENABLE
            break;
        default:
            break;
    }
}

void symR_reset(tap_dance_state_t *state, void *user_data) {
    if (td_state == TD_SINGLE_HOLD) {
        layer_off(LAYER_SYMBOL);
        return;
    }
    uint8_t current_layer = get_highest_layer(default_layer_state);
    switch (td_state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
#    ifdef QWERTY_ENABLE
            if (LAYER_QWERTY == current_layer) unregister_code(DE_A);
#    endif // QWERTY_ENABLE
#    ifdef BONE_ENABLE
            if (LAYER_BONE == current_layer) unregister_code(DE_C);
#    endif // BONE_ENABLE
#    ifdef COLEMAK_DH_ENABLE
            if (LAYER_COLEMAK_DH == current_layer) unregister_code(DE_A);
#    endif // COLEMAK_DH_ENABLE
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    //
    [SYM_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, symL_finished, symL_reset),
    [SYM_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, symR_finished, symR_reset),
};

#endif // TAP_DANCE_ENABLE
