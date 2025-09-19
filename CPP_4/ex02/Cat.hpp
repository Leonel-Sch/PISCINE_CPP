/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:09:28 by leonel            #+#    #+#             */
/*   Updated: 2025/09/19 20:12:47 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
private :
    Brain* _brain;
public :
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(const Cat &other);
    
    void makeSound() const;
    void	displayBrain(void) const;
};