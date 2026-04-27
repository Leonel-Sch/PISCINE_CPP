#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "/" || token == "*");
}

void RPN::performOperation(const std::string &token) {
    int number1;
    int number2;
    long long testnumber;

    if (_stack.size() < 2)
        throw InvalidExpressionException();
    number2 = _stack.top();
    _stack.pop();
    number1 = _stack.top();
    _stack.pop();

    if (token == "+") {
        testnumber = static_cast<long long>(number1) + static_cast<long long>(number2);
        if (testnumber > 2147483647)
            throw OverflowException();
        _stack.push(number1 + number2);
    }
    else if (token == "*") {
        testnumber = static_cast<long long>(number1) * static_cast<long long>(number2);
        if (testnumber > 2147483647)
            throw OverflowException();
        _stack.push(number1 * number2);
    }
    else if (token == "-") {
        testnumber = static_cast<long long>(number1) - static_cast<long long>(number2);
        if (testnumber < -2147483648)
            throw OverflowException();
        _stack.push(number1 - number2);
    }
    else if (token =="/") {
        if (number2 == 0)
            throw DivisionByZeroException();
        testnumber = static_cast<long long>(number1) / static_cast<long long>(number2);
        if (testnumber < -2147483648 || testnumber > 2147483647)
            throw OverflowException();

        _stack.push(number1 / number2);
    }
}

void RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        
        if (isOperator(token)) {
            performOperation(token);
        } 
        else {
            // 2. Ce n'est pas un opérateur, c'est censé être un nombre !
            // Attention : il faudrait vérifier ici que le token est bien un chiffre valide
            // (Tu peux faire une petite vérification ou utiliser atoi directement si tu as confiance)
            
            int number = std::atoi(token.c_str());
            _stack.push(number); // On empile le nombre
        }
    }

    if (_stack.size() != 1) {
        throw InvalidExpressionException();
    }

    std::cout << _stack.top() << std::endl;
}