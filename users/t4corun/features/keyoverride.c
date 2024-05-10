#include "keyoverride.h"

/* 
Key Override
 Here we will override some shifted versions of keys
 https://docs.qmk.fm/#/feature_key_overrides?id=simple-example

Intentionally did not convert all the override/autoshit tap holds to this format
- Here I could type faster and be able to hold to repeat the keycodes however
- I had tons of same finger bigrams doing trying to get ~ and :
- I didn't feel the need to be able to repeat those symbols
*/


const key_override_t delete_override     = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t media_next_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MNXT, KC_MPRV, 1<<_NAVIGATION);

const key_override_t f1_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_1,    KC_F1,   1<<_NUMBER);
const key_override_t f2_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_2,    KC_F2,   1<<_NUMBER);
const key_override_t f3_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_3,    KC_F3,   1<<_NUMBER);
const key_override_t f4_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_4,    KC_F4,   1<<_NUMBER);
const key_override_t f5_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_5,    KC_F5,   1<<_NUMBER);
const key_override_t f6_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_6,    KC_F6,   1<<_NUMBER);
const key_override_t f7_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_7,    KC_F7,   1<<_NUMBER);
const key_override_t f8_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_8,    KC_F8,   1<<_NUMBER);
const key_override_t f9_override         = ko_make_with_layers(MOD_MASK_CSA,   KC_9,    KC_F9,   1<<_NUMBER);
const key_override_t f10_override        = ko_make_with_layers(MOD_MASK_CSA,   KC_COMM, KC_F10,  1<<_NUMBER);
const key_override_t f11_override        = ko_make_with_layers(MOD_MASK_CSA,   KC_DOT,  KC_F11,  1<<_NUMBER);
const key_override_t f12_override        = ko_make_with_layers(MOD_MASK_CSA,   TR_MINS, KC_F12,  1<<_NUMBER);

const key_override_t **key_overrides = (const key_override_t *[]) {

  &delete_override,
  &media_next_override,
  &f1_override,
  &f2_override,
  &f3_override,
  &f4_override,
  &f5_override,
  &f6_override,
  &f7_override,
  &f8_override,
  &f9_override,
  &f10_override,
  &f11_override,
  &f12_override,
  NULL // Null terminate the array of overrides!

};