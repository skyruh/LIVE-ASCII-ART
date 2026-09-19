cmake_minimum_required(VERSION 3.15)
project(ASCII_Camera CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages installed by vcpkg
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Practice: Person A experiments
add_executable(practice_1 practise/1.cpp)
target_link_libraries(practice_1 PRIVATE glfw glad::glad OpenGL::GL)
target_include_directories(practice_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
