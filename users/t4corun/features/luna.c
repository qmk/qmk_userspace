#include "luna.h"

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