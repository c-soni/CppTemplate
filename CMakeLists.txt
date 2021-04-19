cmake_minimum_required(VERSION 3.19)
project(CMakeStarterProject CXX)

include(cmake/SetCompilerWarnings.cmake)

# add the executable
add_executable(app src/main.cpp)
add_library(project_options INTERFACE)

target_compile_features(project_options INTERFACE cxx_std_20)
set_project_warnings(project_options)

target_link_libraries(app project_options)
