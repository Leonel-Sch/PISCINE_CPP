/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:08:39 by lscheupl          #+#    #+#             */
/*   Updated: 2025/08/27 18:44:36 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include <string.h>

class PhoneBook
{
    private:
    Contact book[8];
    int lastInput;
    public:
    void setLastInput(int input);
    int getLastInput();
    void addContact();
    void searchContact();
    void exitBook();
};