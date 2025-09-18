/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:34:57 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 13:50:28 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

ClapTrap :: ClapTrap()
{
	_name = "Default Name";
	std :: cout << "Claptrap Default Constructor Called" << std :: endl;
}
ClapTrap :: ClapTrap(std :: string name)
{
	_name = name;
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

}

void ClapTrap :: attack(const std :: string &target)
{

}
void ClapTrap :: takeDamage(unsigned int amount)
{

}
void ClapTrap :: beRepaired(unsigned int amount)
{

}