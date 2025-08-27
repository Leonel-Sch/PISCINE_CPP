/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:07:32 by lscheupl          #+#    #+#             */
/*   Updated: 2025/08/27 19:56:55 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void PhoneBook::setLastInput(int input)
{
    if (input == -1)
        lastInput = lastInput + 1;
    else
        lastInput = input;
    if (lastInput >= 9)
        lastInput = 1;

}

int PhoneBook::getLastInput()
{
    return (lastInput);
}

void    printMessage(int type)
{
    std :: cout << "Please Enter Your ";
    if (type == F_Name)
        std :: cout << "First Name";
    else if (type == L_Name)
        std :: cout << "Last Name";
    else if (type == N_name)
        std :: cout << "Nickname";
    else if (type == P_Number)
        std :: cout << "Phone Number";
    else if (type == D_Secret)
        std :: cout << "Darkest Secret";
    std :: cout << std :: endl;
}

void PhoneBook::addContact()
{
    std :: string info;
    std :: cout << "Adding Contact number " << getLastInput() << std :: endl;
    for(int i = 0; i <= 4; i++)
    {
    printMessage(i);
    std :: cout << "Phonebook>";
    std :: getline(std :: cin, info);
    if (!(info == ""))
        book[getLastInput() - 1].setInfo(info, i);
    else
        i--;
    }
}
void    printContact(Contact book[8])
{

    for(int i = 0; i < 8; i++)
    {
        if(book[i].getInfo(0).empty())
            return;
        std :: cout << "|" << i+1 << "|";
        for(int j = 0; j <= 2; j++)
        {
            std :: cout << book[i].getInfo(j) << "|";
        }
        std :: cout << std :: endl;
    }
}


void PhoneBook::searchContact()
{
    printContact(book);
}