#include "oled64.h"

#if defined(WPM_ENABLE)
  #include "luna.c"
#endif


// Coordinate the OLED rendering
bool oled_task_user(void) {

  if (is_keyboard_master()) {
    /*
    oled_write_P(PSTR("123456789012345678901"), true);
    oled_write_ln_P(PSTR("2"), false);
    oled_write_ln_P(PSTR("3"), false);
    oled_write_ln_P(PSTR("4"), false);
    oled_write_ln_P(PSTR("5"), false);
    oled_write_ln_P(PSTR("6"), false);
    oled_write_ln_P(PSTR("7"), false);
    oled_write_ln_P(PSTR("8"), false);
    //oled_write_ln_P(PSTR("9"), false);
*/

#if defined(WPM_ENABLE)
    render_luna();
#endif

  } else {
    oled_write_raw_P(klor_face, sizeof(klor_face));
  }

  return false;

}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  
  //OLED_ROTATION_270 for Rollow/Corne/Swoop
  //OLED_ROTATION_180 for KLOR

  return OLED_ROTATION_270;

}
