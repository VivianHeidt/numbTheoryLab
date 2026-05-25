#include <catch2/catch_test_macros.hpp>
#include "ntlab/primes.hpp"

using namespace ntlab;

TEST_CASE("is_prime_works")
{
    REQUIRE(is_prime(2));
    REQUIRE(is_prime(3));
    REQUIRE(is_prime(97));
    REQUIRE_FALSE(is_prime(0));
    REQUIRE_FALSE(is_prime(1));
    REQUIRE_FALSE(is_prime(4));
    REQUIRE_FALSE(is_prime(9));
    REQUIRE_FALSE(is_prime(21));
    REQUIRE_FALSE(is_prime(561));
    REQUIRE_FALSE(is_prime(1105));
    REQUIRE_FALSE(is_prime(1729));
}


TEST_CASE("next_prime_works")
{
    REQUIRE(next_prime(0) == 2);
    REQUIRE(next_prime(2) == 2);
    REQUIRE(next_prime(14) == 17);
    REQUIRE(next_prime(17) == 17);
    REQUIRE(next_prime(18) == 19);
}