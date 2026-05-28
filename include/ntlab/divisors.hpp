#pragma once
#include <cstdint>
#include <vector>
#include "ntlab/types.hpp"

namespace ntlab
{

    // Divisor functions
    u64 tau( u64 n );

    u64 sigma( u64 n );

    std::vector<u64> divisors( u64 n );

}