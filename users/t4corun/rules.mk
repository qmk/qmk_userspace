# Set build options for
# - consistent configuration across all keyboards
# - enable features specific to certain board (e.g. encoders, rgb, oled)
# - a way to save memory on MCU

# ---------------------------------------------------------
# set defaults on these qmk features if not defined 
# in the individual keyboard rules.mk
# 
# ?= means set the value if its not defined elsewhere

LTO_ENABLE ?= yes
MAGIC_ENABLE ?= no
CONSOLE_ENABLE ?= no
UNICODE_ENABLE ?= no
SPACE_CADET_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no

COMBO_ENABLE ?= no
DYNAMIC_MACRO_ENABLE ?= yes
RGB_MATRIX_ENABLE ?= no
RGBLIGHT_ENABLE ?= no
POINTING_DEVICE_ENABLE ?= no
OLED_ENABLE ?= no
ENCODER_MAP_ENABLE ?= no

# qmk features we will force
AUDIO_ENABLE = no
CAPS_WORD_ENABLE = yes
MOUSEKEY_ENABLE = yes


# ---------------------------------------------------------
# include my code that will be common across all my keyboards

SRC += \
	t4corun.c \
	features/tapping.c \
	features/taphold.c 

# ---------------------------------------------------------
# include my code for enabled features for each keyboard

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += features/capsword.c
endif


ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += features/rgbmatrix.c
endif


ifeq ($(strip $(MOUSEKEY_ENABLE)), yes)
	SRC += features/mouse.c
endif


ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += features/oled.c
endif

ifeq ($(strip $(ENCODER_MAP_ENABLE)), yes)
	SRC += features/encoder.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C += features/combo.c
endif