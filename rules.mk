# Disable features we don't use
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
BLUETOOTH_ENABLE = no

# Compile with `flto` for smaller firmware size
LTO_ENABLE = yes

# Enable N-Key Rollover
NKRO_ENABLE = yes
TRI_LAYER_ENABLE = yes

# https://docs.qmk.fm/features/caps_word
CAPS_WORD_ENABLE = yes

# Feature libraries
SRC += features/layer_lock.c
