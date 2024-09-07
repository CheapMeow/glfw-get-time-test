cmake_minimum_required(VERSION 3.24)
project(GLFWGetTimeTest CXX)

# Stop in source builds
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(ENGINE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_ROOT_DIR ${ENGINE_ROOT_DIR}/src)
set(3RD_PARTY_ROOT_DIR ${SRC_ROOT_DIR}/3rdparty)

set(RUNTIME_NAME Runtime)
set(EDITOR_NAME Editor)

add_subdirectory(src/3rdparty)
add_subdirectory(src/runtime)
add_subdirectory(src/editor)