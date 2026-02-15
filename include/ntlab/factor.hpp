#pragma once
#include <cstdint>
#include <vector>

namespace ntlab {

using u64 = std::uint64_t;

// Finds a non-trivial factor of n (n must be composite and > 1).
// May return n in rare failure cases (caller can retry).
u64 pollard_rho(u64 n) noexcept;

// Returns prime factorization (with repetitions). Order not guaranteed.
std::vector<u64> factorize(u64 n) noexcept;

} // namespace ntlab
