BOOTLOADER=caterina

OLED_ENABLE = yes
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
EXTRAFLAGS += -flto
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
LTO_ENABLE = yes
WPM_ENABLE = yes
TAP_DANCE_ENABLE = yes
REPEAT_KEY_ENABLE = yes

# AVR optimizations
RGB_MATRIX_ENABLE = no     # Disable keyboard RGB matrix, as it is enabled by default on rev3
CONSOLE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
UNICODE_ENABLE   = no# Unicode
COMMAND_ENABLE   = no # Commands for debug and configuration
LEADER_ENABLE = no
MUSIC_ENABLE = no
