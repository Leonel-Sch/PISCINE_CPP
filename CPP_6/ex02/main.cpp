#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "-----------------" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        Base* randomBase = generate();
        std::cout << "Pointeur  : ";
        identify(randomBase);
        std::cout << "Reference : ";
        identify(*randomBase);
        std::cout << "-----------------" << std::endl;

        delete randomBase;
    }

    return 0;
}