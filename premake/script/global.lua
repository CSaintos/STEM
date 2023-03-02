-- global.lua

-- paths
globalLoc = ".."
makeLoc = globalLoc .. "/make"
  stemLoc = makeLoc .. "/stem"
    tokenLoc = stemLoc .. "/token"
    nodeLoc = stemLoc .. "/node"
    errorLoc = stemLoc .. "/error"
  stemTestLoc = makeLoc .. "/stem-test"
    TokenUtilsTestLoc = stemTestLoc .. "/TokenUtilsTest"
    IllegalCharErrorTestLoc = stemTestLoc .. "/IllegalCharErrorTest"
  pluginLoc = makeLoc .. "/plugin"
buildLoc = globalLoc .. "/build"
binLoc = globalLoc .. "/bin"

-- workspace paths
wGLoc = "../../.."
wMLoc = (wGLoc .. "/make")

-- project paths
prjLoc = "%{wks.location}/%{prj.name}"
tarLoc = "%{wks.location}/../../build/%{wks.name}/%{prj.name}"
objLoc = "%{wks.location}/../../bin/%{wks.name}/%{prj.name}"

-- project functions
function initPrjLocs()
  location (prjLoc)
  targetdir (tarLoc)
  objdir (objLoc)
end