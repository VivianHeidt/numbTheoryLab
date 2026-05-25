#include <vector>
#include <catch2/catch_test_macros.hpp>
#include "ntlab/factor.hpp"
#include "ntlab/primes.hpp"

using namespace ntlab;

void check_factorization(u64 n)
{
    auto f = factorize(n);

    u64 product = 1;

    for (u64 p : f)
    {
        REQUIRE(is_prime(p));
        product *= p;
    }

    REQUIRE(product == n);
}

TEST_CASE("factorize_properties_work")
{
    check_factorization(1);
    check_factorization(2);
    check_factorization(84);
    check_factorization(97);
    check_factorization(600851475143ULL);
}

TEST_CASE("factorize_known_values")
{
    REQUIRE(factorize(1).empty());
    REQUIRE(factorize(2) == std::vector<u64>{2});
    REQUIRE(factorize(84) == std::vector<u64>{2, 2, 3, 7});
    REQUIRE(factorize(97) == std::vector<u64>{97});
    REQUIRE(factorize(600851475143ULL) == std::vector<u64>{71, 839, 1471, 6857});
}

TEST_CASE("pollard_rho_finds_nontrivial_factors")
{
    for (u64 n : {91ULL, 221ULL, 8051ULL})
    {
        u64 d = pollard_rho(n);

        REQUIRE(d != 1);
        REQUIRE(d != n);
        REQUIRE(n % d == 0);
    }
}