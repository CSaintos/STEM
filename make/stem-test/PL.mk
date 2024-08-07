# stem-test/PL.mk

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = EXE
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = PL
# <path-to-dir>
TARGET_PATH = stem-test/PL
# Include Directories # -I<path-to-dir>
INCLUDES = \
	-Istem/inc/plugin \
	-Istem/api \
	-Istem/inc/util/node/op_node \
	-Istem/inc/util/node/value_node \
	-Istem/inc/util/node \
	-Istem/inc/util/token \
	-Istem/inc/util
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/stem/PL
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
DLINKS =
# Static link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
SLINKS = \
	-lPL
DEFINES = 
SRCDIRS = \
	stem/test/plugin
SRCFILES = \
	PLTest.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
	@echo copying build/plugin into build/stem-test/PL/plugin
	@xcopy build\\plugin build\\stem-test\\PL\\plugin /E /I /Y /Q
endef

include ./make/maker.mk
