#include <catch2/catch_test_macros.hpp>
#include "ntlab/arithmetic.hpp"

using namespace ntlab;

void check_xgcd( i64 a, i64 b )
{
    auto r = xgcd( a, b );
    REQUIRE( a * r.x + b * r.y == static_cast<i64>( r.g ) );
}

TEST_CASE( "gcd_works" )
{
    REQUIRE( gcd( 48, 18 ) == 6 );
    REQUIRE( gcd( 0, 5 ) == 5 );
    REQUIRE( gcd( 5, 0 ) == 5 );
    REQUIRE( gcd( 0, 0 ) == 0 );
    REQUIRE( gcd( 17, 13 ) == 1 );
}

TEST_CASE( "xgcd_works" )
{
    check_xgcd( 30, 12 );
    check_xgcd( 101, 23 );
    check_xgcd( -30, 12 );
    check_xgcd( 0, 7 );
}

TEST_CASE( "modinv_works" )
{
    auto inv1 = modinv( 3, 11 );
    REQUIRE( inv1.has_value() );
    REQUIRE( inv1 == 4 );
    REQUIRE( ( 3 * *inv1 ) % 11 == 1 );

    auto inv2 = modinv( 10, 17 );
    REQUIRE( inv2.has_value() );
    REQUIRE( inv2 == 12 );
    REQUIRE( ( 10 * *inv2 ) % 17 == 1 );

    REQUIRE_FALSE( modinv( 2, 4 ) );
    REQUIRE_FALSE( modinv( 0, 7 ) );
    REQUIRE_FALSE(modinv( 1, 1 ) );
}

TEST_CASE( "powmod_works" )
{
    REQUIRE( powmod( 2, 10, 1000 ) == 24 );
    REQUIRE( powmod( 3, 0, 7 ) == 1 );
    REQUIRE( powmod( 0, 5, 7 ) == 0 );
    REQUIRE( powmod( 5, 3, 1 ) == 0 );
}
