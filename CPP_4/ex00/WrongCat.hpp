/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:10:21 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/19 19:11:51 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
    WrongCat();
    WrongCat(const WrongCat &other);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &other);
    
    void makeSound() const;
};