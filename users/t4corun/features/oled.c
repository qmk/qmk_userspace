#include "oled.h"

#if defined(WPM_ENABLE)
  #include "luna.c"
#endif


// Shows the currently enabled Layer name
void render_layer_state(void) {

  switch (get_highest_layer(layer_state)) {
    case _NAVIGATION:
      oled_write_P(PSTR(OLED_RENDER_LAYER_2), false);
      break;
    case _NUMBER:
      oled_write_P(PSTR(OLED_RENDER_LAYER_3), false);
      break;
    case _SYMBOL:
      oled_write_P(PSTR(OLED_RENDER_LAYER_4), false);
      break;
    case _CONFIG:
      oled_write_P(PSTR(OLED_RENDER_LAYER_5), false);
      break;
    default:
      switch (get_highest_layer(default_layer_state)) {
        case _DEFAULT_LAYER_2:
          oled_write_P(PSTR(OLED_RENDER_DEFAULT_LAYER2), false);
          break;
        case _DEFAULT_LAYER_3:
          oled_write_P(PSTR(OLED_RENDER_DEFAULT_LAYER3), false);
          break;
        default:
          oled_write_P(PSTR(OLED_RENDER_DEFAULT_LAYER1), false);
          break;
      }
      break;
  }

}

// Graphic to show which layer on the stack is enabled
void render_layer_state_graphic(void) {

  switch (get_highest_layer(layer_state)) {
    case _NAVIGATION:
      oled_write_P(lyr_nav, false );
      break;
    case _NUMBER:
      oled_write_P(lyr_num, false );
      break;
    case _SYMBOL:
      oled_write_P(lyr_sym, false );
      break;
    case _CONFIG:
      oled_write_P(lyr_cfg, false );
      break;
    default:
      oled_write_P(lyr_def, false );
      break;
  }

}

// Shows the Host LED State (Num lock, caps lock , scroll lock)
void render_keylock_status(bool vertical) {

  if (vertical) {
    oled_write_ln_P(PSTR(OLED_RENDER_KEYLOCK_NAME), false);
    oled_write_P(PSTR(" "), false);
  }

  host_keyboard_led_state().num_lock ? oled_write_P(num_on, false ) : oled_write_P(num_off, false );
  host_keyboard_led_state().caps_lock || is_caps_word_on() ? oled_write_P(caps_on, false ) : oled_write_P(caps_off, false );
  host_keyboard_led_state().scroll_lock ? oled_write_P(scroll_on, false ) : oled_write_P(scroll_off, false );

}

// Indicates which modifies are enabled
void render_mod_status(bool vertical) {

  uint8_t current_mod = get_mods();
  uint8_t current_osm = get_oneshot_mods();

  if (vertical) {
    oled_write_ln_P(PSTR(OLED_RENDER_MODS_NAME), false);
    oled_write_P(PSTR(" "), false);
  }

  (current_mod | current_osm) & MOD_MASK_SHIFT ? oled_write_P(shift_on, false) : oled_write_P(shift_off, false );
  (current_mod | current_osm) & MOD_MASK_CTRL ? oled_write_P(ctrl_on, false ) : oled_write_P(ctrl_off, false );

  if (vertical) {
    oled_write_P(PSTR(" "), false);
  }

  (current_mod | current_osm) & MOD_MASK_ALT ? oled_write_P(alt_on, false ): oled_write_P(alt_off, false );
  (current_mod | current_osm) & MOD_MASK_GUI ? oled_write_P(gui_on, false ): oled_write_P(gui_off, false );

}


// Indicates which features are turned on or off
void render_feature_status(bool vertical) {

  if (vertical) {
    oled_write_ln_P(PSTR(OLED_RENDER_FEATURE_NAME), false);
    oled_write_P(PSTR(" "), false);
  }


#if defined(RGB_MATRIX_ENABLE)
  rgb_matrix_is_enabled() ? oled_write_P(rgb_on, false) : oled_write_P(rgb_off, false);
#else
  oled_write_P(rgb_off, false);
#endif //RGB_MATRIX_ENABLED

  // only works on master side
  drag_scroll_is_enabled() ? oled_write_P(dragscr_on, false) : oled_write_P(dragscr_off, false);

  if (vertical) {
    oled_write_P(PSTR(" "), false);
  }

#if defined(AUDIO_ENABLE)
  is_audio_on() ? oled_write_P(sound_on, false) : oled_write_P(sound_off, false);
#else
  oled_write_P(sound_off, false);
#endif //AUDIO_ENABLE

#if defined(HAPTIC_ENABLE)
  haptic_get_enable() ? oled_write_P(haptic_on, false) : oled_write_P(haptic_off, false);
#else
  oled_write_P(haptic_off, false);
#endif //HAPTIC_ENABLE

}


// Coordinate the OLED rendering
bool oled_task_user(void) {

#if defined(OLED_DISPLAY_128X64)
  
  if (is_keyboard_master()) {

    oled_set_cursor(0,0);
    render_layer_state();

    oled_set_cursor(0,1);
    oled_write_P(sep_v, false);

    oled_set_cursor(0,4);
    render_mod_status(false);

    oled_set_cursor(0,5);
    oled_write_P(sep_v, false);

    oled_set_cursor(0,7);
    render_keylock_status(false);

    oled_set_cursor(13,7);
    render_feature_status(false);

    oled_set_cursor(15,3);
    oled_write_P(klor_small_face_1, false);

    oled_set_cursor(15,4);
    oled_write_P(klor_small_face_2, false);
  } else {

    oled_set_cursor(0,0);
    oled_write_raw_P(klor_face, sizeof(klor_face));

  }

#else
  //process_record_user is only processed on master side
  //split side OLED does not respond to key presses custom behaviors
  if (is_keyboard_master()) {

    oled_set_cursor(0,0);
    render_keylock_status(true);

    oled_set_cursor(0,3);
    render_feature_status(true);

#if defined(WPM_ENABLE)

    oled_set_cursor(0,7);
    oled_write_P(PSTR(OLED_RENDER_WPM_NAME), false);

    oled_set_cursor(1,8);
    oled_write_P(get_u8_str(get_current_wpm(), ' '), false);

    render_luna();

#endif //WPM_ENABLE

  } else {

    oled_set_cursor(0,0);
    render_layer_state();

    oled_set_cursor(0,2);
    render_layer_state_graphic();

    oled_set_cursor(0,7);
    render_mod_status(true);

    oled_set_cursor(0,13);
    oled_write_P(qmk_logo_small, false);
  }

#endif

  return false;

}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  
  //OLED_ROTATION_270 for Rollow/Corne/Swoop
  //OLED_ROTATION_180 for KLOR

#if defined(OLED_DISPLAY_128X64)
  return OLED_ROTATION_180;
#else
  return OLED_ROTATION_270;
#endif

}
