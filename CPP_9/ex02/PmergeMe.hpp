#pragma once

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _rawInput;

    std::vector<int> _sortVector(std::vector<int> arr);
    std::deque<int> _sortDeque(std::deque<int> arr);
    void _parseInput(int argc, char **argv);
    std::vector<int> _generateInsertionSequence(int loosersSize);

public:
    PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run();

    class InvalidInputException : public std::exception {
        public: virtual const char* what() const throw() { return "Error: Invalid input."; }
    };
};

#endif