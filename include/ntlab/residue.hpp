#pragma once
#include <cstdint>
#include <optional>
#include "ntlab/types.hpp"

namespace ntlab
{

    // Quadratic residues
    int legendre( i64 a, u64 p );
    
    int jacobi( i64 a, u64 n );

    std::optional<u64> sqrt_mod_prime( u64 a, u64 p );

}