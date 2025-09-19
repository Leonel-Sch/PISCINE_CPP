/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:10:24 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 19:12:21 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat :: WrongCat() : WrongAnimal("WrongCat") {
    std :: cout << "WrongCat Default Constructor Called!" << std :: endl;
}

WrongCat :: WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std :: cout << "WrongCat Copy Constructor Called!" << std :: endl;
}

WrongCat& WrongCat :: operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std :: cout << "WrongCat Assignment Operator Called!" << std :: endl;
    return *this;
}

WrongCat :: ~WrongCat() {
    std :: cout << "WrongCat Destructor Called!" << std :: endl;
}

void WrongCat :: makeSound() const {
    std :: cout << "Cocoricco !!!!!!" << std :: endl;
}
