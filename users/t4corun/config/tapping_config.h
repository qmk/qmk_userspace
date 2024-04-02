#pragma once

/*
https://docs.qmk.fm/#/tap_hold
https://docs.qmk.fm/#/one_shot_keys
*/


//Clear variables we plan to use that might be set elsewhere
#undef TAP_CODE_DELAY
#undef TAP_HOLD_CAPS_DELAY

#undef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#undef TAPPING_TERM
#undef TAPPING_TERM_PER_KEY
#undef QUICK_TAP_TERM
#undef QUICK_TAP_TERM_PER_KEY

#undef ONESHOT_TAP_TOGGLE
#undef ONESHOT_TIMEOUT


//Set common configuration for all keyboards
#define TAP_CODE_DELAY 5                    //time before tap is released
#define TAP_HOLD_CAPS_DELAY TAP_CODE_DELAY  //turning down delay for caps lock so ploopy can do DPI switching
#define WAIT_DELAY 5                        //custom variable to configure time between taps

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define QUICK_TAP_TERM 100
#define QUICK_TAP_TERM_PER_KEY

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 2000