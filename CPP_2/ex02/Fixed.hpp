/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:13:11 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/13 20:18:49 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>

class Fixed
{
    private :
    int _value;
    static const int _fbits = 8;
    public :
    
    Fixed(void);
    Fixed(int const value);
    Fixed(float const value);
    Fixed(const Fixed &other);
    
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    
    Fixed operator+(Fixed const &other);
    Fixed operator-(Fixed const &other);
    Fixed operator*(Fixed const &other);
    Fixed operator/(Fixed const &other);
    
    Fixed &operator++();  
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
    
    bool operator>(Fixed const &other) const;
    bool operator<(Fixed const &other) const;
    bool operator>=(Fixed const &other) const;
    bool operator<=(Fixed const &other) const;
    bool operator==(Fixed const &other) const;
    bool operator!=(Fixed const &other) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &f);