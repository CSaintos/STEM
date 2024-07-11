# stem/lexer.mk
.PHONY: all compile build clean

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = STATICLIB
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = lexer
# <path-to-dir>
TARGET_PATH = stem/lexer
# Include Directories # -I<path-to-dir>
INCLUDES = \
	-Istem/inc/front \
	-Istem/inc/util/token \
	-Istem/inc/util \
	-Istem/inc/util/error
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/stem/error \
	-Lbuild/stem/token
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension>
DLINKS = \
# Static link files # -l<file-no-extension> or -l:<file-w-extension>
SLINKS = \
	-lerror \
	-ltoken
DEFINES = 
SRCDIRS = \
	stem/src/front
SRCFILES = \
	Lexer.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
endef

include ./newmake/maker.mk
