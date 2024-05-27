#include "oled.h"

void render_crkbd_logo(void) {

  oled_write_P(crkbd_logo, false);

}

void render_rollow_logo(void) {

  oled_write_raw_P(rollow_logo, sizeof(rollow_logo));

}

void render_qmk_logo(void) {

  oled_write_raw_P(qmk_logo, sizeof(qmk_logo));

}

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

}


void render_keylock_status(void) {

  oled_write_ln_P(PSTR(OLED_RENDER_KEYLOCK_NAME), false);
  oled_write_P(PSTR(" "), false);

  if( host_keyboard_led_state().num_lock ) {
    oled_write_P(num_on, false );
  }else {
    oled_write_P(num_off, false );
  }

  if( host_keyboard_led_state().caps_lock || is_caps_word_on() ) {
    oled_write_P(caps_on, false );
  }else {
    oled_write_P(caps_off, false );
  }

  if( host_keyboard_led_state().scroll_lock ) {
    oled_write_ln_P(scroll_on, false );
  }else {
    oled_write_ln_P(scroll_off, false );
  }

}


void render_mod_status(void) {

  uint8_t current_mod = get_mods();
  uint8_t current_osm = get_oneshot_mods();

  oled_write_ln_P(PSTR(OLED_RENDER_MODS_NAME), false);
  oled_write_P(PSTR(" "), false);

  if( (current_mod | current_osm) & MOD_MASK_SHIFT ) {
    oled_write_P(shift_on, false );
  }else {
    oled_write_P(shift_off, false );
  }

  if( (current_mod | current_osm) & MOD_MASK_CTRL ) {
    oled_write_P(ctrl_on, false );
  }else {
    oled_write_P(ctrl_off, false );
  }

  if( (current_mod | current_osm) & MOD_MASK_ALT ) {
    oled_write_P(alt_on, false );
  }else {
    oled_write_P(alt_off, false );
  }

  if( (current_mod | current_osm) & MOD_MASK_GUI ) {
    oled_write_P(gui_on, false );
  }else {
    oled_write_P(gui_off, false );
  }

}

void render_feature_status(void) {

oled_write_ln_P(PSTR(OLED_RENDER_FEATURE_NAME), false);

#if defined(RGB_MATRIX_ENABLE)
  if (rgb_matrix_is_enabled()) { 
    oled_write_P(rgb_on, false);
  } else {
    oled_write_P(rgb_off, false);
  }
#else
  oled_write_P(rgb_off, false);
#endif

oled_write_P(PSTR(" "), false);

#if defined(AUDIO_ENABLE)
  if (is_audio_on()) { 
    oled_write_P(audio_on, false);
  } else {
    oled_write_P(audio_off, false);
  }

#else
  oled_write_P(audio_off, false);
#endif //AUDIO_ENABLE

#if defined(HAPTIC_ENABLE)
  if (haptic_get_enable()) { 
    oled_write_P(haptic_on, false);
  } else {
    oled_write_P(haptic_off, false);
  }

#else
  oled_write_P(haptic_off, false);
#endif //AUDIO_ENABLE

}


void render_oled_main(void) {

  render_default_layer_state();
  render_layer_state();
  
  oled_write_ln_P(PSTR(" "), false);
  render_keylock_status();

  oled_write_ln_P(PSTR(" "), false);
  render_mod_status();

  oled_write_ln_P(PSTR(" "), false);
  render_feature_status();

}


bool oled_task_user(void) {

  if (is_keyboard_master()) {
    render_oled_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {

#if defined(KEYBOARD_barbellboards_rollow)
    render_rollow_logo();
#elif defined(KEYBOARD_crkbd)
    render_crkbd_logo();
#else
    render_qmk_logo();
#endif

  }

  return false;

}



oled_rotation_t oled_init_user(oled_rotation_t rotation) {

#if !defined(KEYBOARD_klor_2040)
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
#endif

  return OLED_ROTATION_0;

}
