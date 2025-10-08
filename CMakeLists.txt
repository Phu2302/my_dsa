cmake_minimum_required(VERSION 3.10)
project(my_dsa)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thêm thư mục include/
include_directories(include)

# --- Gom toàn bộ file .cpp trong src/ ---
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# --- Gom toàn bộ file .cpp trong tests/ ---
file(GLOB_RECURSE TEST_FILES tests/*.cpp)

# --- Tạo thư viện dsa_lib từ code chính ---
add_library(dsa_lib ${SRC_FILES})

# --- Tạo executable main từ test runner + các file test ---
add_executable(main ${TEST_FILES})

# --- Link executable với thư viện dsa_lib ---
target_link_libraries(main dsa_lib)
