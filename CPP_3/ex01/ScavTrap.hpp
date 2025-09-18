/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:19:26 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 19:44:25 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Claptrap.hpp"
#include <string>
#include <iomanip>
#include <iostream>

class ScavTrap : public ClapTrap
{
public :
    ScavTrap();
    ScavTrap(std :: string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();
    
    void attack(const std :: string &target);
    void guardGate();
};
