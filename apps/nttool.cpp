#include <iostream>
#include <string>

#include "ntlab/arithmetic.hpp"
#include "ntlab/primes.hpp"   // <- NEU

int main(int argc, char* argv[]) {
    using namespace ntlab;

    if (argc < 2) {
        std::cout << "Usage:\n"
                  << "  nttool gcd a b\n"
                  << "  nttool xgcd a b\n"
                  << "  nttool inv a m\n"
                  << "  nttool powmod a e m\n"
                  << "  nttool isprime n\n";   // <- NEU
        return 1;
    }

    std::string cmd = argv[1];

    try {
        if (cmd == "gcd" && argc == 4) {
            u64 a = std::stoull(argv[2]), b = std::stoull(argv[3]);
            std::cout << gcd(a, b) << "\n";
        }
        else if (cmd == "xgcd" && argc == 4) {
            i64 a = std::stoll(argv[2]), b = std::stoll(argv[3]);
            auto r = xgcd(a, b);
            std::cout << r.x << " " << r.y << " " << r.g << "\n"; // x y g
        }
        else if (cmd == "inv" && argc == 4) {
            u64 a = std::stoull(argv[2]), m = std::stoull(argv[3]);
            auto invv = modinv(a, m);
            if (invv) std::cout << *invv << "\n";
            else      std::cout << "no inverse\n";
        }
        else if (cmd == "powmod" && argc == 5) {
            u64 a = std::stoull(argv[2]), e = std::stoull(argv[3]), m = std::stoull(argv[4]);
            std::cout << powmod(a, e, m) << "\n";
        }
        else if (cmd == "isprime" && argc == 3) {  // <- NEU
            u64 n = std::stoull(argv[2]);
            std::cout << (is_prime(n) ? "prime\n" : "composite\n");
        }
        else {
            std::cerr << "Unknown command or wrong args. Run with no args for help.\n";
            return 2;
        }
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 3;
    }

    return 0;
}
