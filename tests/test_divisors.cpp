#include <catch2/catch_test_macros.hpp>
#include "ntlab/divisors.hpp"

using namespace ntlab;

TEST_CASE("tau_works")
{
    REQUIRE( tau( 1 ) == 1 );
    REQUIRE( tau( 2 ) == 2 );
    REQUIRE( tau( 12 ) == 6 );
    REQUIRE( tau( 13 ) == 2 );
    REQUIRE( tau( 36 ) == 9 );
}

TEST_CASE("sigma_works")
{
    REQUIRE( sigma( 1 ) == 1 );
    REQUIRE( sigma( 2 ) == 3 );
    REQUIRE( sigma( 12 ) == 28 );
    REQUIRE( sigma( 13 ) == 14 );
    REQUIRE( sigma( 36 ) == 91 );
}

TEST_CASE("divisors_work")
{
    REQUIRE( divisors( 1 ) == std::vector<ntlab::u64>{ 1 } );
    REQUIRE( divisors( 2 ) == std::vector<ntlab::u64>{ 1, 2 } );
    REQUIRE( divisors( 12 ) == std::vector<ntlab::u64>{ 1, 2, 3, 4, 6, 12 } );
    REQUIRE( divisors( 36 ) ==  std::vector<ntlab::u64>{ 1, 2, 3, 4, 6, 9, 12, 18, 36 } );
}