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

TEST_CASE( "is_primitive_root_works_for_prime_moduli" )
{
    REQUIRE( is_primitive_root( 1, 2 ) );

    REQUIRE( is_primitive_root( 2, 3 ) );

    REQUIRE( is_primitive_root( 2, 5 ) );
    REQUIRE( is_primitive_root( 3, 5 ) );
    REQUIRE_FALSE( is_primitive_root( 4, 5 ) );

    REQUIRE( is_primitive_root( 3, 7 ) );
    REQUIRE( is_primitive_root( 5, 7 ) );
    REQUIRE_FALSE( is_primitive_root( 2, 7 ) );

    REQUIRE( is_primitive_root( 3, 17 ) );
    REQUIRE( is_primitive_root( 5, 17 ) );
    REQUIRE_FALSE( is_primitive_root( 4, 17 ) );
}

TEST_CASE( "primitive_root_returns_valid_generator" )
{
    REQUIRE( primitive_root( 2 ) == 1 );

    for ( u64 p : { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 } )
    {
        u64 g = primitive_root( p );

        REQUIRE( g >= 1 );
        REQUIRE( g < p );
        REQUIRE( is_primitive_root( g, p ) );
    }
}

TEST_CASE( "primitive_root_known_small_values" )
{
    REQUIRE( primitive_root( 2 ) == 1 );
    REQUIRE( primitive_root( 3 ) == 2 );
    REQUIRE( primitive_root( 5 ) == 2 );
    REQUIRE( primitive_root( 7 ) == 3 );
    REQUIRE( primitive_root( 11 ) == 2 );
    REQUIRE( primitive_root( 17 ) == 3 );
}