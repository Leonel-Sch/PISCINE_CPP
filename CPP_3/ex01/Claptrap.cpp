/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:34:57 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 19:57:21 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

ClapTrap :: ClapTrap()
{
	_name = "Default Name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std :: cout << "Claptrap Default Constructor Called" << std :: endl;
}
ClapTrap :: ClapTrap(std :: string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std :: cout << "Claptrap Constructor Called" << std :: endl;
}

ClapTrap :: ClapTrap(const ClapTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std :: cout << "Claptrap Copy Constructor Called" << std :: endl;
}
ClapTrap :: ~ClapTrap()
{
	std :: cout << "Claptrap Destructor Called" << std :: endl; 
}
ClapTrap &ClapTrap :: operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std :: cout << "ClapTrap assignement Operator Called" << std :: endl;
	return (*this);
}

void ClapTrap :: attack(const std :: string &target)
{
	if(_energyPoints <= 0)
	{
		std :: cout << "ClapTrap " << _name << " doesn't have any energy left \n";
		return;
	}
	else if (_hitPoints <= 0)
	{
		std :: cout << "ClapTrap " << _name << " is already dead !\n";
		return;
	}
	else
		_energyPoints--;
	std :: cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !\n";
}
void ClapTrap :: takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std :: cout << _name << " is already dead !";
		return;
	}
	if ((int)amount >= _hitPoints)
	{
		_hitPoints = 0;
		std :: cout << _name << " died !\n";
		return;
	}
	else
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std :: cout << _name << " has " << _hitPoints << " pv left !\n";
	}
}
void ClapTrap :: beRepaired(unsigned int amount)
{
	if(_energyPoints <= 0)
	{
		std :: cout << _name << " doesn't have any energy left \n";
		return;
	}
	else if (_hitPoints <= 0)
	{
		std :: cout << _name << " is already dead !\n";
		return;
	}
	else
		_energyPoints--;
	_hitPoints += amount;
	std :: cout << _name << " repaired " << amount << " pv , he has " << _hitPoints<< " pv left now !\n";
}