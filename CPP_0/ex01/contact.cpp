/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:08:27 by lscheupl          #+#    #+#             */
/*   Updated: 2025/07/22 15:13:11 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./contact.hpp"

void    Contact::SetName (std::string name, int type)
{
    if (type == 0)
        FirstName = name;
    else if (type == 1)
        LastName = name;
    else
        std::cout << "Wrong type selected\n";
}

std::string Contact::getFullName() const
{
    return (FirstName + " " + LastName);
}