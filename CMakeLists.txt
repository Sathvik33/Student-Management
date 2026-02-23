cmake_minimum_required(VERSION 3.16)
project(StudentRecordSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.10.2/mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(StudentUI
    ui_main.cpp
    backend.cpp
)

target_link_libraries(StudentUI Qt6::Widgets)