#!/usr/bin/env fish

# Navigate to the project root directory
cd ~/esp/Risc-V-Keyer

# Define the project root directory (expand tilde manually)
set ROOT_DIR (realpath ~/esp/Risc-V-Keyer)

# Define the components directory
set COMPONENTS_DIR "$ROOT_DIR/components/rvkeyer"

# Define directories to create
set DIRS "$COMPONENTS_DIR/include" "$COMPONENTS_DIR/src"

# Create the directories if they don't exist
for dir in $DIRS
    if not test -d $dir
        mkdir -p $dir
        echo "Created directory: $dir"
    else
        echo "Directory already exists: $dir"
    end
end

# Create or replace CMakeLists.txt in components/rvkeyer
echo 'idf_component_register(SRCS "src/rvkeyer.cpp" \
                       "src/esp32_init.cpp" \
                       "src/morse_symbol_input.cpp" \
                       "src/morse_output.cpp" \
                       "src/morse_decode.cpp" \
                       "src/dynset.cpp" \
                       "src/shutdown.cpp" \
                       "src/log_handler.cpp" \
                       "src/watch_dog_timer.cpp" \
                       "src/nvm_store.cpp" \
                       "src/database_handler.cpp" \
                       "src/morse_translator.cpp" \
                       "src/isr_handler.cpp" \
                       "src/network_manager.cpp" \
                       INCLUDE_DIRS "include")' > "$COMPONENTS_DIR/CMakeLists.txt"
echo "Created or replaced file: $COMPONENTS_DIR/CMakeLists.txt"

# Create empty stubs for header files in components/rvkeyer/include
set HEADER_FILES "rvkeyer.h" "esp32_init.h" "morse_symbol_input.h" "morse_output.h" \
    "morse_decode.h" "dynset.h" "shutdown.h" "log_handler.h" "watch_dog_timer.h" \
    "nvm_store.h" "database_handler.h" "morse_translator.h" "isr_handler.h" "network_manager.h"

for header in $HEADER_FILES
    echo "#ifndef (string replace -a '.' '_' $header)_H\n#define (string replace -a '.' '_' $header)_H\n\n#endif" > "$COMPONENTS_DIR/include/$header"
    echo "Created or replaced file: $COMPONENTS_DIR/include/$header"
end

# Create empty stubs for source files in components/rvkeyer/src
set SOURCE_FILES "rvkeyer.cpp" "esp32_init.cpp" "morse_symbol_input.cpp" "morse_output.cpp" \
    "morse_decode.cpp" "dynset.cpp" "shutdown.cpp" "log_handler.cpp" "watch_dog_timer.cpp" \
    "nvm_store.cpp" "database_handler.cpp" "morse_translator.cpp" "isr_handler.cpp" "network_manager.cpp"

for source in $SOURCE_FILES
    echo "// $source\n\n" > "$COMPONENTS_DIR/src/$source"
    echo "Created or replaced file: $COMPONENTS_DIR/src/$source"
end

echo "Components directory structure and file setup complete."
