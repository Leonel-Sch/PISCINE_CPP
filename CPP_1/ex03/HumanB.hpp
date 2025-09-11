/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:26:31 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/11 21:38:33 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"
class HumanB
{
	private :
    std :: string _name;
	Weapon* _weapon;
	public :
	void attack();
	void setWeapon(Weapon& weapon);
	HumanB(std :: string name);
	~HumanB();
};