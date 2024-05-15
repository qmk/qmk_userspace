VALID_KLOR_LAYOUTS := polydactyl konrad yubitsume saegewerk

ifeq ($(filter $(KLOR_LAYOUT),$(VALID_KLOR_LAYOUTS)),)
    $(call CATASTROPHIC_ERROR,Invalid KLOR_LAYOUT,KLOR_LAYOUT="$(KLOR_LAYOUT)" is not a valid Haptic driver)
else
    OPT_DEFS += -DKLOR_$(strip $(shell echo $(KLOR_LAYOUT) | tr '[:lower:]' '[:upper:]'))
endif