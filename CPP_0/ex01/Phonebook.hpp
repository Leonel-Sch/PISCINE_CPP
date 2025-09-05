/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:08:39 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/05 22:35:35 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include <string>
#include <iomanip>
#include <sstream>
#include <unistd.h>

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