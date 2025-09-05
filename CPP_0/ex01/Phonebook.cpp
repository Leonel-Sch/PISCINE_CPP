/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:07:32 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/05 22:54:42 by leonel           ###   ########.fr       */
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
    usleep(100000);
    std :: cout << "Please Enter Your ";
    if (type == F_Name)
        std :: cout << "First Name";
    else if (type == L_Name)
        std :: cout << "Last Name";
    else if (type == N_Name)
        std :: cout << "Nickname";
    else if (type == P_Number)
        std :: cout << "Phone Number";
    else if (type == D_Secret)
        std :: cout << "Darkest Secret";
    std :: cout << std :: endl << std :: flush;
}

void PhoneBook::addContact()
{
    std :: string info;
    usleep(100000);
    std :: cout << "Adding Contact number " << getLastInput() << std :: endl << std :: flush;
    for(int i = 0; i <= 4; i++)
    {
    printMessage(i);
    std :: cout << "Phonebook>" << std :: flush;
    std :: getline(std :: cin, info);
    if (!(info == ""))
        book[getLastInput() - 1].setInfo(info, i);
    else
        i--;
    }
}
void    printContact(Contact book[8])
{
    std :: string info;
    usleep(100000);
    std :: cout << "|" << std::setw(10) << "index" << "|" << std :: flush;
    usleep(100000);
    std :: cout << std::setw(10) << "First Name" << "|" << std :: flush;
    usleep(100000);
    std :: cout << std::setw(10) << "Last Name" << "|" << std :: flush;
    usleep(100000);
    std :: cout << std::setw(10) << "Nickname" << "|\n" << std :: flush;
    for(int i = 0; i < 8; i++)
    {
        if(book[i].getInfo(0).empty())
            return;
        usleep(100000);
        std :: cout << "|" << std :: setw(10) << i+1 << "|" << std :: flush;
        for(int j = 0; j <= 2; j++)
        {
            usleep(100000);
            info = book[i].getInfo(j);
            if (info.length() > 10)
            {
                std :: cout << info.substr(0 , 9) << ".|" << std :: flush;
            }
            else
                std :: cout << std::setw(10) << book[i].getInfo(j) << "|" << std :: flush;
        }
        std :: cout << std :: endl;
    }
}

int checkNumberInfo(Contact book[8])
{
    for(int i = 0; i < 8; i++)
    {
        if(book[i].getInfo(0).empty())
            return (i);
    }
    return (9);
}
std :: string selectMessage(int i)
{
    if (i == F_Name)
        return ("First Name :");
    else if (i == L_Name)
        return ("Last Name :");
    else if (i == N_Name)
        return ("Nickname :");
    else if (i == P_Number)
        return ("Phone Number :");
    else
        return ("Deepest Secret :");
}

void PhoneBook::searchContact()
{
    std :: string input;
    std :: string index;
    int indexNum;
    printContact(book);
    std :: cout << "PLEASE ENTER YOUR DESIRED INDEX\n" << "Phonebook>" << std :: flush;
    std :: getline(std :: cin, index);
    std :: stringstream ss(index);
    ss >> indexNum;
    
    if (ss.fail() || !ss.eof())
    {
        usleep(100000);
        std :: cout << "ERROR : INVALID INPUT PLEASE RELAUNCH THE SEARCH COMMAND\n" << std :: flush;
        return;
    }
    if (index.length() > 1 || (!(std :: isdigit(index[0]))) || indexNum > 9 || indexNum < 1)
    {
        usleep(100000);
        std :: cout << "ERROR : INVALID INPUT PLEASE RELAUNCH THE SEARCH COMMAND\n" << std :: flush;
        return;
    }
    if (checkNumberInfo(book) < indexNum)
    {
        usleep(100000);
        std :: cout << "ERROR : NO CONTACT AT THIS INDEX, RELAUNCH THE SEARCH COMMAND\n" << std :: flush;
        return;
    }
    for(int j = 0; j <= 4; j++)
    {
        usleep(100000);
        std :: cout << selectMessage(j) << book[indexNum - 1].getInfo(j) << std :: endl << std :: flush;
    }
}