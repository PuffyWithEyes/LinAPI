cmake_minimum_required(VERSION 3.23)
project(linapi)

set(CMAKE_CXX_STANDARD 17)

add_executable(linapi test/unit_tests.cpp bin/linapi.cpp bin/linapi.hpp)
