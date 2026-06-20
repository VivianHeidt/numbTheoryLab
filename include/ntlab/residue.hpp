#pragma once
#include <cstdint>
#include <optional>
#include <utility>
#include "ntlab/types.hpp"
#include "ntlab/arithmetic.hpp"



namespace ntlab
{

    //residues
    int legendre( i64 a, u64 p );

    int jacobi( i64 a, u64 n );

    std::optional<u64> sqrt_mod_prime( u64 a, u64 p );

    bool is_primitive_root( u64 g, u64 p );

    u64 primitive_root( u64 p );

}