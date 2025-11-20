# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(StudentSorter CXX)

set(CMAKE_CXX_STANDARD 17)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(v0_2_vector
    ${SRC_DIR}/main_vec.cpp
    ${SRC_DIR}/Student.cpp
    ${SRC_DIR}/FileGenerator.cpp
    ${SRC_DIR}/StudentIO.cpp
)

add_executable(v0_25_list
    ${SRC_DIR}/main_list.cpp
    ${SRC_DIR}/Student.cpp
    ${SRC_DIR}/FileGenerator.cpp
    ${SRC_DIR}/StudentIO.cpp
)

add_executable(v0_25_deque
    ${SRC_DIR}/main_deque.cpp
    ${SRC_DIR}/Student.cpp
    ${SRC_DIR}/FileGenerator.cpp
    ${SRC_DIR}/StudentIO.cpp
)
