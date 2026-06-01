#include <vector>
#include <map>
#include <algorithm>
#include "ntlab/divisors.hpp"
#include "ntlab/mobius.hpp"
#include "ntlab/utils.hpp"

namespace ntlab
{
    int mobius( u64 n )
    {
        if( n == 1 )
        {
            return 1;
        }

        std::map<u64, u64> exponents = prime_factor_exponents( n );

        for( const auto& element : exponents )
        {
 
            u64 e = element.second;
        
            if( e > 1 )
            {
                return 0;
            }
            
        }

        auto mapEntries = exponents.size();

        if( mapEntries % 2 == 0 )
        {
            return 1;
        }
        
        return -1;
        
    }
}