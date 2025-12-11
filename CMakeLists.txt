cmake_minimum_required(VERSION 3.10)
project(my_dsa)

# Dùng C++17 cho hiện đại và ít lỗi vặt
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============================================================
# 1. SETUP ĐƯỜNG DẪN INCLUDE
# =============================================================
# Giúp code thấy folder include (để #include "queue/Queue.h")
include_directories(include)

# Giúp code thấy folder src (để #include "data_structures/..." trong file .h)
include_directories(src)

# =============================================================
# 2. GOM SOURCE VÀ LỌC FILE (PHẦN QUAN TRỌNG NHẤT)
# =============================================================
# Bước 1: Gom toàn bộ file .cpp trong folder src
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Bước 2: LỌC BỎ các file Template Implementation 
# (Vì các file này đã được #include thẳng vào cuối file .h, 
# nếu để CMake biên dịch nữa sẽ bị lỗi "Multiple Definition")

# Lọc ArrayList (Giải quyết lỗi Linker ArrayList)
list(FILTER SRC_FILES EXCLUDE REGEX ".*/array/ArrayList.cpp$")

# Lọc QueueArray (Giải quyết lỗi Linker Queue)
# Lưu ý: Tên file phải khớp chính xác với file trong ổ cứng của bạn (QueueArray.cpp)
list(FILTER SRC_FILES EXCLUDE REGEX ".*/queue/QueueArray.cpp$")
list(FILTER SRC_FILES EXCLUDE REGEX ".*/queue/Queue.cpp$") 
list(FILTER SRC_FILES EXCLUDE REGEX ".*/algorithms/sorting.cpp$")

# Lọc file main.cpp trong src (nếu có) để tránh xung đột với tests/main.cpp
list(FILTER SRC_FILES EXCLUDE REGEX ".*/src/main.cpp$")

# =============================================================
# 3. TẠO THƯ VIỆN VÀ FILE CHẠY
# =============================================================
# Tạo thư viện dsa_lib từ danh sách file đã lọc
add_library(dsa_lib ${SRC_FILES})

# Gom toàn bộ file test
file(GLOB_RECURSE TEST_FILES "tests/*.cpp")

# Tạo file chạy main.exe
add_executable(main ${TEST_FILES})

# Nối file chạy với thư viện
target_link_libraries(main dsa_lib)