# stem/generator.mk
.PHONY: all compile build clean

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = STATICLIB
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = generator
# <path-to-dir>
TARGET_PATH = stem/generator
# Include Directories # -I<path-to-dir>
INCLUDES = \
	-Istem/inc/back \
	-Istem/inc/util/node \
	-Istem/inc/util/node/op_node \
	-Istem/inc/util/node/value_node \
	-Istem/inc/util/token \
	-Istem/inc/util \
	-Istem/api
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/stem/node
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
DLINKS =
# Static link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
SLINKS = \
	-lnode
DEFINES = 
SRCDIRS = \
	stem/src/back
SRCFILES = \
	Generator.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
endef

include ./newmake/maker.mk
