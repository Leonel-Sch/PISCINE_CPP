/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:45:08 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 20:32:05 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat() : Animal("Cat") {
    _brain = new Brain;
    std :: cout << "Cat Default Constructor Called!" << std :: endl;
}

Cat :: Cat(const Cat &other) : Animal(other) {
    _brain = new Brain(*other._brain);
    std :: cout << "Cat Copy Constructor Called!" << std :: endl;
}

Cat& Cat :: operator=(const Cat &other) {
    if (this->_brain != NULL)
        delete this->_brain;
    if (this != &other) {
        Animal::operator=(other);
        this->_brain = new Brain(*other._brain);
    }
    std :: cout << "Cat Assignment Operator Called!" << std :: endl;
    return *this;
}

Cat :: ~Cat() {
    delete _brain;
    std :: cout << "Cat Destructor Called!" << std :: endl;
}

void Cat :: makeSound() const {
    std :: cout << "Miaou Miaou" << std :: endl;
}

void	Cat :: displayBrain(void) const {
	_brain->displayIdeasFirstAddress();
}