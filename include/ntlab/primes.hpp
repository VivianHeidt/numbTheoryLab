#pragma once
#include <cstdint>



namespace ntlab 
{

using u64 = std::uint64_t;
using i64 = std::int64_t;

bool is_prime(u64 n) noexcept;

u64 next_prime(u64 n) noexcept;

}