cmake_minimum_required(VERSION 3.10)
project(Task02)

set(CMAKE_CXX_STANDARD 17)

# Пути к исходникам
include_directories(src)

# Файлы функций (без main_program.cpp)
set(FUNCTIONS_SOURCES
    src/functions.cpp
)

# Основная программа
add_executable(task_02_program
    src/main_program.cpp
    src/functions.cpp
)

# Пути к GoogleTest (Homebrew на Apple Silicon)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Тесты
add_executable(runTests_ii02825
    ${FUNCTIONS_SOURCES}  # только функции
    test/test.cpp
)

# Линковка тестов с gtest_main
target_link_libraries(runTests_ii02825 gtest gtest_main pthread)

# Флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pthread")
