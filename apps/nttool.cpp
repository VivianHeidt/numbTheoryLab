#include <iostream>
#include <string>

#include "ntlab/arithmetic.hpp"
#include "ntlab/primes.hpp"
#include "ntlab/factor.hpp"
#include "ntlab/congruence.hpp"
#include "ntlab/sieve.hpp"
#include "ntlab/divisors.hpp"
#include "ntlab/totient.hpp"
#include "ntlab/mobius.hpp"
#include "ntlab/residue.hpp"
#include "ntlab/multiplicative.hpp"

int main( int argc, char* argv[] ) 
{
    using namespace ntlab;

    if ( argc < 2 ) 
    {
        std::cout << "Usage:\n"
                  << "  nttool gcd a b\n"
                  << "  nttool xgcd a b\n"
                  << "  nttool inv a m\n"
                  << "  nttool powmod a e m\n"
                  << "  nttool isprime n\n"
                  << "  nttool factor n\n"
                  << "  nttool crt r1 m1 r2 m2\n"
                  << "  nttool primes limit\n"
                  << "  nttool countprimes limit\n"
                  << "  nttool tau n\n"
                  << "  nttool sigma n\n"
                  << "  nttool divisors n\n"
                  << "  nttool phi n\n"
                  << "  nttool mobius n\n"
                  << "  nttool legendre a p\n"
                  << "  nttool jacobi a n\n"
                  << "  nttool sqrtmod a p\n"
                  << "  nttool identity n\n"
                  << "  nttool one n\n"
                  << "  nttool liouville n\n"
                  << "  nttool epsilon n\n"
                  << "  nttool conv one one n\n"
                  << "  nttool conv identity one n\n"
                  << "  nttool conv identity mobius n\n";
        return 1;
    }

    std::string cmd = argv[1];

    try 
    {
                if ( cmd == "gcd" && argc == 4 ) 
        {
            u64 a = std::stoull( argv[2] );
            u64 b = std::stoull( argv[3] );
            std::cout << gcd( a, b ) << "\n";
        }
        else if ( cmd == "xgcd" && argc == 4 ) 
        {
            i64 a = std::stoll( argv[2] );
            i64 b = std::stoll( argv[3] );
            auto r = xgcd( a, b );
            std::cout << r.x << " " << r.y << " " << r.g << "\n";
        }
        else if ( cmd == "inv" && argc == 4 ) 
        {
            u64 a = std::stoull( argv[2] );
            u64 m = std::stoull( argv[3] );
            auto invv = modinv( a, m );

            if ( invv )
            {
                std::cout << *invv << "\n";
            }
            else
            {
                std::cout << "no inverse\n";
            }
        }
        else if ( cmd == "powmod" && argc == 5 ) 
        {
            u64 a = std::stoull( argv[2] );
            u64 e = std::stoull( argv[3] );
            u64 m = std::stoull( argv[4] );
            std::cout << powmod( a, e, m ) << "\n";
        }
        else if ( cmd == "isprime" && argc == 3 ) 
        { 
            u64 n = std::stoull( argv[2] );
            std::cout << ( is_prime( n ) ? "prime\n" : "composite\n" );
        }
        else if ( cmd == "factor" && argc == 3 )
        {
            u64 n = std::stoull( argv[2] );
            auto fs = factorize( n );

            if ( fs.empty() ) 
            {
                std::cout << "(no factors)\n";
            } 
            else 
            {
                for ( std::size_t i = 0; i < fs.size(); ++i ) 
                {
                    if ( i ) std::cout << " ";
                    std::cout << fs[i];
                }
                std::cout << "\n";
            }
        }
        else if ( cmd == "crt" && argc == 6 )
        {
            u64 r1 = std::stoull( argv[2] );
            u64 m1 = std::stoull( argv[3] );
            u64 r2 = std::stoull( argv[4] );
            u64 m2 = std::stoull( argv[5] );

            auto res = crt( r1, m1, r2, m2 );

            if ( !res ) 
            {
                std::cout << "no solution\n";
            } 
            else 
            {
                std::cout << res->first << " " << res->second << "\n";
            }
        }
        else if ( cmd == "primes" && argc == 3 )
        {
            u64 limit = std::stoull( argv[2] );
            auto ps = primes_up_to( limit );

            for ( std::size_t i = 0; i < ps.size(); ++i )
            {
                if ( i ) std::cout << " ";
                std::cout << ps[i];
            }

            std::cout << "\n";
        }
        else if ( cmd == "countprimes" && argc == 3 )
        {
            u64 limit = std::stoull( argv[2] );
            std::cout << prime_count( limit ) << "\n";
        }
        else if ( cmd == "tau" && argc == 3 )
        {
            u64 n = std::stoull( argv[2] );
            std::cout << tau( n ) << "\n";
        }
        else if ( cmd == "sigma" && argc == 3 )
        {
            u64 n = std::stoull( argv[2] );
            std::cout << sigma( n ) << "\n";
        }
        else if ( cmd == "divisors" && argc == 3 )
        {
            u64 n = std::stoull( argv[2] );
            auto ds = divisors( n );

            for ( std::size_t i = 0; i < ds.size(); ++i )
            {
                if ( i ) std::cout << " ";
                std::cout << ds[i];
            }

            std::cout << "\n";
        }
        else if ( cmd == "phi" && argc == 3 )
        {
            u64 n = std::stoull( argv[2] );
            std::cout << phi( n ) << "\n";
        }
        else if ( cmd == "mobius" && argc == 3 )
        {
            u64 n = std::stoull( argv[2] );
            std::cout << mobius( n ) << "\n";
        }
        else if ( cmd == "legendre" && argc == 4 )
        {
            i64 a = std::stoll( argv[2] );
            u64 p = std::stoull( argv[3] );
            std::cout << legendre( a, p ) << "\n";
        }
        else if ( cmd == "jacobi" && argc == 4 )
        {
            i64 a = std::stoll( argv[2] );
            u64 n = std::stoull( argv[3] );
            std::cout << jacobi( a, n ) << "\n";
        }
        else if ( cmd == "sqrtmod" && argc == 4 )
        {
            u64 a = std::stoull( argv[2] );
            u64 p = std::stoull( argv[3] );

            auto r = sqrt_mod_prime( a, p );

            if ( r )
            {
                std::cout << *r << "\n";
            }
            else
            {
                std::cout << "no solution\n";
            }
        }
        else if ( cmd == "identity" && argc == 3 )
        {
            u64 n = std::stoull(argv[2]);
            std::cout << identity(n) << "\n";
        }
        else if ( cmd == "one" && argc == 3 )
        {
            u64 n = std::stoull(argv[2]);
            std::cout << one(n) << "\n";
        }
        else if ( cmd == "liouville" && argc == 3 )
        {
            u64 n = std::stoull(argv[2]);
            std::cout << liouville(n) << "\n";
        }
        else if ( cmd == "epsilon" && argc == 3 )
        {
            u64 n = std::stoull(argv[2]);
            std::cout << epsilon(n) << "\n";
        }
        else 
        {
            std::cerr << "Unknown command or wrong args. Run with no args for help.\n";
            return 2;
        }
    } catch ( const std::exception& e ) 
    {
        std::cerr << "error: " << e.what() << "\n";
        return 3;
    }

    return 0;
}
