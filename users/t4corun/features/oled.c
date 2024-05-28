#include "oled.h"

/* LUNA PET START */

#if defined(WPM_ENABLE)

static uint32_t luna_anim_timer = 0;
static uint8_t luna_current_frame = 0;

void render_luna(void) {

#if OLED_TIMEOUT > 0
  // the animation prevents the normal timeout from occuring
  if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return;
  } else {
    oled_on();
  }
#endif //OLED_TIMEOUT

  if (timer_elapsed32(luna_anim_timer) > OLED_LUNA_ANIM_FRAME_DURATION) {
    luna_anim_timer = timer_read32();
    animate_luna(OLED_LUNA_X, OLED_LUNA_Y);
  }

}

void animate_luna(int LUNA_X, int LUNA_Y) {

  uint8_t current_mod = get_mods();
  uint8_t current_osm = get_oneshot_mods();

  // Make Luna Jump when spacebar is pressed
  // Only works when Luna is rendered on Master Slide
  if (isLunaJumping() || !isJumpShown()) {
    /* clear */
    oled_set_cursor(LUNA_X, LUNA_Y + 2);
    oled_write("     ", false);
    oled_set_cursor(LUNA_X, LUNA_Y - 1);

    setLunaJumped();
  } else {
    /* clear */
    oled_set_cursor(LUNA_X, LUNA_Y - 1);
    oled_write("     ", false);
    oled_set_cursor(LUNA_X, LUNA_Y);
  }

  luna_current_frame = (luna_current_frame + 1) % 2;

  // Animate based on status
  if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {

    oled_write_raw_P(bark[luna_current_frame], OLED_LUNA_ANIM_SIZE);

  } else if ((current_mod | current_osm) & MOD_MASK_CTRL) {

    oled_write_raw_P(sneak[luna_current_frame], OLED_LUNA_ANIM_SIZE);

  } else if (get_current_wpm() <= OLED_LUNA_MIN_WALK_SPEED) {

    oled_write_raw_P(sit[luna_current_frame], OLED_LUNA_ANIM_SIZE);

  } else if (get_current_wpm() <= OLED_LUNA_MIN_RUN_SPEED) {

    oled_write_raw_P(walk[luna_current_frame], OLED_LUNA_ANIM_SIZE);

  } else {

    oled_write_raw_P(run[luna_current_frame], OLED_LUNA_ANIM_SIZE);

  }

}

#endif //WPM_ENABLE

/* KEYBOARD PET END */




// Prints the current base layer
// (e.g. Qwerty, Colemak DH, etc)
void render_default_layer_state(void) {

  switch (get_highest_layer(default_layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR(OLED_RENDER_LAYOUT_QWERTY), false);
      break;
    case _COLEMAK_DH:
      oled_write_P(PSTR(OLED_RENDER_LAYOUT_COLEMAK_DH), false);
      break;
    case _GAME:
      oled_write_ln_P(PSTR(OLED_RENDER_LAYOUT_GAME), false);
      break;
  }

}

// Shows the currently enabled Layer name
// Also shows where on the layer stack it is
void render_layer_state(void) {

  switch (get_highest_layer(layer_state)) {
    case _NAVIGATION:
      oled_write_ln_P(PSTR(OLED_RENDER_LAYER_NAVIGATION), false);
      break;
    case _NUMBER:
      oled_write_ln_P(PSTR(OLED_RENDER_LAYER_NUMBER), false);
      break;
    case _SYMBOL:
      oled_write_ln_P(PSTR(OLED_RENDER_LAYER_SYMBOL), false);
      break;
    case _CONFIG:
      oled_write_ln_P(PSTR(OLED_RENDER_LAYER_CONFIG), false);
      break;
    default:
      oled_write_ln_P(PSTR(OLED_RENDER_LAYER_BASE), false);
      break;
  }

  oled_write_ln_P(PSTR(" "),false);
 
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
void render_keylock_status(void) {

  oled_write_ln_P(PSTR(OLED_RENDER_KEYLOCK_NAME), false);
  oled_write_P(PSTR(" "), false);

  host_keyboard_led_state().num_lock ? oled_write_P(num_on, false ) : oled_write_P(num_off, false );
  host_keyboard_led_state().caps_lock || is_caps_word_on() ? oled_write_P(caps_on, false ) : oled_write_P(caps_off, false );
  host_keyboard_led_state().scroll_lock ? oled_write_ln_P(scroll_on, false ) : oled_write_ln_P(scroll_off, false );

}


// Indicates which modifies are enabled
void render_mod_status(void) {

  uint8_t current_mod = get_mods();
  uint8_t current_osm = get_oneshot_mods();

  oled_write_ln_P(PSTR(OLED_RENDER_MODS_NAME), false);
  oled_write_P(PSTR(" "), false);

  (current_mod | current_osm) & MOD_MASK_SHIFT ? oled_write_P(shift_on, false) : oled_write_P(shift_off, false );
  (current_mod | current_osm) & MOD_MASK_CTRL ? oled_write_P(ctrl_on, false ) : oled_write_P(ctrl_off, false );

  oled_write_P(PSTR(" "), false);

  (current_mod | current_osm) & MOD_MASK_ALT ? oled_write_P(alt_on, false ): oled_write_P(alt_off, false );
  (current_mod | current_osm) & MOD_MASK_GUI ? oled_write_P(gui_on, false ): oled_write_P(gui_off, false );

}

// Indicates which features are turned on or off
void render_feature_status(void) {

oled_write_ln_P(PSTR(OLED_RENDER_FEATURE_NAME), false);
oled_write_P(PSTR(" "), false);

#if defined(RGB_MATRIX_ENABLE)
  rgb_matrix_is_enabled() ? oled_write_P(rgb_on, false) : oled_write_P(rgb_off, false);
#else
  oled_write_P(rgb_off, false);
#endif //RGB_MATRIX_ENABLED

  // only works on master side
  drag_scroll_is_enabled() ? oled_write_P(dragscr_on, false) : oled_write_P(dragscr_off, false);

  oled_write_P(PSTR(" "), false);

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

  //process_record_user is only processed on master side
  //split side OLED does not respond to key presses custom behaviors
  if (is_keyboard_master()) {

    render_keylock_status();

    oled_write_ln_P(PSTR(" "), false);
    render_feature_status();

#if defined(WPM_ENABLE)
    oled_write_ln_P(PSTR(" "), false);
    oled_write_ln_P(PSTR(OLED_RENDER_WPM_NAME), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(get_u8_str(get_current_wpm(), ' '), false);

    render_luna();
#endif //WPM_ENABLE

  } else {

    render_default_layer_state();
    render_layer_state();

    oled_write_ln_P(PSTR(" "), false);
    render_mod_status();

    oled_write_ln_P(PSTR(" "), false);
    oled_write_P(qmk_logo_small, false);
  }

  return false;

}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}
