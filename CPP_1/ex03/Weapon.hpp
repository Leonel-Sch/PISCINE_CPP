/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:13:29 by leonel            #+#    #+#             */
/*   Updated: 2025/09/10 21:40:45 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
	private :
	std :: string type;
	public :
	std :: string & getType();
	void setType(std :: string type);
	Weapon(std :: string str);
};