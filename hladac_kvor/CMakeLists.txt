cmake_minimum_required(VERSION 3.13)
project(hladac_kvor)

set(CMAKE_CXX_STANDARD 17)

add_executable(hladac_kvor main.cpp common.cpp common.h QuorumFinder.h FindingStrategy.h)