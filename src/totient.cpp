#include <vector>
#include <map>
#include <algorithm>
#include "ntlab/divisors.hpp"
#include "ntlab/totient.hpp"
#include "ntlab/utils.hpp"

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
}



