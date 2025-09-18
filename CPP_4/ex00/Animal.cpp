/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:31:00 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 22:03:13 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal :: Animal() : _type("Default") {
    std :: cout << "Animal Class Default Constructor Called ! Its' a " << _type << std :: endl;
}

Animal :: Animal(std :: string type) : _type(type) {
    std :: cout << "Animal Class Constructor Called ! Its' a " << _type << std :: endl;
}

Animal :: Animal(Animal &other) : _type(other._type) {
    std :: cout << "Animal Class Copy Constructor Called ! Its' a " << _type << std :: endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
    {
        _type = other._type;
    }
    std :: cout << "Animal Class Assignment Operator Called ! It's a " << _type << std :: endl;
    return (*this);
}

Animal :: ~Animal() {
    std :: cout << "Animal Class Destructor Called ! It was a " << _type << std :: endl;
}

void Animal :: makeSound(){
    if (_type == "Dog")
        std :: cout << "Ouaf Ouaf\n";
    else if (_type == "Cat")
        std :: cout << "Miaou Miaou\n";
    else
        std :: cout << "Silencious Animal ?\n";
}