#pragma once
#include <map>
#include <vector>
#include "ntlab/types.hpp"
#include "ntlab/factor.hpp"

namespace ntlab
{
     std::map<ntlab::u64, ntlab::u64> prime_factor_exponents( ntlab::u64 n );
}