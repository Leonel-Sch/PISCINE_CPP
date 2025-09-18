/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:19:23 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 19:55:12 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once

#include "ScavTrap.hpp" 

ScavTrap :: ScavTrap() : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructed\n";
}

ScavTrap :: ScavTrap(std :: string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Constructor called !\n";
}

ScavTrap :: ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap Assignemnt Operator called !\n";
    return *this;
}

ScavTrap :: ~ScavTrap()
{
    std :: cout << "ScavTrap destroyer called\n";
}

void ScavTrap :: attack(const std :: string &target)
{
	if(_hitPoints <= 0)
	{
        std :: cout << "ScavTrap " << _name << " is already dead !\n";
		
		return;
	}
	else if (_energyPoints <= 0)
	{
		std :: cout << "ScavTrap " << _name << " doesn't have any energy left \n";
		return;
	}
	else
		_energyPoints--;
	std :: cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}