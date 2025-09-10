/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:18:13 by leonel            #+#    #+#             */
/*   Updated: 2025/09/10 21:40:53 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon :: Weapon(std :: string str) :type(str) {}

std :: string & Weapon :: getType()
{
	std :: string &ref = type;
}

void Weapon :: setType(std :: string newtype)
{
	type = newtype;
}