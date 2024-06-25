#include "hoststateautomouse.h"


// keyboard side code to simulate auto mouse between ploopy nano and qmk keyboard
// nano pointer movement activates auto mouse layer, which toggles numlock
// when num lock is enabled, keyboard turns on mouse layer
bool led_update_user(led_t led_state) {
  if(host_keyboard_led_state().num_lock) {
    layer_on(_MOUSE);
  } else if (!host_keyboard_led_state().num_lock) {
    layer_off(_MOUSE);
  }

  return true;
}