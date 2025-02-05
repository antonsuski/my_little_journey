# general settings
cmake_minimum_required(VERSION 3.25)
project(observer LANGUAGES CXX)

# building observer class as library
add_library(observer STATIC obs.cxx sbj.cxx)
target_include_directories(observer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# exe
add_executable(test main.cxx)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test PRIVATE observer)
