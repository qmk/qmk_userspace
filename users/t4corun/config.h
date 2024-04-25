/*
* Set build options for
* - consistent configuration across all keyboards
* - enable features specific to certain board (e.g. encoders, rgb, oled)
* - a way to save memory on MCU
*
* Pattern
* - This will hold config for features we force to be on
* - bring in additional configuration for features that can be enabled/disabled
* - clear and reset the setting
*/

#pragma once

//Turn off settings we won't use to save memory
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE



//Clear variables we plan to use that might be set elsewhere
#undef USB_POLLING_INTERVAL_MS

//Set common configuration for all keyboards
#define USB_POLLING_INTERVAL_MS 1





#include "config/tapping_config.h"

#if defined(CAPS_WORD_ENABLE)
#   include "config/capsword_config.h"
#endif

#if defined(RGB_MATRIX_ENABLE)
#   include "config/rgbmatrix_config.h"
#endif

#if defined(MOUSEKEY_ENABLE)
#   include "config/mouse_config.h"
#endif

#if defined(COMBO_ENABLE)
#   include "config/combo_config.h"
#endif

#if defined(SPLIT_KEYBOARD)
#	  include "config/split_config.h"
#endif

#if defined(OLED_ENABLE)
#	  include "config/oled_config.h"
#endif