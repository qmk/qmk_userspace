#pragma once

/* Combos
*
* https://docs.qmk.fm/#/feature_combo
*
*/

//Clear variables we plan to use that might be set elsewhere
#undef COMBO_ONLY_FROM_LAYER
#undef EXTRA_SHORT_COMBOS

#undef COMBO_TERM
#undef COMBO_TERM_PER_COMBO

#undef COMBO_HOLD_TERM
#undef COMBO_MUST_HOLD_PER_COMBO

#undef COMBO_MUST_TAP_PER_COMBO
#undef COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#undef COMBO_SHOULD_TRIGGER


//Set common configuration for all keyboards
#define COMBO_ONLY_FROM_LAYER 0 //this will always setup combos based off of QWERTY layout
#define EXTRA_SHORT_COMBOS

#define COMBO_TERM 35
#define COMBO_TERM_PER_COMBO

#define COMBO_HOLD_TERM TAPPING_TERM
#define COMBO_MUST_HOLD_PER_COMBO

#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#define COMBO_SHOULD_TRIGGER