/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:41:16 by leonel            #+#    #+#             */
/*   Updated: 2025/09/10 21:41:17 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.cpp"
#include <string>


class HumanA
{
	private :
	Weapon weapon;
	std :: string name;
	public :
	void attack();
	HumanA();
}