#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Wrong Number of Arguments: expected: ./btc <file.txt>" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc("data.csv");
        btc.processInput(argv[1]);
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
    return 0;
}