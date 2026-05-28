#include <vector>
#include <map>
#include <algorithm>
#include "ntlab/divisors.hpp"
#include "ntlab/factor.hpp"
#include "ntlab/utils.hpp"

namespace ntlab
{

    u64 tau( u64 n )
    {
        u64 result = 1;

        if( n == 1 )
        {
            return result;
        }

        std::map<u64, u64> exponents = prime_factor_exponents( n );

        for( const auto& element : exponents )
        {
            result *= element.second + 1;
        }

        return result;

    }

    u64 sigma( u64 n )
    {
        u64 result = 1;

        if( n == 1 )
        {
            return result;
        }

        std::map<u64, u64> exponents = prime_factor_exponents( n );

        for( const auto& element : exponents )
        {
            u64 local_sum = 1;
            u64 power = 1;

            for( u64 i = 0; i < element.second; i++ )
            {
                power *= element.first;
                local_sum += power;
            }

            result *= local_sum;
        }

        return result;

    }

    std::vector<u64> divisors( u64 n )
    {
        std::vector<u64> result = { 1 };

        if( n == 1 )
        {
            return result;
        }

        std::map<u64, u64> exponents = prime_factor_exponents( n );

        for( const auto& element : exponents )
        {
            u64 p = element.first;
            u64 e = element.second;

            u64 current_size = result.size();
            u64 power = 1;

            for( u64 i = 0; i < e; i++ )
            {
                power *= p;

                for( u64 j = 0; j < current_size; j++ )
                {
                    result.push_back( result[j] * power );
                }
            }
        }

        std::sort( result.begin(), result.end() );

        return result;
    }

}