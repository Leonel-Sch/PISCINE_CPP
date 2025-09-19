/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:07:47 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 19:08:59 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iomanip>
#include <iostream>

class WrongAnimal
{
protected :
    std :: string _type;
public :
    WrongAnimal();
    WrongAnimal(std :: string type);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    
    virtual ~WrongAnimal();
    virtual void makeSound() const;
    virtual const std :: string& getType() const;
};