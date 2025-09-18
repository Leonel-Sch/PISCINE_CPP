/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:27:47 by leonel            #+#    #+#             */
/*   Updated: 2025/09/18 13:33:21 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

class ClapTrap
{
private :
	std :: string _name;
	int _hitPoints = 10;
	int _energyPoints = 10;
	int _attackDamage = 0;
public :
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std :: string &target);
	void takeDamage(unsigned int )
}