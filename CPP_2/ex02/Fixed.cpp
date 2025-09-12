/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:13:08 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/13 00:00:28 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed :: Fixed(int const value) : _value(value<<_fbits)
{
    std :: cout << "Int Constructor Called !" << std :: endl;
}
Fixed :: Fixed(float const value) : _value((int)roundf(value  *(1<<_fbits)))
{
    std :: cout << "Float Constructor Called !" << std :: endl;
}

Fixed :: Fixed()
{
    _value = 0;
    std :: cout << "Default Constructor Called !" << std :: endl;
}

Fixed :: Fixed(const Fixed &other) : _value(other._value)
{
    std :: cout << "Fixed Copy Constructor Called !" << std :: endl;
}

Fixed :: ~Fixed()
{
    std :: cout << "Fixed Destructor Called !" << std :: endl;
}

Fixed& Fixed :: operator=(const Fixed &other)
{
    std :: cout << "Fixed Assignement Operator Called !" << std :: endl;
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
    std :: cout << "getRawBits member function called" << std :: endl;
    return (_value);
}

void Fixed :: setRawBits( int const raw )
{
    _value = raw;
    std :: cout << "setRawBits member function called" << std :: endl;
}
std::ostream &operator<<(std::ostream &os, Fixed const &f) { os << f.toFloat(); return os; }

