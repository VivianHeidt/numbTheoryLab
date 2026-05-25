# Number Theory Lab (C++)

A modern C++17 playground for experimenting with classical number theory algorithms, modular arithmetic, primality testing, and factorization.

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

## Factorization

* Pollard Rho factorization
* Recursive prime factorization

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
│     ├─ factor.hpp
│     └─ primes.hpp
├─ src/
│  ├─ arithmetic.cpp
│  ├─ congruence.cpp
│  ├─ factor.cpp
│  └─ primes.cpp
├─ tests/
│  ├─ test_arithmetic.cpp
│  ├─ test_congruence.cpp
│  ├─ test_factor.cpp
│  └─ test_primes.cpp
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

The project currently provides a small CLI tool called `nttool`.

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

* Euler phi function
* Möbius function
* divisor functions
* sieve algorithms
* Legendre / Jacobi symbols
* Tonelli–Shanks
* Big integer arithmetic
* FFT multiplication
* finite fields
* benchmarking suite

---

# Motivation

This project was started as a personal exploration of:

* algorithmic number theory
* systems programming
* performance-oriented C++
* mathematical software engineering

It also serves as a long-term learning project and portfolio project.

---

# License

MIT License
