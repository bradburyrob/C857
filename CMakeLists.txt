cmake_minimum_required(VERSION 3.17)
project(StudentRoster)

set(CMAKE_CXX_STANDARD 14)

add_executable(StudentRoster main.cpp student.cpp student.h roster.cpp roster.h degree.h)