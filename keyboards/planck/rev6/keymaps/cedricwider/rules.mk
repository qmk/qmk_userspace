ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no

# Define how long a key needs to be held (in milliseconds) for the hold action
TAPPING_TERM = 200
DYNAMIC_TAPPING_TERM_ENABLE = yes

CONSOLE_ENABLE = yes
DEBUG_ENABLE = yes
# Disabled because yo can't just enable the feature without defining it in keymap.c
# COMBO_ENABLE = yes
# TAP_DANCE_ENABLE = yes
