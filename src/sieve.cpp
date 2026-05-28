#include "ntlab/sieve.hpp"

namespace ntlab
{
    std::vector<u64> primes_up_to( u64 limit )
    {
        if( limit < 2 )
        {
            return std::vector<u64>{};
        }

        std::vector<bool> is_prime_table( limit + 1, true );
        is_prime_table[0] = false;
        is_prime_table[1] = false;
        std::vector<u64> primes;

        for( u64 i = 2; i <= limit / i; i++ )
        {
            if( is_prime_table[i] )
            {
                for( u64 j = i * i; j <= limit ; j += i )
                {
                    is_prime_table[j] = false;
                }
            }
        }

        for( u64 candidate = 0; candidate < is_prime_table.size(); candidate++ )
        {
            if( is_prime_table[candidate] )
            {
                primes.push_back( candidate );
            }
        }

        return primes;
    }

    u64 prime_count( u64 limit )
    {
        std::vector<u64> count_vector = primes_up_to( limit );

        return static_cast<u64>( count_vector.size() );
    }
}


