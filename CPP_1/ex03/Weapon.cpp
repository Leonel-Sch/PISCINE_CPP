/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:18:13 by leonel            #+#    #+#             */
/*   Updated: 2025/09/11 21:36:29 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon :: Weapon(std :: string str) :type(str) {}

std :: string & Weapon :: getType()
{
	std :: string &ref = type;
	return (ref);
}

void Weapon :: setType(std :: string newtype)
{
	type = newtype;
}