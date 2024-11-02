#include "ncsibra.h"
#include "osl.h"
#include "tap_hold.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if keycode is ESC or at least contains ESC(in case of Mod Tap etc) and one shot modifier or one shot layer is active, then cancel
  if (record->event.pressed && OSK_ACTIVE() && ((keycode & 0xFF) == KC_ESC)) {
    layer_off(get_oneshot_layer());
    reset_oneshot_layer();
    clear_oneshot_mods();
    return false;
  }

  return process_record_user_taphold(keycode, record) &&
    process_record_user_osl(keycode, record);
};

void matrix_scan_user(void) {
    matrix_scan_tap_hold(HELD);
}
