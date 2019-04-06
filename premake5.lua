workspace "Negligent-Precision"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
	"Debug",
	"PreRelease",
	"Release"
	}


-- TODO: I'm not sure I like this
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Negligent-Precision/vendor/GLFW"

project "Negligent-Precision"
	location "Negligent-Precision"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")


	--TODO: precompiled headers

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs	
	{
		"%{prj.name}/vendor/include",
		"%{prj.name}/vendor/GLFW/include"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NP_PLATFORM_WINDOWS",
			"NP_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NP_DEBUG"
		symbols "On"

	filter "configurations:PreRelease"
		defines "NP_PRERELEASE"
		optimize "On"

	filter "configurations:Release"
		defines "NP_RELEASE"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/include",
		"Negligent-Precision/src"
	}

	links
	{
		"Negligent-Precision"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NP_PLATFORM_WINDOWS"
		}