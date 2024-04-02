#pragma once

/*
https://docs.qmk.fm/#/feature_split_keyboard

*/

#undef SPLIT_TRANSPORT_MIRROR
#undef SPLIT_LAYER_STATE_ENABLE
#undef SPLIT_LED_STATE_ENABLE
#undef SPLIT_MODS_ENABLE
#undef SPLIT_USB_DETECT

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
//#   define SPLIT_USB_DETECT

#define MASTER_RIGHT