/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:41:16 by leonel            #+#    #+#             */
/*   Updated: 2025/09/11 21:42:48 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"
#include <string>


class HumanA
{
	private :
	Weapon* _weapon;
	std :: string _name;
	public :
	void attack();
	HumanA(std :: string name, Weapon &weapon);
	~HumanA();
};