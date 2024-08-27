# File: main/CMakeLists.txt

idf_component_register(SRCS "rvkeyer.cpp"
                       INCLUDE_DIRS "../components/morse_keyer/include" "../components/network/include")
