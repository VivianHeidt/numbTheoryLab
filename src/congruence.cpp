#include "ntlab/congruence.hpp"
#include "ntlab/arithmetic.hpp"

namespace ntlab
{

using ntlab::u64;

std::optional<u64> solve_linear_congruence(u64 a, u64 b, u64 m) noexcept
{
    if( m == 0 )
    {
        return std::nullopt;
    }
    else if( m == 1 )
    {
        return 0;
    };
    
    a %= m;
    b %= m;

    u64 g = gcd( a, m );

    if( b % g != 0 )
    {
        return std::nullopt;
    };
    
    a /= g;
    b /= g;
    m /= g;

    std::optional<u64> inv_opt = modinv( a, m );

    if (!inv_opt) 
    {
    return std::nullopt;
    }
        
    u64 inv = *inv_opt;


    u64 x0 = mulmod( inv, b, m );
    
        return x0;
}

std::optional<std::pair<u64, u64>> crt( u64 r1, u64 m1, u64 r2, u64 m2 ) noexcept
{
    if( m1 == 0 || m2 == 0 )
    {
        return std::nullopt;
    }

    r1 %= m1;
    r2 %= m2;

    if( m1 == 1 )
    {
        return std::pair<u64, u64>{ r2, m2 };
    }

    if( m2 == 1 )
    {
        return std::pair<u64, u64>{ r1, m1 };
    }
    
    u64 diff;

    if( r2 >= r1 )
    {
        diff = r2 - r1;
    }
    else
    {
        diff = r2 + m2 - r1;
    }

    diff %= m2;

    std::optional<u64> t0 = solve_linear_congruence( m1, diff, m2 );

    if( !t0)
    {
        return std::nullopt;
    }
    
    u64 t = *t0;

    u64 g = gcd( m1, m2 );

    u64 M = ( m1 / g ) * m2;

    // r = (r1 + m1*t) mod M  (overflow-safe)
    u64 term = mulmod( m1 % M, t % M, M );
    u64 r = ( term + ( r1 % M ) ) % M;

    return std::pair<u64, u64>{ r, M };
}

} 
