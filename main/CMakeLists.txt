# CMakeLists.txt for the main application

idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS ""
)

# Ensure the project uses C++17 standard
# Set C++ standard only for C++ files
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)
