#include <iostream>
#include <cstdlib>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void findTwoPrimes(int number) {
    for (int i = 2; i <= number / 2; i++) {
        if (isPrime(i) && isPrime(number - i)) {
            std::cout << number << " = " << i << " + " << (number - i) << std::endl;
            return;
        }
    }
    std::cout << "No prime pair found." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <even number>" << std::endl;
        return 1;
    }

    int number = std::atoi(argv[1]);
    if (number <= 2 || number % 2 != 0) {
        std::cerr << "Please enter an even number greater than 2." << std::endl;
        return 1;
    }

    findTwoPrimes(number);

    return 0;
}

