# maker.mk
.PHONY: all compile build dirs clean

#* Compiler flags
CXXFLAGS += -MD -MP -g
#* Pre-constants
SLINK_FILES = $(patsubst -l%, %.lib, $(patsubst -l:%, %, $(SLINKS)))
DLINK_FILES = $(patsubst -l%, %.dll, $(patsubst -l:%, %, $(DLINKS)))
LINKS = $(SLINK_FILES) $(DLINK_FILES)

#* First class functions
find_srcs = $(wildcard $(addprefix $(addsuffix /, $(SRCDIR)), $(SRCFILES)))
find_libs = $(wildcard $(addprefix $(addsuffix /, $(LINKDIR)), $(LINKS)))
list_rm = $(wordlist 2, $(words $1), $1)
pairmap = $(and $(strip $2), $(strip $3), $(call $1, $(firstword $2), $(firstword $3)) $(call pairmap, $1, $(call list_rm, $2), $(call list_rm, $3)))
compile_exe_cmd = $(shell $(CXX) $(INCLUDES) -c$1 -o$2 $(CXXFLAGS) -MF$(2:%.o=%.d))
compile_lib_cmd = $(shell $(CXX) -fPIC $(INCLUDES) -c$1 -o$2 $(CXXFLAGS) -MF$(2:%.o=%.d))

#* Constants
ifeq ($(OS),Windows_NT)
	SYS = Windows
else ifeq ($(shell uname -s),Linux)
	SYS = Linux
else ifeq ($(shell uname -s),Darwin)
	SYS = OSX
endif
SRCS = $(foreach SRCDIR, $(SRCDIRS), $(find_srcs))
LIBS = $(foreach LINKDIR, $(patsubst -L%, %, $(LINKDIRS)), $(find_libs))
OBJECTS = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(SRCFILES)))
TARGET = $(TARGETDIR)/$(TARGET_NAME)
ifeq ($(BUILDTYPE), EXE)
TARGET := $(TARGET).exe
else ifeq ($(BUILDTYPE), STATICLIB)
TARGET := $(TARGET).lib
else ifeq ($(BUILDTYPE), DYNAMICLIB)
TARGET := $(TARGET).dll
endif

#* Process execution
ifneq ($(filter $(PROCESS), BOTH LINKONLY),)
all: $(TARGET)
	$(POSTBUILDCMDS)
else ifeq ($(PROCESS), COMPILEONLY)
all: $(OBJECTS)
else
all:
	@echo error: invalid process
endif

# Create bin directory
$(OBJDIR):
ifeq ($(wildcard $(OBJDIR)),)
ifeq ($(SYS),Windows)
	@mkdir $(subst /,\\,$(OBJDIR))
else ifneq ($(filter $(SYS), Linux OSX),)
	@mkdir -p $(OBJDIR)
endif
	@echo create bin directory
endif

# Compile sources into objects
$(OBJECTS): $(SRCS) | $(OBJDIR)
	@echo compile
ifeq ($(BUILDTYPE), EXE)
	$(call pairmap, compile_exe_cmd, $(SRCS), $(OBJECTS))
else ifneq ($(filter $(BUILDTYPE), STATICLIB DYNAMICLIB),)
	$(call pairmap, compile_lib_cmd, $(SRCS), $(OBJECTS))
else
	@echo invalid buildtype
endif
	@echo compiled

# Create build directory
$(TARGETDIR):
ifeq ($(wildcard $(TARGETDIR)),)
ifeq ($(SYS),Windows)
	@mkdir $(subst /,\\,$(TARGETDIR))
else ifneq ($(filter $(SYS), Linux OSX),)
	@mkdir -p $(TARGETDIR)
endif
	@echo create build directory
endif

# Build target from objects
ifeq ($(PROCESS), LINKONLY)
$(TARGET): $(LIBS) | $(TARGETDIR)
else
$(TARGET): $(OBJECTS) $(LIBS) | $(TARGETDIR)
endif
	@echo build
ifeq ($(BUILDTYPE), EXE)
	$(CXX) $(OBJECTS) $(LINKDIRS) -Wl,-Bstatic $(SLINKS) -Wl,-Bdynamic $(DLINKS) -Wl,--as-needed -o $(TARGET)
else ifeq ($(BUILDTYPE), STATICLIB)
	$(AR) -rcs $(TARGET) $(OBJECTS)
else ifeq ($(BUILDTYPE), DYNAMICLIB)
	$(CXX) -shared -o $(TARGET) $(OBJECTS) $(LINKDIRS) -Wl,-Bstatic $(SLINKS) -Wl,-Bdynamic $(DLINKS) -Wl,--as-needed
endif
	@echo built

compile: $(OBJECTS)
build: $(TARGET)
	$(POSTBUILDCMDS)
dirs: $(OBJDIR) $(TARGETDIR)
#	@echo $(CXXFLAGS)

clean: 
	@echo clean
ifneq ($(wildcard $(OBJCLEANDIR)),)
ifeq ($(SYS),Windows)
	rmdir /s /q $(subst /,\\,$(OBJCLEANDIR))
else ifneq ($(filter $(SYS), Linux OSX),)
	rmdir /s /q $(OBJCLEANDIR)
endif
endif
ifneq ($(wildcard $(TARGETCLEANDIR)),)
ifeq ($(SYS),Windows)
	rmdir /s /q $(subst /,\\,$(TARGETCLEANDIR))
else ifneq ($(filter $(SYS), Linux OSX),)
	rmdir /s /q $(TARGETCLEANDIR)
endif
endif
	@echo cleaned

-include $(OBJECTS:%.o=%.d)
