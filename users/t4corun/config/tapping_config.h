#pragma once

/* Tapping, Oneshot
*
* https://docs.qmk.fm/#/tap_hold
* https://docs.qmk.fm/#/one_shot_keys
*
*/


//Clear variables we plan to use that might be set elsewhere
#undef TAP_CODE_DELAY
#undef TAP_HOLD_CAPS_DELAY

#undef TAPPING_TERM
#undef TAPPING_TERM_PER_KEY

#undef QUICK_TAP_TERM

#undef ONESHOT_TAP_TOGGLE
#undef ONESHOT_TIMEOUT


//Set common configuration for all keyboards
#define TAP_CODE_DELAY 5                    //time before tap is released
#define TAP_HOLD_CAPS_DELAY TAP_CODE_DELAY  //turning down delay for caps lock so ploopy can do DPI switching
#define WAIT_DELAY 5                        //custom variable to configure time between taps

#define TAPPING_TERM 175

#define QUICK_TAP_TERM 120

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2000