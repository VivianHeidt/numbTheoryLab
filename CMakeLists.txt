cmake_minimum_required(VERSION 3.16)

project(numbTheoryLab CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ntlab STATIC
    src/arithmetic.cpp
    src/primes.cpp
    src/factor.cpp
    src/congruence.cpp
    src/sieve.cpp
    src/divisors.cpp
    src/utils.cpp 
    src/totient.cpp 
)

target_include_directories(ntlab PUBLIC include)

add_executable(nttool apps/nttool.cpp)
target_link_libraries(nttool PRIVATE ntlab)

# ---------------- Tests / Catch2 ----------------

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

enable_testing()

add_executable(ntlab_tests
    tests/test_arithmetic.cpp
    tests/test_primes.cpp
    tests/test_factor.cpp
    tests/test_congruence.cpp
    tests/test_sieve.cpp
    tests/test_divisors.cpp
    tests/test_utils.cpp 
    tests/test_totient.cpp 
)

target_link_libraries(ntlab_tests
    PRIVATE
        ntlab
        Catch2::Catch2WithMain
)