# stem/lexer.mk

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
	-Istem/inc/util/token/trie \
	-Istem/inc/util \
	-Istem/inc/util/error \
	-Istem/inc/util/character
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/stem/error \
	-Lbuild/stem/character \
	-Lbuild/stem/token \
	-Lbuild/stem/trie
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension>
DLINKS =
# Static link files # -l<file-no-extension> or -l:<file-w-extension>
SLINKS = \
	-ltrie \
	-ltoken \
	-lcharacter \
	-lerror
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

include ./make/maker.mk
