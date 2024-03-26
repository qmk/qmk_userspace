#include QMK_KEYBOARD_H
#include "transactions.h"

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FUN,
    _MEDIA,
    _MOUSE,
    _NUM
};

enum custom_keycodes {
    QC_EGRV = SAFE_RANGE,       // è
    QC_EAIG,                    // é
    QC_AGRV,                    // à
    QC_CCED,                    // ç
    QC_UGRV,                    // ù
    QC_ICRC,                    // î
    QC_OCRC,                    // ù
    KC_LEFT_ENC_MODE,           // left encoder mode
    KC_RIGHT_ENC_MODE,          // right encoder mode
    ALT_TAB,                    // alt-tab
    QC_QUOT                    // non-dead quotes
};

enum left_encoder_mode {
    LENC_VOL,                    // volume control
    LENC_WORD,                   // scroll horizontally by word
    LENC_NOOP
};

enum right_encoder_mode {
    RENC_TAB,                    // alt tabbing
    RENC_SCROLL,                 // mouse scroll
    RENC_PAGE,                   // scroll half pages
    RENC_NOOP
};

typedef struct _master_to_slave_t {
    bool is_sneaking;
    bool is_barking;
} master_to_slave_t;

enum left_encoder_mode left_encoder = LENC_VOL;
enum right_encoder_mode right_encoder = RENC_TAB;

// Alt tab on steroids
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// Luna behaviour
bool is_barking = false;
bool is_sneaking = false;
bool is_jumping = false;
bool showed_jump = true;

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define LALT_ENT MT(MOD_LALT, KC_ENT)
#define RALT_ENT MT(MOD_RALT, KC_ENT)
#define KC_LENC LT(0, KC_LEFT_ENC_MODE)
#define KC_RENC KC_RIGHT_ENC_MODE
#define SPC_SYM LT(_SYM, KC_SPC)
#define CUS_MEH MEH_T(MEH(KC_SPC))

// Custom actions
#define KC_COPY LCTL(KC_C)
#define KC_PAST LCTL(KC_V)
#define KC_CUT LCTL(KC_X)
#define KC_REDO LCTL(KC_Y)
#define KC_UNDO LCTL(KC_Z)

// Home row mods
#define HR_GA LGUI_T(KC_A)
#define HR_AR LALT_T(KC_R)
#define HR_CS LCTL_T(KC_S)
#define HR_ST LSFT_T(KC_T)
#define HR_SN LSFT_T(KC_N)
#define HR_CE LCTL_T(KC_E)
#define HR_AI LALT_T(KC_I)
#define HR_GO LGUI_T(KC_O)

// Thumb tap/hold
#define MEH_GUI MEH_T(KC_LGUI)
#define MED_ESC LT(_MEDIA, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define MOU_TAB LT(_MOUSE, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define FUN_DEL LT(_FUN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: Colemak DH
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |  - / _ |GUI/A |R/ALT |S/CTRL|T/SHFT|   G  |                              |   M  |N/SHFT|E/CTRL|I/ALT |O/GUI | ' / "  |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | Lalt / |   Z  |   X  |   C  |   D  |   V  | [ {  | LENC |  | RENC |  ] } |   K  |   H  | ,  < | . >  | /  ? |        |
     * | Enter  |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      | LGui |  Esc | Space| Tab  |  | Enter| Bspc |Delete|      |      |
     *                        |      | MEH  | Media| Nav  | Mouse|  |  Sym | Num  | Func |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_COLEMAK_DH] = LAYOUT(
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
      KC_MINS,   HR_GA,   HR_AR,   HR_CS,   HR_ST,    KC_G,                                        KC_M,   HR_SN,   HR_CE,   HR_AI,   HR_GO, QC_QUOT,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LBRC, KC_LENC, KC_RENC, KC_RBRC,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 XXXXXXX, KC_LGUI, MED_ESC, NAV_SPC, MOU_TAB, SYM_ENT, NUM_BSP, FUN_DEL, CUS_MEH, XXXXXXX
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
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_REDO, KC_PAST, KC_COPY, KC_CUT, KC_UNDO, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, KC_COPY, XXXXXXX, KC_PAST, XXXXXXX, _______, _______, XXXXXXX,  KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
                                 _______, _______,  KC_ESC,  KC_SPC,  KC_TAB,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    ),

    /*
     * Mouse Layer: Media, navigation
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              | Redo | Paste| Copy | Cut  | Undo |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | LGui |  Alt | Ctrl | Shift|      |                              | Prev |Mouse←|Mouse↓|Mouse↑|Mouse→|        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      | Next | Scrl←| Scrl↓| Scrl↑| Scrl→|        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      | Esc  | Space| Tab  |  | Right| Left |Middle|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_MOUSE] = LAYOUT(
      XXXXXXX, _______, _______, _______, _______, _______,                                     KC_REDO, KC_PAST, KC_COPY, KC_CUT, KC_UNDO, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
      XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_BTN5, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                 _______, _______, _______, _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______
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
      XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
                left_encoder++;
                if (left_encoder == LENC_NOOP) {
                    left_encoder = 0;
                }
            } else if (record->event.pressed) {
                tap_code(KC_MUTE);
            }
            return false;
        case KC_RENC:
             if (record->event.pressed) {
                right_encoder++;
                if (right_encoder == RENC_NOOP) {
                    right_encoder = 0;
                }
            }
            return false;
        case CUS_MEH:
            if (record->tap.count && record->event.pressed) {
                register_code16(MEH(KC_SPC));
                unregister_code16(MEH(KC_SPC));
                break;
            }
        case ALT_TAB:
            if (record-> event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case QC_QUOT:
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_QUOTE));
                SEND_STRING(SS_TAP(X_SPC));
            }
            return false;
    }
    return true;
};

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

tap_dance_action_t tap_dance_actions[] = {};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

/**************** Encoder *****************/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // left
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
    } else if (index == 1) { // right
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
            case RENC_SCROLL:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                return false;
            default:
                return false;
        }
    }
    return false;
}

/**************** Oled *****************/
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 96

int current_wpm_luna = 0;

uint8_t current_frame = 0;

uint32_t anim_timer_luna = 0;
uint32_t anim_sleep = 0;

// Draw Luna on OLED
void render_luna(int LUNA_X, int LUNA_Y) {
    // Sit
    static const char PROGMEM sit[2][3][ANIM_SIZE/3] = {
        // 'sit1', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        },
        // 'sit2', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        }
   };

    // Walk
    static const char PROGMEM walk[2][3][ANIM_SIZE/3] = {
        // 'walk1', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        },
        // 'walk2', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        }
    };

    // Run
    static const char PROGMEM run[2][3][ANIM_SIZE/3] = {
        // 'run1', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00}
        },
        // 'run2', 32x22px
        {
            {0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        }
    };

    // Bark
    static const char PROGMEM bark[2][3][ANIM_SIZE/3] = {
        // 'bark1', 32x22px
        {
            {0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        },
        // 'bark2', 32x22px
        {
            {0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
        }
    };

    // Sneak
    static const char PROGMEM sneak[2][3][ANIM_SIZE/3] = {
        // 'sneak1', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00}
        },
        // 'sneak2', 32x22px
        {
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00},
            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}
        }
    };

    // Draw a frame - needed to draw on 3 different lines without having to store all blank spaces
    void draw_frame(const char  frame[3][ANIM_SIZE/3]) {
        oled_write("        ", false);
        oled_write_raw_P(frame[0], ANIM_SIZE/3);
        oled_advance_page(false);
        oled_write("        ", false);
        oled_write_raw_P(frame[1], ANIM_SIZE/3);
        oled_advance_page(false);
        oled_write("        ", false);
        oled_write_raw_P(frame[2], ANIM_SIZE/3);
    }

    // Handle animation
    void animation_phase(void) {
        // jump
        if (is_jumping || !showed_jump) {
            // clear
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showed_jump = true;
        } else {
            // clear
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        // switch frame
        current_frame = (current_frame + 1) % 2;

        // current status
        if (is_barking) {
            draw_frame(bark[abs(1 - current_frame)]);
        } else if (is_sneaking) {
            draw_frame(sneak[abs(1 - current_frame)]);
        } else if (current_wpm_luna <= MIN_WALK_SPEED) {
            draw_frame(sit[abs(1 - current_frame)]);
        } else if (current_wpm_luna <= MIN_RUN_SPEED) {
            draw_frame(walk[abs(1 - current_frame)]);
        } else {
            draw_frame(run[abs(1 - current_frame)]);
        }
    }

    // animation timer
    if (timer_elapsed32(anim_timer_luna) > ANIM_FRAME_DURATION) {
        anim_timer_luna = timer_read32();
        current_wpm_luna = get_current_wpm();
        animation_phase();
    }

    // this fixes the screen on and off bug
    if (current_wpm_luna > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}

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
            case _MOUSE:
                oled_write_P(PSTR("Mouse\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Num\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }


        oled_write_P(PSTR("Left: "), false);
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

        oled_write_P(PSTR("Right: "), false);
        switch (right_encoder) {
            case RENC_SCROLL:
                oled_write_P(PSTR("Mouse scroll\n"), false);
                break;
            case RENC_TAB:
                oled_write_P(PSTR("Alt - Tab\n"), false);
                break;
            case RENC_PAGE:
                oled_write_P(PSTR("Page scroll\n"), false);
                break;
            default:
                break;
        }
    } else {
        render_luna(0,1);
        oled_set_cursor(0,6);
        oled_write_P(PSTR("       WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}

/*** Custom data sync for OLED ***/
void user_sync_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    is_sneaking = m2s->is_sneaking;
    is_barking = m2s->is_barking;
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_LUNA, user_sync_slave_handler);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 50) {
            master_to_slave_t m2s = {
                get_mods() & MOD_MASK_CTRL,
                get_mods() & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock
            };
            if (transaction_rpc_send(USER_SYNC_LUNA, sizeof(m2s), &m2s)) {
                last_sync = timer_read32();
            };
        }
    }
}
