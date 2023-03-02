-- test-stem.lua

require "script/global"

workspace "stem-test"
  configurations { "Debug", "Release" }
  location (wMLoc .. "/stem-test")

  filter { "configurations:Debug" }
    defines { "DEBUG" }
    symbols "On"
  filter { "configurations:Release" }
    defines { "RELEASE" }
    optimize "On"
  filter {}

  include "script/stem-test/TokenUtilsTest.lua"
  include "script/stem-test/IllegalCharErrorTest.lua"

workspace "stem-test"