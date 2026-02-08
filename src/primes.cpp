#include "ntlab/primes.hpp"
#include "ntlab/arithmetic.hpp"

#include <array>

namespace 
{

// checks, for Miller–Rabin-Witness for n
bool miller_rabin_witness(ntlab::u64 a,
                           ntlab::u64 d,
                           ntlab::u64 s,
                           ntlab::u64 n) noexcept
{
    using ntlab::mulmod;
    using ntlab::powmod;

    ntlab::u64 x = powmod(a, d, n);

    if (x == 1 || x == n - 1)
        return false;

    for (ntlab::u64 i = 1; i < s; ++i) 
    {
        x = mulmod(x, x, n);
        if (x == n - 1)
            return false;
    }

    return true; // composite witness
}

bool miller_rabin(ntlab::u64 n) noexcept
{
    // for odd n and n >= 5

    // n-1 = d * 2^s
    ntlab::u64 d = n - 1;
    ntlab::u64 s = 0;

    while ((d & 1) == 0) 
    {
        d >>= 1;
        ++s;
    }

    // deterministic Bases for uint64
    static constexpr std::array<ntlab::u64, 7> bases
    {
        2ULL, 325ULL, 9375ULL, 28178ULL,
        450775ULL, 9780504ULL, 1795265022ULL
    };

    for (ntlab::u64 a : bases) 
    {
        if (a % n == 0)
            continue;

        if (miller_rabin_witness(a, d, s, n))
            return false;
    }

    return true;
}

} // anonymous namespace


namespace ntlab 
{

bool is_prime(u64 n) noexcept
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if ((n & 1) == 0) return false;

    // Pre-filter
    static constexpr u64 small_primes[] = 
    {
        3,5,7,11,13,17,19,23,29,31,37
    };

    for (u64 p : small_primes) 
    {
        if (n == p) return true;
        if (n % p == 0) return false;
    }

    // main Test
    return miller_rabin(n);
}


u64 next_prime(u64 n) noexcept
{
    if (n <= 2) return 2;
    if ((n & 1) == 0) ++n;

    while (!is_prime(n))
        n += 2;

    return n;
}

} // namespace ntlab
