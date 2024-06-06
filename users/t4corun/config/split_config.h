#pragma once

/* Split keyboard
*
* https://docs.qmk.fm/#/feature_split_keyboard
* 
*/

//Clear variables we plan to use that might be set elsewhere
#undef SPLIT_TRANSPORT_MIRROR
#undef SPLIT_LAYER_STATE_ENABLE
#undef SPLIT_LED_STATE_ENABLE
#undef SPLIT_MODS_ENABLE
#undef SPLIT_OLED_ENABLE
#undef SPLIT_ACTIVITY_ENABLE
#undef SPLIT_USB_DETECT
#undef SPLIT_WPM_ENABLE

//Set common configuration for all keyboards
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_WPM_ENABLE

#define MASTER_RIGHT