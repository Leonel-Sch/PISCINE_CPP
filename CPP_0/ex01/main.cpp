/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:23:46 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/05 23:06:24 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
    std :: string input;
    PhoneBook theBook;
    theBook.setLastInput(0);
    usleep(100000);
    std :: cout << "Welcome to the Phonebook2000, the phonebook is empty.\n" << std :: flush;
    usleep(100000);
    std :: cout << "Please use the instruction ADD, to add a contact, SEARCH to search a contact and EXIT to leave\n" << std :: flush;
    while(1)
    {
    std :: cout << "Phonebook>" << std :: flush;
    std :: getline(std :: cin, input);
    if (input == "ADD")
    {
        theBook.setLastInput(-1);
        theBook.addContact();
    }
    if (input == "SEARCH")
        theBook.searchContact();
    if (input == "EXIT")
        return 0;
    }
}