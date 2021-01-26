workspace "stl"
	architecture "x64"
	startproject "stl"
	targetdir "build"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "stl"
	location "stlproj"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	warnings "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"stlproj/src/**.h",
		"stlproj/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"STL_USE_MSVC",
		"STL_USE_STD_NAMESPACE"
	}

	includedirs
	{
		"stlproj/src"
	}

	filter "configurations:Debug"
		defines "STL_DEBUG"
		runtime "Debug"
		symbols "on"

		
	filter "configurations:Release"
		defines "STL_RELEASE"
		runtime "Release"
		optimize "on"