#pragma once
#include <cstdint>
#include <vector>
#include "ntlab/types.hpp"

namespace ntlab
{

    //sieve
    std::vector<u64> primes_up_to( u64 limit );
    
    u64 prime_count( u64 limit );

}
