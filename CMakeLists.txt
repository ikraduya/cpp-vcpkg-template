cmake_minimum_required(VERSION 3.14)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project("cpp-vcpkg-template")

add_executable(main main.cpp)

find_package(xtensor CONFIG REQUIRED)
target_link_libraries(main PRIVATE xtensor xtensor::optimize)

set_target_properties(
	main
	PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED YES
)