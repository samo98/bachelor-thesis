cmake_minimum_required(VERSION 3.13)
project(safety_coefficient_finder)

set(CMAKE_CXX_STANDARD 17)

add_executable(safety_coefficient_finder main.cpp QuorumFinder.h FindingStrategy.h helpers.h IntersectionFinder.h)