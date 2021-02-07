workspace "VAR"
architecture "x86_64"
startproject "VAR"

configurations { "Debug", "Release" }
    
    flags
	{
		"MultiProcessorCompile"
    }
    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["GLFW"] = "VAR/Vendor/glfw/include"
    IncludeDir["Vulkan"] = "VAR/Vendor/Vulkan/Include"
    IncludeDir["glm"] = "VAR/Vendor/glm"

    group "Dependencies"
    include "VAR/Vendor/glfw"
    group ""

project "VAR"
            location "VAR"
            kind "ConsoleApp"
            language "C++"
            cppdialect "C++17"
            staticruntime "on"

            targetdir ("bin/" .. outputdir .. "/%{prj.name}")
            objdir("bin-int/" .. outputdir .. "/%{prj.name}")

            pchheader "Pch.h"
            pchsource "VAR/src/Precompiled/Pch.cpp"


            files
            {
                "%{prj.name}/src/**.h",
                "%{prj.name}/src/**.hpp",
                "%{prj.name}/src/**.c",
                "%{prj.name}/src/**.cpp",
                "%{prj.name}/Vendor/glm/glm/**hpp",
                "%{prj.name}/Vendor/glm/glm/**inl"
            }

            defines
            {
                "_CRT_SECURE_NO_WARNINGS",
                "GLFW_INCLUDE_NONE",
            }

            includedirs
            {
                "%{prj.name}/src/**",
                "%{prj.name}/Vendor/spdlog/include",
                "%{prj.name}/src/Precompiled",
                "%{IncludeDir.GLFW}",
                "%{IncludeDir.Vulkan}",
                "%{IncludeDir.glm}"
                
            }

            libdirs
            {
                "%{prj.name}/Vendor/Vulkan/Lib"
            }

            links
            {   
                "vulkan-1.lib",           
                "GLFW", 
            }
            

            filter "configurations:Debug"
                    defines { "DEBUG" }
                    runtime "Debug"
                    symbols "On"
              
            filter "configurations:Release"
                    defines { "NDEBUG" }
                    runtime "Release"
                    optimize "On"