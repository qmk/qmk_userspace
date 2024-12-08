#include "struckmb.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Return after running through all individual hooks
    if (keycode <= NO_MODS && record->event.pressed) {
        switch (keycode) {
            case NO_MODS:
                clear_oneshot_mods();
                return false;
            case DL_PREV:
                if (get_highest_layer(default_layer_state) > 0) {
                    set_single_persistent_default_layer(get_highest_layer(default_layer_state) - 1);
                } else {
                    set_single_persistent_default_layer(LAYER_SYMBL - 1);
                }
                return false;
            case DL_NEXT:
                // uint8_t next_default_layer = get_highest_layer(default_layer_state) + 1;
                if (get_highest_layer(default_layer_state) + 1 < LAYER_SYMBL) {
                    set_single_persistent_default_layer(get_highest_layer(default_layer_state) + 1);
                } else {
                    set_single_persistent_default_layer(0);
                }
                return false;
        }
    }

#ifdef OS_DETECTION_ENABLE
    switch (detected_host_os()) {
        case OS_MACOS:
            switch (keycode) {
                case DE_RSQU: // '
                    if (record->event.pressed) {
                        register_code16(DE_QUOT);
                    } else {
                        unregister_code16(DE_QUOT);
                    }
                    return false;
                case KC_CUT:
                    if (record->event.pressed) {
                        register_code16(G(KC_X));
                    } else {
                        unregister_code16(G(KC_X));
                    }
                    return false;
                case KC_COPY:
                    if (record->event.pressed) {
                        register_code16(G(KC_C));
                    } else {
                        unregister_code16(G(KC_C));
                    }
                    return false;
                case KC_PSTE:
                    if (record->event.pressed) {
                        register_code16(G(KC_V));
                    } else {
                        unregister_code16(G(KC_V));
                    }
                    return false;
                case KC_BRIU:
                    if (record->event.pressed) {
                        register_code16(KC_BRMU);
                    } else {
                        unregister_code16(KC_BRMU);
                    }
                    return false;
                case KC_BRID:
                    if (record->event.pressed) {
                        register_code16(KC_BRMD);
                    } else {
                        unregister_code16(KC_BRMD);
                    }
                    return false;
            }
            break;

        case OS_LINUX:
        case OS_WINDOWS:
            switch (keycode) {
                case DE_AT: // @
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_Q));
                    } else {
                        unregister_code16(ALGR(DE_Q));
                    }
                    return false;
                case DE_ELLP: // …
                    if (record->event.pressed) {
                        register_code16(ALGR(KC_DOT));
                    } else {
                        unregister_code16(ALGR(KC_DOT));
                    }
                    return false;
                case DE_LBRC: // [
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_8));
                    } else {
                        unregister_code16(ALGR(DE_8));
                    }
                    return false;
                case DE_RBRC: // ]
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_9));
                    } else {
                        unregister_code16(ALGR(DE_9));
                    }
                    return false;
                case DE_BSLS: // "\"
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_SS));
                    } else {
                        unregister_code16(ALGR(DE_SS));
                    }
                    return false;
                case DE_LCBR: // {
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_7));
                    } else {
                        unregister_code16(ALGR(DE_7));
                    }
                    return false;
                case DE_RCBR: // }
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_0));
                    } else {
                        unregister_code16(ALGR(DE_0));
                    }
                    return false;
                case DE_PIPE: // |
                    if (record->event.pressed) {
                        register_code16(ALGR(KC_NUBS));
                    } else {
                        unregister_code16(ALGR(KC_NUBS));
                    }
                    return false;
                case DE_TILD: // ~
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_PLUS));
                    } else {
                        unregister_code16(ALGR(DE_PLUS));
                    }
                    return false;
                case DE_LDAQ: // «
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_X));
                    } else {
                        unregister_code16(ALGR(DE_X));
                    }
                    return false;
                case DE_RDAQ: // »
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_Y));
                    } else {
                        unregister_code16(ALGR(DE_Y));
                    }
                    return false;
                case DE_LSAQ: // ‹
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_X)));
                    } else {
                        unregister_code16(S(ALGR(DE_X)));
                    }
                    return false;
                case DE_RSAQ: // ›
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_Y)));
                    } else {
                        unregister_code16(S(ALGR(DE_Y)));
                    }
                    return false;
                case DE_PND: // £
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_3)));
                    } else {
                        unregister_code16(S(ALGR(DE_3)));
                    }
                    return false;
                case DE_CENT: // ¢
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_C));
                    } else {
                        unregister_code16(ALGR(DE_C));
                    }
                    return false;
                case DE_EURO: // €
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_E));
                    } else {
                        unregister_code16(ALGR(DE_E));
                    }
                    return false;
                case DE_IEXL: // ¡
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_1)));
                    } else {
                        unregister_code16(S(ALGR(DE_1)));
                    }
                    return false;
                case DE_SLQU: // ‚
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_V)));
                    } else {
                        unregister_code16(S(ALGR(DE_V)));
                    }
                    return false;
                case DE_NDSH: // –
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_MINS));
                    } else {
                        unregister_code16(ALGR(DE_MINS));
                    }
                    return false;
                case DE_MDSH: // —
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_MINS)));
                    } else {
                        unregister_code16(S(ALGR(DE_MINS)));
                    }
                    return false;
                case DE_LSQU: // ‘
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_B)));
                    } else {
                        unregister_code16(S(ALGR(DE_B)));
                    }
                    return false;
                case DE_RSQU: // ’
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_N)));
                    } else {
                        unregister_code16(S(ALGR(DE_N)));
                    }
                    return false;
                case DE_IQUE: // ¿
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_SS)));
                    } else {
                        unregister_code16(S(ALGR(DE_SS)));
                    }
                    return false;
                case DE_MDDT: // •
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_COMM));
                    } else {
                        unregister_code16(ALGR(DE_COMM));
                    }
                    return false;
                case DE_DIV: // ÷
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_DOT)));
                    } else {
                        unregister_code16(S(ALGR(DE_DOT)));
                    }
                    return false;
                case DE_PLMN: // ±
                    if (record->event.pressed) {
                        register_code16(S(ALGR(DE_9)));
                    } else {
                        unregister_code16(S(ALGR(DE_9)));
                    }
                    return false;
                case DE_DLQU: // „
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_V));
                    } else {
                        unregister_code16(ALGR(DE_V));
                    }
                    return false;
                case DE_LDQU: // “
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_B));
                    } else {
                        unregister_code16(ALGR(DE_B));
                    }
                    return false;
                case DE_RDQU: // ”
                    if (record->event.pressed) {
                        register_code16(ALGR(DE_N));
                    } else {
                        unregister_code16(ALGR(DE_N));
                    }
                    return false;
                case KC_CUT:
                    if (record->event.pressed) {
                        register_code16(S(KC_DEL));
                    } else {
                        unregister_code16(S(KC_DEL));
                    }
                    return false;
                case KC_COPY:
                    if (record->event.pressed) {
                        register_code16(C(KC_INS));
                    } else {
                        unregister_code16(C(KC_INS));
                    }
                    return false;
                case KC_PSTE:
                    if (record->event.pressed) {
                        register_code16(S(KC_INS));
                    } else {
                        unregister_code16(S(KC_INS));
                    }
                    return false;
            }
            break;

        default:
            // ???
            break;
    }
#endif /* ifdef OS_DETECTION_ENABLE */

    return
        //     process_record_keymap(keycode, record) &&
        // #ifdef ENCODER_ENABLE
        //            process_record_encoder(keycode, record) &&
        // #endif // ENCODER_ENABLE
        true;
}
