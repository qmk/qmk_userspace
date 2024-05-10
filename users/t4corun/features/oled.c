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

  oled_write_P(PSTR(OLED_RENDER_LAYOUT_NAME), false);

  switch (get_highest_layer(default_layer_state)) {

    case _QWERTY:
      oled_write_P(PSTR(OLED_RENDER_LAYOUT_QWERTY), false);
      break;
    
    case _COLEMAK_DH:
      oled_write_P(PSTR(OLED_RENDER_LAYOUT_COLEMAK_DH), false);
      break;

    case _GAME:
      oled_write_P(PSTR(OLED_RENDER_LAYOUT_GAME), false);
      break;

  }

}


void render_layer_state(void) {

  oled_write_P(PSTR(OLED_RENDER_LAYER_NAME),       false);
  oled_write_P(PSTR(OLED_RENDER_LAYER_BASE),       get_highest_layer(layer_state) == FIRST_DEFAULT_LAYER);  
  oled_write_P(PSTR(OLED_RENDER_LAYER_NAVIGATION), get_highest_layer(layer_state) == _NAVIGATION);
  oled_write_P(PSTR(OLED_RENDER_LAYER_NUMBER),     get_highest_layer(layer_state) == _NUMBER);
  oled_write_P(PSTR(OLED_RENDER_LAYER_SYMBOL),     get_highest_layer(layer_state) == _SYMBOL);
  //oled_write_P(PSTR(OLED_RENDER_LAYER_FUNCTION),   get_highest_layer(layer_state) == _FUNCTION);
  oled_write_P(PSTR(OLED_RENDER_LAYER_CONFIG),     get_highest_layer(layer_state) == _CONFIG);

}


void render_keylock_status(void) {

  oled_write_P(PSTR(OLED_RENDER_KEYLOCK_NAME), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("N"), host_keyboard_led_state().num_lock);
  oled_write_P(PSTR("C"), host_keyboard_led_state().caps_lock || is_caps_word_on() );
  oled_write_ln_P(PSTR("S"), host_keyboard_led_state().scroll_lock );

}


void render_mod_status(void) {

  uint8_t current_mod = get_mods();
  uint8_t current_osm = get_oneshot_mods();

  oled_write_P(PSTR(OLED_RENDER_MODS_NAME), false);
  oled_write_P(PSTR(" "), false);

  bool isShift = (current_mod | current_osm) & MOD_MASK_SHIFT;
  bool isCtrl  = (current_mod | current_osm) & MOD_MASK_CTRL;
  bool isAlt   = (current_mod | current_osm) & MOD_MASK_ALT;
  bool isGUI   = (current_mod | current_osm) & MOD_MASK_GUI;

  oled_write_P(PSTR("S"), isShift );
  oled_write_P(PSTR("C"), isCtrl );
  oled_write_P(PSTR("A"), isAlt );
  oled_write_P(PSTR("G"), isGUI );  

}


void render_oled_main(void) {

  render_default_layer_state();
  render_keylock_status();
  render_mod_status();
  render_layer_state();

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

  if (is_keyboard_master()) {

    return OLED_ROTATION_270;

  } else {

    return OLED_ROTATION_0;

  }

}