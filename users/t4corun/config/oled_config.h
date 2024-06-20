#pragma once

/* OLED
*
* https://docs.qmk.fm/#/feature_oled_driver
* 
*/

//Clear variables we plan to use that might be set elsewhere
#undef OLED_TIMEOUT
#undef OLED_FONT_H

//Set common configuration for all keyboards
#define OLED_TIMEOUT 60000 //1 min

#if defined(OLED_DISPLAY_128X64)
#   define OLED_FONT_H "./lib/font.c"
#else
#   define OLED_FONT_H "./lib/font_narrow.c"
#endif //OLED_DISPLAY_128X64