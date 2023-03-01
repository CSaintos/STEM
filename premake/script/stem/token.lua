-- token.lua

require "script/global"

project "token"
  kind "SharedLib"
  language "C++"
  location (prjLoc)
  targetdir (tarLoc)  
  objdir (objLoc)

  files {
    (globalLoc .. "/stem/src/util/token/**.cpp")
  }

  includedirs {
    (globalLoc .. "/stem/inc/util/token"),
    (globalLoc .. "/stem/inc/util")
  }

project "token"