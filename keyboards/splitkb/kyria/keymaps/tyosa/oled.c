#include QMK_KEYBOARD_H
#include "tyosa.h"
#include "quantum.h"
#include "luna.h"
#include "encoder.h"

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

