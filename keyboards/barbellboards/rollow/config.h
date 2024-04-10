#pragma once

#define MASTER_LEFT

#if defined(OLED_ENABLE)
# if !defined(OLED_FONT_H)
#   define OLED_FONT_H "keyboards/barbellboards/rollow/lib/glcdfont.c"
# endif //OLED_FONT_H
#endif //OLED_ENABLE
