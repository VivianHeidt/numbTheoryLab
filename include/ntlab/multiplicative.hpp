#pragma once
#include "ntlab/types.hpp"
#include "ntlab/utils.hpp"
#include "ntlab/divisors.hpp"
#include "ntlab/mobius.hpp"

namespace ntlab
{   
    // Identity function: id(n) = n
    u64 identity( u64 n ); 
    
    // Constant-one function: 1(n) = 1
    u64 one( u64 n );
    
    // Liouville function λ(n) = (-1)^Ω(n)
    i64 liouville( u64 n ); 
    
    // Dirichlet identity: ε(n) = 1 if n == 1 else 0
    u64 epsilon( u64 n );
    
    template <typename F, typename G>
    auto dirichlet_convolution( F f, G g, u64 n )
    {
        auto divs = divisors( n );

        auto sum = decltype( f( 1 ) * g( 1 ) ){ 0 };

        for( u64 d : divs )
        {
            sum += f( d ) * g( n / d );
        }

        return sum;
    }

    template <typename F>
    auto mobius_inversion( F f, u64 n )
    {
        return dirichlet_convolution( f, mobius, n );
    }
}