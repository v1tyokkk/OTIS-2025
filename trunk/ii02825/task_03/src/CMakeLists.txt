cmake_minimum_required(VERSION 3.10)
project(Lab3PID)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
    lab3.cpp
    pid.cpp
    model.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lab3 ${SRC_FILES})

enable_testing()

find_package(GTest REQUIRED)

add_executable(testlab3_runner
    ../test/testlab3.cpp
    pid.cpp
    model.cpp
)

target_link_libraries(testlab3_runner GTest::gtest_main pthread)

add_test(NAME PIDTests COMMAND testlab3_runner)
