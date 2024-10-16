# stem-test/lexer.mk

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = EXE
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = lexer
# <path-to-dir>
TARGET_PATH = stem-test/lexer
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
	-Lbuild/stem/lexer \
	-Lbuild/stem/reader \
	-Lbuild/stem/trie \
	-Lbuild/stem/token \
	-Lbuild/stem/error \
	-Lbuild/stem/character
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension> # Order from least dependent (most depending) to most dependent (least depending) 
DLINKS =
# Static link files # -l<file-no-extension> or -l:<file-w-extension> # Order from least dependent (most depending) to most dependent (least depending)
SLINKS = \
	-llexer \
	-lreader \
	-ltrie \
	-ltoken \
	-lerror \
	-lcharacter
DEFINES = 
SRCDIRS = \
	stem/test/front
SRCFILES = \
	LexerTest.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
endef

include ./make/maker.mk
