/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:09:11 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 19:09:12 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal :: WrongAnimal() : _type("Default") {
    std :: cout << "WrongAnimal Class Default Constructor Called ! Its' a " << _type << std :: endl;
}

WrongAnimal :: WrongAnimal(std :: string type) : _type(type) {
    std :: cout << "WrongAnimal Class Constructor Called ! Its' a " << _type << std :: endl;
}

WrongAnimal :: WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std :: cout << "WrongAnimal Class Copy Constructor Called ! Its' a " << _type << std :: endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
    {
        _type = other._type;
    }
    std :: cout << "WrongAnimal Class Assignment Operator Called ! It's a " << _type << std :: endl;
    return (*this);
}

WrongAnimal :: ~WrongAnimal() {
    std :: cout << "WrongAnimal Class Destructor Called ! It was a " << _type << std :: endl;
}

void WrongAnimal :: makeSound() const {
        std :: cout << "WrongAnimal ?\n";
}

const std :: string& WrongAnimal :: getType() const{
    return _type;
}