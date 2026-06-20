#include "ntlab/residue.hpp"
#include "ntlab/primes.hpp"
#include "ntlab/arithmetic.hpp"
#include "ntlab/utils.hpp"

namespace ntlab
{

    int legendre( i64 a, u64 p )
    {
        a %= static_cast<i64>( p );

        if( a < 0 )
        {
            a += p;
        }

        if( a == 0 )
        {
            return 0;
        }

        u64 value = powmod( static_cast<u64>( a ), ( p - 1 ) / 2, p );

        if( value == 1 )
        {
            return 1;
        }

        if( value == p - 1 )
        {
            return -1;
        }

        return 0;
    }

    int jacobi( i64 a, u64 n )
    {
        if( n == 0 || n % 2 == 0 )
        {
            return 0;
        }

        i64 nn = static_cast<i64>( n );

        a %= nn;

        if( a < 0 )
        {
            a += nn;
        }

        int result = 1;

        while( a != 0 )
        {
            while( ( a % 2 ) == 0 )
            {
                a /= 2;

                i64 r = nn % 8;

                if( r == 3 || r == 5 )
                {
                    result = -result;
                }
            }

            std::swap( a, nn );

            if( a % 4 == 3 && nn % 4 == 3 )
            {
                result = -result;
            }

            a %= nn;
        }

        return ( nn == 1 ) ? result : 0;
    }

    std::optional<u64> sqrt_mod_prime( u64 a, u64 p )
    {
        a %= p;

        if( a == 0 )
        {
            return 0;
        } 
        else if ( p == 2 )
        {
            return a;
        }
        else if ( legendre( a, p ) != 1 )
        {
            return std::nullopt;
        }

        if( p % 4 == 3 )
        {
            return powmod( a, ( p + 1 ) / 4, p );
        }

        u64 q = p - 1;
        u64 s = 0;
        u64 z = 2;

        while( q % 2 == 0 )
        {
            q /= 2;
            s++;
        }

        while( legendre( z, p ) != -1 )
        {
            z++;
        }

        u64 m = s;
        u64 c = powmod(z, q, p);
        u64 t = powmod(a, q, p);
        u64 r = powmod(a, (q + 1) / 2, p);

        while( t != 1 )
        {
            u64 i = 1;
            u64 value = mulmod( t, t, p );

            while( value != 1 )
            {
                value = mulmod( value, value, p );
                i++;
            }

            u64 exponent = 1ULL << ( m - i - 1 );
            u64 b = powmod( c, exponent, p );

            u64 b2 = mulmod( b, b, p );

            r = mulmod( r, b, p );
            t = mulmod( t, b2, p );
            c = b2;
            m = i;
        }

        return r;
    }

    bool is_primitive_root( u64 g, u64 p )
    {
        if ( !is_prime( p ) )
        {
            return false;
        }

        if ( p == 2 )
        {
            return g % p == 1;
        }

        if ( g == 0 || g >= p )
        {
            return false;
        }

        auto factors = prime_factor_exponents( p - 1 );

        for ( const auto& [q, exponent] : factors )
        {
            if ( powmod( g, ( p - 1 ) / q, p ) == 1 )
            {
                return false;
            }
        }

        return true;
    }

    u64 primitive_root( u64 p )
    {
        if ( !is_prime( p ) )
        {
            throw std::invalid_argument( "primitive_root is only implemented for prime moduli" );
        }

        if ( p == 2 )
        {
            return 1;
        }

        for ( u64 g = 2; g < p; ++g )
        {
            if ( is_primitive_root( g, p ) )
            {
                return g;
            }
        }

        throw std::runtime_error( "no primitive root found" );
    }
}