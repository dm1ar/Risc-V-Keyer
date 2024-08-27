# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(Risc-V-Keyer)

set(EXTRA_COMPONENT_DIRS components/morse_keyer components/network)

# Set C++ standard only for C++ files
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)