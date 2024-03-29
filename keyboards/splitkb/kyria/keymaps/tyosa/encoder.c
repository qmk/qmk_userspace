#include "quantum.h"
#include "tyosa.h"

enum left_encoder_mode {
    LENC_VOL,           // volume control
    LENC_WORD,          // scroll horizontally by word
    LENC_NOOP
};

enum right_encoder_mode {
    RENC_TAB,           // alt tabbing
    RENC_PAGE,          // scroll half pages
    RENC_NOOP
};

enum left_encoder_mode left_encoder = LENC_VOL;
enum right_encoder_mode right_encoder = RENC_TAB;

void left_encoder_click(void) {
    left_encoder++;
    if (left_encoder == LENC_NOOP) {
        left_encoder = 0;
    }
}

void left_encoder_hold(void) {
    tap_code(KC_MUTE);
}

void right_encoder_click(void) {
    right_encoder++;
    if (right_encoder == RENC_NOOP) {
        right_encoder = 0;
    }
}

void right_encoder_hold(void) {
    tap_code(KC_MUTE);
}

void left_encoder_oled(void) {
    switch (left_encoder) {
        case LENC_VOL:
            oled_write_P(PSTR("Volume\n"), false);
            break;
        case LENC_WORD:
            oled_write_P(PSTR("Word\n"), false);
            break;
        default:
            break;
    }
}

void right_encoder_oled(void) {
    switch (right_encoder) {
        case RENC_TAB:
            oled_write_P(PSTR("Alt - Tab\n"), false);
            break;
        case RENC_PAGE:
            oled_write_P(PSTR("Page scroll\n"), false);
            break;
        default:
            break;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (left_encoder) {
            case LENC_VOL:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                return false;
            case LENC_WORD:
                if (clockwise) {
                    tap_code16(C(KC_RIGHT));
                } else {
                    tap_code16(C(KC_LEFT));
                }

                return false;
            default:
                return false;
        }
    } else if (index == 1) {
        switch (right_encoder) {
            case RENC_PAGE:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                return false;
            case RENC_TAB:
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                } else {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(S(KC_TAB));
                }
                return false;
            default:
                return false;
        }
    }
    return false;
}
