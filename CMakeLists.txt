cmake_minimum_required(VERSION 3.15)
project(Screensaver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

# Find Raylib system package
find_package(raylib REQUIRED)

# Project sources
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(screensaver ${SOURCES})

# Include directories: Raylib + raygui
target_include_directories(screensaver PRIVATE
    ${raylib_INCLUDE_DIRS}  # Raylib headers
    libs                     # contains raygui.h
)

# Link Raylib
target_link_libraries(screensaver PRIVATE raylib)
