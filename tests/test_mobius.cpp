#include <catch2/catch_test_macros.hpp>
#include "ntlab/mobius.hpp"

using namespace ntlab;

TEST_CASE("mobius_works")
{
    REQUIRE( mobius( 1 ) == 1 );
    REQUIRE( mobius( 2 ) == -1 );
    REQUIRE( mobius( 3 ) == -1 );
    REQUIRE( mobius( 6 ) == 1 );
    REQUIRE( mobius( 10 ) == 1 );
    REQUIRE( mobius( 12 ) == 0 );
    REQUIRE( mobius( 18 ) == 0 );
    REQUIRE( mobius( 30 ) == -1 );
}