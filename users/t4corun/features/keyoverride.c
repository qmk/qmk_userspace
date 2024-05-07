#include "keyoverride.h"

const key_override_t delete_override    = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t medianext_override = ko_make_basic(MOD_MASK_SHIFT, KC_MNXT, KC_MPRV);


const key_override_t **key_overrides = (const key_override_t *[]){

    &delete_override,
    &medianext_override,
    NULL // Null terminate the array of overrides!

};