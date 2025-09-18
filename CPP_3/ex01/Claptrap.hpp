/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:27:47 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 19:46:04 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class ClapTrap
{
protected :
	std :: string 	_name;
	int 			_hitPoints;
	int				_energyPoints;
	int 			_attackDamage;
public :
	ClapTrap();
	ClapTrap(std :: string name);
	ClapTrap(const ClapTrap &other);
	virtual ~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);

	virtual void attack(const std :: string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
