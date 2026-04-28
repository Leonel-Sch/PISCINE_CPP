/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:13:08 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/13 20:21:54 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed :: Fixed(int const value) : _value(value<<_fbits)
{
    // std :: cout << "Int Constructor Called !" << std :: endl;
}
Fixed :: Fixed(float const value) : _value((int)roundf(value  *(1<<_fbits)))
{
    // std :: cout << "Float Constructor Called !" << std :: endl;
}

Fixed :: Fixed()
{
    _value = 0;
    // std :: cout << "Default Constructor Called !" << std :: endl;
}

Fixed :: Fixed(const Fixed &other) : _value(other._value)
{
    // std :: cout << "Fixed Copy Constructor Called !" << std :: endl;
}

Fixed :: ~Fixed()
{
    // std :: cout << "Fixed Destructor Called !" << std :: endl;
}

Fixed& Fixed :: operator=(const Fixed &other)
{
    // std :: cout << "Fixed Assignement Operator Called !" << std :: endl;
    if (this != &other)
        _value = other._value;
    return (*this);
}

float Fixed :: toFloat(void) const
{
    return((float)(_value)/(1<<_fbits));
}

int Fixed :: toInt(void) const
{
    return(_value>>_fbits);
}

int Fixed :: getRawBits( void ) const
{
    // std :: cout << "getRawBits member function called" << std :: endl;
    return (_value);
}

void Fixed :: setRawBits( int const raw )
{
    _value = raw;
    // std :: cout << "setRawBits member function called" << std :: endl;
}
Fixed Fixed :: operator+(Fixed const &other)
{
    Fixed result;
    result.setRawBits(_value + other._value);
    return (result);
}

Fixed Fixed :: operator-(Fixed const &other)
{
    Fixed result;
    result.setRawBits(_value - other._value);
    return (result);
}

Fixed Fixed :: operator*(Fixed const &other)
{
    Fixed result;
    long res;
    res = (_value * other._value);
    result.setRawBits((int)(res>>_fbits));
    return (result);
}

Fixed Fixed :: operator/(Fixed const &other)
{
    Fixed result;
    long res;
    res = (long(_value<<_fbits));
    result.setRawBits((int)(res/other._value));
    return (result);
}

Fixed &Fixed :: operator++()
{
    ++_value;
    return(*this);
}

Fixed &Fixed :: operator--()
{
    --_value;
    return(*this);
}

Fixed Fixed :: operator++(int)
{
    Fixed tmp(*this);
    ++_value;
    return (tmp);
}

Fixed Fixed :: operator--(int)
{
    Fixed tmp(*this);
    --_value;
    return (tmp);
}

std::ostream &operator<<(std::ostream &os, Fixed const &f) 
{
    os << f.toFloat();
    return (os);
}

bool Fixed :: operator>(Fixed const &other) const
{ 
    return (_value >  other._value);
}

bool Fixed :: operator<(Fixed const &other) const
{ 
    return (_value <  other._value);
}

bool Fixed :: operator>=(Fixed const &other) const
{
    return (_value >= other._value);
}

bool Fixed :: operator<=(Fixed const &other) const
{
    return (_value <= other._value);
}

bool Fixed :: operator==(Fixed const &other) const
{
    return (_value == other._value);
}

bool Fixed :: operator!=(Fixed const &other) const
{
    return (_value != other._value);
}

Fixed  &Fixed :: min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed   &Fixed :: max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed  const &Fixed :: max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed  const &Fixed :: min(Fixed const &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}