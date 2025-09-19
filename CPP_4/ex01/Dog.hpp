/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:09:39 by leonel            #+#    #+#             */
/*   Updated: 2025/09/19 20:12:41 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
private :
    Brain* _brain;
public :
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(const Dog &other);
    
    void makeSound() const;
    void	displayBrain(void) const;
};