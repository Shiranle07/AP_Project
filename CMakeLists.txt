cmake_minimum_required(VERSION 3.14)
project("AP_Project") 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

enable_testing()
set(SOURCE_FILES
    src/InsertUrlCommand.cpp # this is where the code we want to test
    src/BloomFilter.h
    src/HashOne.h
    src/HashTwo.h
    src/InsertUrlCommand.h
    src/BloomFilter.cpp
    src/HashOne.cpp
    src/HashTwo.cpp
    src/CheckUrlCommand.cpp
    src/CheckUrlCommand.h
)

set(TEST_FILES
    tests/test_main.cpp #this is the main for tests
    tests/InsertCommand_test.cpp # this file contain the tests
)

add_executable(ProjectTests ${TEST_FILES})

#Link Google Test to the test executable
target_link_libraries(ProjectTests PRIVATE gtest gtest_main pthread)

#Include the source directory for tests
target_include_directories(ProjectTests PRIVATE src)

include(GoogleTest)
add_test(NAME ProjectTests COMMAND ProjectTests)