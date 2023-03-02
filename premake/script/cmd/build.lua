-- build.lua

require "script/global"

function makeBuild(path)
  local cwd = os.getcwd()
  os.chdir(path)
  os.execute("mingw32-make")
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
      {"all", "all stem projects"}
    }
  },

  newoption {
    trigger = "stem-test",
    value = "test project",
    description = "Build test project",
    allowed = {
      {"TokenUtils", "TokenUtilsTest.cpp"},
      {"IllegalCharError", "IllegalCharErrorTest.cpp"},
      {"all", "all stem test projects"}
    }
  },

  execute = function()
    if (_OPTIONS["stem"] == "token") then
      print "Building token lib"
      makeBuild(tokenLoc)
    elseif (_OPTIONS["stem"] == "node") then
      print "Building node lib"
      makeBuild(nodeLoc)
    elseif (_OPTIONS["stem"] == "error") then
      print "Building error lib"
      makeBuild(errorLoc)
    elseif (_OPTIONS["stem"] == "all") then
      print "Building stem project and libs"
      makeBuild(stemLoc)
    elseif (_OPTIONS["stem-test"] == "TokenUtils") then
      print "Building TokenUtilsTest"
      makeBuild(TokenUtilsTestLoc)
      os.execute("{COPYFILE} ../build/stem/token/token.dll ../build/stem-test/TokenUtilsTest")
    elseif (_OPTIONS["stem-test"] == "IllegalCharError") then
      print "Building IllegalCharErrorTest"
      makeBuild(IllegalCharErrorTestLoc)
      os.execute("{COPYFILE} ../build/stem/error/error.dll ../build/stem-test/IllegalCharErrorTest")
    end
  end
}