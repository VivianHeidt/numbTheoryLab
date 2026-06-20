#include <vector>
#include <map>
#include <algorithm>
#include "ntlab/divisors.hpp"
#include "ntlab/totient.hpp"
#include "ntlab/utils.hpp"
#include "ntlab/arithmetic.hpp"

namespace ntlab
{
    u64 phi( u64 n )
    {
        if( n == 1 )
        {
            return 1;
        }

        u64 result = n;

        std::map<u64, u64> exponents = prime_factor_exponents( n );

        for( const auto& element : exponents )
        {
 
        u64 p = element.first;
        result = ( result / p ) * ( p - 1 );
            
        }

        return result;

    }

    u64 carmichael( u64 n )
    {
        auto exponents = prime_factor_exponents( n );

        u64 result = 1;

        for ( const auto& [p, k] : exponents )
        {
            u64 lambda_pk;

            if ( p == 2 )
            {
                if ( k == 1 )
                {
                    lambda_pk = 1;
                }
                else if( k == 2 )
                {
                    lambda_pk = 2;
                }
                else
                {
                    lambda_pk = pow_u64( 2, k - 2 );
                }
            }
            else
            {
                lambda_pk = pow_u64( p, k - 1 ) * ( p - 1 );
            }

            result = lcm( result, lambda_pk );
        }

        return result;
    }
}



