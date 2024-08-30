idf_component_register(
    SRCS
    "main.cpp"
    INCLUDE_DIRS
    .
     "")
# Set C++ standard only for C++ files
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)
