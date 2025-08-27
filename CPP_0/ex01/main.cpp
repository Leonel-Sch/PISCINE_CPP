/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:23:46 by lscheupl          #+#    #+#             */
/*   Updated: 2025/08/27 19:47:17 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
    std :: string input;
    PhoneBook theBook;
    theBook.setLastInput(0);
    std :: cout << "Welcome to the Phonebook2000, the phonebook is empty.\nPlease use the instruction ADD, to add a contact, SEARCH to search a contact and EXIT to leave\n";
    while(1)
    {
    std :: cout << "Phonebook>";
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