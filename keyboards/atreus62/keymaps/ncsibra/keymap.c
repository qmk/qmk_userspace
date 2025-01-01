#include "ncsibra.h"

#define OSL_MID   OSL_MOD_LAYER, XXXXXXX
#define BLANK_MID XXXXXXX, XXXXXXX

#define LAYOUT_ncsibra( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k48, k49, k4a, k4b, k4c, k4d, \
    k46, k47 \
) \
LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d \
)

#define LAYOUT_wrapper(...)            LAYOUT_ncsibra(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_wrapper(COLEMAK_LAYER, BLANK_MID),

[_QWERTY] = LAYOUT_wrapper(QWERTY_LAYER, BLANK_MID),

[_LOWER] = LAYOUT_wrapper(LOWER_LAYER, BLANK_MID),

[_RAISE] = LAYOUT_wrapper(RAISE_LAYER, BLANK_MID),

[_NUM] = LAYOUT_wrapper(NUM_LAYER, BLANK_MID),

[_WOW] = LAYOUT_wrapper(WOW_LAYER, BLANK_MID),

[_MOD] = LAYOUT_wrapper(MOD_LAYER, BLANK_MID),
};
