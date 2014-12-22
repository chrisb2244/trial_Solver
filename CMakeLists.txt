cmake_minimum_required(VERSION 2.8)
project(twoPhaseFlowSolver CXX)

# Version number
set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)

set(${CMAKE_VERBOSE_MAKEFILE} TRUE)

# Testing?
# enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(warnings "/W4 /WX /EHsc")
endif()
if (NOT CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${warnings}"
		CACHE STRING "Flags used by the compiler during all build types." FORCE)
	set(CMAKE_C_FLAGS   "${warnings}"
		CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

# Add C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

# Subdirectories
add_subdirectory(SetupFile)
add_subdirectory(MeshHandler)
include_directories(SetupFile MeshHandler)

add_executable(${PROJECT_NAME} twoPhaseFlowSolver.C)
target_link_libraries(twoPhaseFlowSolver SetupFile MeshHandler)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
	"A flag showing that CMake has configured at least once.")
