#include "keyoverride.h"

//https://docs.qmk.fm/#/feature_key_overrides?id=simple-example

const key_override_t delete_override     = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t media_next_override = ko_make_basic(MOD_MASK_SHIFT, KC_MNXT, KC_MPRV);
const key_override_t at_sym_override     = ko_make_basic(MOD_MASK_SHIFT, KC_AT,   KC_AMPR);
const key_override_t exlm_sym_override   = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_DLR);
const key_override_t perc_sym_override   = ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_CIRC);
const key_override_t comm_sym_override   = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_LPRN);
const key_override_t dot_sym_override    = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_RPRN);


const key_override_t **key_overrides = (const key_override_t *[]){

  &delete_override,
  &media_next_override,
  &at_sym_override,
  &exlm_sym_override,
  &perc_sym_override,
  &comm_sym_override,
  &dot_sym_override,
  NULL // Null terminate the array of overrides!

};