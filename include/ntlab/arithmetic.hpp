#pragma once
#include <cstdint>
#include <optional>
#include <random>
#include <utility>


namespace ntlab 
{

using u64 = std::uint64_t;
using i64 = std::int64_t;

// RNG handle (non-cryptographic)
std::mt19937_64& rng();

// Unsigned gcd
u64 gcd(u64 a, u64 b) noexcept;

// Extended gcd (signed API)
struct XgcdResult { i64 x; i64 y; u64 g; };
XgcdResult xgcd(i64 a, i64 b) noexcept;

// Extended gcd on unsigned inputs (used by modinv to avoid narrowing)
XgcdResult xgcd_u64(u64 A, u64 B) noexcept;

// a^{-1} mod m if gcd(a,m)=1
std::optional<u64> modinv(u64 a, u64 m) noexcept;

// (a*b) % m, overflow-safe (uses __int128 when available)
u64 mulmod(u64 a, u64 b, u64 m) noexcept;

// (a^e) % m via binary exponentiation
u64 powmod(u64 a, u64 e, u64 m) noexcept;

} // namespace ntlab
