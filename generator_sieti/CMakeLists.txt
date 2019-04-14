cmake_minimum_required(VERSION 3.13)
project(generator_sieti)

set(CMAKE_CXX_STANDARD 14)

add_executable(generator_sieti main.cpp NetworkCreator.h CreatingStrategy.h)