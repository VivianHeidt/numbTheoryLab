#pragma once
#include <cstdint>
#include "ntlab/types.hpp"



namespace ntlab 
{

    bool is_prime( u64 n ) noexcept;

    u64 next_prime( u64 n ) noexcept;

}