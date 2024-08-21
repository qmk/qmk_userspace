#include "oled.h"

#if defined(WPM_ENABLE)
  #include "luna.c"
#endif


// Shows the currently enabled Layer name
void render_default_layer_state (uint8_t col, uint8_t line, bool moveCursor) {
  if(moveCursor) {
    oled_set_cursor(col, line);
  }

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
}


// Shows the currently enabled Layer name
// This only shows the name that is enabled
void render_layer_state (uint8_t col, uint8_t line, bool moveCursor) {
  if(moveCursor) {
    oled_set_cursor(col, line);
  }

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
    case _MOUSE_FUNC:
      oled_write_P(PSTR(OLED_RENDER_LAYER_5), false);
      break;
    default:
      oled_write_P(PSTR(OLED_RENDER_LAYER_1), false);
      break;
  }
}


// Shows the currently enabled Layer name
// Renders a list of all the layers and highlights the active one
void render_layer_state_list (uint8_t col, uint8_t line, bool moveCursor) {
  if(moveCursor) {
    oled_set_cursor(col, line);
  }

  uint8_t current_layer = get_highest_layer(layer_state);

  oled_write_P(PSTR(OLED_RENDER_LAYER_2), current_layer == _NAVIGATION);
  oled_write_P(PSTR(OLED_RENDER_LAYER_3), current_layer == _NUMBER);
  oled_write_P(PSTR(OLED_RENDER_LAYER_4), current_layer == _SYMBOL);
  oled_write_P(PSTR(OLED_RENDER_LAYER_5), current_layer == _MOUSE_FUNC);
}



// Shows the Host LED State (Num lock, caps lock , scroll lock)
void render_lock_status (uint8_t col, uint8_t line) {
  oled_set_cursor(col, line);
  host_keyboard_led_state().num_lock ? oled_write_P(num_on, false ) : oled_write_P(num_off, false );
  host_keyboard_led_state().caps_lock || is_caps_word_on() ? oled_write_P(caps_on, false ) : oled_write_P(caps_off, false );
  host_keyboard_led_state().scroll_lock ? oled_write_P(scroll_on, false ) : oled_write_P(scroll_off, false );
}


// Indicates which modifies are enabled
void render_mod_status (uint8_t col, uint8_t line) {
  uint8_t current_mods = get_mods() | get_oneshot_mods();

  // draw the top line
  oled_set_cursor(col, line);
  current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_upper, false) : oled_write_P(shift_off_upper, false );
  oled_write_P(mod_sep, false);
  current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_upper, false ) : oled_write_P(ctrl_off_upper, false );
  oled_write_P(mod_sep, false);
  current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_upper, false ) : oled_write_P(alt_off_upper, false );
  oled_write_P(mod_sep, false);
  current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_upper, false ) : oled_write_P(gui_off_upper, false );

  // draw the lower line
  oled_set_cursor(col, line + 1);
  current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_lower, false) : oled_write_P(shift_off_lower, false );
  oled_write_P(mod_sep, false);
  current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_lower, false ) : oled_write_P(ctrl_off_lower, false );
  oled_write_P(mod_sep, false);
  current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_lower, false ) : oled_write_P(alt_off_lower, false );
  oled_write_P(mod_sep, false);
  current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_lower, false ) : oled_write_P(gui_off_lower, false );
}


// Indicates which modifies are enabled
void render_mod_status_vertical (uint8_t col, uint8_t line) {
  uint8_t current_mods = get_mods() | get_oneshot_mods();

  oled_set_cursor(col,line);
  current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_upper, false) : oled_write_P(shift_off_upper, false );
  oled_set_cursor(col,line+1);
  current_mods & MOD_MASK_SHIFT ? oled_write_P(shift_on_lower, false) : oled_write_P(shift_off_lower, false );

  oled_set_cursor(col,line+3);
  current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_upper, false ) : oled_write_P(ctrl_off_upper, false );
  oled_set_cursor(col,line+4);
  current_mods & MOD_MASK_CTRL ? oled_write_P(ctrl_on_lower, false ) : oled_write_P(ctrl_off_lower, false );

  oled_set_cursor(col,line+6);
  current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_upper, false ) : oled_write_P(alt_off_upper, false );
  oled_set_cursor(col,line+7);
  current_mods & MOD_MASK_ALT ? oled_write_P(alt_on_lower, false ) : oled_write_P(alt_off_lower, false );

  oled_set_cursor(col,line+9);
  current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_upper, false ) : oled_write_P(gui_off_upper, false );
  oled_set_cursor(col,line+10);
  current_mods & MOD_MASK_GUI ? oled_write_P(gui_on_lower, false ) : oled_write_P(gui_off_lower, false );
}

void render_feature_status (uint8_t col, uint8_t line) {
  oled_set_cursor(col,line);
#if defined(RGB_MATRIX_ENABLE)
  rgb_matrix_is_enabled() ? oled_write_P(rgb_matrix_on, false) : oled_write_P(rgb_matrix_off, false);
#else
  oled_write_P(rgb_matrix_off, false);
#endif //RGB_MATRIX_ENABLED

  oled_set_cursor(col+3,line);
#if defined(AUDIO_ENABLE)
  is_audio_on() ? oled_write_P(sound_on, false) : oled_write_P(sound_off, false);
#else
  oled_write_P(sound_off, false);
#endif //AUDIO_ENABLE

  oled_set_cursor(col+6,line);
#if defined(HAPTIC_ENABLE)
  haptic_get_enable() ? oled_write_P(haptic_on, false) : oled_write_P(haptic_off, false);
#else
  oled_write_P(haptic_off, false);
#endif //HAPTIC_ENABLE
}

void render_klor_face_small (uint8_t col, uint8_t line) {
  oled_set_cursor(col,line);
  oled_write_P(klor_small_face_1, false);

  oled_set_cursor(col,line+1);
  oled_write_P(klor_small_face_2, false);
}

void render_oled_32x128 (void) {
  //process_record_user is only processed on master side
  //split side OLED does not respond to key presses custom behaviors
  if (is_keyboard_master()) {
    render_default_layer_state(0,1,true);
    render_layer_state_list(0,2,true);
#if defined(WPM_ENABLE)
    render_luna();
#endif //WPM_ENABLE
  } else {
    render_mod_status_vertical(1,1);
    render_lock_status(1,14);
  }
}


// 21 x 8
void render_oled_128x64 (void) {
  if (is_keyboard_master()) {

/*
base lyr: current lyr
---------------------
                     
 mod  mod  mod  mod  
 mod  mod  mod  mod  
                     
-------------- xxxxx 
 NCS xx xx xx  xxxxx 
*/
    render_default_layer_state(0,0, true);
    render_layer_state(0,0, false);

    oled_set_cursor(0,1);
    oled_write_P(sep_v, false);

    render_mod_status(1,3);

    oled_set_cursor(0,6);
    oled_write_P(sep_short_v, false);

    render_lock_status(1,7);
    render_feature_status(5,7);
    render_klor_face_small(15,6);
  } else {
    oled_set_cursor(0,0);
    oled_write_raw_P(klor_face, sizeof(klor_face));
  }
}


// Coordinate the OLED rendering
bool oled_task_user (void) {
#if defined(OLED_DISPLAY_128X64)
  render_oled_128x64();
#else
  render_oled_32x128();
#endif
  return false;
}

oled_rotation_t oled_init_user (oled_rotation_t rotation) {
#if defined(OLED_DISPLAY_128X64)
  //OLED_ROTATION_180 for KLOR
  return OLED_ROTATION_180;
#else
  //OLED_ROTATION_270 for Rollow/Corne/Swoop
  return OLED_ROTATION_270;
#endif
}
