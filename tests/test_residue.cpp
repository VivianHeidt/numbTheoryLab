#include <catch2/catch_test_macros.hpp>
#include "ntlab/residue.hpp"
#include "ntlab/arithmetic.hpp"

using namespace ntlab;

TEST_CASE("legendre_symbol_works")
{
    REQUIRE( legendre( 0, 7 ) == 0 );
    REQUIRE( legendre( 1, 7 ) == 1 );
    REQUIRE( legendre( 2, 7 ) == 1 );
    REQUIRE( legendre( 3, 7 ) == -1 );
    REQUIRE( legendre( -1, 5 ) == 1 );
    REQUIRE( legendre( -1, 7 ) == -1 );
}

TEST_CASE("jacobi_symbol_works")
{
    REQUIRE( jacobi( 1, 15 ) == 1 );
    REQUIRE( jacobi( 2, 15 ) == 1 );
    REQUIRE( jacobi( 5, 15 ) == 0 );
    REQUIRE( jacobi( 7, 15 ) == -1 );
    REQUIRE( jacobi( 1001, 9907 ) == -1 );
}

TEST_CASE("sqrt_mod_prime_handles_simple_cases")
{
    auto r1 = sqrt_mod_prime( 10, 13 );
    REQUIRE( r1.has_value() );
    REQUIRE( mulmod( *r1, *r1, 13 ) == 10 );

    auto r2 = sqrt_mod_prime( 4, 7 );
    REQUIRE( r2.has_value() );
    REQUIRE( mulmod( *r2, *r2, 7 ) == 4 );

    auto r3 = sqrt_mod_prime( 0, 13 );
    REQUIRE( r3.has_value() );
    REQUIRE( *r3 == 0 );

    auto r4 = sqrt_mod_prime( 1, 2 );
    REQUIRE( r4.has_value() );
    REQUIRE( *r4 == 1 );
}

TEST_CASE("sqrt_mod_prime_returns_nullopt_for_non_residues")
{
    auto r = sqrt_mod_prime( 5, 13 );
    REQUIRE_FALSE( r.has_value() );
}