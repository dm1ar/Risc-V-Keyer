# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/rax/esp/v5.3/esp-idf/components/bootloader/subproject"
  "/home/rax/esp/Risc-V-Keyer/build/bootloader"
  "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix"
  "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix/tmp"
  "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix/src/bootloader-stamp"
  "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix/src"
  "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/rax/esp/Risc-V-Keyer/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
