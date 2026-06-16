#include "ntlab/multiplicative.hpp"


namespace ntlab 
{
    u64 identity( u64 n )
    {
        return n;
    }

    u64 one( u64 n )
    {
        return 1;
    }

    i64 liouville( u64 n )
    {
        std::map<u64, u64> exponents = prime_factor_exponents( n );

        i64 omega = 0;

        for( const auto& element : exponents )
        {
            u64 multiplicity = element.second;
            omega += multiplicity;  
        }

        if( omega % 2 == 0)
        {
            return 1;
        }
        else 
        {
            return -1;
        }

    }

    u64 epsilon( u64 n )
    {
        if( n == 1 )
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
}