#include <catch2/catch_test_macros.hpp>
#include "ntlab/congruence.hpp"

using namespace ntlab;

TEST_CASE( "linear_congruence_works" )
{
    auto s1 = solve_linear_congruence( 3, 6, 9 );
    REQUIRE( s1.has_value() );
    REQUIRE( ( 3 * *s1 ) % 9 == 6 % 9 );

    auto s2 = solve_linear_congruence( 2, 1, 4 );
    REQUIRE_FALSE( s2.has_value() );

    auto s3 = solve_linear_congruence( 1, 5, 7 );
    REQUIRE( s3.has_value() );
    REQUIRE( *s3 == 5 );
    REQUIRE( ( 1 * *s3 ) % 7 == 5 % 7 );
}

TEST_CASE( "crt_works" )
{
    auto res = crt( 2, 3, 3, 5 );

    REQUIRE( res.has_value() );

    u64 r = res->first;
    u64 M = res->second;

    REQUIRE( r == 8 );
    REQUIRE( M == 15 );

    REQUIRE( r % 3 == 2 );
    REQUIRE( r % 5 == 3 );
}

TEST_CASE( "crt_detects_no_solution" )
{
    auto res = crt( 1, 2, 0, 4 );

    REQUIRE_FALSE( res.has_value() );
}