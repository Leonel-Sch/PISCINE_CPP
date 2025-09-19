/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:10:12 by leonel            #+#    #+#             */
/*   Updated: 2025/09/19 19:40:12 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iomanip>
#include <iostream>

class Animal
{
protected :
    std :: string _type;
public :
    Animal();
    Animal(std :: string type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    
    virtual ~Animal();
    virtual void makeSound() const;
    virtual const std :: string& getType() const;
};