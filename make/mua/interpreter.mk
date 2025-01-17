# mua/interpreter.mk

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = STATICLIB
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = interpreter
# <path-to-dir>
TARGET_PATH = mua/interpreter
# Include Directories # -I<path-to-dir>
INCLUDES = \
	-Imua/inc/front \
	-Imua/inc/back \
	-Imua/inc/util/node/op_node/bin_node \
	-Imua/inc/util/node/op_node/una_node \
	-Imua/inc/util/node \
	-Imua/inc/util/token \
	-Imua/inc/util \
	-Imua/inc/util/character
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/mua/node \
	-Lbuild/mua/token \
	-Lbuild/mua/character
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
DLINKS = \
# Static link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
SLINKS = \
	-lnode \
	-ltoken \
	-lcharacter
DEFINES = 
SRCDIRS = \
	mua/src/back
SRCFILES = \
	Interpreter.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
endef

include ./make/maker.mk
