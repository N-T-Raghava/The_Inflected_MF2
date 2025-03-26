cmake_minimum_required(VERSION 3.10)

project(MF2)

set(CMAKE_CXX_STANDARD 17)

# Include header files from 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files from 'src' directory (excluding main.cpp)
file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Add executable for main program
add_executable(main src/main.cpp ${SOURCES})

# Add executable for Catch2-based tests
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(tests ${SOURCES} ${TEST_SOURCES})

