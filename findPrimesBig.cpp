#include <iostream>
#include "external/Miller_Rabin/miller_rabin.hpp"

using namespace boost::multiprecision;

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

    bool found = false;
    for (cpp_int i = 2; i <= number / 2; ++i) {
        if (fudmottin::millerRabinTest(i) && fudmottin::millerRabinTest(number - i)) {
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

