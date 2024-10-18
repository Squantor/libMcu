# SPDX-License-Identifier: MIT
#
# Copyright (c) 2020-2020 Bart Bilos
# For conditions of distribution and use, see LICENSE file

# libMcuLL library files and settings
#
# Version: 20220715

# library settings
NAME := libMcu

# current makefile base dir relative to Makefile
LIB_DIR := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))

# library files and includes
$(NAME)_LIB_FILES :=

$(NAME)_LIB_INCLUDES := -I$(LIB_DIR)/inc

# --- nothing user definable below ---
LIBRARIES += $(NAME)