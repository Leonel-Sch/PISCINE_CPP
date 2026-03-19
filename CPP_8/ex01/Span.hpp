#pragma once

#ifndef SPAN_HPP
# define SPANN_HPP

# include <vector>
# include <algorithm>
# include <cstdlib>
# include <iterator>
# include <iostream>
# include <ctime>



class NotEnoughElementsException : public std::exception {
    public :
    virtual const char* what() const throw(){
        return "Not Enough Element in the Vector";
    }
};

class AlreadyFullException : public std::exception {
    public :
    virtual const char* what() const throw(){
        return "The Vector is already full";
    }
};

class Span{
private :
    unsigned int _N;
    std::vector<int> _tab;
public :
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();
    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    void addNumbers();

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end){
        unsigned int size = std::distance(begin,end);

        if (_tab.size() + size > _N) {
            throw AlreadyFullException();
        }
        _tab.insert(_tab.end(), begin, end);
    }
};

#endif