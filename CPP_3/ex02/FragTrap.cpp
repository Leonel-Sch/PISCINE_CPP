/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:30:06 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 20:35:35 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp" 

FragTrap :: FragTrap() : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructed\n";
}

FragTrap :: FragTrap(std :: string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Constructor called !\n";
}

FragTrap :: FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Assignemnt Operator called !\n";
    return *this;
}

FragTrap :: ~FragTrap()
{
    std :: cout << "FragTrap destroyer called\n";
}

void FragTrap :: attack(const std :: string &target)
{
	if(_hitPoints <= 0)
	{
        std :: cout << "FragTrap " << _name << " is already dead !\n";
		
		return;
	}
	else if (_energyPoints <= 0)
	{
		std :: cout << "FragTrap " << _name << " doesn't have any energy left \n";
		return;
	}
	else
		_energyPoints--;
	std :: cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !\n";
}

void FragTrap :: highFivesGuys(void)
{
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " cannot request high fives (no HP)." << std::endl;
        return;
    }

    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
    std::cout << "      o/            \\o" << std::endl;
    std::cout << "     /|              |\\ " << std::endl;
    std::cout << "    / \\            / \\" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "          HIGH FIVE!" << std::endl;
}