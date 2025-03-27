cmake_minimum_required(VERSION 3.10)

project(TheInflectedMF2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define executable
add_executable(tests
    src/mf2.cpp
    src/dict.cpp
    src/inflection.cpp    
    tests/tests.cpp
)

# Include directories
target_include_directories(tests PRIVATE include)
