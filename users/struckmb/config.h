#define EE_HANDS

// // select at least on of these base layers
// #define QWERTY_ENABLE
// #define BONE_ENABLE
// #define COLEMAK_DH_ENABLE

// // some additionl layers can be added
// #define GAME_ENABLE (left hand qwerty + right hand arrows and numbers)
// #define ASETNIOP_ENABLE (corded writing)
// #define ARTSENIO_ENABLE (one handed writing)

#ifdef TAP_DANCE_ENABLE
#    define TAPPING_TERM 120
#    ifdef DYNAMIC_TAPPING_TERM_ENABLE
#        define DYNAMIC_TAPPING_TERM_INCREMENT 10
#    endif // DYNAMIC_TAPPING_TERM_ENABLE
#endif     // TAP_DANCE_ENABLED
