/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:08:15 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/05 22:28:49 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef enum
{
    F_Name,
    L_Name,
    N_Name,
    P_Number,
    D_Secret,
} InfoType;

class Contact
{
    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    public:
    void setInfo(std::string info, int type);
    std::string getInfo(int type);
};

