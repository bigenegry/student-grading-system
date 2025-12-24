cmake_minimum_required(VERSION 3.10)
project(student_grading_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(student_grading_system
    src/main.cpp
    src/Person.cpp
    src/InputPerson.cpp
    src/OutputPerson.cpp
    src/Utilities.cpp
)
