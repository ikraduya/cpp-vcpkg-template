cmake_minimum_required(VERSION 3.14)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project("cpp-vcpkg-template")

add_executable(main main.cpp)

find_package(xtensor CONFIG REQUIRED)
target_link_libraries(main PRIVATE xtensor xtensor::optimize)

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
    set (X86orX64 TRUE)
else ()
    set (X86orX64 FALSE)
endif ()

find_package(TBB CONFIG)
if (WIN32 AND X86orX64)
	if (NOT TBB_FOUND)
		message(STATUS "Intel's Threading Building Block library not found")
	else()
		target_link_libraries(main PRIVATE TBB::tbb xtensor::use_TBB xtensor::use_xsimd)
	endif()
else()
	if (NOT X86orX64)
		message(STATUS "Skipped adding Intel's Threading Building Block and xsimd because processor architecture is not X86 or X64.")
	else()
		message(STATUS "Skipped adding Intel's Threading Building Block on Linux.")
	endif()
endif()

set_target_properties(
	main
	PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED YES
)