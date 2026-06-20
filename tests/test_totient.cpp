#include <catch2/catch_test_macros.hpp>
#include "ntlab/totient.hpp"

using namespace ntlab;

TEST_CASE("phi_works")
{
    REQUIRE( phi( 1 ) == 1 );
    REQUIRE( phi( 2 ) == 1 );
    REQUIRE( phi( 9 ) == 6 );
    REQUIRE( phi( 10 ) == 4 );
    REQUIRE( phi( 12 ) == 4 );
    REQUIRE( phi( 13 ) == 12 );
    REQUIRE( phi( 36 ) == 12 );
}

TEST_CASE( "carmichael_divides_phi" )
{
    for ( u64 n = 1; n <= 1000; ++n )
    {
        REQUIRE( phi( n ) % carmichael( n ) == 0 );
    }
}