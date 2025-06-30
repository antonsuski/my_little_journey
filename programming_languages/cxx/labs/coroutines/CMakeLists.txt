cmake_minimum_required(VERSION 3.10)
project(00)

find_package(Boost REQUIRED)


add_executable(00 00.cxx)
target_include_directories(00 PRIVATE ${Boost_INCLUDE_DIRS})
target_compile_options(00 PUBLIC --std=c++23)

