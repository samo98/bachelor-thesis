cmake_minimum_required(VERSION 3.13)
project(network_generator)

set(CMAKE_CXX_STANDARD 14)

add_executable(network_generator main.cpp NetworkCreator.h CreatingStrategy.h)