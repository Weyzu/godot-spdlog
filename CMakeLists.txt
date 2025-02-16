cmake_minimum_required(VERSION 3.22)
project(godot-spdlog VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# === Dependencies ==
set(GODOT_CPP_DIR "${CMAKE_SOURCE_DIR}/external/godot-cpp")
set(GODOT_GDEXTENSION_DIR "${GODOT_CPP_DIR}/gdextension")
set(SPDLOG_DIR "${CMAKE_SOURCE_DIR}/external/spdlog")
# ===================

add_subdirectory(${GODOT_CPP_DIR} "${CMAKE_BINARY_DIR}/godot-cpp-build")
add_subdirectory(${SPDLOG_DIR} "${CMAKE_BINARY_DIR}/spdlog-build")

set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(SOURCES
  ${PROJECT_SRC_DIR}/register_types.cpp
  ${PROJECT_SRC_DIR}/logger.cpp
)

add_library(godot-spdlog SHARED ${SOURCES})

target_include_directories(godot-spdlog PRIVATE
  ${PROJECT_SRC_DIR}
  ${GODOT_CPP_DIR}/include
  ${SPDLOG_DIR}/include
)

# TODO: link to template_debug when building debug
target_link_libraries(godot-spdlog PRIVATE
  godot-cpp
  spdlog
)
