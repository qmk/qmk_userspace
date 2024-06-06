#pragma once

/* Haptic Feedback
*
* https://docs.qmk.fm/#/feature_haptic_feedback
* 
*/

#if defined(HAPTIC_DRV2605L)
//Clear variables we plan to use that might be set elsewhere
#   undef DRV2605L_GREETING
#   undef DRV2605L_DEFAULT_MODE

//Set common configuration for all keyboards
#   define DRV2605L_GREETING DRV2605L_EFFECT_750_MS_ALERT_100
#   define DRV2605L_DEFAULT_MODE DRV2605L_EFFECT_STRONG_CLICK_1_100
#endif //HAPTIC_DRV2605L