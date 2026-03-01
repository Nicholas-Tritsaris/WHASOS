# WHAOS - CMake build for Visual Studio 2022 (Linux target)
# Open folder in VS2022, select "Linux" configuration, build
# Requires: Linux Development with C++ workload, WSL or remote Linux

cmake_minimum_required(VERSION 3.16)
project(WHAOS C CXX)

set(CMAKE_C_STANDARD 11)

# whad - WHAOS init (PID 1)
add_executable(whad src/init/whad.c)
set_target_properties(whad PROPERTIES
    OUTPUT_NAME whad
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/whad
)
target_link_libraries(whad PRIVATE pthread rt)

# whaos-panel - WHAOS taskbar (GTK3, Linux only)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_executable(whaos-panel
    src/desktop/main.c
    src/desktop/whaos_panel.c
)
target_include_directories(whaos-panel PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_libraries(whaos-panel PRIVATE ${GTK3_LIBRARIES})
target_compile_options(whaos-panel PRIVATE ${GTK3_CFLAGS_OTHER})
set_target_properties(whaos-panel PROPERTIES
    OUTPUT_NAME whaos-panel
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/whaos-panel
)
