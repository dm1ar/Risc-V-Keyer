# CMakeLists.txt for the rvkeyer component

idf_component_register(
    SRCS "src/rvkeyer.cpp"
         "src/esp32_init.cpp"
         "src/morse_symbol_input.cpp"
         "src/morse_output.cpp"
         "src/morse_decode.cpp"
         "src/dynset.cpp"
         "src/shutdown.cpp"
         "src/log_handler.cpp"
         "src/watch_dog_timer.cpp"
         "src/nvm_store.cpp"
         "src/database_handler.cpp"
         "src/morse_translator.cpp
