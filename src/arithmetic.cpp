#include "ntlab/arithmetic.hpp"
#include <chrono>

namespace ntlab 
{

// ---------------- RNG ----------------
std::mt19937_64& rng() 
{
    static std::mt19937_64 gen
    {
        std::random_device{}() ^
        static_cast<u64>( std::chrono::high_resolution_clock::now().time_since_epoch().count() )
    };
    return gen;
}

// ---------------- gcd ----------------
u64 gcd( u64 a, u64 b ) noexcept 
{
    if ( a == 0 ) return b;
    if ( b == 0 ) return a;
    if ( a < b ) std::swap( a, b ); 
    while ( b != 0 ) 
    {
        u64 t = a % b;
        a = b; b = t;
    }
    return a;
}

// -------- extended gcd (signed) ------
XgcdResult xgcd( i64 a, i64 b ) noexcept 
{
    if ( a == 0 && b == 0 ) return { 0, 0, 0 };

    const i64 sa = ( a < 0 ? -1 : 1 );
    const i64 sb = ( b < 0 ? -1 : 1 );
    u64 A = ( a < 0 ? static_cast<u64>( -a ) : static_cast<u64>( a ) );
    u64 B = ( b < 0 ? static_cast<u64>( -b ) : static_cast<u64>( b ) );

    i64 x0 = 1,  y0 = 0;   // coeffs for A
    i64 x1 = 0,  y1 = 1;   // coeffs for B

    while ( B != 0 ) 
    {
        u64 q = A / B;
        u64 r = A % B;
        A = B;  B = r;

        i64 nx = x0 - static_cast<i64>( q ) * x1;  x0 = x1;  x1 = nx;
        i64 ny = y0 - static_cast<i64>( q ) * y1;  y0 = y1;  y1 = ny;
    }
    // |a|*x0 + |b|*y0 = A; restore original signs on coefficients
    return { sa * x0, sb * y0, A };
}

// -------- extended gcd (unsigned) ----
XgcdResult xgcd_u64( u64 A, u64 B ) noexcept 
{
    i64 x0 = 1,  y0 = 0;
    i64 x1 = 0,  y1 = 1;
    while ( B != 0 ) 
    {
        u64 q = A / B;
        u64 r = A % B;
        A = B;  B = r;
        i64 nx = x0 - static_cast<i64>( q ) * x1;  x0 = x1;  x1 = nx;
        i64 ny = y0 - static_cast<i64>( q ) * y1;  y0 = y1;  y1 = ny;
    }
    return { x0, y0, A };
}

// ------------- modular inverse -------
std::optional<u64> modinv( u64 a, u64 m ) noexcept 
{
    if ( m == 0 ) return std::nullopt;
    a %= m;
    auto r = xgcd_u64( a, m );
    if ( r.g != 1 ) return std::nullopt;
    i64 x = r.x % static_cast<i64>( m );
    if ( x < 0 ) x += static_cast<i64>( m );
    return static_cast<u64>( x );
}

// ------------- mulmod (portable) -----
u64 mulmod( u64 a, u64 b, u64 m ) noexcept 
{
#if defined( __SIZEOF_INT128__ )
    return static_cast<u64>( ( __uint128_t )a * ( __uint128_t )b % m );
#else
    // add-and-double fallback (works on MSVC too)
    u64 res = 0;
    a %= m; b %= m;
    while ( b ) 
    {
        if ( b & 1 ) res = ( res + a ) % m;
        a = ( a << 1 ) % m;
        b >>= 1;
    }
    return res;
#endif
}

// ------------- powmod -----------------
u64 powmod( u64 a, u64 e, u64 m ) noexcept 
{
    if ( m == 1 ) return 0;
    u64 r = 1;
    a %= m;
    while ( e ) 
    {
        if ( e & 1 ) r = mulmod( r, a, m );
        a = mulmod( a, a, m );
        e >>= 1;
    }
    return r;
}

} // namespace ntlab
