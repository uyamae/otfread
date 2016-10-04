cmake_minimum_required(VERSION 2.8)
include_directories("${PROJECT_SOURCE_DIR}/otfread")
add_executable(App main.cpp)
target_link_libraries(App otfread)

