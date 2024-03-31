# Goldbach's Conjecture Solver

This repository contains a simple C++ program named `findPrimes` that
demonstrates Goldbach's Conjecture. According to Goldbach's Conjecture,
every even number greater than 2 can be expressed as the sum of two primes.
This program accepts an even number as an argument and outputs
two prime numbers that sum up to the input number.

## Compilation

The program is written in C++20 and can be compiled with the following command:

```bash
c++ -std=c++20 -O3 -o findPrimes findPrimes.cpp
```

## Usage

After compiling, you can run the program by passing an even number greater
than 2 as an argument:

```bash
./findPrimes 10
```

This will output two prime numbers that add up to 10, for example:

```bash
10 = 3 + 7
```

## License

This code is licensed under the MIT License. See the LICENSE file for details.

Have fun with it!

