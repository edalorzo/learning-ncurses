cmake_minimum_required(VERSION 3.20)
project(LearningCurses)
set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)
include_directories(CURSES_INCLUDE_DIRS)

message(STATUS "${CURSES_INCLUDE_DIRS}")
message(STATUS "${CURSES_LIBRARIES}")

add_executable(my-curses-app main.cpp)
target_link_libraries(my-curses-app ${CURSES_LIBRARIES})
