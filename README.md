# Number Theory Lab (C++)

A modern C++17 playground for experimenting with classical number theory algorithms, modular arithmetic, primality testing, factorization, arithmetic functions, and quadratic residues.

The goal of this project is both educational and practical:

* learn algorithmic number theory
* improve modern C++ skills
* build a reusable mathematics toolkit
* explore performance-oriented programming
* create a portfolio project with real software engineering practices

---

# Features

## Arithmetic

* Euclidean GCD
* Extended Euclidean Algorithm
* Modular inverse
* Overflow-safe modular multiplication
* Fast modular exponentiation

## Prime Algorithms

* Deterministic Miller–Rabin primality test for `uint64_t`
* Next prime search
* Sieve of Eratosthenes
* Prime counting

## Factorization

* Pollard Rho factorization
* Recursive prime factorization

## Divisor Functions

* Divisor count `tau(n)`
* Divisor sum `sigma(n)`
* Enumeration of all positive divisors

## Arithmetic Functions

* Euler's Totient Function `phi(n)`
* Möbius Function `mu(n)`

## Quadratic Residues

* Legendre Symbol
* Jacobi Symbol
* Tonelli–Shanks modular square roots

## Congruences

* Linear congruence solver
* Chinese Remainder Theorem (CRT)

## Engineering

* Modern CMake project structure
* Modular library design
* Unit tests with Catch2
* Cross-platform compatible

---

# Project Structure

```text
numbTheoryLab/
├─ apps/
│  └─ nttool.cpp
├─ include/
│  └─ ntlab/
│     ├─ arithmetic.hpp
│     ├─ congruence.hpp
│     ├─ divisors.hpp
│     ├─ factor.hpp
│     ├─ mobius.hpp
│     ├─ primes.hpp
│     ├─ residue.hpp
│     ├─ sieve.hpp
│     ├─ totient.hpp
│     └─ utils.hpp
├─ src/
│  ├─ arithmetic.cpp
│  ├─ congruence.cpp
│  ├─ divisors.cpp
│  ├─ factor.cpp
│  ├─ mobius.cpp
│  ├─ primes.cpp
│  ├─ residue.cpp
│  ├─ sieve.cpp
│  ├─ totient.cpp
│  └─ utils.cpp
├─ tests/
│  ├─ test_arithmetic.cpp
│  ├─ test_congruence.cpp
│  ├─ test_divisors.cpp
│  ├─ test_factor.cpp
│  ├─ test_mobius.cpp
│  ├─ test_primes.cpp
│  ├─ test_residue.cpp
│  ├─ test_sieve.cpp
│  ├─ test_totient.cpp
│  └─ test_utils.cpp
├─ CMakeLists.txt
└─ README.md
```

---

# Building

## Requirements

* CMake >= 3.16
* C++17 compatible compiler
* GCC / Clang / MSVC

## Build (MinGW / GCC)

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```

## Build (Visual Studio)

```bash
cmake -S . -B build
cmake --build build --config Debug
```

---

# Running

The project provides a CLI tool called `nttool`.

## Examples

### GCD

```bash
./build/nttool gcd 48 18
```

Output:

```text
6
```

### Extended GCD

```bash
./build/nttool xgcd 30 12
```

Output:

```text
1 -2 6
```

### Modular Inverse

```bash
./build/nttool inv 3 11
```

Output:

```text
4
```

### Modular Exponentiation

```bash
./build/nttool powmod 2 10 1000
```

Output:

```text
24
```

### Primality Test

```bash
./build/nttool isprime 97
```

Output:

```text
prime
```

### Factorization

```bash
./build/nttool factor 84
```

Output:

```text
2 2 3 7
```

### Chinese Remainder Theorem

```bash
./build/nttool crt 2 3 3 5
```

Output:

```text
8 15
```

Meaning:

```text
x ≡ 8 (mod 15)
```

### Sieve

```bash
./build/nttool primes 20
```

Output:

```text
2 3 5 7 11 13 17 19
```

### Prime Count

```bash
./build/nttool countprimes 100
```

Output:

```text
25
```

### Divisor Count

```bash
./build/nttool tau 12
```

Output:

```text
6
```

### Divisor Sum

```bash
./build/nttool sigma 12
```

Output:

```text
28
```

### Divisors

```bash
./build/nttool divisors 12
```

Output:

```text
1 2 3 4 6 12
```

### Euler Phi

```bash
./build/nttool phi 36
```

Output:

```text
12
```

### Möbius Function

```bash
./build/nttool mobius 30
```

Output:

```text
-1
```

### Legendre Symbol

```bash
./build/nttool legendre 5 11
```

Output:

```text
1
```

### Jacobi Symbol

```bash
./build/nttool jacobi 5 21
```

Output:

```text
1
```

### Modular Square Root

```bash
./build/nttool sqrtmod 10 13
```

Output:

```text
6
```

(or another valid square root modulo 13)

---

# Testing

The project uses Catch2 for unit testing.

## Build and run tests

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
./build/ntlab_tests
```

The tests cover:

* arithmetic correctness
* modular arithmetic
* primality testing
* factorization properties
* divisor functions
* Euler phi
* Möbius function
* quadratic residue algorithms
* CRT consistency
* edge cases and invalid inputs

---

# Algorithms

## Euclidean Algorithm

Computes:

```text
gcd(a, b)
```

in logarithmic time.

## Extended Euclidean Algorithm

Finds integers `x` and `y` such that:

```text
ax + by = gcd(a, b)
```

## Miller–Rabin

Deterministic for 64-bit unsigned integers using known witness sets.

## Pollard Rho

Probabilistic integer factorization algorithm efficient for medium-sized composite numbers.

## Sieve of Eratosthenes

Computes all primes up to a given limit in:

```text
O(n log log n)
```

time.

## Euler Totient Function

Computes:

```text
phi(n)
```

the number of integers coprime to `n`.

## Möbius Function

Computes:

```text
mu(n)
```

used in multiplicative number theory and inversion formulas.

## Legendre Symbol

Determines whether an integer is a quadratic residue modulo an odd prime.

## Jacobi Symbol

Generalization of the Legendre symbol to odd composite moduli.

## Tonelli–Shanks

Computes modular square roots modulo odd primes.

## Chinese Remainder Theorem

Combines compatible congruence systems into a single congruence.

---

# Design Goals

* educational clarity
* modular structure
* correctness through testing
* reusable APIs
* modern C++ practices
* clean separation of interface and implementation

---

# Future Ideas

Potential future extensions:

* Carmichael function λ(n)
* Primitive roots
* Baby-step Giant-step discrete logarithm
* Miller–Rabin benchmarking
* Pollard Rho optimizations
* RSA demonstration
* Finite fields
* Big integer arithmetic
* FFT / NTT multiplication
* Benchmarking suite
* GitHub Actions CI

---

# License

MIT License
