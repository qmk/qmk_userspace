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
const key_override_t media_next_override = ko_make_basic(MOD_MASK_SHIFT, KC_MNXT, KC_MPRV);

const key_override_t **key_overrides = (const key_override_t *[]){

  &delete_override,
  &media_next_override,
  NULL // Null terminate the array of overrides!

};