# makefile
.PHONY: all clean dirs $(MAKES) $(CLEANS) $(DIRS)

export CXX = g++
export AR = ar
ifeq ($(CXX_VERSION),)
CXX_VERSION=c++23
endif
export CXXFLAGS = -std=$(CXX_VERSION)
ifeq ($(SYS),)
SYS = Linux
endif
export SYS

#? List of submakes ex. # ./make/submake1.mk
PROJECTS = \
	./make/mua/error.mk \
	./make/mua/character.mk \
	./make/mua/reader.mk \
	./make/mua/token.mk \
	./make/mua/trie.mk \
	./make/mua/node.mk \
	./make/mua/lexer.mk \
	./make/mua/parser.mk \
	./make/mua/definer.mk \
	./make/mua/interpreter.mk \
	./make/mua/writer.mk \
	./make/mua/main.mk \
	./make/mua-test/error.mk \
	./make/mua-test/character.mk \
	./make/mua-test/token.mk \
	./make/mua-test/reader.mk \
	./make/mua-test/node.mk \
	./make/mua-test/number.mk \
	./make/mua-test/lexer.mk \
	./make/mua-test/parser.mk \
	./make/mua-test/definer.mk \
	./make/mua-test/interpreter.mk \
	./make/mua-test/writer.mk

#? List of TARGET_PATHs to be created first. (Only useful if running `make -j` and there are shared TARGET_PATHs) # ./make/submake1.mk 
PROJECTDIRS = \
	./make/mua/error.mk \
	./make/mua-test/error.mk

DIRS = $(foreach PROJECTDIR, $(PROJECTDIRS), d$(PROJECTDIR))
MAKES = $(foreach PROJECT, $(PROJECTS), m$(PROJECT))
CLEANS = $(foreach PROJECT, $(PROJECTS), c$(PROJECT))

all: $(MAKES)
clean: $(CLEANS)
dirs: $(DIRS)

#? Submake dependencies (allows `make -j` to work) ex. # m./make/submake1.mk: m./make/submake2.mk
#? A submake dependes on another if it uses the target of the other (such as the form of a library) 
m./make/mua/trie.mk: m./make/mua/token.mk
m./make/mua/node.mk: m./make/mua/token.mk
m./make/mua/lexer.mk: m./make/mua/error.mk m./make/mua/trie.mk m./make/mua/character.mk
m./make/mua/parser.mk: m./make/mua/error.mk m./make/mua/node.mk
m./make/mua/definer.mk: m./make/mua/error.mk m./make/mua/node.mk m./make/mua/trie.mk
m./make/mua/interpreter.mk: m./make/mua/node.mk
m./make/mua/reader.mk: m./make/mua/character.mk m./make/mua/error.mk
m./make/mua/generator.mk: m./make/mua/node.mk
m./make/plugin/plus.mk: m./make/mua/node.mk
m./make/mua-test/error.mk: m./make/mua/error.mk
m./make/mua-test/character.mk: m./make/mua/character.mk
m./make/mua-test/token.mk: m./make/mua/token.mk
m./make/mua-test/reader.mk: m./make/mua/reader.mk
m./make/mua-test/lexer.mk: m./make/mua/lexer.mk m./make/mua/reader.mk
m./make/mua-test/node.mk: m./make/mua/node.mk
m./make/mua-test/number.mk: m./make/mua/node.mk m./make/mua/character.mk
m./make/mua-test/parser.mk: m./make/mua/parser.mk m./make/mua/lexer.mk m./make/mua/reader.mk
m./make/mua-test/definer.mk: m./make/mua/definer.mk m./make/mua/parser.mk m./make/mua/lexer.mk m./make/mua/reader.mk
m./make/mua-test/interpreter.mk: m./make/mua/interpreter.mk m./make/mua/definer.mk m./make/mua/parser.mk m./make/mua/lexer.mk m./make/mua/reader.mk
m./make/mua-test/generator.mk: m./make/mua/generator.mk m./make/mua/parser.mk m./make/mua/lexer.mk m./make/mua/reader.mk
m./make/mua-test/writer.mk: m./make/mua/writer.mk
m./make/mua/main.mk: m./make/mua/writer.mk m./make/mua/interpreter.mk m./make/mua/definer.mk m./make/mua/parser.mk m./make/mua/lexer.mk m./make/mua/reader.mk

# Static pattern rules for running sub-makes
$(DIRS): d%: %
	@$(MAKE) --no-print-directory -f $< dirs

$(MAKES): m%: % $(DIRS)
	@$(MAKE) --no-print-directory -f $<

$(CLEANS): c%: %
	@$(MAKE) --no-print-directory -f $< clean
