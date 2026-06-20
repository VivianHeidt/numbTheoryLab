# Number Theory Lab (C++)

A modern C++17 playground for experimenting with classical number theory algorithms, modular arithmetic, primality testing, factorization, arithmetic functions, multiplicative number theory, primitive roots, and quadratic residues.

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
* Least Common Multiple (LCM)
* Integer exponentiation
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
* Prime factor exponent extraction

## Divisor Functions

* Divisor count `tau(n)`
* Divisor sum `sigma(n)`
* Enumeration of all positive divisors

## Arithmetic Functions

* Euler's Totient Function `phi(n)`
* Carmichael Function `lambda_C(n)`
* Möbius Function `mu(n)`
* Liouville Function `lambda(n)`
* Identity Function `id(n)`
* Constant-One Function `1(n)`
* Dirichlet Identity `epsilon(n)`
* Generic Dirichlet Convolution
* Möbius Inversion

## Quadratic Residues & Cyclic Groups

* Legendre Symbol
* Jacobi Symbol
* Tonelli–Shanks modular square roots
* Primitive root testing
* Primitive root computation

## Congruences

* Linear congruence solver
* Chinese Remainder Theorem (CRT)

## Engineering

* Modern CMake project structure
* Modular library design
* Unit tests with Catch2
* Cross-platform compatible
* Command-line interface (`nttool`)

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
│     ├─ multiplicative.hpp
│     ├─ primes.hpp
│     ├─ residue.hpp
│     ├─ sieve.hpp
│     ├─ totient.hpp
│     ├─ types.hpp
│     └─ utils.hpp
├─ src/
├─ tests/
├─ CMakeLists.txt
└─ README.md
```

---

# Building

## Requirements

* CMake >= 3.16
* C++17 compatible compiler
* GCC / Clang / MSVC

## Build

```bash
cmake -S . -B build
cmake --build build
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

### Euler Totient Function

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

### Identity Function

```bash
./build/nttool identity 42
```

Output:

```text
42
```

### Constant-One Function

```bash
./build/nttool one 123
```

Output:

```text
1
```

### Dirichlet Identity

```bash
./build/nttool epsilon 17
```

Output:

```text
0
```

### Liouville Function

```bash
./build/nttool liouville 72
```

Output:

```text
-1
```

because

```text
72 = 2³ · 3²
Ω(72) = 5
λ(72) = (-1)^5 = -1
```

### Dirichlet Convolution Examples

```bash
./build/nttool conv one one 12
```

computes

```text
(1 * 1)(12) = τ(12)
```

```bash
./build/nttool conv identity one 12
```

computes

```text
(id * 1)(12) = σ(12)
```

```bash
./build/nttool conv identity mobius 12
```

computes

```text
(id * μ)(12) = φ(12)
```

### Legendre Symbol

```bash
./build/nttool legendre 5 11
```

### Jacobi Symbol

```bash
./build/nttool jacobi 5 21
```

### Modular Square Root

```bash
./build/nttool sqrtmod 10 13
```

---

# Testing

The project uses Catch2 for unit testing.

Run:

```bash
./build/ntlab_tests
```

Current test suite:

* arithmetic correctness
* modular arithmetic
* primality testing
* factorization
* divisor functions
* Euler totient
* Carmichael function
* Möbius function
* Liouville function
* primitive roots
* quadratic residues
* CRT consistency
* Dirichlet convolution identities

The test suite verifies classical identities from multiplicative number theory:

```text
τ = 1 * 1
σ = id * 1
φ = id * μ
μ * 1 = ε
f * ε = f
```

---

# Algorithms

## Euclidean Algorithm

Computes

```text
gcd(a,b)
```

in logarithmic time.

## Extended Euclidean Algorithm

Finds integers `x` and `y` satisfying

```text
ax + by = gcd(a,b)
```

and forms the basis for modular inversion.

## Miller–Rabin

Deterministic primality test for 64-bit integers using a known witness set.

## Pollard Rho

Probabilistic integer factorization algorithm suitable for medium-sized composite integers.

## Sieve of Eratosthenes

Computes all primes up to a given limit in

```text
O(n log log n)
```

time.

## Euler Totient Function

Computes

```text
φ(n)
```

the number of integers coprime to `n`.

## Carmichael Function

Computes

```text
λ(n)
```

the exponent of the multiplicative group modulo `n`.

For odd prime powers:

```text
λ(p^k) = φ(p^k)
```

For powers of two:

```text
λ(2) = 1
λ(4) = 2
λ(2^k) = 2^(k−2), k ≥ 3
```

and generally:

```text
λ(n) = lcm( λ(p1^a1), λ(p2^a2), ... )
```

## Möbius Function

Computes

```text
μ(n)
```

used in inversion formulas and multiplicative number theory.

## Liouville Function

Computes

```text
λ(n) = (-1)^Ω(n)
```

where Ω counts prime factors with multiplicity.

## Dirichlet Convolution

Given arithmetic functions `f` and `g`:

```text
(f * g)(n)
=
Σ f(d) g(n/d)
d|n
```

Important identities:

```text
τ = 1 * 1
σ = id * 1
φ = id * μ
μ * 1 = ε
```

## Möbius Inversion

Provides a constructive way to recover arithmetic functions from divisor sums using the Möbius function.

## Legendre Symbol

Determines whether an integer is a quadratic residue modulo an odd prime.

## Jacobi Symbol

Generalizes the Legendre symbol to odd composite moduli.

## Tonelli–Shanks

Computes modular square roots modulo odd primes.

## Primitive Roots

A primitive root modulo a prime `p` generates the entire multiplicative group

```text
(Z/pZ)^*
```

The library provides:

```cpp
is_primitive_root(g, p)
primitive_root(p)
```

Primitive roots play a central role in cyclic groups, discrete logarithms, and public-key cryptography.

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

* multiplicative order
* Dirichlet inverse
* continued fractions
* Pell equations
* Baby-step Giant-step discrete logarithm
* RSA demonstration
* finite fields
* elliptic curves
* big integer arithmetic
* FFT / NTT multiplication
* benchmarking suite
* GitHub Actions CI

---

# License

MIT License
