#include <vector>
#include "ntlab/utils.hpp"

namespace ntlab
{
    std::map<ntlab::u64, ntlab::u64> prime_factor_exponents( ntlab::u64 n )
    {
        std::vector<ntlab::u64> factor = ntlab::factorize( n );

        std::map<ntlab::u64, ntlab::u64> exponents;

        for( ntlab::u64 i = 0; i < factor.size(); i++)
        {
            exponents[factor[i]]++;
        }

        return exponents;
    }
} 