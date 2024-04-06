#include "oled.h"

void render_crkbd_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
  oled_write_P(crkbd_logo, false);
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
  oled_write_P(PSTR(OLED_RENDER_LAYER_NAME), false);
  oled_write_P(PSTR(OLED_RENDER_LAYER_BASE), get_highest_layer(layer_state) == FIRST_DEFAULT_LAYER);  
  oled_write_P(PSTR(OLED_RENDER_LAYER_NAVIGATION), get_highest_layer(layer_state) == _NAVIGATION);
  oled_write_P(PSTR(OLED_RENDER_LAYER_NUMBER), get_highest_layer(layer_state) == _NUMBER);
  oled_write_P(PSTR(OLED_RENDER_LAYER_SYMBOL), get_highest_layer(layer_state) == _SYMBOL);

#if defined(MOUSEKEY_ENABLE)
  oled_write_P(PSTR(OLED_RENDER_LAYER_MOUSE), get_highest_layer(layer_state) == _MOUSE);
#endif //MOUSEKEY_ENABLE

  oled_write_P(PSTR(OLED_RENDER_LAYER_GAME_NUM), get_highest_layer(layer_state) == _GAME_NUM);
  oled_write_P(PSTR(OLED_RENDER_LAYER_CONFIG), get_highest_layer(layer_state) == _CONFIG);
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
    render_crkbd_logo();
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