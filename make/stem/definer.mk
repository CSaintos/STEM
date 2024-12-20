# stem/definer.mk

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = STATICLIB
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = definer
# <path-to-dir>
TARGET_PATH = stem/definer
# Include Directories # -I<path-to-dir>
INCLUDES = \
	-Istem/inc/front \
	-Istem/inc/util/token/trie \
	-Istem/inc/util/token \
	-Istem/inc/util/node/op_node/bin_node \
	-Istem/inc/util/node/op_node/una_node \
	-Istem/inc/util/node \
	-Istem/inc/util \
	-Istem/inc/util/character
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/stem/trie \
	-Lbuild/stem/node \
	-Lbuild/stem/token \
	-Lbuild/stem/error \
	-Lbuild/stem/character
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
DLINKS = \
# Static link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
SLINKS = \
	-ltrie \
	-lnode \
	-ltoken \
	-lerror \
	-lcharacter
DEFINES = 
SRCDIRS = \
	stem/src/front
SRCFILES = \
	Definer.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
endef

include ./make/maker.mk
