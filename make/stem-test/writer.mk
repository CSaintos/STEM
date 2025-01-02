# stem-test/writer.mk

#? Variables
# STATICLIB, DYNAMICLIB, or EXE # (no space after)
BUILDTYPE = EXE
# COMPILEONLY, LINKONLY, or BOTH # (no space after)
PROCESS = BOTH
TARGET_NAME = writer
# <path-to-dir>
TARGET_PATH = stem-test/writer
# Include Directories # -I<path-to-dir>
INCLUDES = \
	-Istem/inc/front
# Link Directories # -L<path-to-dir>
LINKDIRS = \
	-Lbuild/stem/writer
# Dynamic link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
DLINKS =
# Static link files # -l<file-no-extension> or -l:<file-w-extension> # Order from most dependent to least dependent.
SLINKS = \
	-lwriter
DEFINES = 
SRCDIRS = \
	stem/test/front
SRCFILES = \
	WriterTest.cpp

#? Constants
OBJDIR = bin/$(TARGET_PATH)
TARGETDIR = build/$(TARGET_PATH)
OBJCLEANDIR = $(OBJDIR)
TARGETCLEANDIR = $(TARGETDIR)

#? Custom build cmds
define POSTBUILDCMDS
endef

include ./make/maker.mk
