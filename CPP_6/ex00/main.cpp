#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <vector>



int main (int argc, char **argv)
{
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    else
        std::cout << "Wrong Number of Argument" << std::endl;
    return 1; 
}
























// Helper function to format the test output                /!\ Main Auto 
// void runTest(const std::string& input) {
//     std::cout << "\033[36m====================================\033[0m\n";
//     std::cout << "Testing input: [\033[33m" << input << "\033[0m]\n";
//     std::cout << "\033[36m------------------------------------\033[0m\n";
    
//     // Calling your static method!
//     ScalarConverter::convert(input);
    
//     std::cout << "\n";
// }

// int main(int argc, char **argv) {
//     // 1. Standard 42 Evaluation Mode
//     if (argc == 2) {
//         ScalarConverter::convert(argv[1]);
//         return 0;
//     }
    
//     // 2. Automated Test Suite Mode
//     if (argc != 1) {
//         std::cerr << "Usage: ./convert [literal]" << std::endl;
//         return 1;
//     }

//     std::cout << "\033[32mNo arguments provided. Running automatic test suite...\033[0m\n\n";

//     std::vector<std::string> tests;

//     // --- 1. CHARS ---
//     tests.push_back("c");
//     tests.push_back("a");
//     tests.push_back("*");

//     // --- 2. INTS ---
//     tests.push_back("0");
//     tests.push_back("-42");
//     tests.push_back("42");
//     tests.push_back("2147483647");  // INT_MAX
//     tests.push_back("-2147483648"); // INT_MIN

//     // --- 3. FLOATS ---
//     tests.push_back("0.0f");
//     tests.push_back("-4.2f");
//     tests.push_back("4.2f");

//     // --- 4. DOUBLES ---
//     tests.push_back("0.0");
//     tests.push_back("-4.2");
//     tests.push_back("4.2");

//     // --- 5. PSEUDO-LITERALS (The VIPs) ---
//     tests.push_back("-inff");
//     tests.push_back("+inff");
//     tests.push_back("nanf");
//     tests.push_back("-inf");
//     tests.push_back("+inf");
//     tests.push_back("nan");

//     // --- 6. OVERFLOWS & EDGE CASES ---
//     tests.push_back("2147483649");  // Int overflow -> Should be detected as double/float!
//     tests.push_back("-2147483649"); // Int underflow -> Should be detected as double/float!
//     tests.push_back("1e6");         // Scientific notation (if you chose to handle it, otherwise invalid)
//     tests.push_back("invalid_str");
//     tests.push_back("");            // Empty string

//     // Run all tests
//     for (size_t i = 0; i < tests.size(); ++i) {
//         runTest(tests[i]);
//     }

//     std::cout << "\033[32m=== TESTS FINISHED ===\033[0m\n";

//     return 0;
// }