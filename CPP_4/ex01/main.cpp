/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:08:18 by leonel            #+#    #+#             */
/*   Updated: 2025/09/19 20:37:26 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <string.h>
#include <iomanip>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int	main(void) {
	Animal*	animals[100];
	Cat	originalCat;
	Cat	copyCat(originalCat);
	Dog	originalDog;
	Dog	dogAffected;
	
	dogAffected = originalDog;
	originalCat.displayBrain();
	copyCat.displayBrain();
	originalDog.displayBrain();
	dogAffected.displayBrain();

	std::cout << std::endl << "-------------" << std::endl;
	for (size_t i = 0; i < 50; ++i) {
		animals[i] = new Cat();
	}
	for (size_t i = 50; i < 100; ++i) {
		animals[i] = new Dog();
	}
	for (size_t i = 0; i < 100; ++i) {
		delete animals[i];
	}
}