#include "Span.hpp"

Span::Span() {
    _N = 0;
}

Span::Span(unsigned int N) {
    _N = N;
}

Span::Span(const Span &other) {
    _N = other._N;
    _tab = other._tab;
}

Span::~Span() {}

Span &Span::operator=(const Span& other) {
    if (this != &other){
        _N = other._N;
        _tab = other._tab;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_tab.size() >= _N) {
        throw AlreadyFullException();
    }
    else {
        _tab.push_back(number);
    }
}

int Span::shortestSpan() {
    if (_tab.size() <= 1) {
        throw NotEnoughElementsException();
    }
    std::vector<int> copy = _tab;
    std::sort(copy.begin(), copy.end());
    int span = __INT_MAX__;
    for (unsigned int i = 0; i < _tab.size() - 1; i++) {
        if (span > copy[i + 1] - copy[i])
        span = copy[i + 1] - copy[i];
    }
    return span;
}

int Span::longestSpan() {
    if (_tab.size() <= 1) {
        throw NotEnoughElementsException();
    }
    int min = *std::min_element(_tab.begin(), _tab.end());
    int max = *std::max_element(_tab.begin(), _tab.end());
    return max - min;
}