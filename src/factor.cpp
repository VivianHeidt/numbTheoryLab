#include "ntlab/factor.hpp"
#include "ntlab/arithmetic.hpp"
#include "ntlab/primes.hpp"

#include <algorithm>
#include <vector>

namespace 
{

using ntlab::u64;

//absolute difference for u64
static inline u64 udiff( u64 a, u64 b ) noexcept
{
    return ( a > b ) ? ( a - b ) : ( b - a );
}

// f(x) = x^2 + c mod n
static inline u64 f(  u64 x, u64 c, u64 n ) noexcept
{
    return ( ntlab::mulmod( x, x, n ) + c ) % n;
}

// One attempt of Pollard Rho (may fail -> returns n)
static u64 rho_once(u64 n) noexcept 
{
    if ( ( n & 1ULL ) == 0 ) return 2;

    auto& gen = ntlab::rng();
    std::uniform_int_distribution<u64> dist( 2, n - 2 );

    u64 x = dist( gen );
    u64 y = x;
    u64 c = dist( gen );           // c in [2, n-2]
    u64 d = 1;

    // "tortoise and hare"
    // put a hard cap to avoid infinite loops on rare bad parameters
    for ( int iter = 0; iter < 200000 && d == 1; ++iter ) 
    {
        x = f( x, c, n );
        y = f( f( y, c, n ), c, n );
        d = ntlab::gcd( udiff( x, y ), n );
    }

    if ( d == 0 || d == 1 || d == n ) return n;
    return d;
}

// Recursively split n into prime factors
static void factor_rec( u64 n, std::vector<u64>& out ) noexcept 
{
    if ( n < 2 ) return;

    if ( ntlab::is_prime( n ) ) 
    {
        out.push_back( n );
        return;
    }

    // quick even split
    if ( ( n & 1ULL ) == 0 ) 
    {
        out.push_back( 2 );
        factor_rec( n / 2, out );
        return;
    }

    // Try Pollard Rho until we get a non-trivial factor
    u64 d = n;
    for ( int tries = 0; tries < 32 && d == n; ++tries ) 
    {
        d = rho_once( n );
    }

    if ( d == n ) {
        // Very rare fallback: do a little trial division to make progress
        for ( u64 p = 3; p <= 100000; p += 2 ) 
        {
            if ( n % p == 0 ) { d = p; break; }
        }
        if ( d == n ) {
            // As a last resort, treat n as prime-ish (shouldn't happen often)
            out.push_back( n );
            return;
        }
    }

    factor_rec( d, out );
    factor_rec( n / d, out );
}

} // anonymous namespace

namespace ntlab 
{

u64 pollard_roh( u64 n ) noexcept
{
    if( n < 2 ) return n;
    if( ( n & 1ULL ) == 0 ) return 2;
    if( is_prime( n ) ) return n;

    u64 d = n;
    for ( int tries = 0; tries < 64 && d == n; ++tries)
    {
        d = rho_once(n);
    }
    return d;
}

std::vector<u64> factorize( u64 n ) noexcept
{
    std::vector<u64> f;
    factor_rec( n, f );
    std::sort( f.begin(), f.end() );
    return f;
}

}   //namespace ntlab