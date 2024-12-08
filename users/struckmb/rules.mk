OS_DETECTION_ENABLE = yes

# Userspace code
SRC += struckmb.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	DYNAMIC_TAPPING_TERM_ENABLE = yes
endif
