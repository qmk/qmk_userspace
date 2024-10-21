// vim: tabstop=2:softtabstop=2:shiftwidth=2
#pragma once

// Tap hold configuration
#define TAPPING_TERM 170

// Tapping a One Shot key 2 times will hold the key until tapped once again.
// When combined with one-shot Shifts, it is a nice alternative for Caps Lock
#define ONESHOT_TAP_TOGGLE 2

#ifdef CAPS_WORD_ENABLE
// Pressing Shift with caps word active will invert the state, allowing us to uncapitalize a single letter
#define CAPS_WORD_INVERT_ON_SHIFT
// Turn caps word off if no keys have been pressed after 3s
#define CAPS_WORD_IDLE_TIMEOUT 3000
#endif
