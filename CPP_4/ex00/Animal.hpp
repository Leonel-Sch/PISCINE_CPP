/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:10:12 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 21:38:47 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iomanip>
#include <iostream>

class Animal
{
protected :
    std :: string _type;
public :
    Animal();
    Animal(std :: string type);
    Animal(Animal &other);
    Animal &operator=(const Animal &other);
    ~Animal();
    void makeSound();
};