#include "iter.hpp"

template <typename T>
void increment(T& n) {
    n++;
}

template <typename T>
void print(const T& n) {
    std::cout << n << " ";
}

int main() {
    int tab[] = {0, 1, 2, 3, 4};
    size_t len = 5;

    std::cout << "Avant : ";
    ::iter(tab, len, print<int>);
    std::cout << std::endl;

    ::iter(tab, len, increment<int>);

    std::cout << "Après : ";
    ::iter(tab, len, print<int>);
    std::cout << std::endl;

    return 0;
}