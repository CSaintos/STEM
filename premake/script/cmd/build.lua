-- build.lua

require "script/global"

function makeBuild(path)
  local cwd = os.getcwd()
  os.chdir(path)
  if os.host() == "windows" then
    os.execute("mingw32-make")
  else 
    os.execute("make")
  end
  os.chdir(cwd)
end

newaction {
  trigger = "build",
  description = "Build project (mingw32-make)",

  newoption {
    trigger = "stem",
    value = "project",
    description = "Build project",
    allowed = {
      {"token", "token lib"},
      {"node", "node lib"},
      {"error", "error lib"},
      {"reader", "reader lib"},
      {"PL", "PL Lib"},
      {"lexer", "lexer lib"},
      {"parser", "parser lib"},
      {"generator", "generator lib"},
      {"all", "all stem projects"}
    }
  },

  newoption {
    trigger = "stemT",
    value = "test project",
    description = "Build test project",
    allowed = {
      {"TokenUtils", "TokenUtilsTest.cpp"},
      {"IllegalCharError", "IllegalCharErrorTest.cpp"},
      {"Node", "NodeTest.cpp"},
      {"Reader", "ReaderTest.cpp"},
      {"PL", "PLTest.cpp"},
      {"Lexer", "LexerTest.cpp"},
      {"Parser", "ParserTest.cpp"},
      {"Generator", "GeneratorTest.cpp"},
      {"all", "all stem test projects"}
    }
  },

  newoption {
    trigger = "plugin",
    value = "plugin project",
    description = "Build plugin project",
    allowed = {
      {"plus", "plus lib"},
      {"all", "all plugin libs"}
    }
  },

  execute = function()
    if (_OPTIONS["stem"] == "token") then
      print "Building token lib"
      makeBuild(mL .. tokenL)
    elseif (_OPTIONS["stem"] == "node") then
      print "Building node lib"
      makeBuild(mL .. nodeL)
    elseif (_OPTIONS["stem"] == "error") then
      print "Building error lib"
      makeBuild(mL .. errorL)
    elseif (_OPTIONS["stem"] == "reader") then
      print "Building reader lib"
      makeBuild(mL .. readerL)
    elseif (_OPTIONS["stem"] == "PL") then
      print "Building PL lib"
      makeBuild(mL .. PLL)
    elseif (_OPTIONS["stem"] == "lexer") then
      print "Building lexer lib"
      makeBuild(mL .. lexerL)
    elseif (_OPTIONS["stem"] == "parser") then
      print "Building parser lib"
      makeBuild(mL .. parserL)
    elseif (_OPTIONS["stem"] == "generator") then
      print "Building generator lib"
      makeBuild(mL .. generatorL)
    elseif (_OPTIONS["stem"] == "all") then
      print "Building stem project and libs"
      makeBuild(mL .. stemL)
    elseif (_OPTIONS["stemT"] == "TokenUtils") then
      print "Building TokenUtilsTest"
      makeBuild(mL .. TokenUtilsTL)
      os.execute("{COPYFILE} ../build/stem/token/token.dll ../build/stem-test/TokenUtilsTest")
    elseif (_OPTIONS["stemT"] == "IllegalCharError") then
      print "Building IllegalCharErrorTest"
      makeBuild(mL .. IllegalCharErrorTL)
      os.execute("{COPYFILE} ../build/stem/error/error.dll ../build/stem-test/IllegalCharErrorTest")
    elseif (_OPTIONS["stemT"] == "Node") then
      print "Building NodeTest"
      makeBuild(mL .. NodeTL)
      os.execute("{COPYFILE} ../build/stem/node/node.dll ../build/stem-test/NodeTest")
      os.execute("{COPYFILE} ../build/stem/token/token.dll ../build/stem-test/NodeTest")
    elseif (_OPTIONS["stemT"] == "Reader") then
      print "Building ReaderTest"
      makeBuild(mL .. ReaderTL)
      os.execute("{COPYFILE} ../build/stem/reader/reader.dll ../build/stem-test/ReaderTest")
    elseif (_OPTIONS["stemT"] == "Lexer") then
      print "Building LexerTest"
      makeBuild(mL .. LexerTL)
      os.execute("{COPYFILE} ../build/stem/lexer/lexer.dll ../build/stem-test/LexerTest")
      os.execute("{COPYFILE} ../build/stem/reader/reader.dll ../build/stem-test/LexerTest")
      os.execute("{COPYFILE} ../build/stem/token/token.dll ../build/stem-test/LexerTest")
      os.execute("{COPYFILE} ../build/stem/error/error.dll ../build/stem-test/LexerTest")
    elseif (_OPTIONS["stemT"] == "Parser") then
      print "Building ParserTest"
      makeBuild(mL .. ParserTL)
      os.execute("{COPYFILE} ../build/stem/parser/parser.dll ../build/stem-test/ParserTest")
      os.execute("{COPYFILE} ../build/stem/lexer/lexer.dll ../build/stem-test/ParserTest")
      os.execute("{COPYFILE} ../build/stem/reader/reader.dll ../build/stem-test/ParserTest")
      os.execute("{COPYFILE} ../build/stem/token/token.dll ../build/stem-test/ParserTest")
      os.execute("{COPYFILE} ../build/stem/error/error.dll ../build/stem-test/ParserTest")
      os.execute("{COPYFILE} ../build/stem/node/node.dll ../build/stem-test/ParserTest")
    elseif (_OPTIONS["stemT"] == "PL") then
      print "Building PLTest"
      makeBuild(mL .. PLTL)
      os.execute("{COPYFILE} ../build/stem/PL/PL.dll ../build/stem-test/PLTest")
    elseif (_OPTIONS["stemT"] == "Generator") then
      print "Building GeneratorTest"
      makeBuild(mL .. GeneratorTL)
      os.execute("{COPYFILE} ../build/stem/generator/generator.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/parser/parser.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/lexer/lexer.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/reader/reader.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/token/token.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/error/error.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/node/node.dll ../build/stem-test/GeneratorTest")
      os.execute("{COPYFILE} ../build/stem/PL/PL.dll ../build/stem-test/GeneratorTest")
      print(os.mkdir("../build/stem-test/GeneratorTest/plugin"))
    elseif (_OPTIONS["plugin"] == "plus") then
      print "Building plus lib"
      makeBuild(mL .. plusL)
      os.execute("{COPYFILE} ../build/plugin/plus/plus.dll ../build/stem-test/GeneratorTest/plugin")
    end
  end
}