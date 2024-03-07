cmake_minimum_required(VERSION 3.16.3)
project(VendingMachine LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
# this mandatory command will be the one that will make your cross-compiling work
set(CMAKE_SYSTEM_NAME Linux)

#Necessary for shared library on Windows
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_library(code SHARED code/VendingMachine.h)
target_include_directories(code PRIVATE "${PROJECT_SOURCE_DIR}")
add_subdirectory("code")

add_library(catch2 SHARED )
target_include_directories(catch2 PRIVATE "${PROJECT_SOURCE_DIR}")
add_subdirectory("include")

add_executable(main)
target_sources(main PRIVATE "main.cpp")
target_link_libraries(main PRIVATE code)

add_executable(test1)
target_sources(test1 PRIVATE "tests/test1.cpp")
target_link_libraries(test1 PRIVATE code catch2)

add_executable(test2)
target_sources(test2 PRIVATE "tests/test2.cpp")
target_link_libraries(test2 PRIVATE code catch2)

add_executable(test3)
target_sources(test3 PRIVATE "tests/test3.cpp")
target_link_libraries(test3 PRIVATE code catch2)

add_executable(test4)
target_sources(test4 PRIVATE "tests/test4.cpp")
target_link_libraries(test4 PRIVATE code catch2)