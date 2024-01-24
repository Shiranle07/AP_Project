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
    src/CheckUrlCommand.cpp
)

set(INSERT_TEST_FILES
    tests/test_main.cpp #this is the main for tests
    tests/InsertCommand_test.cpp # this file contain the tests
)

set(CHECK_TEST_FILES
    tests/test_main.cpp #this is the main for tests
    tests/CheckCommand_test.cpp
)

add_executable(InsertTests ${INSERT_TEST_FILES})
add_executable(CheckTests ${CHECK_TEST_FILES})


#Link Google Test to the test executable
target_link_libraries(InsertTests PRIVATE gtest gtest_main pthread)
target_link_libraries(CheckTests PRIVATE gtest gtest_main pthread)


#Include the source directory for tests
target_include_directories(InsertTests PRIVATE src)
target_include_directories(CheckTests PRIVATE src)


include(GoogleTest)
add_test(NAME InsertTests COMMAND InsertTests)
add_test(NAME CheckTests COMMAND CheckTests)