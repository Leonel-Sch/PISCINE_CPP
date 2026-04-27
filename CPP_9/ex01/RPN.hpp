#pragma once

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <stdexcept>
# include <sstream>
# include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    void performOperation(const std::string& token);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void calculate(const std::string& expression);

    class DivisionByZeroException : public std::exception {
        public: virtual const char* what() const throw() { return "Error: Division by zero."; }
    };
    
    class InvalidExpressionException : public std::exception {
        public: virtual const char* what() const throw() { return "Error: Invalid expression."; }
    };
    class OverflowException : public std::exception {
        public: virtual const char* what() const throw() { return "Error: Overflow"; }
    };
};

#endif