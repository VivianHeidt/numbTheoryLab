#include <catch2/catch_test_macros.hpp>
#include "ntlab/sieve.hpp"

using namespace ntlab;

TEST_CASE("small_limits")
{
    REQUIRE( primes_up_to( 0 ) == std::vector<ntlab::u64>{} );
    REQUIRE( primes_up_to( 1 ) == std::vector<ntlab::u64>{} );
    REQUIRE( primes_up_to( 2 ) == std::vector<ntlab::u64>{ 2 } );
}

TEST_CASE("primes_up_to_10/30")
{
    REQUIRE( primes_up_to( 10 ) == std::vector<ntlab::u64>{ 2, 3, 5, 7 } );
    REQUIRE( primes_up_to( 30 ) == std::vector<ntlab::u64>{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 } );
}

TEST_CASE("prime_counts")
{
    REQUIRE( prime_count( 0 ) == 0 );
    REQUIRE( prime_count( 1 ) == 0 );
    REQUIRE( prime_count( 2 ) == 1 );
    REQUIRE( prime_count( 10 ) == 4 );
}

TEST_CASE("larger_known_values")
{
    REQUIRE( prime_count( 100 ) == 25 );
    REQUIRE( prime_count( 1000 ) == 168 );
}