#pragma once

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T &a, const T &b) {
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
const T& max(const T &a, const T &b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif
