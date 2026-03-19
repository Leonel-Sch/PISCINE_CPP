
#include "Span.hpp"

int main() {
    std::cout << "-------------------------------" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest : " << sp.shortestSpan() << " (attendu: 2)" << std::endl;
    std::cout << "Longest  : " << sp.longestSpan() << " (attendu: 14)" << std::endl;

    std::cout << "-------------------------------" << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception &e) {
        std::cout << "Exception attrapee : " << e.what() << std::endl;
    }

    Span emptySpan = Span(1);
    emptySpan.addNumber(10);
    try {
        emptySpan.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Exception attrapee : " << e.what() << std::endl;
    }

    std::cout << "-------------------------------" << std::endl;
    Span bigSpan(10000);
    std::vector<int> bigVector;
    
    std::srand(std::time(NULL)); 
    
    for (int i = 0; i < 10000; i++) {
        bigVector.push_back(std::rand());
    }

    try {
        bigSpan.addNumbers(bigVector.begin(), bigVector.end());
        std::cout << "Shortest (BigSpan) : " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest  (BigSpan) : " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
    return 0;
}