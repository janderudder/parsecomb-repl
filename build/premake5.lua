-- premake5.lua
workspace "C++17-Project-Workspace"
   configurations { "simple", "debug", "release" }

project "repl-parsecomb"

   kind        "ConsoleApp"
   objdir      "%{cfg.buildcfg}/obj"
   language    "C++"
   cppdialect  "C++17"
   location    "../"
   targetdir   "../bin"
   targetname  "repl-parsecomb"

   files {
      "../src/**.cpp",
      "../../tokenizer/src/tokenizer/**.cpp"
   }

   includedirs    {
      "../include",
      "../../parsecomb/include",
      "../../tokenizer/include"
   }

   links          { }

   enablewarnings { "all", "extra", "shadow", "unused" }

   filter "configurations:simple"
      defines  { "DEBUG" }
      symbols  "Off"
      disablewarnings { "unused" }

   filter "configurations:debug"
      defines   { "DEBUG" }
      symbols   "On"
      optimize  "Debug"
      targetdir "../bin/dbg"

   filter "configurations:release"
      symbols  "Off"
      defines  { "NDEBUG" }
      optimize "On"
