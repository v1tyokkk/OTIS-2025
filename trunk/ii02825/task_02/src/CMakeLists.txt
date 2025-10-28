cmake_minimum_required(VERSION 3.10)
project(Task02)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(main src/main.cpp src/functions.cpp)

# Тесты
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests test/test.cpp src/functions.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(NAME RunAllTests COMMAND runTests)
