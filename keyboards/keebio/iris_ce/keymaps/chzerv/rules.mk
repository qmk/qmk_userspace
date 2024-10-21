# Include keyboard independent rules from the root directory
ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../rules.mk
