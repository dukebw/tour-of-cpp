cmake_minimum_required(VERSION 3.24)
project(tour-of-cpp VERSION 0.0.1 LANGUAGES CXX)

add_executable(resource_management src/resource_management.cpp)
target_compile_features(resource_management PRIVATE cxx_std_20)
