/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:08:15 by lscheupl          #+#    #+#             */
/*   Updated: 2025/08/27 19:32:08 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef enum
{
    F_Name,
    L_Name,
    N_name,
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

