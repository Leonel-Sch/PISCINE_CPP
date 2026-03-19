#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>

class NotFoundException : public std::exception {
    public :
    virtual const char* what() const throw(){
        return "Value not Found";
    }
};

template <typename T>
typename T::iterator easyfind(T& tab, int number){
    
    typename T::iterator it = find(tab.begin(), tab.end(), number);

    if (it == tab.end())
        throw NotFoundException();
    else
        return it;
}

#endif