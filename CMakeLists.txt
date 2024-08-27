# Minimum CMake version required
cmake_minimum_required(VERSION 3.16)

# Project name
project(rvkeyer)

# Set C++ standard only for C++ files globally
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)

# Include the main directory
add_subdirectory(main)

# Set the components directory
set(EXTRA_COMPONENT_DIRS "${CMAKE_SOURCE_DIR}/components")

# Include the components directory
include_directories(${EXTRA_COMPONENT_DIRS})

# Add the rvkeyer component
add_subdirectory(components/rvkeyer)
