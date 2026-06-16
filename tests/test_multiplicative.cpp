#include <catch2/catch_test_macros.hpp>
#include "ntlab/multiplicative.hpp"
#include "ntlab/totient.hpp"
#include "ntlab/mobius.hpp"
#include "ntlab/divisors.hpp"

using namespace ntlab;

TEST_CASE( "identity_works" )
{
    REQUIRE( identity( 1 ) == 1 );
    REQUIRE( identity( 2 ) == 2 );
    REQUIRE( identity( 42 ) == 42 );
    REQUIRE( identity( 999999 ) == 999999 );
}

TEST_CASE( "one_works" )
{
    REQUIRE( one( 1 ) == 1 );
    REQUIRE( one( 2 ) == 1 );
    REQUIRE( one( 42 ) == 1 );
    REQUIRE( one( 999999 ) == 1 );
}

TEST_CASE( "epsilon_works" )
{
    REQUIRE( epsilon( 1 ) == 1 );
    REQUIRE( epsilon( 2 ) == 0 );
    REQUIRE( epsilon( 3 ) == 0 );
    REQUIRE( epsilon( 12 ) == 0 );
    REQUIRE( epsilon( 999999 ) == 0 );
}

TEST_CASE( "liouville_works" )
{
    REQUIRE( liouville( 1 ) == 1 );

    REQUIRE( liouville( 2 ) == -1 );
    REQUIRE( liouville( 3 ) == -1 );
    REQUIRE( liouville( 5 ) == -1 );

    REQUIRE( liouville( 4 ) == 1 );    // 2^2
    REQUIRE( liouville( 6 ) == 1 );    // 2 * 3
    REQUIRE( liouville( 8 ) == -1 );   // 2^3
    REQUIRE( liouville( 12 ) == -1 );  // 2^2 * 3
    REQUIRE( liouville( 36 ) == 1 );   // 2^2 * 3^2
    REQUIRE( liouville( 72 ) == -1 );  // 2^3 * 3^2
}

TEST_CASE( "dirichlet_convolution_one_one_counts_divisors" )
{
    REQUIRE( dirichlet_convolution( one, one, 1 ) == 1 );
    REQUIRE( dirichlet_convolution( one, one, 2 ) == 2 );
    REQUIRE( dirichlet_convolution( one, one, 6 ) == 4 );
    REQUIRE( dirichlet_convolution( one, one, 12 ) == 6 );
    REQUIRE( dirichlet_convolution( one, one, 36 ) == 9 );
}

TEST_CASE( "dirichlet_convolution_identity_one_sums_divisors" )
{
    REQUIRE( dirichlet_convolution( identity, one, 1 ) == 1 );
    REQUIRE( dirichlet_convolution( identity, one, 2 ) == 3 );
    REQUIRE( dirichlet_convolution( identity, one, 6 ) == 12 );
    REQUIRE( dirichlet_convolution( identity, one, 12 ) == 28 );
    REQUIRE( dirichlet_convolution( identity, one, 36 ) == 91 );
}

TEST_CASE( "dirichlet_convolution_with_epsilon_is_identity_element" )
{
    REQUIRE( dirichlet_convolution( identity, epsilon, 1 ) == identity( 1 ) );
    REQUIRE( dirichlet_convolution( identity, epsilon, 6 ) == identity( 6 ) );
    REQUIRE( dirichlet_convolution( identity, epsilon, 36 ) == identity( 36 ) );

    REQUIRE( dirichlet_convolution( one, epsilon, 1 ) == one( 1 ) );
    REQUIRE( dirichlet_convolution( one, epsilon, 6 ) == one( 6 ) );
    REQUIRE( dirichlet_convolution( one, epsilon, 36 ) == one( 36 ) );

    REQUIRE( dirichlet_convolution( liouville, epsilon, 1 ) == liouville( 1 ) );
    REQUIRE( dirichlet_convolution( liouville, epsilon, 12 ) == liouville( 12 ) );
    REQUIRE( dirichlet_convolution( liouville, epsilon, 72 ) == liouville( 72 ) );
}

TEST_CASE( "dirichlet_convolution_identity_mobius_equals_phi" )
{
    REQUIRE( dirichlet_convolution( identity, mobius, 1 ) == phi( 1 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 2 ) == phi( 2 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 3 ) == phi( 3 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 4 ) == phi( 4 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 5 ) == phi( 5 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 6 ) == phi( 6 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 12 ) == phi( 12 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 24 ) == phi( 24 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 36 ) == phi( 36 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 72 ) == phi( 72 ) );
    REQUIRE( dirichlet_convolution( identity, mobius, 100 ) == phi( 100 ) );
}

TEST_CASE( "dirichlet_convolution_identity_mobius_equals_phi_many_values" )
{
    for ( u64 n = 1; n <= 1000; ++n )
    {
        REQUIRE
        (
            dirichlet_convolution( identity, mobius, n )
            == phi( n )
        );
    }
}

TEST_CASE( "dirichlet_convolution_one_one_equals_tau_many_values" )
{
    for ( u64 n = 1; n <= 1000; ++n )
    {
        REQUIRE
        (
            dirichlet_convolution( one, one, n )
            == tau( n )
        );
    }
}

TEST_CASE( "dirichlet_convolution_identity_one_equals_sigma_many_values" )
{
    for ( u64 n = 1; n <= 1000; ++n )
    {
        REQUIRE
        (
            dirichlet_convolution( identity, one, n )
            == sigma( n )
        );
    }
}

TEST_CASE( "dirichlet_convolution_epsilon_is_identity_many_values" )
{
    for ( u64 n = 1; n <= 1000; ++n )
    {
        REQUIRE
        (
            dirichlet_convolution( identity, epsilon, n )
            == identity( n )
        );

        REQUIRE
        (
            dirichlet_convolution( one, epsilon, n )
            == one( n )
        );

        REQUIRE
        (
            dirichlet_convolution( liouville, epsilon, n )
            == liouville( n )
        );
    }
}