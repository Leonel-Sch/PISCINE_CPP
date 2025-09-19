/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:45:08 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 20:33:17 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog() : Animal("Dog") {
    _brain = new Brain;
    std :: cout << "Dog Default Constructor Called!" << std :: endl;
}

Dog :: Dog(const Dog &other) : Animal(other) {
    _brain = new Brain(*other._brain);
    std :: cout << "Dog Copy Constructor Called!" << std :: endl;
}

Dog& Dog :: operator=(const Dog &other) {
    if (this->_brain != NULL)
        delete this->_brain;
    if (this != &other) {
        Animal::operator=(other);
        this->_brain = new Brain(*other._brain);
    }
    if (this != &other) {
        Animal::operator=(other);
    }
    std :: cout << "Dog Assignment Operator Called!" << std :: endl;
    return *this;
}

Dog :: ~Dog() {
    delete _brain;
    std :: cout << "Dog Destructor Called!" << std :: endl;
}

void Dog :: makeSound() const {
    std :: cout << "Ouaf Ouaf" << std :: endl;
}

void	Dog :: displayBrain(void) const {
	_brain->displayIdeasFirstAddress();
}