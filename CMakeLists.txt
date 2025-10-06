cmake_minimum_required(VERSION 3.10)
project(my_dsa)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thêm include/
include_directories(include)

# Gom tất cả .cpp trong src/
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Tạo thư viện chung từ toàn bộ src
add_library(dsa_lib ${SRC_FILES})

# =============================
#  Build từng test riêng lẻ
# =============================

# Test singly linked list
add_executable(test_slinkedlist tests/linked_list/test_slinkedlist.cpp)
target_link_libraries(test_slinkedlist dsa_lib)

# Test doubly linked list
#add_executable(test_dlinkedlist tests/linked_list/test_dlinkedlist.cpp)
#target_link_libraries(test_dlinkedlist dsa_lib)

# Test stack
#add_executable(test_stack tests/stack/test_stack.cpp)
#target_link_libraries(test_stack dsa_lib)

# (Tương tự bạn add các test khác)
