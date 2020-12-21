cmake_minimum_required(VERSION 3.14)
project(graph-project-lospandemials)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(graph-project-lospandemials main.cpp)
target_link_libraries(graph-project-lospandemials sfml-system sfml-window sfml-graphics)