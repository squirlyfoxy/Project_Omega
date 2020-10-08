cmake_minimum_required(VERSION 3.0)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project("Project Omega")

include_directories("${PROJECT_SOURCE_DIR}/src")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

set(CMAKE_CXX_FLAGS "-Ttext 0x8000 -ffreestanding -mno-red-zone -m64")
set(CMAKE_EXE_LINKER_FLAGS "-T \"linker.ld\" ")

FILE (GLOB_RECURSE kernel_C_SOURCES "*.c")
FILE (GLOB_RECURSE kernel_CPP_SOURCES "*.cpp")

ADD_LIBRARY (kernel STATIC
                ${kernel_C_SOURCES}
                ${kernel_CPP_SOURCES}
            )

ADD_CUSTOM_COMMAND (
    TARGET kernel
    POST_BUILD
    COMMAND $ENV{HOME}/opt/cross/x86_64-elf/bin/x86_64-elf-ld -T \"linker.ld\" -o "out/kernel.bin"
)