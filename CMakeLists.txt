cmake_minimum_required(VERSION 3.16)
project(numbTheoryLab CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ntlab STATIC
    src/arithmetic.cpp
    src/primes.cpp
    src/factor.cpp
)
target_include_directories(ntlab PUBLIC include)


add_executable(nttool apps/nttool.cpp)
target_link_libraries(nttool PRIVATE ntlab)
