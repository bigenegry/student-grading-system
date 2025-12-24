cmake_minimum_required(VERSION 3.10)
project(student_grading_system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student_grading_system
    src/main.cpp
    src/Person.cpp
)
