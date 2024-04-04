#include <iostream>
#include <cstdlib>
#include <array>
#include <cstdint>

const uint64_t NUM_PRIMES = 2000;

constexpr bool isPrime(uint64_t n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    for (uint64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

constexpr std::array<uint64_t, NUM_PRIMES> computePrimes() {
    std::array<uint64_t, NUM_PRIMES> primes;
    uint64_t count = 0;
    for (uint64_t i = 2; count < primes.size(); i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }
    return primes;
}

void findTwoPrimes(uint64_t number) {
    constexpr auto primes = computePrimes();
    bool foundPair = false;

    for (auto prime : primes) {
        uint64_t complement = number - prime;
        if (complement > 1 && isPrime(complement)) {
            std::cout << number << " = " << prime << " + " << complement << std::endl;
            foundPair = true;
            break;
        }
    }

    if (!foundPair) {
        std::cout << "No prime pair found within pre-computed primes. Falling back to isPrime()." << std::endl;
        uint64_t largestPrime = primes.back();
        for (uint64_t i = largestPrime; i <= number / 2; i++) {
            if (isPrime(i) && isPrime(number - i)) {
                std::cout << number << " = " << i << " + " << number - i << std::endl;
                foundPair = true;
                break;
            }
        }
    }

    if (!foundPair) {
        std::cout << "No prime pair found." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <even number>" << std::endl;
        return 1;
    }

    uint64_t number = std::strtoull(argv[1], nullptr, 10);

    if (number == 0 && errno == EINVAL) {
        std::cerr << "Invalid number format." << std::endl;
        return 1;
    }

    if (number <= 2 || number % 2 != 0) {
        std::cerr << "Please enter an even number greater than 2." << std::endl;
        return 1;
    }

    findTwoPrimes(number);

    return 0;
}

