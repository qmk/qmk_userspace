.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

# Determine which qmk cli to use
QMK_BIN := qmk

# Try to determine qmk_firmware from qmk config - no fallback is required as this functionality has existed since qmk_cli 0.0.46
QMK_FIRMWARE_ROOT = $(shell $(QMK_BIN) env QMK_FIRMWARE)
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` or QMK_HOME environment variable is not set)
endif

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
