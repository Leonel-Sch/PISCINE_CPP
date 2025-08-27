/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:07:32 by lscheupl          #+#    #+#             */
/*   Updated: 2025/08/27 18:55:19 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void PhoneBook::setLastInput(int input)
{
    if (input == -1)
        lastInput = lastInput + 1;
    else
        lastInput = input;
}

int PhoneBook::getLastInput()
{
    return (lastInput);
}

void PhoneBook::addContact()
{
    std :: cout << "Adding Contact number " << getLastInput() << std :: endl;
    
}