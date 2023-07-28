cmake_minimum_required(VERSION 3.25)
project(simd_cuda_testing)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(vector-addition)
add_subdirectory(dot-product)