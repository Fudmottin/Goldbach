#include <iostream>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>

using namespace boost::multiprecision;

cpp_int powMod(cpp_int base, cpp_int exp, cpp_int mod) {
    cpp_int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool millerRabinTest(cpp_int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 5) return true;

    cpp_int d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
    }

    boost::random::mt19937_64 rng(std::random_device{}());
    for (int i = 0; i < k; i++) {
        cpp_int a = boost::random::uniform_int_distribution<cpp_int>(2, n - 2)(rng);
        cpp_int x = powMod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool isPrime = false;
        for (cpp_int r = 1; r < d; r *= 2) {
            x = powMod(x, 2, n);
            if (x == 1) return false;
            if (x == n - 1) {
                isPrime = true;
                break;
            }
        }

        if (!isPrime) return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <even number>" << std::endl;
        return 1;
    }

    cpp_int number;
    try {
        number = cpp_int(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid input." << std::endl;
        return 1;
    }

    if (number <= 2 || number % 2 != 0) {
        std::cerr << "Please enter an even number greater than 2." << std::endl;
        return 1;
    }

    int k = 40; // Number of iterations for Miller-Rabin test
    bool found = false;
    for (cpp_int i = 2; i <= number / 2; ++i) {
        if (millerRabinTest(i, k) && millerRabinTest(number - i, k)) {
            std::cout << number << " = " << i << " + " << number - i << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "No prime pair found." << std::endl;
    }

    return 0;
}

