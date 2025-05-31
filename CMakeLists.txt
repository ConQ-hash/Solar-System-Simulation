cmake_minimum_required(VERSION 3.10)
project(solar_sim)

# Use C++17
set(CMAKE_CXX_STANDARD 17)

# Glad
add_library(glad src/glad/src/glad.c)
target_include_directories(glad PUBLIC src/glad/include)

# GLFW (via pkg-config)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})

# Main executable
add_executable(solar_sim src/main.cpp)
target_include_directories(solar_sim PRIVATE src src/glad/include)

# Link GLAD and GLFW
target_link_libraries(solar_sim glad ${GLFW_LIBRARIES})
