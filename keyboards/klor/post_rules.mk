VALID_KLOR_CONFIG := polydactyl konrad yubitsume saegewerk

ifeq ($(filter $(KLOR_CONFIG),$(VALID_KLOR_CONFIG)),)
    $(call CATASTROPHIC_ERROR,Invalid KLOR_LAYOUT,KLOR_LAYOUT="$(KLOR_CONFIG)" is not a valid KLOR Layout)
else
    OPT_DEFS += -DKLOR_$(strip $(shell echo $(KLOR_CONFIG) | tr '[:lower:]' '[:upper:]'))
endif

# Turn off features for AVR Processors due to memory size
ifeq ($(strip $(PLATFORM)),AVR)
    AUDIO_ENABLE = no
    MUSIC_ENABLE = no
    HAPTIC_ENABLE = no
    RGB_MATRIX_ENABLE = no
endif