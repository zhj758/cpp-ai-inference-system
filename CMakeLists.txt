cmake_minimum_required(VERSION 3.16)
project(ai_inference VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# 主程序
add_executable(ai_demo src/main.cpp src/utils.cpp)

# 容器练习程序
add_executable(container_demo src/demo.cpp)

#链表算法（反转、合并）
add_executable(linked_list src/linked_list.cpp)

#智能指针（shared_ptr / unique_ptr / weak_ptr）
add_executable(smart_ptr src/smart_ptr_demo.cpp)

#写一个自己的 Logger，支持 INFO/WARN/ERROR 和时间戳
add_executable(test_logger src/test_logger.cpp src/logger.cpp)