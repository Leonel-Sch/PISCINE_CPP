/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:08:27 by lscheupl          #+#    #+#             */
/*   Updated: 2025/07/25 17:06:53 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./contact.hpp"

void    Contact::setInfo (std::string info, int type)
{
    if (type == F_Name)
        _firstName = info;
    else if (type == L_Name)
        _lastName = info;
    else if (type = N_name)
        _nickname = info;
    else if (type = P_Number)
        _phoneNumber = info;
    else if (type = D_Secret)
        _darkestSecret = info;
}

// std::string Contact::getInfo() const
// {
//     return (FirstName + " " + LastName);
// }