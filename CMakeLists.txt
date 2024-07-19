cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD           20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)

project(TimeEstimationApp)
add_executable(${PROJECT_NAME} main.cpp)
add_library(util lib/util.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-window)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)