#include <catch2/catch_test_macros.hpp>
#include <map>

#include "ntlab/utils.hpp"

using namespace ntlab;

TEST_CASE("prime_factor_exponents of 1")
{
    std::map<u64, u64> expected{};

    REQUIRE( prime_factor_exponents( 1 ) == expected );
}

TEST_CASE("prime_factor_exponents of prime")
{
    std::map<u64, u64> expected =
    {
        { 2, 1 }
    };

    REQUIRE( prime_factor_exponents( 2 ) == expected );
}

TEST_CASE("prime_factor_exponents of 12")
{
    std::map<u64, u64> expected =
    {
        { 2, 2 },
        { 3, 1 }
    };

    REQUIRE( prime_factor_exponents( 12 ) == expected );
}

TEST_CASE("prime_factor_exponents of 36")
{
    std::map<u64, u64> expected =
    {
        { 2, 2 },
        { 3, 2 }
    };

    REQUIRE( prime_factor_exponents( 36 ) == expected );
}

TEST_CASE("prime_factor_exponents of 60")
{
    std::map<u64, u64> expected =
    {
        { 2, 2 },
        { 3, 1 },
        { 5, 1 }
    };

    REQUIRE( prime_factor_exponents( 60 ) == expected );
}

TEST_CASE("prime_factor_exponents of power")
{
    std::map<u64, u64> expected =
    {
        { 2, 10 }
    };

    REQUIRE( prime_factor_exponents( 1024 ) == expected );
}