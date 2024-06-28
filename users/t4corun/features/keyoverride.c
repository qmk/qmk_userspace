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

#if defined(HAPTIC_ENABLE)
const key_override_t hfnext_override     = ko_make_with_layers(MOD_MASK_SHIFT, HF_NEXT, HF_PREV, 1<<_CONFIG);
const key_override_t hfconu_override     = ko_make_with_layers(MOD_MASK_SHIFT, HF_CONU, HF_COND, 1<<_CONFIG);
#endif //HAPTIC_ENABLE

#if defined(AUDIO_ENABLE)
const key_override_t ckup_override       = ko_make_with_layers(MOD_MASK_SHIFT, CK_UP,   CK_DOWN, 1<<_CONFIG);
#endif //AUDIO_ENABLE

const key_override_t **key_overrides = (const key_override_t *[]) {

  &delete_override,

#if defined(HAPTIC_ENABLE)
  &hfnext_override,
  &hfconu_override,
#endif //HAPTIC_ENABLE

#if defined(AUDIO_ENABLE)
  &ckup_override,
#endif //AUDIO_ENABLE

  NULL // Null terminate the array of overrides!

};