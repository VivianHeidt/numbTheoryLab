#pragma once
#include <cstdint>
#include <optional>
#include <utility>


namespace ntlab {

using u64 = std::uint64_t;

// Solve: a*x ≡ b (mod m)
// Returns smallest non-negative solution if it exists.
std::optional<u64> solve_linear_congruence(u64 a, u64 b, u64 m) noexcept;

// Chinese Remainder Theorem for two congruences:
// x ≡ r1 (mod m1), x ≡ r2 (mod m2)
// Returns (r, m) meaning x ≡ r (mod m), or nullopt if no solution.
std::optional<std::pair<u64, u64>> crt(u64 r1, u64 m1, u64 r2, u64 m2) noexcept;

}
