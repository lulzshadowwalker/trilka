workspace "Trilka"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist" -- Distribution
    }

local outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Trilka"
    location "Trilka"
    kind "SharedLib" -- Dynamic library 
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}") -- Object (intermediate) files

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
    }

    filter "system:macosx"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "11"

        defines
        {
            "TK_PLATFORM_MAC",
            "TK_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir)
        }

    filter "configurations:Debug"
        defines "TK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TK_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp" -- Console application
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}") -- Object (intermediate) files

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Trilka/vendor/spdlog/include",
        "Trilka/src"
    }

    links
    {
        "Trilka"
    }

    filter "system:macosx"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "11"

        defines
        {
            "TK_PLATFORM_MAC"
        }

    filter "configurations:Debug"
        defines "TK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TK_DIST"
        optimize "On"

