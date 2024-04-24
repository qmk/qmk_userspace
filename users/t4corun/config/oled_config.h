#pragma once

/*
https://docs.qmk.fm/#/feature_oled_driver
*/

//Clear variables we plan to use that might be set elsewhere
#undef OLED_TIMEOUT


//Set common configuration for all keyboards
#define OLED_TIMEOUT 60000 //1 min