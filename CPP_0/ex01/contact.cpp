/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:08:27 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/05 22:28:59 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./contact.hpp"

void    Contact::setInfo (std::string info, int type)
{
    if (type == F_Name)
        _firstName = info;
    else if (type == L_Name)
        _lastName = info;
    else if (type == N_Name)
        _nickname = info;
    else if (type == P_Number)
        _phoneNumber = info;
    else if (type == D_Secret)
        _darkestSecret = info;
}

std :: string Contact::getInfo (int type)
{
    if (type == F_Name)
        return (_firstName);
    else if (type == L_Name)
        return (_lastName);
    else if (type == N_Name)
        return (_nickname);
    else if (type == P_Number)
        return (_phoneNumber);
    else if (type == D_Secret)
        return (_darkestSecret);
    return (NULL);
}
