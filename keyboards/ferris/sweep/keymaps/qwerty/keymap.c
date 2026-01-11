#include QMK_KEYBOARD_H

// Aliases for characters that don't have a keycode
#define KC_DOUBLE_QUOTE_OPEN LALT(KC_LEFT_BRACKET)
#define KC_DOUBLE_QUOTE_CLOSE LALT(LSFT(KC_LEFT_BRACKET))
#define KC_SINGLE_QUOTE_OPEN LALT(KC_RIGHT_BRACKET)
#define KC_SINGLE_QUOTE_CLOSE LALT(LSFT(KC_RIGHT_BRACKET))
#define KC_UK_HASH LALT(KC_3)
#define KC_UK_POUND LSFT(KC_3)
#define KC_EURO LALT(KC_2)

#define KC_NAV_HISTORY_BACK LGUI(KC_LEFT_BRACKET)
#define KC_NAV_HISTORY_FORWARD LGUI(KC_RIGHT_BRACKET)
#define KC_NAV_PREV_TAB LCTL(LSFT(KC_TAB))
#define KC_NAV_NEXT_TAB RCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_Y, KC_U, KC_I, KC_O, KC_P,

        KC_A, KC_S, MT(MOD_LGUI,KC_D), MT(MOD_LCTL,KC_F), KC_G,
        KC_H, MT(MOD_RCTL,KC_J), MT(MOD_RGUI,KC_K), KC_L, KC_SCLN,

        KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, QK_REPEAT_KEY, KC_DOT, KC_SLSH,

        TO(1), OSM(MOD_LSFT),
        OSM(MOD_LALT), KC_SPACE
    ),
    // QWERTY numbers and navigation
	[1] = LAYOUT_split_3x5_2(
        KC_ESC, KC_KP_7, KC_KP_8, KC_KP_9, KC_NO,
        KC_NAV_HISTORY_BACK, KC_NAV_PREV_TAB, KC_NAV_NEXT_TAB, KC_NAV_HISTORY_FORWARD, KC_BSPC,

        KC_TAB, KC_KP_4, MT(MOD_LGUI,KC_KP_5), MT(MOD_LCTL,KC_KP_6), KC_NO,
        KC_LEFT, MT(MOD_RCTL,KC_DOWN), MT(MOD_RGUI,KC_UP), KC_RIGHT, KC_ENTER,

        KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_NO,
        KC_NO, KC_NO, QK_REPEAT_KEY, KC_DOT, KC_NO,

        TO(2), KC_TRNS,
        KC_TRNS, TO(0)
    ),
    // QWERTY alt-symbols layer (macOS Alt+key symbols - rare)
    [2] = LAYOUT_split_3x5_2(
        LALT(KC_Q), LALT(KC_W), LALT(KC_E), LALT(KC_R), LALT(KC_T),
        LALT(KC_Y), LALT(KC_U), LALT(KC_I), LALT(KC_O), LALT(KC_P),

        LALT(KC_A), LALT(KC_S), LALT(KC_D), LALT(KC_F), LALT(KC_G),
        LALT(KC_H), LALT(KC_J), LALT(KC_K), LALT(KC_L), LALT(KC_SCLN),

        LALT(KC_Z), LALT(KC_X), LALT(KC_C), LALT(KC_V), LALT(KC_B),
        LALT(KC_N), LALT(KC_M), LALT(KC_COMMA), LALT(KC_DOT), LALT(KC_SLSH),

        TO(0), KC_TRNS,
        KC_TRNS, TO(0)
    )
};

// https://docs.qmk.fm/#/feature_key_overrides?id=creating-key-overrides
// All layers are QWERTY layers (0, 1, 2)
#define QWERTY_LAYERS ~0

// QWERTY: alt ; = enter, shift+alt ; = noop
const key_override_t semicolon_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_SCLN, KC_ENTER, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t semicolon_key_alt_shifted_override = ko_make_with_layers(MOD_MASK_SA, KC_SCLN, KC_NO, QWERTY_LAYERS);

// QWERTY: alt p = backspace, shift+alt p = noop
const key_override_t p_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_P, KC_BSPC, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t p_key_alt_shifted_override = ko_make_with_layers(MOD_MASK_SA, KC_P, KC_NO, QWERTY_LAYERS);

// QWERTY: alt / = delete word, shift+alt / = noop
const key_override_t slsh_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_SLSH, LALT(KC_BSPC), QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t slsh_key_alt_shifted_override = ko_make_with_layers(MOD_MASK_SA, KC_SLSH, KC_NO, QWERTY_LAYERS);

// Alt+key on QWERTY layer 0 outputs symbols (from old layer 1)
// Top row
const key_override_t q_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_Q, KC_ESC, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t w_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_W, KC_AT, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t e_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_E, KC_UK_HASH, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t r_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_R, KC_DOLLAR, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t t_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_T, KC_PERCENT, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t y_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_Y, KC_CIRCUMFLEX, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t u_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_U, KC_AMPERSAND, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t i_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_I, KC_ASTERISK, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t o_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_O, KC_MINUS, QWERTY_LAYERS, MOD_MASK_SHIFT);

// Middle row
const key_override_t a_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_A, KC_TAB, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t s_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_S, KC_GRAVE, QWERTY_LAYERS, MOD_MASK_SHIFT);
// D, F, J, K handled in process_record_user() due to mod-tap interference
const key_override_t g_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_G, KC_NO, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t h_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_H, KC_BACKSLASH, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t l_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_L, KC_RBRC, QWERTY_LAYERS, MOD_MASK_SHIFT);

// Bottom row
const key_override_t z_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_Z, KC_TILDE, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t x_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_X, KC_MINUS, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t c_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_C, KC_PLUS, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t v_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_V, KC_EQUAL, QWERTY_LAYERS, MOD_MASK_SHIFT);
const key_override_t b_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_B, KC_UNDERSCORE, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t m_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_M, KC_LPRN, QWERTY_LAYERS, MOD_MASK_CSG);
const key_override_t dot_key_alt_override = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_DOT, KC_RPRN, QWERTY_LAYERS, MOD_MASK_CSG);

// Shift+Alt+key on QWERTY layer 0 (shifted symbols from old layer 1)
// Top row
const key_override_t q_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_Q, KC_NO, QWERTY_LAYERS);
const key_override_t w_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_W, KC_EURO, QWERTY_LAYERS);
const key_override_t e_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_E, KC_NO, QWERTY_LAYERS);
const key_override_t r_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_R, KC_UK_POUND, QWERTY_LAYERS);
const key_override_t t_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_T, KC_NO, QWERTY_LAYERS);
const key_override_t y_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_Y, KC_NO, QWERTY_LAYERS);
const key_override_t u_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_U, KC_NO, QWERTY_LAYERS);
const key_override_t i_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_I, KC_NO, QWERTY_LAYERS);
const key_override_t o_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_O, KC_NO, QWERTY_LAYERS);
const key_override_t p_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_P, KC_NO, QWERTY_LAYERS);

// Middle row
const key_override_t a_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_A, KC_NO, QWERTY_LAYERS);
const key_override_t s_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_S, KC_NO, QWERTY_LAYERS);
// D, F, J, K handled in process_record_user() due to mod-tap interference
const key_override_t g_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_G, KC_NO, QWERTY_LAYERS);
const key_override_t h_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_H, KC_NO, QWERTY_LAYERS);
const key_override_t l_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_L, KC_RCBR, QWERTY_LAYERS);
const key_override_t scln_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_SCLN, KC_NO, QWERTY_LAYERS);

// Bottom row
const key_override_t z_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_Z, KC_NO, QWERTY_LAYERS);
const key_override_t x_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_X, KC_DOUBLE_QUOTE_OPEN, QWERTY_LAYERS);
const key_override_t c_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_C, KC_SINGLE_QUOTE_OPEN, QWERTY_LAYERS);
const key_override_t v_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_V, KC_SINGLE_QUOTE_CLOSE, QWERTY_LAYERS);
const key_override_t b_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_B, KC_DOUBLE_QUOTE_CLOSE, QWERTY_LAYERS);
const key_override_t n_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_N, KC_NO, QWERTY_LAYERS);
const key_override_t m_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_M, KC_LABK, QWERTY_LAYERS);
const key_override_t comma_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_COMMA, KC_NO, QWERTY_LAYERS);
const key_override_t dot_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_DOT, KC_RABK, QWERTY_LAYERS);
const key_override_t slsh_key_shift_alt_override = ko_make_with_layers(MOD_MASK_SA, KC_SLSH, KC_NO, QWERTY_LAYERS);

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t period_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM);
const key_override_t repeat_key_override = ko_make_basic(MOD_MASK_SHIFT, QK_REPEAT_KEY, QK_ALT_REPEAT_KEY);
const key_override_t lparen_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LABK);
const key_override_t rparen_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RABK);
const key_override_t minus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_DOUBLE_QUOTE_OPEN);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_SINGLE_QUOTE_OPEN);
const key_override_t equal_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL, KC_SINGLE_QUOTE_CLOSE);
const key_override_t underscore_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_DOUBLE_QUOTE_CLOSE);
const key_override_t dollar_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR, KC_UK_POUND);
const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_EURO);
// Alt+keypad number keys act as FN keys
const key_override_t kp_one_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_1, KC_F1);
const key_override_t kp_two_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_2, KC_F2);
const key_override_t kp_three_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_3, KC_F3);
const key_override_t kp_four_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_4, KC_F4);
const key_override_t kp_five_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_5, KC_F5);
const key_override_t kp_six_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_6, KC_F6);
const key_override_t kp_seven_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_7, KC_F7);
const key_override_t kp_eight_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_8, KC_F8);
const key_override_t kp_nine_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_9, KC_F9);
const key_override_t kp_zero_key_override = ko_make_basic(MOD_MASK_ALT, KC_KP_0, KC_F10);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &semicolon_key_alt_override,
    &semicolon_key_alt_shifted_override,
    &p_key_alt_override,
    &p_key_alt_shifted_override,
    &slsh_key_alt_override,
    &slsh_key_alt_shifted_override,
    // QWERTY Alt+key overrides
    &q_key_alt_override,
    &w_key_alt_override,
    &e_key_alt_override,
    &r_key_alt_override,
    &t_key_alt_override,
    &y_key_alt_override,
    &u_key_alt_override,
    &i_key_alt_override,
    &o_key_alt_override,
    &a_key_alt_override,
    &s_key_alt_override,
    // D, F, J, K handled in process_record_user()
    &g_key_alt_override,
    &h_key_alt_override,
    &l_key_alt_override,
    &z_key_alt_override,
    &x_key_alt_override,
    &c_key_alt_override,
    &v_key_alt_override,
    &b_key_alt_override,
    &m_key_alt_override,
    &dot_key_alt_override,
    // QWERTY Shift+Alt vacant overrides
    &q_key_shift_alt_override,
    &w_key_shift_alt_override,
    &e_key_shift_alt_override,
    &r_key_shift_alt_override,
    &t_key_shift_alt_override,
    &y_key_shift_alt_override,
    &u_key_shift_alt_override,
    &i_key_shift_alt_override,
    &o_key_shift_alt_override,
    &p_key_shift_alt_override,
    &a_key_shift_alt_override,
    &s_key_shift_alt_override,
    // D, F, J, K handled in process_record_user()
    &g_key_shift_alt_override,
    &h_key_shift_alt_override,
    &l_key_shift_alt_override,
    &scln_key_shift_alt_override,
    &z_key_shift_alt_override,
    &x_key_shift_alt_override,
    &c_key_shift_alt_override,
    &v_key_shift_alt_override,
    &b_key_shift_alt_override,
    &n_key_shift_alt_override,
    &m_key_shift_alt_override,
    &comma_key_shift_alt_override,
    &dot_key_shift_alt_override,
    &slsh_key_shift_alt_override,
    &delete_key_override,
    &period_key_override,
    &repeat_key_override,
    &lparen_key_override,
    &rparen_key_override,
    &minus_key_override,
    &plus_key_override,
    &equal_key_override,
    &underscore_key_override,
    &dollar_key_override,
    &at_key_override,
    &kp_one_key_override,
    &kp_two_key_override,
    &kp_three_key_override,
    &kp_four_key_override,
    &kp_five_key_override,
    &kp_six_key_override,
    &kp_seven_key_override,
    &kp_eight_key_override,
    &kp_nine_key_override,
    &kp_zero_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM qwerty_combo[] = {KC_ESC, KC_TAB, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(qwerty_combo, TO(0))
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// If this value is greater than 100, the keyboard
// won't work on iOS devices. (Default value is 500)
#define USB_MAX_POWER_CONSUMPTION 100

// Custom handling for Alt+homerow mod-tap keys
// Key overrides don't work with mod-tap keys, so we handle them manually
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Check which modifiers are active (including one-shot modifiers)
    uint8_t mods = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t all_mods = mods | oneshot_mods;

    bool alt_held = (all_mods & MOD_MASK_ALT);
    bool shift_held = (all_mods & MOD_MASK_SHIFT);
    bool only_alt = alt_held && !shift_held && !(all_mods & MOD_MASK_CG); // Alt only, no Shift/Ctrl/GUI

    if (record->event.pressed) {
        // Handle Alt+homerow mod-tap keys
        if (only_alt) {
            uint8_t temp_mods = get_mods();

            switch(keycode) {
                case MT(MOD_LGUI, KC_D):  // Alt+D → '
                    del_mods(MOD_MASK_ALT); // Clear Alt temporarily
                    del_oneshot_mods(MOD_MASK_ALT); // Clear one-shot Alt (consume it)
                    tap_code16(KC_QUOTE); // Send '
                    set_last_keycode(KC_QUOTE);
                    set_last_mods(0);
                    set_mods(temp_mods); // Restore regular mods only
                    return false;
                case MT(MOD_LCTL, KC_F):  // Alt+F → "
                    del_mods(MOD_MASK_ALT);
                    del_oneshot_mods(MOD_MASK_ALT);
                    tap_code16(KC_DQUO); // Send "
                    set_last_keycode(KC_QUOTE);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    set_mods(temp_mods);
                    return false;
                case MT(MOD_RCTL, KC_J):  // Alt+J → [
                    del_mods(MOD_MASK_ALT);
                    del_oneshot_mods(MOD_MASK_ALT);
                    tap_code16(KC_LBRC); // Send [
                    set_last_keycode(KC_LBRC);
                    set_last_mods(0);
                    set_mods(temp_mods);
                    return false;
                case MT(MOD_RGUI, KC_K):  // Alt+K → |
                    del_mods(MOD_MASK_ALT);
                    del_oneshot_mods(MOD_MASK_ALT);
                    tap_code16(KC_PIPE); // Send |
                    set_last_keycode(KC_BACKSLASH);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    set_mods(temp_mods);
                    return false;
            }

            // Handle Alt+key repeat behavior for non-homerow keys
            // Key overrides happen after repeat key tracking, so we manually
            // set what repeat should remember (the overridden output, not Alt+key)
            switch(keycode) {
                case KC_Q:  // Alt+Q → Esc
                    set_last_keycode(KC_ESC);
                    set_last_mods(0);
                    break;
                case KC_W:  // Alt+W → @
                    set_last_keycode(KC_2);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_E:  // Alt+E → # (UK keyboard: Alt+3)
                    set_last_keycode(KC_3);
                    set_last_mods(MOD_BIT(KC_LALT));
                    break;
                case KC_R:  // Alt+R → $
                    set_last_keycode(KC_4);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_T:  // Alt+T → %
                    set_last_keycode(KC_5);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_Y:  // Alt+Y → ^
                    set_last_keycode(KC_6);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_U:  // Alt+U → &
                    set_last_keycode(KC_7);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_I:  // Alt+I → *
                    set_last_keycode(KC_8);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_O:  // Alt+O → -
                case KC_X:  // Alt+X → -
                    set_last_keycode(KC_MINUS);
                    set_last_mods(0);
                    break;
                case KC_P:  // Alt+P → Backspace
                    set_last_keycode(KC_BSPC);
                    set_last_mods(0);
                    break;
                case KC_A:  // Alt+A → Tab
                    set_last_keycode(KC_TAB);
                    set_last_mods(0);
                    break;
                case KC_S:  // Alt+S → `
                    set_last_keycode(KC_GRAVE);
                    set_last_mods(0);
                    break;
                case KC_H:  // Alt+H → backslash
                    set_last_keycode(KC_BACKSLASH);
                    set_last_mods(0);
                    break;
                case KC_L:  // Alt+L → ]
                    set_last_keycode(KC_RBRC);
                    set_last_mods(0);
                    break;
                case KC_Z:  // Alt+Z → ~
                    set_last_keycode(KC_GRAVE);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_C:  // Alt+C → +
                    set_last_keycode(KC_EQUAL);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_V:  // Alt+V → =
                    set_last_keycode(KC_EQUAL);
                    set_last_mods(0);
                    break;
                case KC_B:  // Alt+B → _
                    set_last_keycode(KC_MINUS);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_M:  // Alt+M → (
                    set_last_keycode(KC_9);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_DOT:  // Alt+. → )
                    set_last_keycode(KC_0);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_SCLN:  // Alt+; → Enter
                    set_last_keycode(KC_ENTER);
                    set_last_mods(0);
                    break;
                case KC_SLSH:  // Alt+/ → delete word (Alt+Backspace)
                    set_last_keycode(KC_BSPC);
                    set_last_mods(MOD_BIT(KC_LALT));
                    break;
            }
        }

        // Handle Shift+Alt+homerow mod-tap keys
        if (alt_held && shift_held) {
            uint8_t temp_mods = get_mods();

            switch(keycode) {
                case MT(MOD_RCTL, KC_J):  // Shift+Alt+J → {
                    del_mods(MOD_MASK_ALT | MOD_MASK_SHIFT); // Clear Alt+Shift temporarily
                    del_oneshot_mods(MOD_MASK_ALT | MOD_MASK_SHIFT); // Consume one-shot mods
                    tap_code16(KC_LCBR); // Send {
                    set_last_keycode(KC_LBRC);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    set_mods(temp_mods); // Restore regular mods only
                    return false;
                case MT(MOD_RGUI, KC_K):  // Shift+Alt+K → !
                    del_mods(MOD_MASK_ALT | MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_ALT | MOD_MASK_SHIFT);
                    tap_code16(KC_EXCLAIM); // Send !
                    set_last_keycode(KC_1);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    set_mods(temp_mods);
                    return false;
                case MT(MOD_LGUI, KC_D):
                case MT(MOD_LCTL, KC_F):
                    return false; // Block D, F with Shift+Alt (no symbol assigned)
            }

            // Handle Shift+Alt+key repeat behavior for non-homerow keys
            switch(keycode) {
                case KC_W:  // Shift+Alt+W → € (Alt+2 on macOS)
                    set_last_keycode(KC_2);
                    set_last_mods(MOD_BIT(KC_LALT));
                    break;
                case KC_R:  // Shift+Alt+R → £
                    set_last_keycode(KC_3);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_L:  // Shift+Alt+L → }
                    set_last_keycode(KC_RBRC);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_X:  // Shift+Alt+X → " (left double quote: Alt+[)
                    set_last_keycode(KC_LEFT_BRACKET);
                    set_last_mods(MOD_BIT(KC_LALT));
                    break;
                case KC_C:  // Shift+Alt+C → ' (left single quote: Alt+])
                    set_last_keycode(KC_RIGHT_BRACKET);
                    set_last_mods(MOD_BIT(KC_LALT));
                    break;
                case KC_V:  // Shift+Alt+V → ' (right single quote: Alt+Shift+])
                    set_last_keycode(KC_RIGHT_BRACKET);
                    set_last_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
                    break;
                case KC_B:  // Shift+Alt+B → " (right double quote: Alt+Shift+[)
                    set_last_keycode(KC_LEFT_BRACKET);
                    set_last_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
                    break;
                case KC_M:  // Shift+Alt+M → <
                    set_last_keycode(KC_COMMA);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
                case KC_DOT:  // Shift+Alt+. → >
                    set_last_keycode(KC_DOT);
                    set_last_mods(MOD_BIT(KC_LSFT));
                    break;
            }
        }

        // Handle Shift-only key repeat behavior for key overrides
        // Key overrides happen after repeat key tracking, so we manually
        // set what repeat should remember (the overridden output, not Shift+key)
        if (shift_held && !alt_held && !(all_mods & MOD_MASK_CG)) {
            switch(keycode) {
                case KC_DOT:  // Shift+. → ,
                    set_last_keycode(KC_COMMA);
                    set_last_mods(0);
                    break;
            }
        }
    }

    return true; // Continue normal processing
}

// Define handedness for Chordal Hold using layout array
// For Ferris Sweep (split keyboard): left half = 'L', right half = 'R'
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_2(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L',                 'R', 'R'
    );
